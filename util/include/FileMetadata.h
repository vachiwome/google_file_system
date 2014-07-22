#ifndef FILE_METADATA_HH
#define FILE_METADATA_HH

#include <string>

using namespace std;

class FileMetadata {
	private:
		vector<int> allowedReaders;
		vector<int> allowedWriters;
		vector<ChunkInfo*> chunkInfo;
};
#endif