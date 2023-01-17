#include "Results.h"

Results::Results(Data *data) {
    description =  "4. display results";
    this->data = data;
}

void Results::execute(){}

string Results::getDescription() {
    return description;

}

/* Destructor. */
Results::~Results() {}