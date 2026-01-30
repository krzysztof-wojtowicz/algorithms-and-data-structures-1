//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

namespace dictionaries {

class SplayTree {
public:
    struct node {
        int key;
        node *left, *right;
    } *root;

    SplayTree();
    static void splay(int v, node *&root);
    void insert(int v);
    void deleteV(int v);
    node *search(int v);
    void printLevelOrder();

protected:
    static void LZig(node *&p);
    static void LZigZig(node *&p);
    static void LZigZag(node *&p);
    static void RZig(node *&p);
    static void RZigZig(node *&p);
    static void RZigZag(node *&p);
    static void printLevelOrderR(node *root);
};

} // dictionaries

#endif //SPLAY_TREE_H