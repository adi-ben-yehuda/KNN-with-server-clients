#include "Download.h"

using namespace std;

Download::Download(Data *data) {
    description = "5. download results";
    this->data = data;
}

string Download::getDescription() {
    return description;
}

void Download::execute() {}

/* Destructor. */
Download::~Download() {}