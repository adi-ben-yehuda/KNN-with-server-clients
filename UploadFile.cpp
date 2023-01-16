#include "UploadFile.h"
#include <netinet/in.h>
#include <cstring>
#include "File.h"

using namespace std;

UploadFile:: UploadFile() {
    pathTrain = "";
    pathTest = "";
    description = "1. upload an unclassified csv data file";
}

// Setter for pathTrain.
void UploadFile::setTrain(string train){
    pathTrain = train;
}

// Setter for pathTest.
void UploadFile::setTest(string test){
    pathTest = test;
}

// Setter for clientSocket.
void UploadFile::setSocket(int socket){
    sock = socket;
}

// Getter for pathTrain.
string UploadFile::getTrain() {
    return pathTrain;
}

// Getter for pathTest.
string UploadFile::getTest() {
    return pathTest;
}

string UploadFile::getDescription() {
    return description;
}

void UploadFile::execute(){
    ofstream File;
    int sent_bytes = 0, readBytes = 0;
    string messageTrain = "Please upload your local train CSV file.\n",
    messageTest = "Please upload your local test CSV file.\n", complete = "Upload complete.\n";
    char buffer[4096] = " ";
    int expectedDataLen = sizeof(buffer);
    bool close = false;

    // Send messageTrain to the client.
    sent_bytes = send(sock, messageTrain.c_str(), messageTrain.length(), 0);
    // Check if the sending of the data succeeded.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

    File = createFile("train");
    // Get all the data.s
    while (!close) {
        readBytes = recv(sock, buffer, expectedDataLen, 0);

        if (readBytes <= 0) {
            perror("error receiving from client");
        } else {
            for (int i = 0; i < 4096; ++i) {
                if (buffer[i] != '&') {
                    File << buffer[i];
                } else {
                    close=true;
                    break;
                }
            }
        }
    }

    File.close();

    // Send "Upload complete" message to the client.
    sent_bytes = send(sock, complete.c_str(), complete.length(), 0);
    // Check if the sending of the data succeeded.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

    // Send messageTest to the client.
    sent_bytes = send(sock, messageTest.c_str(), messageTest.length(), 0);
    // Check if the sending of the data succeeded.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

    memset(buffer, ' ', 4096);
    File = createFile("test");
    close = false;

    while (!close) {
        readBytes = recv(sock, buffer, expectedDataLen, 0);

        if (readBytes <= 0) {
            perror("error receiving from client");
        } else {
            for (int i = 0; i < 4096; ++i) {
                if (buffer[i] != '&') {
                    File << buffer[i];
                } else {
                    close=true;
                    break;
                }
            }
        }
    }

    File.close();

    // Send "Upload complete" message to the client.
    sent_bytes = send(sock, complete.c_str(), complete.length(), 0);
    // Check if the sending of the data succeeded.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}

/* Destructor. */
UploadFile::~UploadFile() {}