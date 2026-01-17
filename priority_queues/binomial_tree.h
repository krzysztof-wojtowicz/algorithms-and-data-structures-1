//
// Created by Krzysztof Wójtowicz on 30/11/2025.
//

#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

namespace priority_queues {

class BinomialTree {
protected:
    struct node {
        int val;
        int h;
        node *child;
        node *next, *prev;
        int mark;
    } *root;
    static node* newNode(int v);

private:
    void freeLevel(node *p);

public:
    BinomialTree();
    BinomialTree(int tab[], int n);
    ~BinomialTree();
    node* getRoot();
    void setRoot(node *r);
    static node* lastChild(node *root);
    static void printChildrenValues(node *root);
    static void printAll(node *root);
    static bool isMarkInRootCorrect(node *root);
    static node* merge(node *root1, node *root2);
};

} // priority_queues

#endif //BINOMIAL_TREE_H
