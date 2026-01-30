//
// Created by Krzysztof Wójtowicz on 30/01/2026.
//

#ifndef ARRAY_H
#define ARRAY_H

#define MAX_SIZE 1000

namespace dictionaries {

class Array {
public:
    int A[MAX_SIZE] = { -1 };
    int iLast;

public:
    Array();
    Array(int* tab, int n);
    int search(int v);
    void insert(int v);
    void deleteV(int v);
    void print();
};

class OrderedArray : public Array {
public:
    OrderedArray(int* tab, int n);
    int search(int v);
    int qSearch(int v);
    void insert(int v);
};

} // dictionaries

#endif //ARRAY_H