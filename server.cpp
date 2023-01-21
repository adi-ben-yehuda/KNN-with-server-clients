#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <cmath>
#include <map>
#include "File.h"
#include "Command.h"
#include "UploadFile.h"
#include "Results.h"
#include "Classify.h"
#include "Setting.h"
#include "Download.h"
#include "Data.h"
#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;


/* The function gets string of the user input and checks if it is numeric. */
bool optionIsNumber(string buffer) {
    char opt = buffer[0];
    if ((opt == '1' || opt == '2' || opt == '3' || opt == '4' || opt == '5') && buffer[1] == '\000') {
        return true;
    }
    return false;
}

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

// The function send to the client the menu.
void sendMenu(Command *options[5], int clientSocket) {
    string desc;
    int sent_bytes;

    desc = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i = 0; i < 5; ++i) {
        desc += options[i]->getDescription() + "\n";
    }
    sent_bytes = send(clientSocket, desc.c_str(), desc.length(), 0);

    // Check if the sending of the data succeeded.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}

// The function get clientSocket. According to the option from the client, run the correct algorithm.
void *runClient(void *clientSocket) {
    int sent_bytes = 0, readBytes = 0, i = 0;
    string error = "invalid input\n";

    int clientSock = *(int *) clientSocket;
    SocketIO * sio = new SocketIO(clientSock);
    Data data = Data();
    data.setSock(clientSock);
    Command *options[5];

    options[0] = new UploadFile(&data, sio);
    options[1] = new Setting(&data, sio);
    options[2] = new Classify(&data,  sio);
    options[3] = new Results(&data, sio);
    options[4] = new Download(&data, sio);

    while (true) {
        // Send menu to the client.
        sendMenu(options, clientSock);

        // Get data from the clientSocket to buffer.
        char buffer[4096] = " ";
        int expectedDataLen = sizeof(buffer);
        readBytes = recv(clientSock, buffer, expectedDataLen, 0);
        if (readBytes <= 0) {
            perror("error reading from client");
        } else if (buffer[0] == '8' && buffer[1] == '\000') {
            // The user enters 8 in the console so close the connection with the client.
            close(clientSock);
            break;
        } else {
            if (optionIsNumber(buffer)) { // Check if the option is in the range 1-5.
                i = stoi(&buffer[0]) - 1;
                options[i]->execute();
            } else { // Print invalid input.
                sent_bytes = send(clientSock, error.c_str(), error.length(), 0);
                // Check if the sending of the data succeeded.
                if (sent_bytes < 0) {
                    perror("error sending to client");
                }
            }
        }
    }
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
