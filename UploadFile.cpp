#include "UploadFile.h"
#include <netinet/in.h>
#include <cstring>
#include "File.h"
#include "Data.h"

using namespace std;

UploadFile::UploadFile(Data *data, DefaultIO * dio) {
    description = "1. upload an unclassified csv data file";
    this->data = data;
    this->dio = dio;
}

string UploadFile::getDescription() {
    return description;
}

void UploadFile::execute() {
    ofstream File;
    int sent_bytes, readBytes;
    string messageTrain = "Please upload your local train CSV file.\n",
            messageTest = "Please upload your local test CSV file.\n", complete = "Upload complete.\n";
    char buffer[4096] = " ";
    int expectedDataLen = sizeof(buffer);
    bool close = false;

    // Send messageTrain to the client.
    sent_bytes = send(data->getSock(), messageTrain.c_str(), messageTrain.length(), 0);
    // Check if the sending of the data succeeded.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
    bool firstTime = true;
    readBytes = recv(data->getSock(), buffer, expectedDataLen, 0);
    if (readBytes <= 0) {
        perror("error receiving from client");
    }

    if (buffer[0] != '*') { // valid train
        File = createFile("train.csv");
        // Get all the data.s
        while (!close) {
            if (!firstTime) {
                readBytes = recv(data->getSock(), buffer, expectedDataLen, 0);
                if (readBytes <= 0) {
                    perror("error receiving from client");
                }
            }
            firstTime = false;
            for (int i = 0; i < 4096; ++i) {
                if (buffer[i] != '&') {
                    File.put(buffer[i]);
                } else {
                    close = true;
                    break;
                }
            }

        }

        File.close();

        // Send "Upload complete" message to the client.
        sent_bytes = send(data->getSock(), complete.c_str(), complete.length(), 0);
        // Check if the sending of the data succeeded.
        if (sent_bytes < 0) {
            perror("error sending to client");
        }

        // Send messageTest to the client.
        sent_bytes = send(data->getSock(), messageTest.c_str(), messageTest.length(), 0);
        // Check if the sending of the data succeeded.
        if (sent_bytes < 0) {
            perror("error sending to client");
        }

        memset(buffer, '\000', 4096);
        close = false;

        readBytes = recv(data->getSock(), buffer, expectedDataLen, 0);
        if (readBytes <= 0) {
            perror("error receiving from client");
        }
        firstTime = true;
        if (buffer[0] != '*') { // valid train
            File = createFile("test.csv");
            // Get all the data.s
            while (!close) {
                if (!firstTime) {
                    readBytes = recv(data->getSock(), buffer, expectedDataLen, 0);
                    if (readBytes <= 0) {
                        perror("error receiving from client");
                    }
                }
                firstTime = false;
                for (int i = 0; i < 4096; ++i) {
                    if (buffer[i] != '&') {
                        File.put(buffer[i]);
                    } else {
                        close = true;
                        break;
                    }
                }
            }

            File.close();

            // Send "Upload complete" message to the client.
            sent_bytes = send(data->getSock(), complete.c_str(), complete.length(), 0);
            // Check if the sending of the data succeeded.
            if (sent_bytes < 0) {
                perror("error sending to client");
            }
            data->setIsTrain(true);
            data->setIsTest(true);
        }
    }
}


/* Destructor. */
UploadFile::~UploadFile() {}