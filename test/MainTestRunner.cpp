#include <cppunit/ui/text/TestRunner.h>

#include "include/util/TestFileManager.h"
#include "include/util/TestChunkInfo.h"

#include "include/server/TestClientServer.h"
#include "include/server/TestMasterServer.h"
#include "include/server/TestBasicServer.h"
#include "include/server/TestChunkServer.h"

#include "include/comm/TestSocketManager.h"
#include "include/comm/TestCommManager.h"
#include "include/comm/TestMessage.h"

int main( int argc, char **argv) {
	CppUnit::TextUi::TestRunner runner;

	runner.addTest(TestFileManager::suite());
	runner.addTest(TestChunkInfo::suite());

	runner.addTest(TestClientServer::suite());
	runner.addTest(TestMasterServer::suite());
	runner.addTest(TestBasicServer::suite());
	runner.addTest(TestChunkServer::suite());

	runner.addTest(TestSocketManager::suite());
	runner.addTest(TestCommManager::suite());
	runner.addTest(TestMessage::suite());

	runner.run();

	return 0;
	}