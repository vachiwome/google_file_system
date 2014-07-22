#ifndef MASTER_SERVER_HH
#define MASTER_SERVER_HH

#include <vector>
#include <map>

class MasterServer : public BasicServer {
	private:
		map<string, FileMetadata> metadata;
		map<int, map<int, vector<string>>> filesOnChunk;
		map<int, vector<ChunkInfo*>> chunkReplicas;

		bool canClientAccessChunk(int clientId, int chunkServerId, int chunkId, int mode);

	public:

		vector<ChunkInfo*> computeReadChunkInfo(string filename);

		vector<ChunkInfo*> computeWriteChunkInfo(string filename, int size);

		void sendFileChunkInfo(vector<ChunkInfo*> info, string hostname, int portno);

		void sendAccessRights(bool hasRights, string hostname, int portno);

};
#ifndef
