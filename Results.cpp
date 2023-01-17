#include "Results.h"
#include <netinet/in.h>

Results::Results(Data *data) {
    description =  "4. display results";
    this->data = data;
}

string Results::getDescription() {
    return description;

}

void Results::execute(){
    string results = "";
    int sent_bytes = 0;

    // Copy key-value pair from Map to vector of pairs
    for (auto &it: data->getClassifications()) {
        results += (to_string(it.first) + "\t" + it.second +"\n");
    }

    results += "Done.\n";

    // Send message to the client.
    sent_bytes = send(data->getSock(), results.c_str(), results.length(), 0);
    // Check if the sending of the data succeeded.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

    // Send a sign for end of the sending to the client.
    sent_bytes = send(data->getSock(), "&", 1, 0);
    if (sent_bytes < 0) {
        cout << "Sending failed" << endl;
    }

}

/* Destructor. */
Results::~Results() {}