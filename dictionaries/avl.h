//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#ifndef AVL_H
#define AVL_H

#include "bst.h"

namespace dictionaries {

class Avl : public Bst {

public:
    Avl();
    static void insert(int v, node *&root, bool &h);
    static void deleteV(int v, node *&root, bool &h);
    static void RR(node *&p);
    static void LL(node *&p);
    static void LR(node *&p);
    static void RL(node *&p);
    static void printLevelOrder(node *root);
};

} // dictionaries

#endif //AVL_H