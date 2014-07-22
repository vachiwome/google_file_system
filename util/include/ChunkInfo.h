#ifndef CHUNK_INFO
#define CHUNK_INFO

struct ChunkInfo {
	int chunkServerId;
	int chunkId;
	int startOffset;
	int endOffset;
};

typedef struct ChunkInfo ChunkInfo;

ChunkInfo* createChunkInfo(int chunkServerId, int chunkId, int startOffset, int endOffset);

#endif