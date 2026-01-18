#include <iostream>
#include <cstdlib>
#include <ctime>

/* PRIORITY QUEUES */
#include "dictionaries/bst.h"
#include "priority_queues/list.h"
#include "priority_queues/tree.h"
#include "priority_queues/heap.h"
#include "priority_queues/beap.h"
#include "priority_queues/leftist_skew_heap.h"
#include "priority_queues/binomial_tree.h"

/* DICTIONARIES */
#include "dictionaries/bst.h"
#include "dictionaries/avl.h"

/* SORTING ALGORITHMS*/
#include "sorting/sort.h"

using namespace priority_queues;
using namespace dictionaries;
using namespace sorting;

enum SortingAlgorithm {
    SELECTION,
    INSERTION,
    BUBBLE,
    MIX,
    COMB,
    HEAP,
    HEAP2,
    QUICK,
    QUICK2,
};

void sorting_usage(int tab[], int n, SortingAlgorithm algorithm = BUBBLE, bool isOutput = false);
void priority_queues_usage();
void dictionaries_usage();

int main() {
    /* SORTING ALGORITHMS */
    int A[] = {-100,5,2,3,1,0}; // A[0] => sentinel
    int n = 5; // without sentinel
    sorting_usage(A, n, QUICK2, true);

    return 0;
}

void sorting_usage(int tab[], int n, SortingAlgorithm algorithm, bool isOutput) {
    std::cout<<"BEFORE:"<<std::endl;
    Sort::printTab(tab, n);
    std::cout<<std::endl;

    switch (algorithm) {
        case SELECTION:
            Sort::selection(tab, n, isOutput);
            break;
        case INSERTION:
            Sort::insertion(tab, n, isOutput);
            break;
        case BUBBLE:
            Sort::bubble(tab, n, isOutput);
            break;
        case MIX:
            Sort::mix(tab, n, isOutput);
            break;
        case COMB:
            Sort::comb(tab, n, isOutput);
            break;
        case HEAP:
            Sort::heap(tab, n, isOutput);
            break;
        case HEAP2:
            Sort::heap2(tab, n, isOutput);
            break;
        case QUICK:
            Sort::quick(tab, n, isOutput);
            break;
        case QUICK2:
            Sort::quick2(tab, n, isOutput);
            break;
        default:
            Sort::bubble(tab, n, isOutput);
            break;
    }

    std::cout<<std::endl<<"AFTER:"<<std::endl;
    Sort::printTab(tab, n);
    std::cout<<std::endl;
}

