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





int main(int argc, char **argv) {

    // Check if the args are valid, if not we get out of the program.
    if (!argsIsValid(argc, argv)) {
        cout << "invalid arguments" << endl;
        return 0;
    }

    const int serverPort = atoi(argv[1]);

    int k = 0, i = 0, countErrors = 0, sent_bytes = 0;
    string distance = "", error = "invalid input";
    vector<double> p, q, r;
    bool isValid = true, isK = false, isDistance = false, isVector = false;
    char *token = NULL;
    double numCheck = 0.0, validDistance = 0.0;
//    MaxHeap kHeap;




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

//    while (true) {


    // Create socket for a specific client.
    struct sockaddr_in client_sin;
    unsigned int addrLen = sizeof(client_sin);
    int clientSocket = accept(serverSocket, (struct sockaddr *) &client_sin, &addrLen);

    // Check if the creation of the socket succeeded.
    if (clientSocket < 0) {
        perror("error accepting client");
    }

    // The default values.
    Data data = Data();
    data.setSock(clientSocket);
    Command *options[5];

    options[0] = new UploadFile(&data);
    options[1] = new Setting(&data);
    options[2] = new Classify(&data);
    options[3] = new Results(&data);
    options[4] = new Download(&data);

    while (true) {
        sendMenu(options, clientSocket);

        // Get data from the clientSocket to buffer.
        char buffer[4096] = " ";
        int expectedDataLen = sizeof(buffer);
        int readBytes = recv(clientSocket, buffer, expectedDataLen, 0);

        if (readBytes <= 0) {
            isValid = false;
        } else if (buffer[0] == '8' && buffer[1] == '\000') {
            // The user enters 8 in the console.
            close(clientSocket);
            break;
        } else {
            if (optionIsNumber(buffer)) { // Check if the option is in the range 1-5.
                i = stoi(&buffer[0]) - 1;
                options[i]->execute();
            } else { // Print invalid input.
                sent_bytes = send(clientSocket, error.c_str(), error.length(), 0);
                // Check if the sending of the data succeeded.
                if (sent_bytes < 0) {
                    perror("error sending to client");
                }
            }


        }
//                string num = "";
//                // Separate the buffer by spaces.
//                token = strtok(buffer, " ");
//                while (token != NULL) {
//                    stringstream s(token);
//                    // Check if the token is numeric.
//                    if (isNumeric(token)) {
//                        // After the distance comes the k.
//                        if (countErrors == 1) {
//                            k = stoi(token);
//                            isK = true;
//                            break;
//                        } else {
//                            // Add the number to the vector.
//                            p.push_back(stod(token));
//                            isVector = true;
//                        }
//                    } else if (s >> numCheck && s.eof()) { // The input is double or negative.
//                        // After the distance comes the k, and it can't be a double or negative.
//                        if (countErrors == 1) {
//                            isValid = false;
//                            break;
//                        } else {
//                            // Add the number to the vector.
//                            p.push_back(stod(token));
//                            isVector = true;
//                        }
//                    } else { // The data is string
//                        countErrors++;
//                        if (countErrors == 1) {
//                            validDistance = getDistance(r, q, token);
//                            // Check if the distance is valid algorithm.
//                            if (validDistance != -1) {
//                                distance = token;
//                                isDistance = true;
//                            } else {
//                                isValid = false;
//                                break;
//                            }
//                        } else { // That is, there are more than one time that we get a string.
//                            isValid = false;
//                            break;
//                        }
//                    }
//                    token = strtok(NULL, " ");
//                }
//            }
//
//            // Check if the vector is empty.
//            if (p.empty()) {
//                isValid = false;
//            }
//
//            // Check if the server does not get a vector, distance or k.
//            if (!(isK && isDistance && isVector)) {
//                sent_bytes = send(clientSocket, error.c_str(), error.length(), 0);
//            } else if (!isValid) { // If the data we received from the client is invalid.
//                sent_bytes = send(clientSocket, error.c_str(), error.length(), 0);
//            } else { // If all data is valid, send the classification to the client.
//                kHeap = getKNearestElements(fileName, p, distance, k);
//                // That is, there was an error in the size of the vector or the data in the file is invalid.
//                if (kHeap.getHeap().empty()) {
//                    sent_bytes = send(clientSocket, error.c_str(), error.length(), 0);
//                } else {
//                    string common = getCommonType(kHeap);
//                    sent_bytes = send(clientSocket, common.c_str(), common.length(), 0);
//                }
//            }
//
//            // Check if the sending of the data succeeded.
//            if (sent_bytes < 0) {
//                perror("error sending to client");
//            }
//
//            isValid = true;
//            countErrors = 0;
//            p.clear();
    }
//    }

    close(serverSocket);
    return 0;
}
