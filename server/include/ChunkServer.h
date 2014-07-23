#ifndef CHUNK_SERVER_HH
#define CHUNK_SERVER_HH

#include <vector>
#include <string>
#include <map>

using namespace std;

class ChunkServer : public BasicServer {

	private:
		map<int, string> chunkToFile;

	public:

		void work();

		void processMessage(Message);

		void processReadChunkData(ChunkInfo* chunkInfo, char* buffer);

		void processReadChunkData(vector<ChunkInfo*> chunkInfo, char* buffer);

		void processWriteMessage(vector<ChunkInfo*> chunkInfo, char* data);

		void processWriteCommand(int primaryId);

		void acknowledgeData();
};
#endif