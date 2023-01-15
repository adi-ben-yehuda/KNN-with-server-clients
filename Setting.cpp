#include "Setting.h"

using namespace std;

Setting:: Setting() {
    k = 5;
    metric = "AUC";
    description =  "2. algorithm settings";
}

// Setter for K.
void Setting::setK(int x) {
    k = x;
}

// Getter for K.
int Setting::getK() {
    return k;
}

// Setter for metric.
void Setting::setMetric(string dist){
    metric = dist;
}

// Getter for metric.
string Setting::getMetric() {
    return metric;
}

string Setting::getDescription() {
    return description;
}


void Setting::execute(){}

/* Destructor. */
Setting::~Setting() {}