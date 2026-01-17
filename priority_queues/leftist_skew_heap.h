//
// Created by Krzysztof Wójtowicz on 30/11/2025.
//

#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "tree.h"

namespace priority_queues {

class LeftistHeap : public Tree {
public:
    static node* unionLeftistHeap(node *root1, node *root2);
    node* delMax();
    void insert(int v);
};

class SkewHeap : public Tree {
public:
    static node* unionSkewHeap(node *root1, node *root2);
    node* delMax();
    void insert(int v);
};

} // priority_queues

#endif //LEFTIST_HEAP_H
