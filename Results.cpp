#include "Results.h"
#include <netinet/in.h>

Results::Results(Data *data, DefaultIO * dio) {
    description = "4. display results";
    this->data = data;
    this->dio = dio;
}

string Results::getDescription() {
    return description;

}

void Results::execute() {
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

        results += "Done.\n";

        // Send message to the client.
        dio->write(results);

        // Send a sign for end of the sending to the client.
        dio->write("&");
    }
}

/* Destructor. */
Results::~Results() {}