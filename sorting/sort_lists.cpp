//
// Created by Krzysztof Wójtowicz on 01/02/2026.
//

#include "sort_lists.h"

#include <iostream>

namespace sorting {

// create list from int tab[] of size n
std::pair<SortLists::node*, SortLists::node*> SortLists::createList(int tab[], int n) {
    std::pair<node*, node*> result = {nullptr, nullptr};

    if (n == 0)
        return result;

    node *head = new node{tab[0], nullptr};
    node *p = head;

    for (int i = 1; i < n; i++) {
        p->next = new node{tab[i], nullptr};

        p = p->next;
    }

    result = {head, p};
    return result;
}

// bucket sort for lists
void SortLists::bucket(node *&head, node *&tail) {
    std::cout<<"<<< BUCKET SORT >>>"<<std::endl;

    // find m (biggest element in the list)
    int m = max(head);

    // buckets
    node *bhead[m+1];
    node *btail[m+1];
    std::fill(bhead, bhead + m + 1, nullptr);
    std::fill(btail, btail + m + 1, nullptr);

    // add each list element to its bucket
    while (head) {
        int i = head->v;
        shiftToEnd(head, bhead[i], btail[i]);
        std::cout<<"ADD TO ["<<i<<"]: "; printList(bhead[i]);
    }

    head = tail = nullptr;
    for (int i = 0; i <= m; i++) {
        linkToEnd(head, tail, bhead[i], btail[i]);
    }
}

// merge sort for lists
void SortLists::merge(node *&head, node *&tail) {
    std::cout<<"<<< MERGE SORT >>>"<<std::endl;

    // count elements in orginal list
    int elemCnt = 0;
    node *p = head;
    while (p) {
        elemCnt++;
        p = p->next;
    }

    // call to recursive function
    mergeR(head, tail, elemCnt);
}

// recursive merge function call
void SortLists::mergeR(node *&head, node *&tail, int elemCnt) {
    // only one element in list -> return
    if (elemCnt <= 1) return;

    // get first list (first half)
    node *head1 = head;
    node *tail1 = head;

    for (int i = 1; i <= elemCnt/2 - 1; i++) {
        tail1 = tail1->next;
    }

    // get second list (second half)
    node *head2 = tail1->next;
    node *tail2 = tail;
    tail1->next = nullptr;

    // run merge sort recursively for both sub lists
    mergeR(head1, tail1, elemCnt/2);
    mergeR(head2, tail2, elemCnt - elemCnt/2);

    // merge two sorted lists
    head = nullptr;
    tail = nullptr;
    mergeLists(head1, tail1, head2, tail2, head, tail);

    // print merge step result
    std::cout<<"  MERGE STEP: "; printList(head);
}

// merge two lists together
void SortLists::mergeLists(node *head1, node *tail1, node *head2, node *tail2, node *&head, node *&tail) {
    // add elements from both lists in correct order
    while (head1 && head2) {
        if (head1->v < head2->v) {
            shiftToEnd(head1, head, tail);
        }
        else {
            shiftToEnd(head2, head, tail);
        }
    }

    // add remaining elements from each of the lists
    if (head1) {
        tail->next = head1;
        tail = tail1;
    }
    if (head2) {
        tail->next = head2;
        tail = tail2;
    }
}

// unlink element and move it to the end of bucket/merged list
void SortLists::shiftToEnd(node *&head, node *&bhead, node *&btail) {
    // empty bucket
    if (!bhead) {
        bhead = head;
        head = head->next;
        bhead->next = nullptr;
        btail = bhead;
    }
    // append to the end of list
    else {
        btail->next = head;
        head = head->next;
        btail = btail->next;
        btail->next = nullptr;
    }
}

// link bucket list to original head and tail
void SortLists::linkToEnd(node *&head, node *&tail, node *bhead, node *btail) {
    // empty bucket
    if (!bhead)
        return;

    // empty list
    if (!head) {
        head = bhead;
        tail = btail;
        return;
    }

    // append list to the end
    tail->next = bhead;
    tail = btail;
}

// print list
void SortLists::printList(node *head) {
    if (!head) return;

    node *p = head;

    while (p) {
        std::cout<<p->v<<" -> ";

        p = p->next;
    }
    std::cout<<std::endl;
}

// returns max element of list
int SortLists::max(node *head) {
    node *p = head;

    int max = -1;

    while (p) {
        if (max < p->v) max = p->v;

        p = p->next;
    }

    return max;
}

} // sorting