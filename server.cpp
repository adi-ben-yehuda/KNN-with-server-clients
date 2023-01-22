#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cmath>
#include "File.h"
#include "CLI.h"
#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

/* Function that get the port as an argument.
 * Check if it is number and and if it is in the valid range.*/
int getPort(char **argv) {
    int port = 0;
    /* Check if the arg is number*/
    if (isNumeric(argv[1])) {
        port = atoi(argv[1]);
        if (port < 1024 || port > 65535) { // Check if the port is in the valid range.
            port = 0;
        }
    }
    return port;
}

// The function checks if the args that entered by the user is valid.
bool argsIsValid(int argc, char **argv) {
    // If the arguments are empty.
    if (argc != 2) {
        return false;
    }

    int port = getPort(argv);
    // If the number is not numeric or not in the valid range, close the program.
    if (port == 0) {
        return false;
    }
    return true;
}


// The function get clientSocket. According to the option from the client, run the correct algorithm.
void *runClient(void *clientSocket) {
    CLI cli = CLI(*(int *) clientSocket);
    cli.start();

    pthread_exit(NULL); // Close the thread.
}


int main(int argc, char **argv) {

    // Check if the args are valid, if not we get out of the program.
    if (!argsIsValid(argc, argv)) {
        cout << "invalid arguments" << endl;
        return 0;
    }

    const int serverPort = atoi(argv[1]);
    int threadC;

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the creation of the socket succeeded.
    if (serverSocket < 0) {
        perror("error creating socket");
    }

    // Initialize the data for the bind between the socket and the port.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(serverPort);

    // Check if the bind succeeded.
    if (bind(serverSocket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    // Check if the listen to socket succeeded.
    if (listen(serverSocket, 5) < 0) {
        perror("error listening to a socket");
    }

    while (true) {

        // Create socket for a specific client.
        struct sockaddr_in client_sin;
        unsigned int addrLen = sizeof(client_sin);
        int clientSocket = accept(serverSocket, (struct sockaddr *) &client_sin, &addrLen);

        // Check if the creation of the socket succeeded.
        if (clientSocket < 0) {
            perror("error accepting client");
        }

        // Create thread for each client.
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_t clientThread;
        threadC = pthread_create(&clientThread, NULL, runClient, (void *) &clientSocket);
        if (threadC) {
            perror("Error creating thread");
        }
    }
    close(serverSocket);
    return 0;
}
