#include <iostream>

#include <string.h>

class FileManager {

	static char* readFile(string filename, int start, int end);
	static void writeFile(string filename, char* data, int start, int size);
};