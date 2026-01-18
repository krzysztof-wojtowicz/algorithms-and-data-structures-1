//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#include "b_tree.h"

namespace dictionaries {

// constructor
BTree::BTree() {
    root = nullptr;
}

// searches for v in BTree
BTree::node *BTree::search(node *root, int v) {
    if (!root)
        return nullptr;

    // sentinel
    root->key[0] = -100000000;
    int i = root->k;

    while (root->key[i] > v)
        i--;

    if (root->key[i] == v)
        return root;

    return search(root->next[i],v);
}

} // dictionaries