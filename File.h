#ifndef ADVANCED_EX2_FILE_H
#define ADVANCED_EX2_FILE_H

#include <iostream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

bool isFileExist(string fileName);

MaxHeap getKNearestElements(string fileName, vector<double> p, string distType, int k);

bool isNumeric(string const &str);

#endif
