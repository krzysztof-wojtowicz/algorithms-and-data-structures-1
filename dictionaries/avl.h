//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#ifndef AVL_H
#define AVL_H

#include "bst.h"

namespace dictionaries {

class AVL : public BST {

public:
    AVL();
    void insert(int v);
    void deleteV(int v);
    void printLevelOrder();

protected:
    // rotations
    static void RR(node *&p);
    static void LL(node *&p);
    static void LR(node *&p);
    static void RL(node *&p);
    // recursive functions
    static void insertR(int v, node *&root, bool &h);
    static void deleteVR(int v, node *&root, bool &h);
    static void printLevelOrderR(node *root);
};

} // dictionaries

#endif //AVL_H