//
// Created by Krzysztof Wójtowicz on 30/01/2026.
//

#include "hash.h"
#include <iostream>

namespace dictionaries {

// constructor
Hash::Hash() {
    for (int i = 0; i < MAX_HASH; i++)
        A[i] = FREE;
}

// hash function
int Hash::h(int v) {
    return v % MAX_HASH;
}

// search for value
int Hash::search(int v) {
    int k = h(v);

    if (A[k] == v)
        return k;
    else
        return -1;
}

// insert value if it doesn't exist
void Hash::insert(int v) {
    A[h(v)] = v;
}

// delete value
void Hash::deleteV(int v) {
    A[h(v)] = DEL;
}

// print hash array
void Hash::print() {
    std::cout<<"HASH [s="<<MAX_HASH<<"]: ";
    for (int i = 0; i < MAX_HASH; i++) {
        if (A[i] == FREE)
            std::cout<<"F ";
        else if (A[i] == DEL)
            std::cout<<"D ";
        else
            std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}

// chain hash constructor
ChainHash::ChainHash() {
    for (int i = 0; i < MAX_HASH; i++) {
         A[i] = nullptr;
    }
}

// search in chain hash
ChainHash::node* ChainHash::search(int v) {
    node *head = A[h(v)];

    // search for v element
    while (head) {
        if (head->v == v)
            return head;

        head = head->next;
    }

    return head;
}

// insert to chain hash
void ChainHash::insert(int v) {
    node *head = A[h(v)];

    // if list empty insert at the beginning
    if (!head) {
        node *p = new node;
        p->v = v;
        p->next = nullptr;
        A[h(v)] = p;
        return;
    }

    // check if v exists in the list
    node *p = search(v);
    if (p)
        return;

    // insert at the beginning
    p = new node;
    p->v = v;
    p->next = head;
    A[h(v)] = p;
}

// delete from chain hash
void ChainHash::deleteV(int v) {
    node **head = &A[h(v)];

    // empty list
    if (!(*head))
        return;

    // search for v
    while (*head && (*head)->v != v) {
        head = &(*head)->next;
    }

    // delete v
    if (*head && (*head)->v == v) {
        node *p = (*head);
        (*head) = p->next;
        delete p;
    }
}

// print chain hash
void ChainHash::print() {
    std::cout<<"CHAIN [s="<<MAX_HASH<<"]: ";
    for (int i = 0; i < MAX_HASH; i++) {
        if (A[i] == nullptr)
            std::cout<<"F ";
        else {
            node *head = A[i];

            while (head->next) {
                std::cout<<head->v<<"->";
                head = head->next;
            }
            std::cout<<head->v<<" ";
        }
    }
    std::cout<<std::endl;
}

// search in open hash
int OpenHash::search(int v) {
    int i = h(v);

    // search for v
    while (A[i] != FREE && A[i] != v) {
        i = (i + 1) % MAX_HASH;
    }

    // return index of v
    if (A[i] == v)
        return i;

    return -1;
}

// insert in open hash
void OpenHash::insert(int v) {
    int i = h(v);

    // search for empty slot
    while (A[i] != FREE && A[i] != DEL && A[i] != v) {
        i = (i + 1) % MAX_HASH;
    }

    // insert v
    if (A[i] != v)
        A[i] = v;
}

// delete from open hash
void OpenHash::deleteV(int v) {
    int i = h(v);

    // search for v
    while (A[i] != FREE && A[i] != v) {
        i = (i + 1) % MAX_HASH;
    }

    // delete v
    if (A[i] == v)
        A[i] = DEL;
}

// second hash function for double hash
int DoubleHash::h1(int v) {
    return (2 * (v % (MAX_HASH/2)) + 1) % MAX_HASH;
}

// search in double hash
int DoubleHash::search(int v) {
    int i = h(v);

    // search for v
    while (A[i] != FREE && A[i] != v) {
        i = (i + h1(v)) % MAX_HASH;
    }

    // return index of v
    if (A[i] == v)
        return i;

    return -1;
}

// insert to double hash
void DoubleHash::insert(int v) {
    int i = h(v);

    // search for empty slot
    while (A[i] != FREE && A[i] != DEL && A[i] != v) {
        i = (i + h1(v)) % MAX_HASH;
    }

    // insert v
    if (A[i] != v)
        A[i] = v;
}

// delete from double hash
void DoubleHash::deleteV(int v) {
    int i = h(v);

    // search for v
    while (A[i] != FREE && A[i] != v) {
        i = (i + h1(v)) % MAX_HASH;
    }

    // delete v
    if (A[i] == v)
        A[i] = DEL;
}

} // dictionaries