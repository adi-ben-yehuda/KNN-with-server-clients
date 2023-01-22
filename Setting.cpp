#include "Setting.h"
#include <netinet/in.h>
#include <string.h>
#include "File.h"
#include "Distance.h"
#include "Data.h"

using namespace std;

Setting::Setting(Data *data, DefaultIO *dio) {
    description = "2. algorithm settings";
    this->data = data;
    this->dio = dio;

}

string Setting::getDescription() {
    return description;
}

void Setting::execute() {
    string message = "The current KNN parameters are: K = " + to_string(data->getK())
                     + ", distance metric = " + data->getMetric() + "\n", kInvalid = "invalid value for K\n",
            metricInvalid = "invalid value for metric\n", error = "invalid input\n", tempMetric = "", content = "";
    char buffer[4096] = " ", *token = NULL;
    int count = 0, tempK;
    bool kValid = true, mValid = true;

    // Send message to the client.
    dio->write(message);

    // Receive the settings from the user.
    content = dio->read();
    // copying the contents of the string to char array
    strcpy(buffer, content.c_str());

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
                    dio->write(kInvalid);
                    kValid = false;
                }
                count++;
            } else if (count == 1) {
                if (isDistanceValid(token)) {
                    tempMetric = token;
                } else {
                    // Send message to the client.
                    dio->write(metricInvalid);
                    mValid = false;
                }
                count++;
            } else if (count > 1) {
                // Send message to the client.
                dio->write(error);
                mValid = false;
                kValid = false;
            }
            token = strtok(NULL, " ");
        }

        if (count == 1) {
            // Send message to the client.
            dio->write(metricInvalid);
            mValid = false;
        }

        if (kValid && mValid) {
            data->setK(tempK);
            data->setMetric(tempMetric);
        }
    }
}

/* Destructor. */
Setting::~Setting() {
    delete data;
    delete dio;
}