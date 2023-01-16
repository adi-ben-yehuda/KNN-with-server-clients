#ifndef ADVANCED_EX2_DISTANCE_H
#define ADVANCED_EX2_DISTANCE_H

#include <vector>
#include <iostream>

using namespace std;

double taxicabGeometry(vector<double> p, vector<double> q);

double chebyshevDistance(vector<double> p, vector<double> q);

double canberraDistance(vector<double> p, vector<double> q);

double minkowskiDistance(vector<double> p, vector<double> q);

double euclideanDistance(vector<double> p, vector<double> q);

double getDistance(vector<double> p, vector<double> q, string distType);
bool isDistanceValid(string distType);

#endif