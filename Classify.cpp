#include "Classify.h"

using namespace std;

Classify::Classify() {
    this->k = 0;
    this->metric = "";
    this->pathTrain = "";
    this->pathTest = "";

    description = "3. classify data";
}

// Setter for K.
void Classify::setK(int x) {
    k = x;
}

// Getter for K.
int Classify::getK() {
    return k;
}

// Setter for metric.
void Classify::setMetric(string dist) {
    metric = dist;
}

// Getter for metric.
string Classify::getMetric() {
    return metric;
}

// Setter for metric.
void Classify::setPathTrain(string path) {
    pathTrain = path;
}

// Getter for metric.
string Classify::getPathTrain() {
    return pathTrain;
}

// Setter for metric.
void Classify::setPathTest(string path) {
    pathTest = path;
}

// Getter for metric.
string Classify::getPathTest() {
    return pathTest;
}

void Classify::execute() {}