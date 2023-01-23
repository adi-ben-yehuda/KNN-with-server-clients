#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "File.h"
#include <pthread.h>


using namespace std;

/* Function that get the port as an argument.
 * Check if it is number and if it is in the valid range.*/
int getPort(char **argv) {
    int port = 0;
    /* Check if the arg is number*/
    if (isNumeric(argv[2])) {
        port = atoi(argv[2]);
        if (port < 1024 || port > 65535) { // Check if the port is in the valid range.
            port = 0;
        }
    }
    return port;
}

void option1(int sock) {
    string pathTrain = "", pathTest = "";
    char buffer[4096] = " ";
    int expected_data_len = sizeof(buffer);
    int sent_bytes, read_bytes;

    // Receive messageTrain from the server.
    read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer;
    }

    // Get the path of train file from the user.
    getline(cin,pathTrain);

    // If the pathTrain is empty or invalid path.
    if (pathTrain == "" || !isFileExist(pathTrain)) {
        cout << "invalid input" << endl;
        // Send messageTrain to the client.
        sent_bytes = send(sock, "*", 1, 0);
        // Check if the sending of the data succeeded.
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
        // Get menu from server.
        read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes <= 0) {
            cout << "Acceptance failed" << endl;
        }
        cout << buffer;
        return;
    }
    sendDataFile(sock, pathTrain);

    memset(buffer, '\000', 4096);
    // Get "upload complete" and messageTest from server.
    read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer;
    }

    // Get the path of test file from the user.
    getline(cin,pathTest);


    // If the pathTest is empty or invalid path.
    if (pathTest == "" || !isFileExist(pathTest)) {
        cout << "invalid input" << endl;
        // Send messageTrain to the client.
        sent_bytes = send(sock, "*", 1, 0);
        // Check if the sending of the data succeeded.
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
        // Get menu from server.
        read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes <= 0) {
            cout << "Acceptance failed" << endl;
        }
        cout << buffer;
        return;
    }
    sendDataFile(sock, pathTest);

    memset(buffer, '\000', 4096);
    // Get "upload complete" and the menu from server.
    read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer;
    }
}

void option2(int sock) {
    char buffer[4096] = " ";
    int expected_data_len = sizeof(buffer), sent_bytes;
    string parameters;

    // Receive message of the current settings from the server.
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer;
    }

    // Get the parameters from the console.
    getline(cin, parameters);

    if (parameters != "") {
        sent_bytes = send(sock, parameters.c_str(), parameters.length(), 0);
        if (sent_bytes < 0) {
            cout << "Sending failed" << endl;
        }
    } else {
        sent_bytes = send(sock, "*", 1, 0);
        if (sent_bytes < 0) {
            cout << "Sending failed" << endl;
        }
    }

    memset(buffer, '\000', 4096);
    // Get invalid message and the menu from server.
    read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer;
    }
}

void option3(int sock) {
    char buffer[4096] = " ";
    int expected_data_len = sizeof(buffer);

    // Receive message from the server: complete or upload data.
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) { //  connection is closed
        close(sock);
    } else if (read_bytes < 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer;
    }
}

void option4(int sock) {
    char buffer[4096] = "\000";
    int expected_data_len = sizeof(buffer);
    int read_bytes;
    bool close = false;
    string data = "";

    // Get all the classification from the server.
    while (!close) {
        memset(buffer, '\000', 4096);
        read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes <= 0) {
            perror("error receiving from client");
        } else {
            for (int i = 0; i < 4096; ++i) {
                if (buffer[i] != '&' && buffer[i] != '\000') {
                    data += buffer[i];
                } else if (buffer[i] == '\000') {
                    close = true;
                    break;
                }
            }
        }
    }
    cout << data;
}

typedef struct {
    string path;
    string data;
} argsStruct;

