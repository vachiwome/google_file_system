#ifndef CHUNK_SERVER_DATA
#define CHUNK_SERVER_DATA

#define CHUNK_SIZE 64

struct ChunkServerData {
	int currentChunk;
	int chunkOffset;
};

typedef ChunkServerData ChunkServerData;

#endif