#include "../include/MasterServer.h"

#include <vector>
#include <map>

map<int,vector<ChunkInfo*> > MasterServer::computeReadChunkInfo(string filename) {

}

map<int, vector<ChunkInfo*>> MasterServer::computeWriteChunkInfo(int size) {

}

void MasterServer::sendFileChunkInfo(map<int, vector<ChunkInfo*> > chunkInfo, int chunkServer) {

}

void MasterServer::sendAccessRights(bool hasRights, int chunkServer) {
	
}