// Write the data to a file that exists in the path.
void *writeToFile(void *parameter) {
    argsStruct *args = (argsStruct *) parameter;
    ofstream File;

    File = createFile(args->path);
    if (File) {
        File << args->data;
        File.close();
    }

    delete args;
    pthread_exit(NULL); // Close the thread.
}

// Check if the end of the path is csv or txt
bool checkEnd(string path) {
    char *temp;
    string end;
    const int length = path.length();

    // declaring character array (+1 for null terminator)
    char *char_array = new char[length + 1];

    // copying the contents of the string to char array
    strcpy(char_array, path.c_str());

    // Split the path according to .
    char *token = strtok(char_array, ".");

    while (token != NULL) {
        temp = token;
        token = strtok(NULL, ".");
    }

    end = temp;
    if (end == "csv" || end == "txt") {
        return true;
    }
    return false;
}

void option5(int sock) {
    string path = "";
    int read_bytes, threadC;
    char buffer[4096] = " ";
    int expected_data_len = sizeof(buffer);
    ofstream File;
    bool close = false, sign = false, valid = true;
    string data = "";

    // Get the path for creating file from the user.
    getline(cin, path);

    // In case the path is empty or exists or doesn't end with csv or txt,
    // print invalid input
    if (path == "" || isFileExist(path) || !checkEnd(path)) {
        cout << "invalid input" << endl;
        valid = false;
    }

    // Receive all the classifications from the server.
    while (!close) {
        memset(buffer, '\000', 4096);
        read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes <= 0) {
            perror("error receiving from client");
        } else {
            for (int i = 0; i < 4096; ++i) {
                // Before the &, this is the data to write to the file.
                if (!sign && buffer[i] != '&') {
                    data += buffer[i];
                } else if (buffer[i] == '&') {
                    // That is from now, will be the menu.
                    sign = true;
                } else if (sign && buffer[i] != '&' && buffer[i] != '\000') {
                    // Print the menu.
                    cout << buffer[i];
                } else if (buffer[i] == '\000') {
                    close = true;
                    break;
                }
            }
        }
    }

    if (valid) {
        argsStruct *args = new argsStruct;
        args->data = data;
        args->path = path;

        // Create thread for each client.
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_t clientThread;
        threadC = pthread_create(&clientThread, NULL, writeToFile, (void *) args);
        if (threadC) {
            perror("Error creating thread");
        }
    }
}

int main(int argc, char **argv) {
    // If the arguments are empty. or the port is invalid.
    if (argc != 3 || getPort(argv) == 0) {
        cout << "invalid arguments" << endl;
        return false;
    }

    const char *ip_address = argv[1];
    const int port = getPort(argv);
    string option;
    char buffer[4096] = " ";
    int read_bytes, expected_data_len = sizeof(buffer);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // Check if the creation of the socket succeeded.
    if (sock < 0) {
        perror("error creating socket");
    }

    // Initialize the data for the connection to the server.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);

    // Check if the connection succeeded.
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        return false;
    }
    // Menu
    read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes <= 0) {
        cout << "Acceptance failed" << endl;
    } else {
        cout << buffer;
    }

    /* Get numbers from the user and saves them in vectors. */
    while (true) {
            option = cin.get();
            cin.ignore(256, '\n');

            // Send the data that get from the console, to the server.
            int sent_bytes = send(sock, option.c_str(), option.length(), 0);
            if (sent_bytes < 0) {
                cout << "Sending failed" << endl;
            }
            if (option == "1") {
                option1(sock);
            } else if (option == "2") {
                option2(sock);
            } else if (option == "3") {
                option3(sock);
            } else if (option == "4") {
                option4(sock);
            } else if (option == "5") {
                option5(sock);
            } else if (option == "8") {
                close(sock);
                break;
            } else {
                cout << "else" << endl;
                // recieve invalid option message.
                read_bytes = recv(sock, buffer, expected_data_len, 0);
                if (read_bytes <= 0) {
                    cout << "Acceptance failed" << endl;
                } else {
                    cout << buffer;
                }
            }
    }
}