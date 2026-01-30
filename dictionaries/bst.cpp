//
// Created by Krzysztof Wójtowicz on 16/01/2026.
//

#include "bst.h"
#include <iostream>

namespace dictionaries {

// constructor
BST::BST() {
    root = nullptr;
    srand(time(NULL));
}

// return root
BST::node *BST::getRoot() {
    return root;
}

// searches for element v in BST tree
BST::node **BST::search(int v) {
    node **p = &root;

    while (*p && (*p)->key != v) {
        if (v > (*p)->key)
            p = &((*p)->right);
        else
            p = &((*p)->left);
    }

    return p;
}

// inserts element v to BST tree
void BST::insert(int v) {
    node **p = search(v);

    // if element already exists
    if (*p)
        return;

    *p = new node;
    (*p)->key = v;
    (*p)->left = nullptr;
    (*p)->right = nullptr;
}

// deletes element v from BST tree
void BST::deleteV(int v) {
    node *pv, **q, **p;
    p = search(v);

    if (*p) {
        // if both subtrees
        if ((*p)->left && (*p)->right) {
            // randomly choose left or right subtree
            int i = rand() % 2;

            q = i == 0 ? &((*p)->left) : &((*p)->right);
            // search for biggest element in the left subtree
            // or the smallest in the right subtree
            while ((i == 0 && (*q)->right) || (i == 1 && (*q)->left)) {
                q = i == 0 ? &((*q)->right) : &((*q)->left);
            }

            // place element in the place of deleted one
            pv = *q;
            (*p)->key = pv->key;
            // place left/right child in the place of moved element (if it has one)
            *q = i == 0 ? pv->left : pv->right;
        }
        // only one subtree or leaf
        else {
            pv = *p;
            *p = (*p)->left ? (*p)->left : (*p)->right;
        }
        delete pv;
    }
}

// prints BST tree in order
void BST::printR(node const *root) {
    if (!root) return;

    printR(root->left);
    std::cout<<root->key<<" ";
    printR(root->right);
}

// prints elements level order
void BST::printLevelOrderR(node *root) {
    if (!root) return;
    std::queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node *p = q.front();
        q.pop();
        std::cout<<p->key<<" ";
        // push to queue
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
}

// print method for class object
void BST::print() {
    printR(root);
    std::cout<<std::endl;
}

// print level order method for class object
void BST::printLevelOrder() {
    printLevelOrderR(root);
    std::cout<<std::endl;
}

} // dictionaries