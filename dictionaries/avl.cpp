//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#include "avl.h"
#include <queue>
#include <iostream>

namespace dictionaries {

// constructor
Avl::Avl() {
    root = nullptr;
}

// inserts new element, does rotations if necessary and updates bl
void Avl::insert(int v, node *&root, bool &h) {
    node *ptr;

    // root/leaf doesnt exist
    if (!root) {
        root = new node;
        root->key = v;
        root->left = root->right = nullptr;
        root->bl = 0;
        h = true;
        return;
    }

    // left subtree
    if (v < root->key) {
        insert(v, root->left, h);
        if (h) {
            switch (root->bl) {
                case 1:
                    ptr = root->left;
                    if (ptr->bl == 1 || ptr->bl == 0)
                        LL(root);
                    else
                        LR(root);
                    h = false;
                    break;
                case 0:
                    root->bl = 1;
                    break;
                case -1:
                    root->bl = 0;
                    h = false;
                    break;
            }
        }
        return;
    }

    // right subtree
    if (v > root->key) {
        insert(v, root->right, h);
        if (h) {
            switch (root->bl) {
                case 1:
                    root->bl = 0;
                    h = false;
                    break;
                case 0:
                    root->bl = -1;
                    break;
                case -1:
                    ptr = root->right;
                    if (ptr->bl == -1 || ptr->bl == 0)
                        RR(root);
                    else
                        RL(root);
                    h = false;
                    break;
            }
        }
        return;
    }
}

// deletes element v
void Avl::deleteV(int v, node *&root, bool &h) {
    node *ptr;

    if (!root) {
        h = false;
        return;
    }

    if (v < root->key) {
        deleteV(v, root->left, h);
        if (h) {
            switch (root->bl) {
                case 1:
                    root->bl = 0;
                    h = true;
                    break;
                case 0:
                    root->bl = -1;
                    h = false;
                    break;
                case -1:
                    ptr = root->right;
                    if (ptr->bl == -1 || ptr->bl == 0) {
                        if (ptr->bl == 0) h = false;
                        else h = true;
                        RR(root);
                    } else {
                        RL(root);
                        h = true;
                    }
                    break;
            }
        }
        return;
    }

    if (v > root->key) {
        deleteV(v, root->right, h);
        if (h) {
            switch (root->bl) {
                case -1:
                    root->bl = 0;
                    h = true;
                    break;
                case 0:
                    root->bl = 1;
                    h = false;
                    break;
                case 1:
                    ptr = root->left;
                    if (ptr->bl == 1 || ptr->bl == 0) {
                        if (ptr->bl == 0) h = false;
                        else h = true;
                        LL(root);
                    } else {
                        LR(root);
                        h = true;
                    }
                    break;
            }
        }
        return;
    }

    if (root->left && root->right) {
        node *replacer = root->left;
        while (replacer->right) {
            replacer = replacer->right;
        }

        root->key = replacer->key;
        deleteV(replacer->key, root->left, h);

        if (h) {
             switch (root->bl) {
                case 1:
                    root->bl = 0;
                    h = true;
                    break;
                case 0:
                    root->bl = -1;
                    h = false;
                    break;
                case -1:
                    ptr = root->right;
                    if (ptr->bl == -1 || ptr->bl == 0) {
                        if (ptr->bl == 0) h = false;
                        else h = true;
                        RR(root);
                    } else {
                        RL(root);
                        h = true;
                    }
                    break;
            }
        }
    } else {
        node *temp = root;
        if (root->left) {
            root = root->left;
        } else {
            root = root->right;
        }
        delete temp;
        h = true;
    }
}

// RR rotation
void Avl::RR(node *&p) {
    node *x = p->right;
    p->right = x->left;
    x->left = p;
    p->bl = x->bl == -1 ? 0 : -1;
    x->bl = x->bl == 0 ? 1 : 0;
    p = x;
}

// LL rotation
void Avl::LL(node *&p) {
    node *x = p->left;
    p->left = x->right;
    x->right = p;
    p->bl = x->bl == 1 ? 0 : 1;
    x->bl = x->bl == 0 ? -1 : 0;
    p = x;
}

// LR rotation
void Avl::LR(node *&p) {
    node *x = p->left;
    node *y = x->right;


    x->right = y->left;
    y->left = x;
    p->left = y->right;
    y->right = p;

    if (y->bl == 1) {
        p->bl = -1;
        x->bl = 0;
    } else if (y->bl == -1) {
        p->bl = 0;
        x->bl = 1;
    } else {
        p->bl = 0;
        x->bl = 0;
    }

    y->bl = 0;
    p = y;
}

// RL rotation
void Avl::RL(node *&p) {
    node *x = p->right;
    node *y = x->left;

    x->left = y->right;
    y->right = x;
    p->right = y->left;
    y->left = p;

    if (y->bl == -1) {
        p->bl = 1;
        x->bl = 0;
    } else if (y->bl == 1) {
        p->bl = 0;
        x->bl = -1;
    } else {
        p->bl = 0;
        x->bl = 0;
    }

    y->bl = 0;
    p = y;
}

// prints elements level order
void Avl::printLevelOrder(node *root) {
    if (!root) return;
    std::queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node *p = q.front();
        q.pop();
        std::cout<<p->key<<"["<<p->bl<<"] ";
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
}

} // dictionaries