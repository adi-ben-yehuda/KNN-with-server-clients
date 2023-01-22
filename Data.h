#ifndef ADVANCED_EX_4_DATA_H
#define ADVANCED_EX_4_DATA_H

#include <iostream>
#include <map>

using namespace std;

class Data {
private:
    int k;
    string metric;
    map<int, string> classifications; // key = line number. value = classification.
    bool isTrain;
    bool isTest;
    bool isClassify;


public:
    Data();

    int getK();

    string getMetric();

    map<int, string> getClassifications();

    bool getIsUpload();

    bool getIsTrain();

    bool getIsTest();

    bool getIsClassify();

    void setK(int K);

    void setMetric(string metric);

    void addClassifications(pair<int, string> classify);

    void removeClassifications();

    void setIsTrain(bool isTrain);

    void setIsTest(bool isTest);

    void setIsClassify(bool isClassify);

    ~Data() {}
};

#endif //ADVANCED_EX_4_DATA_H
