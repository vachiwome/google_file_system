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
	}
}

void ChunkServer::processReadChunkData(ChunkInfo* chunkInfo) {

}

void ChunkServer::processReadBulkChunkData(vector<ChunkInfo*> chunkInfo) {

}

void ChunkServer::processWriteMessage(vector<ChunkInfo*> chunkInfo, char* data) {

}

void ChunkServer::processWriteCommand(int primaryId) {

}

void ChunkServer::acknowledgeData() {

}

void ChunkServer::work() {

}
