//
// Created by Krzysztof Wójtowicz on 30/01/2026.
//

#include "array.h"
#include <iostream>

namespace dictionaries {

// parameterless constructor
Array::Array() {
    iLast = -1;
}

// constructor with starting array
Array::Array(int *tab, int n) {
    for (int i = 0; i < n; i++) {
        A[i] = tab[i];
    }

    iLast = n - 1;
}

// search in array dictionary, returns index of found element
int Array::search(int v) {
    // sentinel at the end
    A[iLast + 1] = v;
    int i = 0;

    while (A[i] != v)
        i++;

    // check if value is in the array or is a sentinel
    if (i <= iLast)
        return i;
    else
        return -1;
}

// insert to unordered array
void Array::insert(int v) {
    // check if value exists in array
    int k = search(v);
    if (k > 0)
        return;

    // insert at the end
    A[++iLast] = v;
}

// delete from array
void Array::deleteV(int v) {
    // search for index
    int k = search(v);

    // if value doesnt exist return
    if (k == -1)
        return;

    // shift elements to the left
    iLast--;
    for (int i = k; i <= iLast; i++)
        A[i] = A[i+1];
}

// print array elements
void Array::print() {
    std::cout<<"Array: ";
    for (int i = 0; i <= iLast; i++) {
        std::cout<<A[i]<<", ";
    }
    std::cout<<std::endl;
}

// constructor for ordered array (insert values in order)
OrderedArray::OrderedArray(int *tab, int n) {
    for (int i = 0; i < n; i++) {
        // insert first element
        if (i == 0) {
            A[i] = tab[i];
            continue;
        }

        // search for valid position for tab[i] element
        int j = 0;
        while (j < i && A[j] < tab[i])
            j++;

        // insert at the end
        if (j == i) {
            A[j] = tab[i];
            continue;
        }

        // if in the middle, move elements to the right
        for (int k = i-1; k >= j; k--)
            A[k+1] = A[k];
        A[j] = tab[i];
    }

    iLast = n - 1;
}

// search in ordered array dictionary
int OrderedArray::search(int v) {
    if (iLast < 0) return -1;

    // binary search in ordered array
    int l = 0;
    int r = iLast;
    int steps = 0;

    while (l <= r) {
        steps++;

        int k = (l + r) / 2;
        if (A[k] >= v)
            r = k - 1;
        if (A[k] <= v)
            l = k + 1;
    }

    if (l > r+1) {
        std::cout<<"("<<steps<<") ";
        return r+1;
    }
    else
        return -1;
}

// insert in ordered array dictionary
void OrderedArray::insert(int v) {
    // search for element if exist
    int k = search(v);
    if (k >= 0)
        return;

    // insert v to dict
    int i = iLast;
    iLast++;
    // move bigger elements to the right
    while (v < A[i] && i>= 0) {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = v;
}

// interpolative search in ordered array
int OrderedArray::qSearch(int v) {
    // check if array not empty
    if (iLast < 0)
        return -1;

    // starting range
    int l = 0;
    int r = iLast;
    int p;
    int steps = 0;

    // check if v is in range of ordered array
    if (v < A[l] || v > A[r])
        return -1;

    do {
        steps++;

        // calculate k and p
        int k = l + int(1.0 * (v - A[l]) / (A[r] - A[l]) * (r - l + 1));
        if (k > r)
            k = r;
        if (k < l)
            k = l;

        p = int(ceil(sqrt(r - l + 1.0)));

        // search subtrees
        if (A[k] < v) {
            while (k + p <= r && A[k+p] < v)
                k += p;
        }
        else {
            while (k > l && A[k] > v) {
                if (k - p < l)
                    k = l;
                else
                    k -= p;
            }
        }

        // update our search range (l and r)
        l = k;
        if (k + p < r)
            r = k + p;

        // check if v still in our range
        if (v < A[l] || (r < iLast && v > A[r]))
            return -1;
    } while (p > 1 && A[l] != v && r != l);

    // return index of found element
    if (A[l] == v) {
        std::cout<<"("<<steps<<") ";
        return l;
    }
    else
        return -1;
}

} // dictionaries