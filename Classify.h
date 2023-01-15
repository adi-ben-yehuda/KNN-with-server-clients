#ifndef ADVANCED_EX_4_CLASSIFY_H
#define ADVANCED_EX_4_CLASSIFY_H

#include <iostream>
#include <map>
#include "Command.h"

class Classify : public Command {
private:
    int k;
    string metric;
    string pathTrain;
    string pathTest;
    map<int, string> classifications; // key = line number. value = classification.

public:
    Classify();

    void setK(int x);
    int getK();
    void setMetric(string dist);
    string getMetric();
    void setPathTrain(string pathTrain);
    string getPathTrain();
    void setPathTest(string pathTest);
    string getPathTest();
    string getDescription();
    void execute();

    ~Classify();
};


#endif //ADVANCED_EX_4_CLASSIFY_H
