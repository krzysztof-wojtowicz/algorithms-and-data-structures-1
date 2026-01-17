//
// Created by Krzysztof Wójtowicz on 29/11/2025.
//

#include <iostream>
#include <iomanip>
#include "tree.h"

namespace priority_queues {

// creates new tree node
Tree::node *Tree::newNode(int const v, node *left, node *right, int npl) {
    auto *p = new node;
    p->val = v;
    p->left = left;
    p->right = right;
    p->npl = npl;

    return p;
}

// constructor for empty tree
Tree::Tree() : root(nullptr) {}

// constructor for tree with root
Tree::Tree(int const v) : root(newNode(v)) {}

// constructor for tree with given root
Tree::Tree(node *r) : root(r) {}

// deconstruct
Tree::~Tree() {
    freePostOrder(root);
}

void Tree::freePostOrder(node *p) {
    if (!p) return;

    freePostOrder(p->left);
    freePostOrder(p->right);

    delete p;
}

// return root
Tree::node *Tree::getRoot() const{
    return root;
}

// set root
void Tree::setRoot(node *r) {
    root = r;
}

// prints elements pre order (used in DFS)
void Tree::printPreOrder(node const *root) {
    if (!root) return;

    std::cout<<root->val<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// prints elements in order (used in BST)
void Tree::printInOrder(node const *root) {
    if (!root) return;

    printInOrder(root->left);
    std::cout<<root->val<<" ";
    printInOrder(root->right);
}

// prints elements post order (used in ONP - "odwrotna notacja polska")
void Tree::printPostOrder(node const *root) {
    if (!root) return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    std::cout<<root->val<<" ";
}

// prints elements LIFO
void Tree::printLIFO(node *root) {
    if (!root) return;
    std::stack<node*> s;
    s.push(root);

    while (!s.empty()) {
        node *p = s.top();
        s.pop();
        std::cout<<p->val<<" ";
        if (p->left) s.push(p->left);
        if (p->right) s.push(p->right);
    }
}

// prints elements level order
void Tree::printLevelOrder(node *root) {
    if (!root) return;
    std::queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node *p = q.front();
        q.pop();
        std::cout<<p->val<<" ";
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
}

// insert value v at the end of tree
void Tree::insert(int const v) {
    if (!root) {
        root = newNode(v);
        return;
    }

    std::queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node *p = q.front();
        q.pop();

        if(!p->left) {
            p->left = newNode(v);
            return;
        }
        if (!p->right) {
            p->right = newNode(v);
            return;
        }
        q.push(p->left);
        q.push(p->right);
    }
}

// calculate tree height
int Tree::height() const {
    return height(root);
}

int Tree::height(node *p) {
    if (!p) return 0;

    int leftH = height(p->left);
    int rightH = height(p->right);
    return 1 + std::max(leftH, rightH);
}


} // priority_queues