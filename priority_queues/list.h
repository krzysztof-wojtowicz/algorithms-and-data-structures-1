//
// Created by Krzysztof Wójtowicz on 29/11/2025.
//

#ifndef LIST_H
#define LIST_H

#define TAB_LIST_MAX 10
#define TAB_LIST_DEFAULT 0

namespace priority_queues {

// unordered list
class List {
protected:
    struct node {
        int val;
        node* next;
    } *head;

    static node* newNode(int v, node *next);

private:
    void printRevRecursive(node const *head) const;

public:
    List();
    ~List();
    void printAll() const;
    void printRev() const;
    void insertFront(int v);
    void insertEnd(int v) const;
    node* delFirst();
    node* delValue(int v);
    node* delMax();
    [[nodiscard]] node* search(int v) const;
};

// ordered list - from max to min
class OrderedList : public List {
public:
    void insertOrdered(int v);
    node* delMax(); // deletes first element
};

// tab list - without pointers
class TabList {
protected:
    struct node {
        int val;
        int next;
    } A[TAB_LIST_MAX];
    int head;

private:
    [[nodiscard]] int getFreeIndex() const;

public:
    TabList();
    void printAll() const;
    void printTab() const;
    void insertFront(int v);
};

} // priority_queues

#endif //LIST_H
