#include <iostream>
#include <fstream>
#include <string>

#include <string.h>
#include <assert.h>
#include <stdio.h>

char* FileManager::readFile(string filename, int start, int end) {
	FILE* filehandle = fopen(filename.c_str(), "r");
	char* buffer = NULL;
	if (filehandle != NULL) {
		buffer = new char[1 + end - start];
		fseek(filehandle, start);
		int i;
		for (i = 0; i < (end - start); i++) {
			buffer[i] = fgetc(filehandle);
		}
	}
	return buffer;
}

void FileManager::writeFile(string filename, char* data, int start, int size) {
	FILE* filehandle = fopen(filename.c_str(), "w");
	if (filehandle != NULL) {
		fseek(filehandle, start);
		int i;
		for (i = 0; i < (end - start); i++) {
			fputs(filehandle, data[i]);
		}
	}

}