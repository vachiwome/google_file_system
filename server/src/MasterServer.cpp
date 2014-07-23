#include "../include/MasterServer.h"

#include <vector>
#include <map>

map<int,vector<ChunkInfo*> > MasterServer::getChunkServerInfo(string filename) {
	return metadata[filename];
}

void Master::setChunkServerInfo(string filename, map<int, vector<ChunkInfo*> > chunkServerInfo) {
	metadata[filename] = chunkServerInfo;
}

void Master::addChunkServerInfo(string filename, map<int, vector<ChunkInfo*> > addedInfo) {
	map<int, vector<ChunkInfo*> > currentInfo = metadata[filename];
	for (it = addedInfo.begin(); it != addedInfo.end(); it++) {
		currentInfo[it->first].insert(currentInfo[it->first].end(), addedInfo.begin(), addedInfo.end());
	}
}

map<int, vector<ChunkInfo*>> MasterServer::computeCreateChunkInfo(vector<int> replicas, int size) {
	int repl;
	map<int, vector<ChunkInfo*> > chunkServerInfo;
	for (repl = 0; repl < replicas.size(); repl++) {
		vector<ChunkInfo*> chunkInfo = assignChunks(repl,size);
		chunkServerInfo[repl] = chunkInfo;
	}
	return chunkServerInfo;
}

map<int, vector<ChunkInfo*> > MasterServer::computeAppendChunkInfo(string filename, int size) {
	map<int, vector<ChunkInfo*> > currentInfo = metadata[filename];
	vector<int> replicas;
	map<int, vector<ChunkInfo*> >::iterator it;
	for (it = currentInfo.begin(); it != currentInfo.end(); it++) {
		replicas.push_back(it->first);
	}
	return computeCreateChunkInfo(replicas, size);
}

Message* Master::procGetChunkServerInfoMsg(Message* message) {
	map<int,vector<ChunkInfo*> > chunkServerInfo = getChunkServerInfo(message->filename);
	return createMessage(chunkServerInfo);
}

Message* Master::procCreateChunkInfoMsg(Message* message) {
	map<int, vector<ChunkInfo*>> chunkServerInfo = computeCreateChunkInfo(computeChunkReplicas(), message->size);
	return createMessage(chunkServerInfo);
}

Message* Master::procGetAppendChunkInfo(Message* message) {
	map<int, vector<ChunkInfo*> > chunkServerInfo = computeAppendChunkInfo(message->filename, message->size);
	return createMessage(chunkServerInfo);
}

void Master::processMessage(Message* message) {
	Message* response = NULL;
	switch(message->type) {
		case GET_CHUNK_SERVER_INFO_MSG:
			response = procGetChunkServerInfoMsg(message);
			break;
		case GET_CREATE_CHUNK_INFO_MSG:
			response = procCreateChunkInfoMsg(message);
			break;
		case GET_APPEND_CHUNK_INFO_MSG:
			response = procGetAppendChunkInfo(message);
			break;
		default:
			cout << "unknown message type : " << message->type << endl;
			break;
	}
	dns[message->source].sendMessage(response);
}

void Master::serve() {
	while(true) {
		Message* message = recvManager.receiveMessage();
		processMessage(message);
	}
}

