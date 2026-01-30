//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#include "avl.h"
#include <queue>
#include <iostream>

namespace dictionaries {

// constructor
AVL::AVL() {
    root = nullptr;
}

// basic insert for class object
void AVL::insert(int v) {
    bool h;
    insertR(v, root, h);
}

// inserts new element, does rotations if necessary and updates bl
void AVL::insertR(int v, node *&root, bool &h) {
    node *ptr;

    // root/leaf doesnt exist, insert new node
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
        // recursively go down the search path
        insertR(v, root->left, h);

        // if height changed update bl
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
        // recursively go down the search path
        insertR(v, root->right, h);

        // if height changed update bl
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

// basic delete for class object
void AVL::deleteV(int v) {
    bool h;
    deleteVR(v, root, h);
}

// deletes element v
void AVL::deleteVR(int v, node *&root, bool &h) {
    node *ptr;

    // value doesnt exist in tree
    if (!root) {
        h = false;
        return;
    }

    // left subtree
    if (v < root->key) {
        // delete recursively for subtree
        deleteVR(v, root->left, h);

        // if height changed update bl
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

    // right subtree
    if (v > root->key) {
        // delete recursively for subtree
        deleteVR(v, root->right, h);

        // if height changed update bl
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

    // else v == root->key
    // delete similarly to BST trees
    if (root->left && root->right) {
        // find the biggest element in left subtree to replace with
        node *replacer = root->left;
        while (replacer->right) {
            replacer = replacer->right;
        }

        // replace key
        root->key = replacer->key;
        // delete replacer recursively from left subtree
        deleteVR(replacer->key, root->left, h);

        // if height changed update bl
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
    }
    // only one child or leaf
    else {
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

// RR rotation (single right)
void AVL::RR(node *&p) {
    node *x = p->right;
    p->right = x->left;
    x->left = p;
    p->bl = x->bl == -1 ? 0 : -1;
    x->bl = x->bl == 0 ? 1 : 0;
    p = x;
}

// LL rotation (single left)
void AVL::LL(node *&p) {
    node *x = p->left;
    p->left = x->right;
    x->right = p;
    p->bl = x->bl == 1 ? 0 : 1;
    x->bl = x->bl == 0 ? -1 : 0;
    p = x;
}

// LR rotation (double left)
void AVL::LR(node *&p) {
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

// RL rotation (double right)
void AVL::RL(node *&p) {
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

// prints level order for class object
void AVL::printLevelOrder() {
    printLevelOrderR(root);
    std::cout<<std::endl;
}

// prints elements level order
void AVL::printLevelOrderR(node *root) {
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