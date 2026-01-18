//
// Created by Krzysztof Wójtowicz on 29/11/2025.
//

#include "heap.h"
#include <algorithm>
#include <cmath>
#include <iostream>

namespace priority_queues {

// constructor
Heap::Heap() : hl(0) {
    A[0] = -1;
}

// returns heap height
int Heap::heapHeight() const {
    return static_cast<int>(std::floor(std::log2(hl))) + 1;
}

// down heap -> for given element i we swap it with bigger child
// than do the same for the child index etc...
void Heap::downHeap(int i) {
    for(;;) {
        int left = 2*i;
        int right = left + 1;
        // check if element has children
        if (left > hl)
            break;

        // get index of biggest child
        int iMax = left;
        if (right <= hl && A[right] > A[left])
            iMax = right;

        // swap nodes if value is bigger than node
        if (A[i] < A[iMax]) {
            std::swap(A[i],A[iMax]);
            i = iMax;
        }
        else {
            break;
        }
    }
}

// up heap -> similar to down heap, but works up the tree
void Heap::upHeap(int i) {
    for(;;) {
        int parent = i/2;
        // check if parent exists
        if (parent == 0)
            break;

        // swap with parent if value bigger
        if (A[i] > A[parent]) {
            std::swap(A[i], A[parent]);
            i = parent;
        }
        else {
            break;
        }
    }
}

// inserts value at the end of heap and then does the upHeap
void Heap::insert(int v) {
    hl++;
    A[hl] = v;

    upHeap(hl);
}

// deletes max value -> root, inserts last node in its place and does downHeap
int Heap::delMax() {
    int val = A[1];
    A[1] = A[hl];
    hl--;
    downHeap(1);
    return val;
}

// prints heap in console
void Heap::printHeap() const {
    int h = heapHeight();
    int w = (h-1)*4 + 3;

    std::cout<<"height: "<<h<<", hl: "<<hl<<std::endl;

    for (int k = 0; k < h; k++) {
        int prev = 1 << k;
        w = (w-1)/2;
        for (int i = 0; i < (1 << k) && prev + i <= hl; i++) {
            spaces(w);
            std::cout<<A[prev + i];
            spaces(w + 1);
        }
        std::cout<<std::endl;
    }
}

void Heap::spaces(int n) {
    for (int i = 0; i < n; i++) {
        std::cout<<" ";
    }
}

// prints heap array
void Heap::printTab() const {
    for (int i = 1; i <= hl; i++) {
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}

// builds heap from top using given array of elements
void Heap::buildHeapFromTop(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        insert(tab[i]); // insert uses up heap
    }
}

// builds heap from the bottom using given array of elements
void Heap::buildHeapFromBottom(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        A[i+1] = tab[i]; // we add all the elements
        hl++;
    }
    // use down heap on every parent in the tree
    // hl/2 always equals to the index of the last parent
    for (int i = hl/2; i > 0; i--) {
        downHeap(i);
    }
}

// return hl value
int Heap::getHl() {
    return hl;
}
} // priority_queues