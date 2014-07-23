#include <iostream>

#include <string.h>

class FileManager {

	static char* readFile(string filename, int start, int end);
	static char* writeFile(string filename, int start);
};