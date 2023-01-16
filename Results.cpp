#include "Results.h"

Results::Results(Data data) {
    description =  "4. display results";
    this->data = data;
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