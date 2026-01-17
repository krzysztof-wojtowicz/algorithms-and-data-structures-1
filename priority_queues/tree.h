//
// Created by Krzysztof Wójtowicz on 29/11/2025.
//

#ifndef TREE_H
#define TREE_H

namespace priority_queues {

class Tree {
public:
    struct node {
        int val;
        node *left, *right;
        int npl;
    };

    static node *newNode(int v, node *left = nullptr, node *right = nullptr, int npl = 0);

protected:
    node *root;
    static void freePostOrder(node *p);
    static int height(node *p);

public:
    Tree();
    explicit Tree(int v);
    Tree(node* r);
    ~Tree();
    [[nodiscard]] node* getRoot() const;
    void setRoot(node *r);
    static void printPreOrder(node const *root);
    static void printInOrder(node const *root);
    static void printPostOrder(node const *root);
    static void printLIFO(node *root);
    static void printLevelOrder(node *root);
    void insert(int v);
    [[nodiscard]] int height() const;
};

} // priority_queues

#endif //TREE_H
