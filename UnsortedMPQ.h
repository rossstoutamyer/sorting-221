#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

/**
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::vector
   // For remove_min() and min() just throw exception if the UnsortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
private:
   std::vector<T> mpqList;
   int minIndex;

public:
   // Remove minimum from MPQ and return it
    virtual T remove_min() {
       if (this->is_empty()) {
          throw std::invalid_argument("Empty.");
       }

       T minVal = this->min();
       int removedPosition = minIndex;
       
       T lastVal = mpqList.at(mpqList.size() - 1);
       mpqList.at(mpqList.size() - 1) = mpqList.at(removedPosition);
       mpqList.at(removedPosition) = lastVal; 
       mpqList.pop_back();

       return minVal;
    }
    // Get the minimum from MPQ
    virtual T min() {
       if (this->is_empty()) {
          throw std::invalid_argument("Empty.");
       }
       minIndex = 0;
       T minVal = mpqList.at(0);
       for (int i = 0; i < mpqList.size(); ++i) {
          if (mpqList.at(i) < minVal) {
             minVal = mpqList.at(i);
             minIndex = i;
          }
       }

       return minVal;
    }
    // Check if MPQ is empty
    virtual bool is_empty() {
       if (mpqList.size() == 0) {
          return true;
       }
       return false;
    }
    // Insert into MPQ
    virtual void insert(const T& data) {
       T insertVal = data;
      
       mpqList.push_back(insertVal);
    }
};

#endif