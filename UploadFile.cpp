#include "UploadFile.h"
#include <netinet/in.h>
#include <cstring>
#include "File.h"
#include "Data.h"

using namespace std;

UploadFile::UploadFile(Data *data, DefaultIO *dio) {
    description = "1. upload an unclassified csv data file";
    this->data = data;
    this->dio = dio;
}

string UploadFile::getDescription() {
    return description;
}

void UploadFile::execute() {
    ofstream File;
    string messageTrain = "Please upload your local train CSV file.\n",
            messageTest = "Please upload your local test CSV file.\n", complete = "Upload complete.\n", content = "";
    char buffer[4096] = " ";
    bool close = false;

    dio->write(messageTrain);

    bool firstTime = true;
    content = dio->read();
    // copying the contents of the string to char array
    strcpy(buffer, content.c_str());

    if (buffer[0] != '*') { // valid train
        File = createFile("train.csv");
        // Get all the data.s
        while (!close) {
            if (!firstTime) {
                content = dio->read();
                // copying the contents of the string to char array
                strcpy(buffer, content.c_str());
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
        dio->write(complete);

        // Send messageTest to the client.
        dio->write(messageTest);

        memset(buffer, '\000', 4096);
        close = false;

        content = dio->read();
        // copying the contents of the string to char array
        strcpy(buffer, content.c_str());
        firstTime = true;
        if (buffer[0] != '*') { // valid train
            File = createFile("test.csv");
            // Get all the data.s
            while (!close) {
                if (!firstTime) {
                    content = dio->read();
                    // copying the contents of the string to char array
                    strcpy(buffer, content.c_str());
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
            dio->write(complete);

            data->setIsTrain(true);
            data->setIsTest(true);
        }
    }
}


/* Destructor. */
UploadFile::~UploadFile() {
    delete data;
    delete dio;
}