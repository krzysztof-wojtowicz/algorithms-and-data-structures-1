//
// Created by Krzysztof Wójtowicz on 30/01/2026.
//

#ifndef RST_H
#define RST_H

#define MAX_B 3

namespace dictionaries {

class RST {
public:
    struct node {
        int key;
        int b;          // which bit decides where to go in given node
        node *next[2];
    } *root;

    RST();
    node **search(int v);
    void insert(int v);
    void deleteV(int v);
    void printLevelOrder();

protected:
    static int bit(int x, int i);
    static void printLevelOrderR(node *root);
};

} // dictionaries

#endif //RST_H