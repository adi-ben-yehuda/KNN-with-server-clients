#include "Download.h"

using namespace std;

Download::Download() {
    description = "5. download results";
}

string Download::getDescription() {
    return description;
}

// Setter for clientSocket.
void Download::setSocket(int socket){
    sock = socket;
}

void Download::execute() {}

/* Destructor. */
Download::~Download() {}