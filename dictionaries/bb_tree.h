//
// Created by Krzysztof Wójtowicz on 30/01/2026.
//

#ifndef BB_TREE_H
#define BB_TREE_H

#include "bst.h"

namespace dictionaries {

class BBTree {
public:
    struct node {
        int key;
        node *next[2];
        int flag;           // 1 if right connection is horizontal
    } *root;

    node **search(int v);   // NOT IMPLEMENTED TODO
    void insert(int v);     // NOT IMPLEMENTED TODO
    void deleteV(int v);    // NOT IMPLEMENTED TODO
};

} // dictionaries

#endif BB_TREE_H