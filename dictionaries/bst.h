//
// Created by Krzysztof Wójtowicz on 16/01/2026.
//

#ifndef BST_H
#define BST_H

namespace dictionaries {

class BST {
public:
    struct node {
        int key;
        int bl;
        node *left, *right;
    };
    node *root;

    BST();
    [[nodiscard]] node* getRoot();
    node **search(int v);
    void insert(int v);
    void  deleteV(int v);
    void print();
    void printLevelOrder();

private:
    // recursive functions
    static void printR(node const *root);
    static void printLevelOrderR(node *root);
};

} // dictionaries

#endif //BST_H