void priority_queues_usage() {
    /* unordered list */
    // std::cout<<"Unordered list"<<std::endl;
    // List list1;
    //
    // list1.insertFront(2);
    // list1.insertEnd(15);
    // list1.insertFront(10);
    // list1.insertEnd(13);
    // // before deletion of max
    // list1.printAll();
    // // after deletion of max
    // list1.delMax();
    // list1.printAll();

    /* ordered list */
    // std::cout<<"Ordered list:"<<std::endl;
    // OrderedList list2;
    //
    // list2.insertOrdered(4);
    // list2.insertOrdered(10);
    // list2.insertOrdered(3);
    // list2.insertOrdered(5);
    // // before deletion of max
    // list2.printAll();
    // // after deletion of max
    // list2.delMax();
    // list2.printAll();
    // // prints elements from the back
    // list2.printRev();
    //
    // auto p = list2.search(3);
    // std::cout<<p->val;

    /* tab list */
    // TabList list3;
    // list3.insertFront(5);
    // list3.insertFront(2);
    // list3.insertFront(10);
    // list3.printAll();
    // list3.printTab();

    /* tree */
    // Tree tree1(1);
    // std::cout<<"--- Tree ---"<<std::endl;
    // tree1.insert(2);
    // tree1.insert(3);
    // tree1.insert(4);
    // tree1.insert(5);
    // std::cout<<"- pre order"<<std::endl;
    // Tree::printPreOrder(tree1.getRoot());
    // std::cout<<std::endl;
    // std::cout<<"- in order"<<std::endl;
    // Tree::printInOrder(tree1.getRoot());
    // std::cout<<std::endl;
    // std::cout<<"- post order"<<std::endl;
    // Tree::printPostOrder(tree1.getRoot());
    // std::cout<<std::endl;
    // std::cout<<"- LIFO"<<std::endl;
    // Tree::printLIFO(tree1.getRoot());
    // std::cout<<std::endl;
    // std::cout<<"- level order"<<std::endl;
    // Tree::printLevelOrder(tree1.getRoot());
    // std::cout<<std::endl;

    /* heap */
    // Heap heap1, heap2;
    // int n = 11;
    // int A[n];
    // srand(time(nullptr));
    // for (int i = 0; i < n; i++) {
    //     A[i] = 1 + rand() % 9;
    // }
    // heap1.buildHeapFromTop(A,n);
    // heap2.buildHeapFromBottom(A,n);
    // std::cout<<"Heap built from top:"<<std::endl;
    // heap1.printHeap();
    // std::cout<<"Heap built from bottom:"<<std::endl;
    // heap2.printHeap();
    //
    // std::cout<<"Before del:"<<std::endl;
    // heap1.printHeap();
    // std::cout<<"After del:"<<std::endl;
    // heap1.delMax();
    // heap1.printHeap();

    /* beap */
    // Beap beap1;
    //
    // srand(time(nullptr));
    // for (int i = 0; i < 15; i++) {
    //     beap1.insert(1 + rand() % 9);
    // }
    // std::cout<<"Beap after insert:"<<std::endl;
    // beap1.printBeap();
    // std::cout<<"After del:"<<std::endl;
    // beap1.delMax();
    // beap1.printBeap();
    // int found = beap1.search(5);
    // std::cout<<"Searched for 5, found it on: "<<found<<std::endl;

    /* leftist and skew heap */
    // LeftistHeap lheap1, lheap2, lheap3;
    // SkewHeap sheap1, sheap2, sheap3;
    // int A[] = {27,20,22,9,16,7,13,4};
    // int B[] = {24,18,23,12,6,1,2,12};
    // // build two leftist heaps
    // for (int i = 0; i < 8; i++) {
    //     lheap1.insert(A[i]);
    //     lheap2.insert(B[i]);
    //     sheap1.insert(A[i]);
    //     sheap2.insert(B[i]);
    // }
    // std::cout<<"L. heap 1:"<<std::endl;
    // Tree::printLevelOrder(lheap1.getRoot());
    // std::cout<<std::endl;
    // std::cout<<"L. heap 2:"<<std::endl;
    // Tree::printLevelOrder(lheap2.getRoot());
    // std::cout<<std::endl;
    //
    // std::cout<<"Union l. heap:"<<std::endl;
    // lheap3.setRoot(LeftistHeap::unionLeftistHeap(lheap1.getRoot(), lheap2.getRoot()));
    // lheap1.setRoot(nullptr);
    // lheap2.setRoot(nullptr);
    // Tree::printLevelOrder(lheap3.getRoot());
    // std::cout<<std::endl;
    // std::cout<<"S. heap 1:"<<std::endl;
    // Tree::printLevelOrder(sheap1.getRoot());
    // std::cout<<std::endl;
    // std::cout<<"S. heap 2:"<<std::endl;
    // Tree::printLevelOrder(sheap2.getRoot());
    // std::cout<<std::endl;
    //
    // std::cout<<"Union s. heap:"<<std::endl;
    // sheap3.setRoot(SkewHeap::unionSkewHeap(sheap1.getRoot(), sheap2.getRoot()));
    // sheap1.setRoot(nullptr);
    // sheap2.setRoot(nullptr);
    // Tree::printLevelOrder(sheap3.getRoot());
    // std::cout<<std::endl;

    /* binomial tree */
    // we want to create tree with h = 3, n = 8
    // int A[] = {3,4,1,8,7,9,2,3};
    // BinomialTree btree(A,8);
    //
    // std::cout<<"Children values:"<<std::endl;
    // BinomialTree::printChildrenValues(btree.getRoot());
    // std::cout<<"All values:"<<std::endl;
    // BinomialTree::printAll(btree.getRoot());

    /* binomial queue (not fully implemented) */
    // TODO
}

void dictionaries_usage() {
    /* BST tree */
    // Bst bst_tree = Bst();
    //
    // bst_tree.insert(10);
    // bst_tree.insert(15);
    // bst_tree.insert(8);
    // bst_tree.insert(12);
    // bst_tree.insert(18);
    // bst_tree.insert(5);
    // Bst::print(bst_tree.getRoot());
    //
    // Bst::node **val = bst_tree.search(12);
    // std::cout<<(*val)->key<<std::endl;
    //
    // Bst::node *deleted = bst_tree.deleteV(8);
    // delete(deleted);
    // Bst::print(bst_tree.getRoot());

    /* AVL tree*/
    // Avl avl_tree = Avl();
    // bool h;
    // int tab[] = {4,5,7,2,1,3,6};
    // for (int v : tab) {
    //     Avl::insert(v, avl_tree.root, h);
    //     std::cout<<std::endl;
    //     Avl::printLevelOrder(avl_tree.getRoot());
    // }
    //
    // int tab2[] = {4,8,5};
    // for (int v : tab2) {
    //     Avl::deleteV(v, avl_tree.root, h);
    //     std::cout<<std::endl;
    //     Avl::printLevelOrder(avl_tree.getRoot());
    // }

    /* B Tree*/
    // TODO

    /* Splay tree */
    // TODO
}

