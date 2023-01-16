#ifndef ADVANCED_EX_4_DATA_H
#define ADVANCED_EX_4_DATA_H

#include <iostream>
#include <map>

using namespace std;

class Data {
public:
    static int k;
    static string metric;
    static string pathTrain;
    static string pathTest;
    static map<int, string> classifications; // key = line number. value = classification.
};


#endif //ADVANCED_EX_4_DATA_H
