//
// Created by Krzysztof Wójtowicz on 17/01/2026.
//

#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

namespace dictionaries {

class SplayTree {
public:
    struct node {
        int key;
        node *left, *right;
    } *root;

    SplayTree();
    static void splay(int v, node *&root);
    static void moveToRoot(int v, node *&root);
    void insert(int v);
    void deleteV(int v);
    node *search(int v);

protected:
    void LZig(node *&p);
    void LZigZig(node *&p);
    void LZigZag(node *&p);
    void RZig(node *&p);
    void RZigZig(node *&p);
    void RZigZag(node *&p);
};

} // dictionaries

#endif //SPLAY_TREE_H