#include <string>

#include "../include/ClientServer.h"

map<int, vector<ChunkInfo*> > ClientServer::requestReadReplicaInfo(filename) {
	Message* readReplicaMsg = createMessage(MessageType.READ_REPLICA_MSG, filename);
	dns[MASTER_SERVER].sendMessage(readReplicaMsg);
	Message* response = dns[MASTER_SERVER].receiveMessage();
	return response->readReplicaInfo;
}

char* ClientServer::readChunkData(int chunkServer, ChunkInfo* chunkInfo) {
	Message* readChunkMsg = createMessage(MessageType.READ_CHUNK_MSG, ChunkInfo* chunkInfo);
	dns[chunkServer].sendMessage(readChunkMsg);
	Message* response = dns[chunkServer].receiveMessage();
	return response->data;
}

char* ClientServer::readBulkChunkData(int chunkServer, vector<ChunkInfo*> chunkInfo) {
	Message* readBulkChunkMsg = createMessage(MessageType.READ_BULK_CHUNK_MSG);
	dns[chunkServer].sendMessage(readBulkChunkMsg);
	Message* response = dns[chunkServer].receiveMessage();
	return response->data;
}

char* ClientServer::readFile(string filename) {
	map<int, vector<ChunkInfo*> > replicaInfo = requestReadReplicaInfo(filename);
	map<int, vector<ChunkInfo*> >::iterator it;
	for (it = replicaInfo.begin(); it != replicaInfo.end(); it++) {
		char* data = readBulkChunkData(it->first, it->second);
		if (data != NULL) {
			return data;
		} 
	} 
	return NULL;
}


map<int, std::vector<ChunkInfo*> > ClientServer::requestWriteReplicaInfo(int filesize) {
	Message* writeReplicaInfoMsg = createMessage(MessageType.WRITE_REPLICA_MSG, filesize);
	dns[MASTER_SERVER].sendMessage(writeReplicaInfoMsg);
	Message* response = dns[MASTER_SERVER].receiveMessage();
	return response->writeReplicaInfo;
}


void ClientServer::sendWriteMessage(int chunkServer, vector<ChunkInfo*> chunkInfo, char* data) {
	Message* writeMessage = createMessage(MessageType.WRITE_MESSAGE, vector<ChunkInfo*> chunkInfo, data);
	dns[chunkServer].sendMessage(writeMessage);
	Message* ack = dns[MASTER_SERVER].receiveMessage();
	assert(ack != NULL);
}

void ClientServer::sendWriteCommand(int primaryServer, vector<int> replicas) {
	Message* writeCommand = createMessage(MessageType.WRITE_COMMAND_MSG, vector<int> replicas);
	dns[primaryServer].sendMessage(writeCommand);
	Message* ack = dns[primaryServer].receiveMessage();
	assert(ack != NULL);
} 

void ClientServer::writeFile(string filename, char* data, int size) {
	map<int, vector<ChunkInfo*> > writeReplicaInfo = requestWriteReplicaInfo(size);
	map<int, vector<ChunkInfo*> >::iterator it;
	vector<int> replicas;
	for (it = writeReplicaInfo.begin(); it != writeReplicaInfo.end(); it++) {
		replicas.push_back(it->first);
		sendWriteMessage(it->first, it->second, data);
	}
	int primaryServer = replicas.size()/2;
	sendWriteCommand(primaryServer, replicas)
}





