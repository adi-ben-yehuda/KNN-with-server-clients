//
// Created by shahar on 1/12/23.
//

#include "UploadFile.h"
using namespace std;

UploadFile:: UploadFile() {
    pathTrain = "";
    pathTest = "";
    description = "1. upload an unclassified csv data file";
}

// Setter for pathTrain.
void UploadFile::setTrain(string train){
    pathTrain = train;
}

// Setter for pathTest.
void UploadFile::setTest(string test){
    pathTest = test;
}

// Getter for pathTrain.
string UploadFile::getTrain() {
    return pathTrain;
}

// Getter for pathTest.
string UploadFile::getTest() {
    return pathTest;
}

void UploadFile::execute(){}