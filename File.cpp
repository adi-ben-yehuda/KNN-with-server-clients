#include "File.h"
#include "MaxHeap.h"
#include "Distance.h"
#include <iostream>
#include <vector>
#include <netinet/in.h>

using namespace std;

/* The function gets string of the user input and checks if it is numeric. */
bool isNumeric(string const &str) {
    auto it = str.begin();
    while (it != str.end() && isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

/* Check if the file exists in the folders. */
bool isFileExist(string fileName) {
    ifstream file;
    string path = fileName;
    file.open(path);
    if (file) {
        file.close();
        return true;
    }
    return false;
}

ofstream createFile(string fileName) {
    ofstream File(fileName);
    return File;
}

void sendDataFile(int sock, string path) {
    string temp = "", data = "";
    ifstream file;
    file.open(path);

    // Read the Data from the file as double Vector
    while (getline(file, temp)) {
        data += temp + "\n";
    }
    // Send the data that get from the console, to the server.
    int sent_bytes = send(sock, data.c_str(), data.length(), 0);
    if (sent_bytes < 0) {
        cout << "Sending failed" << endl;
    }
    sent_bytes = send(sock, "&", 1, 0);
    if (sent_bytes < 0) {
        cout << "Sending failed" << endl;
    }
    file.close();
}

/* The function gets file name, vector, distance type and k.
    Read every row from the file. If the row is valid, save it in a vector.
    Calculate the distance between each vector and the vector we get according to the distance type.
    Save the k smallest distances in a max heap and return it. */
MaxHeap getKNearestElements(string fileName, vector<double> p, string distType, int k) {
    double numCheck = 0.0;
    string value, temp = "", tempType = "", type = "", path = "";
    char delim = ',', r = '\r';
    int countErrors = 0;
    double num = 0.0, distance = 0.0;
    vector<double> vectorFromFile;
    MaxHeap heap;
    ifstream file;

    path = fileName;

    file.open(path);

    // Read the Data from the file as double Vector
    while (getline(file, temp)) {
        vectorFromFile.clear();
        countErrors = 0;
        stringstream ss(temp);

        // Read every column data of a row. check if valid, if yes add to vector.
        while (getline(ss, value, delim)) {
            stringstream ss2(value);
            /* Check if the input is numeric. */
            if (isNumeric(value)) {
                num = stod(value);
                vectorFromFile.push_back(num);
            } else if (ss2 >> numCheck && ss2.eof()) {
                /* That is, the input is double or negative. */
                vectorFromFile.push_back(numCheck);
            } else {
                countErrors++;
            }
            /* If the data in the vectors are not numeric or double.
                There will be one error because of the string in the end. */
            if (countErrors > 1) {
                return heap;
            }
        }

        // Check if the vectors are in the same size. If not return an error.
        if (vectorFromFile.size() != p.size()) {
            return heap;
        }

        // Calculate the distance between the vectors.
        distance = getDistance(p, vectorFromFile, distType);
        // Get the vector type from the file.
        tempType = value;
        stringstream sType(tempType);
        getline(sType, type, r);
        // Add the distance with his type to the max heap.
        heap.addToHeap(distance, type, k);
    }
    file.close();
    return heap;
}

