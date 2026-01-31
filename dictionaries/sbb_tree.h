//
// Created by Krzysztof Wójtowicz on 31/01/2026.
//

#ifndef SBB_TREE_H
#define SBB_TREE_H

namespace dictionaries {

class SBBTree {
public:
    struct node {
        int key;
        node *next[2];
        int flag[2];            // 1 if connection is horizontal
    } *root;

    SBBTree();
    node **search(int v);
    void insert(int v);
    void deleteV(int v);        // NOT IMPLEMENTED TODO
    void printLevelOrder();

private:
    void rotate(node **p, int dir);
    void split(node **g, node **f, node **p);
    static void printLevelOrder(node *root);
};

} // dictionaries

#endif SBB_TREE_H