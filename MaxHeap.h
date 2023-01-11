#ifndef ADVANCED_EX2_MAXHEAP_H
#define ADVANCED_EX2_MAXHEAP_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>
#include "Distance.h"
#include <queue>
#include <tuple>

using namespace std;

struct Comparator {
    bool operator()(tuple<double, string> &t1, tuple<double, string> &t2) {
        return std::get<0>(t1) < std::get<0>(t2);
    }
};

class MaxHeap {
private:
    priority_queue<tuple<double, string>, vector<tuple<double, string>>, Comparator> heap;

public:
    MaxHeap() {}

    void addToHeap(double distance, string type, int k);

    priority_queue<tuple<double, string>, vector<tuple<double, string>>, Comparator> getHeap();

    ~MaxHeap();
};


#endif