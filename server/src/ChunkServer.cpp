#include "../include/ChunkServer.h"

void ChunkServer::processMessage(Message* message) {
	switch(Message.type) {
		case READ_CHUNK_DATA_MSG:
			processReadChunkData(message->chunkInfo);
			break;
		case READ_BULK_CHUNK_DATA_MSG:
			processReadBulkChunkData(message->bulk_chunk_info); 
			break;
		case WRITE_MSG:
			processWriteMessage(message->bulk_chunk_info, message->data);
			break;
		case WRITE_COMMAND_MSG:
			processWriteCommand(message->primaryId);
			break;
		default:
			cout << "unknown message type : " << message.type << endl;
			exit(1);
		acknowledgeData(message->source);
	}
}

void ChunkServer::processReadChunkData(ChunkInfo* chunkInfo, int source) {
	char* data = FileManager::readFile(chunkToFile[chunkInfo->chunkId], chunkInfo->start, chunkInfo->end);
	Message* fileDataMsg = createMessage(RETURN_CHUNK_DATA, data);
	dns[source].sendMessage(fileDataMsg);
}

void ChunkServer::processReadBulkChunkData(vector<ChunkInfo*> chunkInfo, int) {
	int size = getChunkSize(chunkInfo);
	char* data = new char[size];
	int chunk;
	for (chunk = 0; chunk < chunkInfo.size(); chunk++) {
		char* chunkData = FileManager::readFile(chunkToFile[chunkInfo->chunkId], chunkInfo->start, chunkInfo->end);
		int i, s = getChunkSize(chunkInfo);
		for (i = 0; i < s; i++) {
			data[i] = chunkData[i];
		}
		data += s;
	}

	Message* fileDataMsg = createMessage(RETURN_BULK_CHUNK_DATA, data);
	dns[source].sendMessage(fileDataMsg);
}

void ChunkServer::processWriteMessage(int source, vector<ChunkInfo*> chunkInfo, char* data) {
	ClientData* clData = createClientData(chunkInfo, data);
	clientData[source] = clData;
}

void ChunkServer::processWriteCommand(int client) {
	vector<ChunkInfo*> chunkInfo = clientData[client]->chunkInfo;
	char* data = clientData[client]->data;	
	int chunk = 0, offset = 0;
	for (chunk = 0; chunk < chunkInfo.size(); chunk++) {
		FileManager::writeFile(data + offset, chunkInfo[chunk]->start, chunkInfo[chunk]->end);
		offset += getChunkSize(chunkInfo[chunk]);
	}
}

void ChunkServer::acknowledgeData(int target) {
	Message* ack = createMessage(ACK_MSG, this->getId());
	dns[target].sendMessage(ack);
}

void ChunkServer::serve() {
	while(true) {
		Message* msg = commManager.receiveMessage();
		processMessage(msg);
	}
}
