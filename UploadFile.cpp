#include "UploadFile.h"
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
    string messageTrain = "Please upload your local train CSV file.\n",
            messageTest = "Please upload your local test CSV file.\n", complete = "Upload complete.\n", content = "";
    char buffer[4096] = "\000";
    bool close = false;
    bool firstTime = true;
    string fileNameTrain = "train" + to_string(data->getSocket()) + ".csv";
    string fileNameTest = "test" + to_string(data->getSocket()) + ".csv";

    dio->write(messageTrain);

    content = dio->read();
    // copying the contents of the string to char array
    strcpy(buffer, content.c_str());

    if (buffer[0] != '*') { // valid train
        ofstream File(fileNameTrain);
        if (File) {
            // Get all the data.s
            while (!close) {
                if (!firstTime) {
                    memset(buffer, '\000', 4096);
                    content = dio->read();
                    // copying the contents of the string to char array
                    strcpy(buffer, content.c_str());
                }
                firstTime = false;
                for (int i = 0; i < 4096; ++i) {
                    if (buffer[i] == '&') { // End of data
                        close = true;
                        break;
                    } else if (buffer[i] == '\000') {
                        break;
                    } else {
                        File.put(buffer[i]);
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
                ofstream File2(fileNameTest);
                if (File2) {
                    // Get all the data.s
                    while (!close) {
                        if (!firstTime) {
                            memset(buffer, '\000', 4096);
                            content = dio->read();
                            // copying the contents of the string to char array
                            strcpy(buffer, content.c_str());
                        }
                        firstTime = false;
                        for (int i = 0; i < 4096; ++i) {
                            if (buffer[i] == '&') { // End of data
                                close = true;
                                break;
                            } else if (buffer[i] == '\000') {
                                break;
                            } else {
                                File2.put(buffer[i]);
                            }
                        }
                    }

                    File2.close();

                    // Send "Upload complete" message to the client.
                    dio->write(complete);

                    data->setIsTrain(true);
                    data->setIsTest(true);
                }
            }
        }
    }
}

/* Destructor. */
UploadFile::~UploadFile() {
    delete data;
    delete dio;
}