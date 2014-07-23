#ifndef FILE_METADATA_HH
#define FILE_METADATA_HH

#include <string>
#include <vector>
#include <map>

using namespace std;

struct FileMetadata {
	private:
		vector<int> allowedReaders;
		vector<int> allowedWriters;
		map<int,vector<ChunkInfo*> > chunkServerInfo;
};

typedef struct FileMetadata FileMetadata;

#endif