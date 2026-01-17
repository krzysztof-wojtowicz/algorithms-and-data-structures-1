//
// Created by Krzysztof Wójtowicz on 29/11/2025.
//

#include "beap.h"
#include<iostream>

namespace priority_queues {

// constructor
Beap::Beap() : bl(0) {
    A[0] = -1;
}

// down beap
void Beap::downBeap(int k) {
    for(;;) {
        auto [i,j] = k2ij(k);
        int left = k + i;
        int right = left + 1;

        // check if k has children
        if (left > bl)
            break;

        // get index of bigger child
        int kMax = left;
        if (right <= bl && A[right] > A[left])
            kMax = right;

        // swap with child
        if (A[kMax] > A[k]) {
            std::swap(A[kMax], A[k]);
            k = kMax;
        }
        else {
            break;
        }
    }
}

// up beap
void Beap::upBeap(int k) {
    for(;;) {
        auto [i,j] = k2ij(k);
        i--; // parent row
        int kMin;

        // check if k has parents
        if (i < 1)
            break;
        // check if k has only right parent
        else if (j - 1 < 1)
            kMin = ij2k(i,j);
        // check if k has only left parent
        else if (j > i)
            kMin = ij2k(i, j-1);
        // if both parents exist, get the one with smaller value
        else {
            int leftK = ij2k(i,j-1);
            int rightK = ij2k(i,j);

            kMin = leftK;
            if (A[rightK] < A[leftK])
                kMin = rightK;
        }

        // swap with parent
        if (A[k] > A[kMin]) {
            std::swap(A[k], A[kMin]);
            k = kMin;
        }
        else {
            break;
        }
    }
}

// returns [i,j] value calculated from k
// GEMINI
std::pair<int, int> Beap::k2ij(int const k) {
    double delta = std::sqrt(8.0 * k + 1.0);
    int i = static_cast<int>(std::ceil((delta - 1.0) / 2.0));

    int elements_above = (i * (i - 1)) / 2;

    int j = k - elements_above;

    return {i, j};
}

// returns k value calculated from i,j
// GEMINI
int Beap::ij2k(int const i, int const j) {
    int elements_above = (i * (i - 1)) / 2;

    return elements_above + j;
}

// inserts value at the of array and up beaps it
void Beap::insert(int const v) {
    bl++;
    A[bl] = v;

    upBeap(bl);
}

// deletes max value (root)
int Beap::delMax() {
    int temp = A[1];
    A[1] = A[bl];
    bl--;

    downBeap(1);
}

// searches for value v
int Beap::search(int const v) const {
    // get index of the last element in the last full row
    auto [i,j] = k2ij(bl);
    if (i!=j) {
        i--;
        j = i;
    }
    int k = ij2k(i,j);

    // search for v in beap
    // if v > A[k] go up-left
    // if v < A[k] go down-left or left
    // end if A[k] = v or j = 0 (v not found)
    while (A[k] != v && j != 0){
        // v > A[k] go up-left
        if (v > A[k]) {
            k -= i;
            i--;
            j--;
        }
        // v < A[k] and left child exists => go down-left
        else if (ij2k(i+1,j) <= bl) {
            k += i;
            i++;
        }
        // left child doesn't exist => go left
        else {
            j--;
            k--;
        }
    }

    if (A[k] == v)
        return k;
    return -1;
}

// prints beap
void Beap::printBeap() const {
    auto [h,_] = k2ij(bl);
    int k = 1;
    std::cout<<"Height: "<<h<<", bl: "<<bl<<std::endl;

    int w = h-1;

    for (int i = 1; i <= h; i++) {
        spaces(w);
        w--;
        for (int j = 0; j < i && k <= bl; j ++) {
            std::cout<<A[k]<<" ";
            k++;
        }
        std::cout<<std::endl;
    }
}

void Beap::spaces(int n) {
    for (int i = 0; i < n; i++) {
        std::cout<<" ";
    }
}


} // priority_queues