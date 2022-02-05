#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        //Implement the below 4 methods. Please note these methods are not from MPQ.h
        //BinaryHeap class does not inherit MPQ class 
        //Implement BinaryHeap insert operation
        //Also implement upheap and downheap operations (functions provided below) and call them from wherever necessary
        void insert(const T& data) {
            elements.push_back(data);
            this->size = this->size + 1;
            this->up_heap(this->size - 1);
        }
        // Return true if BinaryHeap is empty otherwise false
        bool is_empty() {return (elements.size() == 0) ? true : false;}
        // Return minimum element in the BinaryHeap
        T min() {
            if (this->is_empty()) {
                throw std::invalid_argument("Empty.");
            }
            return elements.at(0);
        }
        // Remove minimum element in the BinaryHeap and return it
        T remove_min() {
            if (this->is_empty()) {
                throw std::invalid_argument("Empty.");
            }
                T removedVal = elements[0];
                swap(0, this->size - 1);

                elements.pop_back();

                this->size = this->size - 1;
                this->down_heap(0);
                return removedVal;
        }
    private:
        //
        std::vector<T> elements;
        int size = 0;
        //Implement down heap operation
        void down_heap(int i);
        //Implement up heap operation
        void up_heap(int i);

        //Pre-implemented helper functions
        //swaps two elements at positions a and b
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        //Binary tree (Complete Binary tree) can be represented in vector form and hence, stored in a vector. 
        //Returns the right child index of current index
        int right_child(int i) {return 2*i + 2;}
        //Returns the left child index of current index
        int left_child(int i) {return 2*i + 1;}
        //Returns the parent index of current index
        int parent(int i) {return floor((i-1)/2);}
        //Checks if current index is an internal node
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        //Checks if current index is a leaf
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i) {
    if (elements[i] < elements[parent(i)]) {
        swap(i, parent(i));
    }
    if (0 < parent(i)) {
        up_heap(parent(i));
    }
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i) {
    int child = 0;
    T key = elements[i];
    for (; 2 * i + 1 < size; i = child) {
        child = 2 * i + 1;
        if (child != size-1 && elements[child + 1] < elements[child]) {
            child++;
        }
        if (elements[child] < key) {
            elements[i] = elements[child];
        } else {
            break;
        }
    }
    elements[i] = key;
}
#endif