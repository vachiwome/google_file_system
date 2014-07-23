#ifndef CHUNK_INFO
#define CHUNK_INFO

#include <vector>

using namespace std;

struct ChunkInfo {
	int chunkId;
	int startOffset;
	int endOffset;
};

typedef struct ChunkInfo ChunkInfo;

ChunkInfo* createChunkInfo(int chunkId, int startOffset, int endOffset);

int getChunkSize(ChunkInfo* chunkInfo);

int getChunkSize(vector<ChunkInfo*> chunkInfo);

#endif