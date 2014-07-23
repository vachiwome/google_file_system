#ifndef CHUNK_SERVER_HH
#define CHUNK_SERVER_HH

#include <vector>
#include <map>

class ChunkServer : public BasicServer {

	public:

		void processReadChunkData(ChunkInfo* chunkInfo, char* buffer);

		void processReadChunkData(vector<ChunkInfo*> chunkInfo, char* buffer);

		void processWriteMessage(vector<ChunkInfo*> chunkInfo, char* data);

		void processWriteCommand(int primaryId);

		void acknowledgeData();
};
#endif