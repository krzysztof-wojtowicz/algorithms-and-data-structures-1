//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#include "splay_tree.h"
#include <iostream>
#include <queue>

namespace dictionaries {

// constructor
SplayTree::SplayTree() {
    root = nullptr;
}

// search in splay tree using splay function
SplayTree::node *SplayTree::search(int v) {
    // empty tree
    if (!root)
        return nullptr;

    splay(v, root);

    // value closest to v in root
    if (root->key == v)
        return root;
    else
        return nullptr;
}

// inert to splay tree using splay function
void SplayTree::insert(int v) {
    // empty tree
    if (!root) {
        root = new node;
        root->key = v;
        root->left = root->right = nullptr;
        return;
    }

    // splay the value closest to v to the root
    splay (v, root);

    // if v value exists return
    if (root->key == v)
        return;

    // create new node
    node *p = new node;
    p->key = v;

    // connect root to the p node
    if (root->key < v) {
        p->left = root;
        p->right = root->right;
        root->right = nullptr;
    }
    else if (root->key > v) {
        p->right = root;
        p->left = root->left;
        root->left = nullptr;
    }

    // p is the new root
    root = p;
}

// delete from splay tree
void SplayTree::deleteV(int v) {
    // empty tree
    if (!root)
        return;

    // move value closest to v to the root
    splay(v, root);

    // check if v exists
    if (root->key != v)
        return;

    node *p = root;

    // disconnect root with v key from the tree
    if (!root->left) {
        root = root->right;
    }
    else {
        splay(v, root->left);
        root->left->right = root->right;
        root = root->left;
    }

    delete p;
}

// single left rotation for splay function
void SplayTree::LZig(node *&p) {
    node *x = p->left;

    p->left = x->right;
    x->right = p;
    p = x;
}

// double left-left rotation for splay function
void SplayTree::LZigZig(node *&p) {
    LZig(p);
    LZig(p);
}

// double left-right rotation for splay function
void SplayTree::LZigZag(node *&p) {
    RZig(p->left);
    LZig(p);
}

// single right rotation for splay function
void SplayTree::RZig(node *&p) {
    node *x = p->right;

    p->right = x->left;
    x->left = p;
    p = x;
}

// double right-right rotation for splay function
void SplayTree::RZigZig(node *&p) {
    RZig(p);
    RZig(p);
}

// double right-left rotation for splay function
void SplayTree::RZigZag(node *&p) {
    LZig(p->right);
    RZig(p);
}

// splay function moves value closest to the v to the root
// uses rotation to keep the tree balanced
void SplayTree::splay(int v, node *&root) {
    // check root
    if (!root)
        return;

    // we look for the v key
    // we go two levels down and perform rotation if necessary

    // go left x1
    if (v < root->key) {
        // if left child exists
        if (root->left) {
            // go left-left
            if (v < root->left->key) {
                // if left-left grandchild exists
                if (root->left->left) {
                    // perform splay recursively
                    splay(v, root->left->left);
                    // we went left two times so LZigZig rotation
                    LZigZig(root);
                }
                else {
                    // we cant go left two times so LZig rotation only
                    LZig(root);
                }
            }
            // go left-right
            else if (v > root->left->key) {
                // if left-right grandchild exists
                if (root->left->right) {
                    // perform splay recursively
                    splay(v, root->left->right);
                    // we went left-right so LZigZag rotation
                    LZigZag(root);
                }
                else {
                    // we cant go left-right so LZig rotation only
                    LZig(root);
                }
            }
            // we can only go left once
            else {
                LZig(root);
            }
        }
    }

    // go right x1
    else if (v > root->key) {
        // check if right child exists
        if (root->right) {
            // go right-right
            if (v > root->right->key) {
                // if right-right grandchild exists
                if (root->right->right) {
                    // perform splay recursively
                    splay(v, root->right->right);
                    // we went right-right so RZigZig rotation
                    RZigZig(root);
                }
                else {
                    // we cant go right two times so RZig rotation
                    RZig(root);
                }
            }
            // go right-left
            else if (v < root->right->key) {
                // if right-left grandchild exists
                if (root->right->left) {
                    // perform splay recursively
                    splay(v, root->right->left);
                    // we went right-left so RZigZag rotation
                    RZigZag(root);
                }
                else {
                    // we cant go right-left so only RZig
                    RZig(root);
                }
            }
            // we can only go right once
            else {
                RZig(root);
            }
        }
    }
}

// prints elements level order
void SplayTree::printLevelOrderR(node *root) {
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

// print level order method for class object
void SplayTree::printLevelOrder() {
    printLevelOrderR(root);
    std::cout<<std::endl;
}

} // dictionaries