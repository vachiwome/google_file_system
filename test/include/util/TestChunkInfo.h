#ifndef TEST_CHUNK_INFO_HH
#define TEST_CHUNK_INFO_HH

#include <cppunit/TestCaller.h>

using namespace std;

class TestChunkInfo {
	private:
		ChunkInfo* chunkInfo;
		vector<ChunkInfo*> chunkInfoVec;

	public:
		void setUp();

		void tearDown();

		void testGetChunkSize();

		static CppUnit::Test *suite();
};
#endif