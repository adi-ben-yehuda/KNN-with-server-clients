#ifndef ADVANCED_EX_4_DATA_H
#define ADVANCED_EX_4_DATA_H

#include <iostream>
#include <map>

using namespace std;

class Data {
public:
    int k;
    string metric;
    map<int, string> classifications; // key = line number. value = classification.
    bool isUpload;
    bool isTrain;
    bool isTest;
    bool isClassify;
};

#endif //ADVANCED_EX_4_DATA_H
