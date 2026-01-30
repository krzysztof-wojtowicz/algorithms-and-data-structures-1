//
// Created by Krzysztof Wójtowicz on 30/01/2026.
//

#ifndef HASH_H
#define HASH_H

#define MAX_HASH 10
#define FREE -1
#define DEL -5

namespace dictionaries {

class Hash {
public:
    int A[MAX_HASH];
    int h(int v);

public:
    Hash();
    int search(int v);
    void insert(int v);
    void deleteV(int v);
    void print();
};

class ChainHash : public Hash {
public:
    struct node {
        int v;
        node *next;
    };
    node* A[MAX_HASH];

    ChainHash();
    node* search(int v);
    void insert(int v);
    void deleteV(int v);
    void print();
};

class OpenHash : public Hash {
public:
    int search(int v);
    void insert(int v);
    void deleteV(int v);
};

class DoubleHash : public Hash {
public:
    int h1(int v);
    int search(int v);
    void insert(int v);
    void deleteV(int v);
};

} // dictionaries

#endif //HASH_H