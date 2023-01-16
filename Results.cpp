#include "Results.h"

Results::Results() {
    description =  "4. display results";
}

void Results::execute(){}

string Results::getDescription() {
    return description;
}

// Setter for clientSocket.
void Results::setSocket(int socket){
    sock = socket;
}

/* Destructor. */
Results::~Results() {}