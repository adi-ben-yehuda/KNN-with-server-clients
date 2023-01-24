#include <cstring>
#include "CLI.h"
#include "Classify.h"
#include "Setting.h"
#include "UploadFile.h"
#include "Results.h"
#include "Download.h"
#include <unistd.h>

CLI::CLI(int sock) {
    this->sock = sock;
    SocketIO *sio = new SocketIO(sock);
    this->dio = sio;
    this->data = new Data(sock);

    options[0] = new UploadFile(data, sio);
    options[1] = new Setting(data, sio);
    options[2] = new Classify(data, sio);
    options[3] = new Results(data, sio);
    options[4] = new Download(data, sio);
}

// The function send to the client the menu.
void CLI::sendMenu() {
    string desc;

    desc = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i = 0; i < 5; ++i) {
        desc += options[i]->getDescription() + "\n";
    }
    desc += "8. exit\n";
    this->dio->write(desc);
}

/* The function gets string of the user input and checks if it is numeric. */
bool CLI::optionIsNumber(string buffer) {
    char opt = buffer[0];
    if ((opt == '1' || opt == '2' || opt == '3' || opt == '4' || opt == '5') && buffer[1] == '\000') {
        return true;
    }
    return false;
}

void CLI::start() {
    int i = 0;
    string error = "invalid input\n", content = "";

    while (true) {
        // Send menu to the client.
        sendMenu();

        // Get data from the clientSocket to buffer.
        char buffer[4096] = " ";
        content = dio->read();
        // copying the contents of the string to char array
        strcpy(buffer, content.c_str());
        if (buffer[0] == '8' && buffer[1] == '\000') {
            // The user enters 8 in the console so close the connection with the client.
            close(this->sock);
            break;
        } else {
            if (optionIsNumber(buffer)) { // Check if the option is in the range 1-5.
                i = stoi(&buffer[0]) - 1;
                options[i]->execute();
            } else { // Print invalid input.
                this->dio->write(error);
            }
        }
    }
}

CLI::~CLI() {
    delete data;
    delete dio;
}