//
// Created by Krzysztof Wójtowicz on 30/11/2025.
//

#include "binomial_queue.h"

namespace priority_queues {

// prints all values from queue
void BinomialQueue::printAll(node *head) {
    if (!head)
        return;

    node *p = head;
    // print every tree from binomial queue
    while(p) {
        BinomialTree::printAll(p);
        p = p->next;
    }
}

// merges two binomial queues
BinomialTree::node *BinomialQueue::merge(node *head1, node *head2) {
    return nullptr;
}

// extracts first tree and changes head
BinomialTree::node *BinomialQueue::extract(node *&head) {
    if (!head)
        return nullptr;

    node *p = head;
    node *last = head->prev;

    // change head to new head
    head = head->next;
    if (head) {
        head->prev = last;
    }

    // return old head
    p->prev = p;
    p->next = nullptr;
    return p;
}

// add new tree to the end
void BinomialQueue::addToEnd(node *tree) {
    // root is head under the hood
    if (!root) {
        root = tree; // head = tree;
        return;
    }

    // add tree to the end
    root->prev->next = tree;
    tree->prev = root->prev;
    root->prev = tree;
}


} // priority_queues