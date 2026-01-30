//
// Created by Krzysztof Wójtowicz on 30/01/2026.
//

#include "rst.h"
#include <iostream>
#include <queue>

namespace dictionaries {

// bit function returns bit value for given position i
int RST::bit(int x, int i) {
    return (x>>i)&1;
}

// constructor
RST::RST() {
    root = nullptr;
}

// search in RST tree
RST::node **RST::search(int v) {
    node **p = &root;

    // bit position, start from the most significant bit
    int b = MAX_B;
    while ((*p) && (*p)->key != v) {
       p = &((*p)->next[bit(v, b--)]);
    }

    return p;
}

// insert in RST tree
void RST::insert(int v) {
    // look for v or its place
    node **p = search(v);

    // if v exists return
    if (*p)
        return;

    // create new node
    *p = new node;
    (*p)->key = v;
    (*p)->next[0] = (*p)->next[1] = nullptr;
}

// delete from RST tree
void RST::deleteV(int v) {
    // look for v
    node **p = search(v);

    // if v  doesn't exist
    if (!(*p))
        return;

    // check if p is a leaf
    if ((*p)->next[0] == nullptr && (*p)->next[1] == nullptr) {
        delete *p;
        return;
    }

    // get the leaf to insert
    node **leaf;

    // go left
    if ((*p)->next[0]) {
        leaf = &(*p)->next[0];
    }
    // go right
    else {
        leaf = &(*p)->next[1];
    }

    // find leaf
    while ((*leaf)->next[0] || (*leaf)->next[1]) {
        leaf = (*leaf)->next[0] ? &(*leaf)->next[0] : &(*leaf)->next[1];
    }

    // move key from leaf to p and delete leaf
    (*leaf)->next[0] = (*p)->next[0];
    (*leaf)->next[1] = (*p)->next[1];
    *p = *leaf;
    *leaf = nullptr;
}

// prints elements level order
void RST::printLevelOrderR(node *root) {
    if (!root) return;
    std::queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node *p = q.front();
        q.pop();
        std::cout<<p->key<<" [";

        for (int i = MAX_B; i >= 0; i--) {
            std::cout<<bit(p->key, i);
        }

        std::cout<<"]"<<std::endl;
        // push to queue
        if (p->next[0]) q.push(p->next[0]);
        if (p->next[1]) q.push(p->next[1]);
    }
}

// print level order method for class object
void RST::printLevelOrder() {
    printLevelOrderR(root);
    std::cout<<std::endl;
}

} // dictionaries