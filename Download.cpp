#include "Download.h"
#include <netinet/in.h>

using namespace std;

Download::Download(Data *data, DefaultIO * dio) {
    description = "5. download results";
    this->data = data;
    this->dio = dio;
}

string Download::getDescription() {
    return description;
}

void Download::execute() {
    string results = "", mClassify = "please classify the data\n", mUpload = "please upload data\n";
    int sent_bytes = 0;

    if (!data->getIsUpload()) {
        // Send message to the client.
        sent_bytes = send(data->getSock(), mUpload.c_str(), mUpload.length(), 0);
        // Check if the sending of the data succeeded.
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
    }

    if (!data->getIsClassify()) {
        // Send message to the client.
        sent_bytes = send(data->getSock(), mClassify.c_str(), mClassify.length(), 0);
        // Check if the sending of the data succeeded.
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
    }

    if (data->getIsUpload() && data->getIsClassify()) {
        // Copy key-value pair from Map to vector of pairs
        for (auto &it: data->getClassifications()) {
            results += (to_string(it.first) + "\t" + it.second + "\n");
        }

        // Send the data to the client.
        sent_bytes = send(data->getSock(), results.c_str(), results.length(), 0);
        if (sent_bytes < 0) {
            cout << "Sending failed" << endl;
        }

        // Send a sign for end of the sending to the client.
        sent_bytes = send(data->getSock(), "&", 1, 0);
        if (sent_bytes < 0) {
            cout << "Sending failed" << endl;
        }
    }
}

/* Destructor. */
Download::~Download() {}