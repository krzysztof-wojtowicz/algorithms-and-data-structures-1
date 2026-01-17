//
// Created by Krzysztof Wójtowicz on 29/11/2025.
//

#include <iostream>
#include <iomanip>
#include "list.h"

namespace priority_queues {

// constructor
List::List() : head(nullptr) {}

// deconstruct
List::~List() {
    auto p = head;

    while(p) {
        auto const next = p->next;
        delete p;
        p = next;
    }
}

// creates new node
List::node* List::newNode(int const v, node *next = nullptr) {
    auto const p = new node;
    p->val = v;
    p->next = next;
    return p;
}

// prints all list elements
void List::printAll() const {
    auto p = head;

    while(p) {
        std::cout<<p->val<<" -> ";
        p = p->next;
    }
    std::cout<<std::endl;
}

// prints all elements from back to front
void List::printRev() const {
    printRevRecursive(head);
    std::cout<<std::endl;
}

void List::printRevRecursive(node const *head) const{
    // stop condition
    if (!head) return;

    printRevRecursive(head->next);
    std::cout<<head->val<<" <- ";
}

// inserts new value at the front - O(1)
// always use this, much faster than insert at end
void List::insertFront(int const v) {
    head = newNode(v, head);
}

// inserts new value at the end - O(n)
void List::insertEnd(int const v) const  {
    auto p = head;

    while(p->next) {
        p = p->next;
    }

    p->next = newNode(v);
}

// deletes first element
List::node *List::delFirst() {
    if (!head) return nullptr;

    // change head
    node* first = head;
    head = head->next;

    // return deleted node
    first->next = nullptr;
    return first;
}

// delete first occurrence of value v
List::node *List::delValue(int const v) {
    if (!head) return nullptr;

    node* p = head;
    node* prev = nullptr;

    while (p) {
        // check if p->val equals to v and delete this node
        if (p->val == v) {
            if (prev)
                prev->next = p->next;
            // if prev == nullptr => change head
            else
                head = p->next;

            // return deleted node
            p->next = nullptr;
            return p;
        }

        prev = p;
        p = p->next;
    }

    // if v doesn't exist in list
    return nullptr;
}

// deletes max element
List::node *List::delMax() {
    if (!head) return nullptr;

    node* max = head;
    node* prevMax = nullptr;
    node* p = head->next;
    node* prev = head;
    // find max value
    while(p) {
        if (p->val > max->val) {
            prevMax = prev;
            max = p;
        }

        prev = p;
        p = p->next;
    }

    // delete max value from list
    if (prevMax)
        prevMax->next = max->next;
    else
        head = max->next;

    max->next = nullptr;
    return max;
}

// searches for node with value v
List::node *List::search(int const v) const {
    auto p = head;

    while (p && p->val != v) {
        p = p->next;
    }
    return p;
}

// inserts new element to ordered list
void OrderedList::insertOrdered(int const v) {
    node *pNew = newNode(v);
    node **p = &head;

    while(*p && (*p)->val > v) {
        p = &(*p)->next;
    }

    pNew->next = *p;
    *p = pNew;
}

// deletes max element from ordered list (first element)
List::node *OrderedList::delMax() {
    return delFirst();
}

// tab list constructor
TabList::TabList() : head(-1) {
    for (auto &i : A) {
        i = {TAB_LIST_DEFAULT, -1};
    }
}

// prints all tab list elements
void TabList::printAll() const {
    int p = head;

    while (p != -1) {
        std::cout<<A[p].val<<" -> ";
        p = A[p].next;
    }
    std::cout<<std::endl;
}

// print tab in list in tab structure
void TabList::printTab() const {
    std::cout<<"head: "<<head<<std::endl;
    std::cout<<std::setw(3)<<"i"<<std::setw(5)<<"val"<<std::setw(5)<<"next"<<std::endl;
    for (int i = 0; i < TAB_LIST_MAX; i++) {
        std::cout<<std::setw(3)<<i<<std::setw(5)<<A[i].val<<std::setw(5)<<A[i].next<<std::endl;
    }
}

// inserts new element at the front of tab list
void TabList::insertFront(int const v) {
    int i = getFreeIndex();
    if (i == -1) return;
    // insert at the beginning
    A[i].val = v;
    A[i].next = head;
    head = i;
}

// gets first free index for inserting new value
int TabList::getFreeIndex() const {
    for (int i = 0; i < TAB_LIST_MAX; i++) {
        if (A[i].val == TAB_LIST_DEFAULT)
            return i;
    }
    return -1;
}

} // priority_queues