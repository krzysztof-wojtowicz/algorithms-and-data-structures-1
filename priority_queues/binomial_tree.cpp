//
// Created by Krzysztof Wójtowicz on 30/11/2025.
//

#include "binomial_tree.h"
#include <iostream>

namespace priority_queues {

// parameterless constructor
BinomialTree::BinomialTree() : root(nullptr) {}

// construct tree with given values
// n has to be power of 2
BinomialTree::BinomialTree(int tab[], int n) {
    // check if element count is correct
    if (!(n > 0 && (n & (n - 1)) == 0)) {
        root = nullptr;
        return;
    }

    // build tree using merge
    node* A[n];
    // we create n tree with h = 0
    for (int i = 0; i < n; i++) {
        A[i] = newNode(tab[i]);
    }

    // we merge pairs of trees until we have only one big tree
    n = n/2;
    while(n >= 1) {
        for (int i = 0; i < n; i++) {
            A[i] = merge(A[2*i],A[2*i+1]);
        }
        n = n/2;
    }

    root = A[0];
}

// deconstruct
BinomialTree::~BinomialTree() {
    if (!root)
        return;

    freeLevel(root);
}

void BinomialTree::freeLevel(node *p) {
    while (p) {
        if (p->child) {
            freeLevel(p->child);
        }

        node *next = p->next;
        delete p;
        p = next;
    }
}

// create new node
BinomialTree::node *BinomialTree::newNode(int const v) {
    node *p = new node{v, 0, nullptr, nullptr, nullptr, 0};
    p->prev = p;
    return p;
}

// returns root
BinomialTree::node *BinomialTree::getRoot() {
    return root;
}

// sets root
void BinomialTree::setRoot(node *r) {
    root = r;
}

//returns last child if it exists
BinomialTree::node *BinomialTree::lastChild(node *root) {
    if (!root)
        return nullptr;

    if (!root->child)
        return nullptr;

    return root->child->prev;
}

// prints children values
void BinomialTree::printChildrenValues(node *root) {
    if (!root)
        return;

    node *p = root->child;

    while(p) {
        std::cout<<p->val<<" ";
        p = p->next;
    }
    std::cout<<std::endl;
}

// prints all values
void BinomialTree::printAll(node *root) {
    if (!root)
        return;

    std::cout<<root->val<<" ";
    node *p = root->child;

    while(p) {
        printAll(p);
        p = p->next;
    }
}

// checks if mark in root is correct
bool BinomialTree::isMarkInRootCorrect(node *root) {
    if (!root)
        return false;

    node *p = root->child;
    int cnt = 0;
    // we count number of children
    while(p) {
        cnt++;
        p = p->next;
    }

    // if height is the same as number of children then tree is correct and mark should be 0
    if (root->h == cnt && root->mark == 0)
        return true;
    // if there is one child missing, tree is broken and mark should be 1
    if (root->h == cnt + 1 && root->mark == 1)
        return true;

    // if more children are missing return false -> binomial tree can't be missing two or more children
    return false;
}

// merges two trees of the same height
BinomialTree::node *BinomialTree::merge(node *root1, node *root2) {
    if (!root1 || !root2)
        return nullptr;

    // we can't merge two trees with different height
    if (root1->h != root2->h)
        return nullptr;

    // we want bigger value in root1
    if (root1->val < root2->val)
        std::swap(root1, root2);

    // increase height
    root1->h++;

    // if root1 doesn't have child add root2 as child
    if (!root1->child)
        root1->child = root2;
    // if it has children then add at the end
    else {
        node *p = root1->child;

        // we add root2 at the end
        p->prev->next = root2;
        root2->prev = p->prev;
        p->prev = root2;
    }

    return root1;
}


} // priority_queues