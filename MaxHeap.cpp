#include "MaxHeap.h"
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>


using namespace std;

/* The function get the distance, type of vector and k.
    Add the distance and his type to the max heap in necessary. */
void MaxHeap::addToHeap(double distance, string type, int k) {
    //Create tuple of the distance and the type of the vector.
    tuple<double, string> element = make_tuple(distance, type);

    // Check if the size of the heap is smaller than k we add the tuple.
    if (heap.size() < k) {
        heap.push(element);
    }
        // Check if the maximum distance in the heap is bigger than the current distance.
    else if (get<0>(heap.top()) > distance) {
        // Remove the max distance and replace it with a new distance.
        heap.pop();
        heap.push(element);
    }
}


/* Return the heap.*/
priority_queue<tuple<double, string>, vector<tuple<double, string>>, Comparator> MaxHeap::getHeap() {
    return heap;
}

/* Destructor. */
MaxHeap::~MaxHeap() {}


