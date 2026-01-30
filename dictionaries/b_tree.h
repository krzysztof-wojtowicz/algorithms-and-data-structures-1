//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#ifndef BTREE_H
#define BTREE_H

#define M 2

namespace dictionaries {

class BTree {

public:
    struct node {
        int key[2*M + 1]; // key[0] -> sentinel, 2*M keys
        node *next[2*M + 1]; // pointers to next pages
        int k; // number of keys on this page
    } *root;

    BTree();
    node *search(int v);
    void insert(int v);
    void deleteV(int v);
    void printLevelOrder();

private:
    static node *searchR(node *root, int v);
    void split(node *root, int i);
    void insertR(node *root, int v);
    static void printLevelOrderR(node *root);
    void deleteVR(node *root, int v);
    void removeFromLeaf(node *leaf, int idx);
    void removeFromNonLeaf(node *root, int idx);
    int getPred(node *root, int idx);
    int getSucc(node *root, int idx);
    void fill(node *root, int idx);
    void borrowFromPrev(node *root, int idx);
    void borrowFromNext(node *root, int idx);
    void merge(node *root, int idx);
};

} // dictionaries

#endif //BTREE_H