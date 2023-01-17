#include "Download.h"
#include <netinet/in.h>

using namespace std;

Download::Download(Data *data) {
    description = "5. download results";
    this->data = data;
}

string Download::getDescription() {
    return description;
}

void Download::execute() {
    string results = "";
    int sent_bytes = 0;

    // Copy key-value pair from Map to vector of pairs
    for (auto &it: data->getClassifications()) {
        results += (to_string(it.first) + "\t" + it.second +"\n");
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

/* Destructor. */
Download::~Download() {}