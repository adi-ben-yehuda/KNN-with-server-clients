#include "Setting.h"
#include <netinet/in.h>
#include <string.h>
#include "File.h"
#include "Distance.h"
#include "Data.h"

using namespace std;

Setting::Setting(Data *data) {
    description = "2. algorithm settings";
    this->data = data;

}

string Setting::getDescription() {
    return description;
}


void Setting::execute() {
    string message = "The current KNN parameters are: K = " + to_string(data->getK())
                     + ", distance metric = " + data->getMetric() + "\n", kInvalid = "invalid value for K\n",
            metricInvalid = "invalid value for metric\n", m = "invalid input\n", tempMetric;
    char buffer[4096] = " ", *token = NULL;
    int sent_bytes, read_bytes, count = 0, tempK;
    int expected_data_len = sizeof(buffer);
    bool kValid = true, mValid = true;

    // Send message to the client.
    sent_bytes = send(data->getSock(), message.c_str(), message.length(), 0);
    // Check if the sending of the data succeeded.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

    // Receive the settings from the user.
    read_bytes = recv(data->getSock(), buffer, expected_data_len, 0);
    if (read_bytes <= 0) { //  connection is closed
        perror("error receiving from client");
    }

    // The user wants to update the parameters.
    if (buffer[0] != '*') {
        // Separate the buffer by spaces.
        token = strtok(buffer, " ");
        while (token != NULL) {
            // Check if the token is numeric.
            if (count == 0) {
                if (isNumeric(token)) {
                    tempK = stoi(token);
                } else {
                    // Send message to the client.
                    sent_bytes = send(data->getSock(), kInvalid.c_str(), kInvalid.length(), 0);
                    // Check if the sending of the data succeeded.
                    if (sent_bytes < 0) {
                        perror("error sending to client");
                    }
                    kValid = false;
                }
                count++;
            } else if (count == 1) {
                if (isDistanceValid(token)) {
                    tempMetric = token;
                } else {
                    // Send message to the client.
                    sent_bytes = send(data->getSock(), metricInvalid.c_str(), metricInvalid.length(), 0);
                    // Check if the sending of the data succeeded.
                    if (sent_bytes < 0) {
                        perror("error sending to client");
                    }
                    mValid = false;
                }
                count++;
            } else if (count > 1) {
                // Send message to the client.
                sent_bytes = send(data->getSock(), m.c_str(), m.length(), 0);
                // Check if the sending of the data succeeded.
                if (sent_bytes < 0) {
                    perror("error sending to client");
                }
                mValid = false;
                kValid = false;
            }
            token = strtok(NULL, " ");
        }

        if (kValid && mValid) {
            data->setK(tempK);
            data->setMetric(tempMetric);
        }
    }
}

/* Destructor. */
Setting::~Setting() {}