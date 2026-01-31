//
// Created by Krzysztof Wójtowicz on 31/01/2026.
//

#include "sbb_tree.h"

#include <iostream>
#include <queue>

namespace dictionaries {

// constructor
SBBTree::SBBTree() {
    root = nullptr;
}

// search in SBB Tree, same as in BST
SBBTree::node **SBBTree::search(int v) {
    node **p = &root;

    while ((*p) && (*p)->key != v) {
        p = &(*p)->next[(*p)->key > v];
    }

    return p;
}

// insert to SBB Tree
void SBBTree::insert(int v) {
    // empty tree, insert to root
    if (!root) {
        root = new node{v, {nullptr, nullptr}, {0, 0}};
        return;
    }

    // root, father and grandfather
    node **p = &root;
    node **f = nullptr;
    node **g = nullptr;

    // go down through the search path
    while (*p) {
        // check if p is a 4-node (both flags == 1)
        if ((*p)->flag[0] && (*p)->flag[1]) {
            // split 4-node (middle element goes up)
            split(g, f, p);
        }

        // search step
        g = f;
        f = p;
        // go right
        if (v < (*p)->key)
            p = &(*p)->next[0];
        // go left
        else if (v > (*p)->key)
            p = &(*p)->next[1];
        // v already exists
        else
            return;
    }

    // insert to leaf new horizontal node
    *p = new node{v, {nullptr, nullptr}, {0, 0}};
    int side = (v > (*f)->key);
    (*f)->flag[side] = 1;

    // update leaf if two horizontal connections in the same directions
    if (g != nullptr) {
        int father_side = ((*g)->next[1] == *f);
        if ((*g)->flag[father_side] == 1) {
            if (father_side == side) {
                rotate(g, 1 - father_side);
            } else {
                rotate(f, 1 - side);
                rotate(g, 1 - father_side);
            }
        }
    }
}

// rotation for SBB Tree, dir = 0 (left), dir = 1 (right)
void SBBTree::rotate(node **p, int dir) {
    // change direction of connection between nodes on the same page
    // and move child from the middle
    node *q = (*p)->next[1 - dir];
    (*p)->next[1 - dir] = q->next[dir];
    q->next[dir] = *p;

    // update flags
    (*p)->flag[1 - dir] = 0;
    q->flag[dir] = 1;

    // update root to point to middle element
    *p = q;
}

//
void SBBTree::split(node **g, node **f, node **p) {
    // change connections from horizonal to vertical
    (*p)->flag[0] = 0;
    (*p)->flag[1] = 0;

    // move middle element up
    if (f != nullptr) {
        // check if p is left or right child of father and update its flag
        int side = ((*f)->next[1] == *p);
        (*f)->flag[side] = 1;

        // check if we need to update father page (rotation)
        // happens if there are two horizontal connections pointing the same way
        if (g != nullptr) {
            int father_side = ((*g)->next[1] == *f);
            if ((*g)->flag[father_side] == 1) {

                // left-left or right-right rotation
                if (father_side == side) {
                    rotate(g, 1 - father_side);
                }
                // left-right or right-left rotation
                else {
                    rotate(f, 1 - side);
                    rotate(g, 1 - father_side);
                }
            }
        }
    }
}

// prints elements level order
void SBBTree::printLevelOrder(node *root) {
    if (!root) return;
    std::queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node *p = q.front();
        q.pop();
        std::cout<<p->key<<"[";
        if (p->next[0])
            std::cout<<p->flag[0];
        std::cout<<"&";
        if (p->next[1])
            std::cout<<p->flag[1];
        std::cout<<"] ";

        // push to queue
        if (p->next[0]) q.push(p->next[0]);
        if (p->next[1]) q.push(p->next[1]);
    }
}

// print for class object
void SBBTree::printLevelOrder() {
    printLevelOrder(root);
    std::cout<<std::endl;
}
} // dictionaries