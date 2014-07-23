#include <iostream>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netdb.h>
#include <netinet/in.h>

#include "../include/SocketManager.h"


int SocketManager::getFd() {
	return this->fd;
}

int SocketManager::receiveData(char* buffer) {
	return read(this->fd, buffer, MAX_MSG_SIZE);
}

void SocketManager::sendData(const void* data, int size) {
	write(this->fd, data, size);
}

void SocketManager::connectToHost(string hostname, int portno) {
	int sockfd;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
	    exit(1);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;

	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
	    //TODO, call the logger
	    exit(1);
	}
	this->fd = sockfd;
}


void SocketManager::listenAndAccept(int portno){
	int sockfd, newsockfd, truth = 1;
     socklen_t clilen;
     struct sockaddr_in serv_addr, cli_addr;

     if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        //TODO, call the logger
        exit(1);
     }

    if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&truth,sizeof(int)) == -1) {
        //TODO, call the logger
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        //TODO, call the logger
      exit(1);
    }

    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        close(sockfd);
        // TODO, call the logger
        exit(1);
    }
    close(sockfd);
    this->fd = newsockfd;
}


