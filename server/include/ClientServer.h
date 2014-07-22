#ifndef CLIENT_SERVER_HH
#define CLIENT_SERVER_HH

#include <vector>
#include <map>

class ClientServer {
	private:
		int clientId;

	public:
		map<int, vector<ChunkInfo*>> requestReadReplicaInfo(string filename);
		
		map<int, vector<ChunkInfo*>> requestWriteReplicaInfo(int filesize);

		char* readChunkData(ChunkInfo* chunkInfo);

		char* readChunkData(map<int, vector<ChunkInfo*>> replicaInfo);

		void sendChunkData(ChunkInfo* chunkInfo, char* data);

		void sendChunkData(map<int, vector<ChunkInfo*>> replicaInfo, char* data);

		bool waitForAcks(int numReplicas, double timeout);

		void sendWriteCommand(int primaryChunkServer);

};
#endif