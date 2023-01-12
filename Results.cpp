//
// Created by shahar on 1/12/23.
//

#include "Results.h"

Results::Results() {
    description =  "4. display results";
}

// Setter for map.
void Results::setMap(map<int, string> mapClassify) {
    classifications = mapClassify;
}

void Results::execute(){}

string Results::getDescription() {
    return description;
}
