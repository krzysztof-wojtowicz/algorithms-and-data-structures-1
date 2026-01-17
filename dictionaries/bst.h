//
// Created by Krzysztof Wójtowicz on 16/01/2026.
//

#ifndef BST_H
#define BST_H

namespace dictionaries {

class Bst {
public:
    struct node {
        int key;
        int bl;
        node *left, *right;
    };
    node *root;

public:
    Bst();
    [[nodiscard]] node* getRoot();
    node **search(int v);
    void insert(int v);
    void  deleteV(int v);
    static void print(node const *root);
    static void printLevelOrder(node *root);
};

} // dictionaries

#endif //BST_H