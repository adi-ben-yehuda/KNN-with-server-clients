#include "Data.h"

Data::Data() {
    this->k = 5;
    this->metric = "AUC";
    this->isTest = false;
    this->isTrain = false;
    this->isClassify = false;
    map<int, string> classifications;
}

map<int, string> Data::getClassifications() {
    return classifications;
}

bool Data::getIsClassify() {
    return isClassify;
}

bool Data::getIsTest() {
    return isTest;
}

bool Data::getIsTrain() {
    return isTrain;
}

bool Data::getIsUpload() {
    return (isTrain && isTest);
}

int Data::getK() {
    return k;
}

string Data::getMetric() {
    return metric;
}

void Data::addClassifications(pair<int, string> classify) {
    this->classifications.insert(classify);
}

void Data::setIsClassify(bool isClassify) {
    this->isClassify = isClassify;
}

void Data::setIsTest(bool isTest) {
    this->isTest = isTest;
}

void Data::setIsTrain(bool isTrain) {
    this->isTrain = isTrain;
}

void Data::setK(int k) {
    this->k = k;
}

void Data::setMetric(string metric) {
    this->metric = metric;
}

// Remove all the elements form the map.
void Data::removeClassifications() {
    this->classifications.clear();
}