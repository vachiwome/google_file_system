#ifndef CLIENT_SERVER_HH
#define CLIENT_SERVER_HH

#include <vector>
#include <map>

class ClientServer {
	private:
		int clientId;

	public:
		map<int, vector<ChunkInfo*>> requestReadReplicaInfo(string filename);

		char* readChunkData(int chunkServer, ChunkInfo* chunkInfo);

		char* readChunkData(int chunkServer, vector<ChunkInfo*> chunkInfo);

		char* readChunkData(map<int, vector<ChunkInfo*>> replicaInfo);

		char* readFile(string filename);

		map<int, vector<ChunkInfo*>> requestWriteReplicaInfo(int filesize);

		void sendWriteMessage(int chunkServer, vector<ChunkInfo*> chunkInfo, char* data);

		void sendWriteCommand(int primaryServer, vector<int> replicaServer);

		void writeFile(string filename, char* data, int size);

};
#endif