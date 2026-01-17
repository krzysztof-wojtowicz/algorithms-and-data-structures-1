//
// Created by Krzysztof Wójtowicz on 30/11/2025.
//

#include "leftist_skew_heap.h"

namespace priority_queues {

// union connects two leftists heaps together
Tree::node *LeftistHeap::unionLeftistHeap(node *root1, node *root2) {
    // new root -> we take the bigger from root1 & root2
    node *p;
    // if one of the roots is nullptr, return the other one as new root
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    // set the bigger one, and do the union recursively on the right branch
    if (root1->val > root2->val) {
        p = root1;
        p->right = unionLeftistHeap(root1->right, root2);
    }
    else {
        p = root2;
        p->right = unionLeftistHeap(root2->right, root1);
    }

    // if right subtree is bigger, swap subtrees
    if (!p->left || (p->right && p->left->npl < p->right->npl)) {
        node *q = p->left;
        p->left = p->right;
        p->right = q;
    }

    // correct npl if needed
    if (!p->right)
        p->npl = 0;
    else
        p->npl = p->right->npl+1;

    return p;
}

// inserts new element to leftist heap
void LeftistHeap::insert(int const v) {
    node *p = newNode(v);

    root = unionLeftistHeap(root, p);
}

// deletes max element from leftist heap
Tree::node *LeftistHeap::delMax() {
    if (!root)
        return nullptr;
    node *p = root;
    root = unionLeftistHeap(root->right, root->left);

    p->right = nullptr;
    p->left = nullptr;
    return p;
}

// union connects two skew heaps together
Tree::node *SkewHeap::unionSkewHeap(node *root1, node *root2) {
    // new root -> we take the bigger from root1 & root2
    node *p;
    // if one of the roots is nullptr, return the other one as new root
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    // set the bigger one, and do the union recursively on the right branch
    if (root1->val > root2->val) {
        p = root1;
        p->right = unionSkewHeap(root1->right, root2);
    }
    else {
        p = root2;
        p->right = unionSkewHeap(root2->right, root1);
    }

    // in skew heap we always swap subtrees
    node *q = p->left;
    p->left = p->right;
    p->right = q;

    return p;
}

// inserts new element to skew heap
void SkewHeap::insert(int const v) {
    node *p = newNode(v);

    root = unionSkewHeap(root, p);
}

// deletes max element from skew heap
Tree::node *SkewHeap::delMax() {
    if (!root)
        return nullptr;
    node *p = root;
    root = unionSkewHeap(root->right, root->left);

    p->right = nullptr;
    p->left = nullptr;
    return p;
}

} // priority_queues