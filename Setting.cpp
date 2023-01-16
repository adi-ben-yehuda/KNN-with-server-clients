#include "Setting.h"
#include <netinet/in.h>
#include <string.h>
#include "File.h"
#include "Distance.h"

using namespace std;

Setting::Setting() {
    k = 5;
    metric = "AUC";
    description = "2. algorithm settings";
}

// Setter for K.
void Setting::setK(int x) {
    k = x;
}

// Getter for K.
int Setting::getK() {
    return k;
}

// Setter for metric.
void Setting::setMetric(string dist) {
    metric = dist;
}

// Setter for clientSocket.
void Setting::setSocket(int socket) {
    sock = socket;
}

// Getter for metric.
string Setting::getMetric() {
    return metric;
}

string Setting::getDescription() {
    return description;
}


void Setting::execute() {
    string message = "The current KNN parameters are: K = " + to_string(k) + ", distance metric = " + metric + "\n";
    string kInvalid = "invalid value for K\n", metricInvalid = "invalid value for metric\n", m = "invalid input\n";
    int sent_bytes = 0, readBytes = 0, read_bytes,  count = 0, tempK;
    char buffer[4096] = " ", *token = NULL;
    int expected_data_len = sizeof(buffer);
    string tempMetric;
    bool kValid = true, mValid = true;

    // Send message to the client.
    sent_bytes = send(sock, message.c_str(), message.length(), 0);
    // Check if the sending of the data succeeded.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }

    // Receive the settings from the user.
    read_bytes = recv(sock, buffer, expected_data_len, 0);
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
                    sent_bytes = send(sock, kInvalid.c_str(), kInvalid.length(), 0);
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
                    sent_bytes = send(sock, metricInvalid.c_str(), metricInvalid.length(), 0);
                    // Check if the sending of the data succeeded.
                    if (sent_bytes < 0) {
                        perror("error sending to client");
                    }
                    mValid = false;
                }
                count++;
            } else if (count > 1) {
                // Send message to the client.
                sent_bytes = send(sock, m.c_str(), m.length(), 0);
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
            k = tempK;
            metric = tempMetric;
        }
    }
}

/* Destructor. */
Setting::~Setting() {}