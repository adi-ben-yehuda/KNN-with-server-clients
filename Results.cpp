#include "Results.h"

Results::Results() {
    description =  "4. display results";
}

// Setter for map.
void Results::setMap(map<int, string> mapClassify) {
    classifications = mapClassify;
}

// Setter for clientSocket.
void Results::setSocket(int socket){
    sock = socket;
}

void Results::execute(){}

string Results::getDescription() {
    return description;
}

/* Destructor. */
Results::~Results() {}