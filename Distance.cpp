#include <vector>
#include <cmath>
#include "Distance.h"

#define P_OF_MINKOWSKI 2

/* The function gets two vectors and returns the distance between
   them according to the distance type. */
double getDistance(vector<double> p, vector<double> q, string distType) {
    if (distType == "AUC") {
        return euclideanDistance(p, q);
    } else if (distType == "MAN") {
        return taxicabGeometry(p, q);
    } else if (distType == "CHB") {
        return chebyshevDistance(p, q);
    } else if (distType == "CAN") {
        return canberraDistance(p, q);
    } else if (distType == "MIN") {
        return minkowskiDistance(p, q);
    }
    return -1;
}

/* The function gets distance and checks if it is valid. */
bool isDistanceValid(string distType) {
    if (distType == "AUC" || distType == "MAN" || distType == "CHB" || distType == "CAN" || distType == "MIN") {
        return true;
    }
    return false;
}

/* The function gets two vectors. Calculates the distance
    between the vector according to taxicab geometry algorithm.
    Returns the distance. */
double taxicabGeometry(vector<double> p, vector<double> q) {
    int i = 0;
    double sum = 0.0;

    for (; i < p.size(); i++) {
        sum += abs(p.at(i) - q.at(i));
    }

    return sum;
}

/* The function gets two vectors. Calculates the distance
    between the vector according to chebyshev distance algorithm.
    Returns the distance. */
double chebyshevDistance(vector<double> p, vector<double> q) {
    int i = 0;
    double max = 0.0, value = 0.0;

    for (; i < p.size(); i++) {
        value = abs(p.at(i) - q.at(i));
        if (max < value) {
            max = value;
        }
    }
    return max;
}

/* The function gets two vectors. Calculates the distance
    between the vector according to canberra distance algorithm.
    Returns the distance. */
double canberraDistance(vector<double> p, vector<double> q) {
    int i = 0;
    double sum = 0.0, difference = 0.0, totalSum = 0.0;

    for (; i < p.size(); i++) {
        difference = abs(p.at(i) - q.at(i));
        sum = abs(p.at(i)) + abs(q.at(i));
        if (sum != 0) {
            totalSum += difference / sum;
        }
    }

    return totalSum;
}

/* The function gets two vectors. Calculates the distance
    between the vector according to minkowski distance algorithm.
    Returns the distance. */
double minkowskiDistance(vector<double> p, vector<double> q) {
    int i = 0;
    double sum = 0.0, difference = 0.0;

    for (; i < p.size(); i++) {
        difference = abs(p.at(i) - q.at(i));
        sum += pow(difference, P_OF_MINKOWSKI);
    }

    return pow(sum, 1 / (double) P_OF_MINKOWSKI);
}

/* The function gets two vectors. Calculates the distance
    between the vector according to euclidean distance algorithm.
    Returns the distance. */
double euclideanDistance(vector<double> p, vector<double> q) {
    int i = 0;
    double sum = 0;

    for (; i < p.size(); i++) {
        sum += pow(p[i] - q[i], 2);
    }

    return sqrt(sum);
}
