#include "Classify.h"

using namespace std;

Classify::Classify() {
    description = "3. classify data";
}


// Setter for clientSocket.
void Classify::setSocket(int socket){
    sock = socket;
}

string Classify::getDescription() {
    return description;
}

void Classify::execute() {



}

/* Destructor. */
Classify::~Classify() {}
