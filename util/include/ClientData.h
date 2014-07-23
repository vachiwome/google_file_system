#ifndef CLIENT_DATA_HH
#define CLIENT_DATA_HH

#include <vector>

struct ClientData {
	vector<ChunkInfo*> chunkInfo;
	char* data;
};

typedef struct ClientData ClientData;

ClientData* createClientData(vector<ChunkInfo*> chunkInfo, char* data);

#endif