#ifndef CLIENT_SERVER_HH
#define CLIENT_SERVER_HH

#include <vector>
#include <map>

class ClientServer {
	private:
		int clientId;

	public:
		map<int, vector<ChunkInfo*>> requestReadReplicaInfo(string filename);

		void readChunkData(int chunkServer, ChunkInfo* chunkInfo, char* buffer);

		void readChunkData(int chunkServer, vector<ChunkInfo*> chunkInfo, char* buffer);

		void readChunkData(map<int, vector<ChunkInfo*>> replicaInfo, char* buffer);

		char* readFile(string filename);

		map<int, vector<ChunkInfo*>> requestWriteReplicaInfo(int filesize);

		void sendWriteMessage(int chunkServer, vector<ChunkInfo*> chunkInfo, char* data);

		void sendWriteCommand(int primaryServer, vector<int> replicaServer);

		bool waitForAcks(vector<int> replicas, double timeout);

		void writeFile(string filename, char* data);

};
#endif