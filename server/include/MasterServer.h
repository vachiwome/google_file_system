#ifndef MASTER_SERVER_HH
#define MASTER_SERVER_HH

#include <vector>
#include <map>

#include "../../util/include/FileMetadata.h"

class MasterServer : public BasicServer {
	private:
		map<string, FileMetadata> metadata;
		map<int, ChunkServerData> chunkServerData;
		vector<int> chunkServers;


		bool canClientAccessChunk(int clientId, int chunkServerId, int chunkId, int mode);

		vector<ChunkInfo*> assignChunks(int chunkServer, int size);

		vector<int> computeReplicas();

	public:

		map<int,vector<ChunkInfo*> > computeReadChunkInfo(string filename);

		map<int, vector<ChunkInfo*> > computeWriteChunkInfo(int size);

		void sendFileChunkInfo(map<int, vector<ChunkInfo*> > chunkInfo, int chunkServer);

		void sendAccessRights(bool hasRights, int chunkServer);

};
#ifndef
