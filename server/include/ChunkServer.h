#ifndef CHUNK_SERVER_HH
#define CHUNK_SERVER_HH

#include <map>

class ChunkServer : public BasicServer {

	private:

	public:
		void writeChunkData(ChunkInfo* chunkInfo, char* data);

		map<ChunkInfo*, char* chunkData> receiveSingleChunkData();

		map<ChunkInfo*, char* chunkData> receiveBulkChunkData();

		vector<int> waitForWriteOrder();

		void writeData(vector<int> writeOrder, map<ChunkInfo*, char* chunkData>);

		void acknowledgeChunk();
};
#endif