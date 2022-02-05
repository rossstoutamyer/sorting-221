#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
 */
template <typename T>
class BinaryHeapMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // It is enough if the 4 methods in  BinaryHeapMPQ calls the corresponding implemented methods in BinaryHeap.h.
   // To hold the elements use BinaryHeap (from BinaryHeap.h)
   // For remove_min() and min() throw exception if the BinaryHeapMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
private:
   BinaryHeap<T> BmpqList;

public:
   // Remove minimum from MPQ and return it
    virtual T remove_min() {
      return BmpqList.remove_min();
    }
    // Get the minimum from MPQ
    virtual T min() {
      return BmpqList.min();
    }
    // Check if MPQ is empty
    virtual bool is_empty() {
      return BmpqList.is_empty();
    }

    virtual void insert(const T& data) {
      return BmpqList.insert(data);
    }
};

#endif