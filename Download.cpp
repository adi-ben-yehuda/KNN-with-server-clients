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

    if (!data->getIsUpload()) {
        // Send message to the client.
        dio->write(mUpload);
    }

    if (!data->getIsClassify()) {
        // Send message to the client.
        dio->write(mClassify);
    }

    if (data->getIsUpload() && data->getIsClassify()) {
        // Copy key-value pair from Map to vector of pairs
        for (auto &it: data->getClassifications()) {
            results += (to_string(it.first) + "\t" + it.second + "\n");
        }

        // Send the data to the client.
        dio->write(results);

        dio->write("&");
    }
}

/* Destructor. */
Download::~Download() {}