#include "Classify.h"
#include "Data.h"

using namespace std;

Classify::Classify(Data data) {
    description = "3. classify data";
    this->data = data;
}

// Setter for clientSocket.
void Classify::setSocket(int socket){
    sock = socket;
}

string Classify::getDescription() {
    return description;
}

void Classify::execute() {
    data.isClassify = true;
}

/* Destructor. */
Classify::~Classify() {}
