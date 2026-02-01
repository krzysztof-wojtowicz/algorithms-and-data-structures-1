//
// Created by Krzysztof Wójtowicz on 01/02/2026.
//

#ifndef SORT_LISTS_H
#define SORT_LISTS_H

#include <utility>

namespace sorting {

class SortLists {
public:
    struct node {
        int v;
        node *next;
    };

    static std::pair<node*, node*> createList(int tab[], int n);
    static void bucket(node *&head, node *&tail);
    static void merge(node *&head, node *&tail);
    static void printList(node *head);

private:
    static int max(node *head);
    static void shiftToEnd(node* &head, node* &bhead, node* &btail);
    static void linkToEnd(node* &head, node* &tail, node* bhead, node* btail);
    static void mergeLists(node *head1, node *tail1, node *head2, node *tail2, node *&head, node *&tail);
    static void mergeR(node *&head, node *&tail, int elemCnt);
};

} // sorting

#endif //SORT_LISTS_H