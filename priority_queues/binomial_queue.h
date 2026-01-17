//
// Created by Krzysztof Wójtowicz on 30/11/2025.
//

#ifndef BINOMIAL_QUEUE_H
#define BINOMIAL_QUEUE_H

#include "binomial_tree.h"

namespace priority_queues {

class BinomialQueue : public BinomialTree {

// in this implementation head is called root (it was easier to inherit it from BinomialTree)

public:
    static void printAll(node *head); // override and print all trees, not only the first one
    static node* merge(node *head1, node *head2); // override so merging of queues works
    static node *extract(node* &head); // extracts first tree from queue
    void addToEnd(node *tree);
};

} // priority_queues

#endif //BINOMIAL_QUEUE_H
