//
// Created by adi on 1/16/23.
//

#include "Data.h"

Data::Data() {
    this->k = 5;
    this->metric = "AUC";
    this->isTest = false;
    this->isTrain = false;
    this->isClassify = false;
    this->sock = 0;
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

int Data::getSock() {
    return sock;
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

void Data::setSock(int sock) {
    this->sock = sock;
}