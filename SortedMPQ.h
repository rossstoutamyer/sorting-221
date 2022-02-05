#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::list
   // For remove_min() and min() throw exception if the SortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
private:
   std::list<T> mpqList;
   T* begin = mpqList.front();
   T* end = mpqList.back();

public:
   // Remove minimum from MPQ and return it
    virtual T remove_min() {
       if (this->is_empty()) {
          throw std::invalid_argument("Empty.");
       }
       begin = &mpqList.front();

       T* remover = begin;
       T removedVal = *remover;

       mpqList.pop_front();
       begin = &mpqList.front();

       return removedVal;
    }
    // Get the minimum from MPQ
    virtual T min() {
       begin = &mpqList.front();
       if (this->is_empty()) {
          throw std::invalid_argument("Empty.");
       }
       return *begin;
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
       begin = &mpqList.front();
       end = &mpqList.back();
       
       T insertVal = data;
      
       if (this->is_empty()) {
          mpqList.push_front(insertVal);
          begin = &insertVal;
          end = begin;
       } else {
          mpqList.push_front(insertVal);
          mpqList.sort();
          begin = &mpqList.front();
          end = &mpqList.back();
       }
    }
};

#endif