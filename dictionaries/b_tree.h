//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#ifndef TREE_H
#define TREE_H

#define M 256

namespace dictionaries {

class BTree {
public:
    struct node {
        int key[2*M + 1]; // key[0] -> sentinel
        node *next[2*M + 1];
        int k;
    } *root;

    BTree();
    static node *search(node *root, int v);

};

} // dictionaries

#endif //TREE_H