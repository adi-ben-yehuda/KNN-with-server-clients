#include <fstream>
#include <vector>
#include <sstream>
#include "Classify.h"
#include "Data.h"
#include "File.h"
#include <netinet/in.h>
#include <bits/stdc++.h>

using namespace std;

Classify::Classify(Data *data) {
    description = "3. classify data";
    this->data = data;
}

string Classify::getDescription() {
    return description;
}

/* Comparator function to sort pairs according to second value. */
bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second;
}

/*  Function to sort the map according to value in a (key-value) pairs. */
void sort(map<string, int> &M) {
    // Declare vector of pairs
    vector <pair<string, int>> A;

    // Copy key-value pair from Map to vector of pairs
    for (auto &it: M) {
        A.push_back(it);
    }

    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);
}

/* The function runs on each element in the heap and return the most common type. */
string getCommonType(MaxHeap kHeap) {
    priority_queue <tuple<double, string>, vector<tuple<double, string>>, Comparator> temp = kHeap.getHeap();
    map<string, int> commonTypeMap;
    string type = "", commonTypeStr = "";

    while (!temp.empty()) {
        type = get<1>(temp.top());
        auto search = commonTypeMap.find(type);
        if (search != commonTypeMap.end()) {
            // Found. Therefore, increase the value by 1
            search->second += 1;
        } else {
            // Not Found therefore add another element to the map
            commonTypeMap.insert(std::pair<string, int>(type, 1));
        }

        temp.pop();
    }

    sort(commonTypeMap);
    auto it = commonTypeMap.begin();
    commonTypeStr = it->first;
    return commonTypeStr;
}

void Classify::execute() {
    MaxHeap heap;
    vector<double> vectorFromFile;
    string temp = "", value = "", complete = "classifying data complete\n", message = "please upload data\n";
    char delim = ',', r = '\r';
    double num = 0.0, numCheck = 0.0;
    int line = 0, sent_bytes = 0;
    ifstream testFile;

    if (data->getIsUpload()) {
        testFile.open("test.csv");
        // Read the Data from the test file as double Vector.
        while (getline(testFile, temp)) {
            line++;
            vectorFromFile.clear();
            stringstream ss(temp);
            // Read one row from the test file without the \r in the end.
            getline(ss, value, r);
            stringstream sType(value);
            // Read every column data of a row. check if valid, if yes add to vector.
            while (getline(sType, value, delim)) {
                stringstream ss2(value);
                /* Check if the input is numeric. */
                if (isNumeric(value)) {
                    num = stod(value);
                    vectorFromFile.push_back(num);
                } else if (ss2 >> numCheck && ss2.eof()) {
                    /* That is, the input is double or negative. */
                    vectorFromFile.push_back(numCheck);
                } else {
                    break;
                }
            }
            heap = getKNearestElements("train.csv", vectorFromFile, data->getMetric(), data->getK());
            if (!heap.getHeap().empty()) {
                string common = getCommonType(heap);
                data->addClassifications(pair<int, string>(line, common));
            }
        }
        // Send messageTrain to the client.
        sent_bytes = send(data->getSock(), complete.c_str(), complete.length(), 0);
        // Check if the sending of the data succeeded.
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
        data->setIsClassify(true);
    } else {
        // Send messageTrain to the client.
        sent_bytes = send(data->getSock(), message.c_str(), message.length(), 0);
        // Check if the sending of the data succeeded.
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
    }
}

/* Destructor. */
Classify::~Classify() {}
