#include "Download.h"

using namespace std;

Download::Download() {
    description = "5. download results";
}

string Download::getDescription() {
    return description;
}

void Download::setClassificationsMap(map<int, string> classifications) {
    this->classifications = classifications;
}

// Setter for clientSocket.
void Download::setSocket(int socket){
    sock = socket;
}

map<int, string> Download::getClassificationsMap() {
    return classifications;
}

void Download::execute() {}

/* Destructor. */
Download::~Download() {}