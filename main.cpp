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
#include "dictionaries/array.h"
#include "dictionaries/bst.h"
#include "dictionaries/avl.h"
#include "dictionaries/b_tree.h"
#include "dictionaries/splay_tree.h"
#include "dictionaries/rst.h"
#include "dictionaries/hash.h"
#include "dictionaries/sbb_tree.h"

/* SORTING ALGORITHMS*/
#include "sorting/sort_arrays.h"
#include "sorting/sort_lists.h"

using namespace priority_queues;
using namespace dictionaries;
using namespace sorting;

enum ProgramType {
    SORTING_ARRAYS,
    SORTING_LISTS,
    DICTIONARIES,
    PRIORITY_QUEUES,
};

enum SortingArraysAlgorithms {
    SELECTION,
    INSERTION,
    BUBBLE,
    MIX,
    COMB,
    HEAP,
    QUICK,
    QUICK2,
    MERGE,
    SHELL,
    COUNT,
};

enum SortingListsAlgorithms {
    MERGE_LIST,
    BUCKET,
};

enum Dictionaries {
    UNORDERED_ARRAY,
    ORDERED_ARRAY,
    BST_TREE,
    AVL_TREE,
    B_TREE,
    SPLAY_TREE,
    RST_TREE,
    HASH,
    CHAIN_HASH,
    OPEN_HASH,
    DOUBLE_HASH,
    SBB_TREE,
};

// function definitions
void sorting_arrays_usage(int tab[], int n, SortingArraysAlgorithms algorithm = BUBBLE, bool isOutput = false);
void sorting_lists_usage(SortLists::node *head, SortLists::node *tail, SortingListsAlgorithms algorithm = BUCKET);
void priority_queues_usage();
void dictionaries_usage(int tab[], int n, Dictionaries dictionary = UNORDERED_ARRAY);

// main program
int main(int argc, char** argv) {
    ProgramType type = SORTING_LISTS;

    switch (type) {
        case SORTING_ARRAYS: {
            /* SORTING ALGORITHMS FOR ARRAYS USAGE EXAMPLE */
            int A[] = {-1000,3,5,2,1,4,6,0,6,2,0,1}; // A[0] => sentinel
            int n = 11; // how many elements without sentinel
            sorting_arrays_usage(A, n, MERGE, true);
            break;
        }
        case SORTING_LISTS: {
            /* SORTING ALGORITHMS FOR LISTS USAGE EXAMPLE */
            int A[] = {3, 1, 8, 4, 2, 1, 9, 3, 5};
            int n = 9;
            // create list returns head and tail of created list
            std::pair<SortLists::node*, SortLists::node*> list = SortLists::createList(A, n);
            sorting_lists_usage(list.first, list.second, MERGE_LIST);
            break;
        }
        case DICTIONARIES: {
            /* DICTIONARIES USAGE EXAMPLE */
            int A[] = {1,2,3,4,5,6,7,8,9};
            int n = 9;
            dictionaries_usage(A, n, SBB_TREE );
            break;
        }
        // TODO priority queues
        case PRIORITY_QUEUES:

            break;
        default:
            break;
    }

    return 0;
}

// example usage of different array sorting algorithms
void sorting_arrays_usage(int tab[], int n, SortingArraysAlgorithms algorithm, bool isOutput) {
    std::cout<<"BEFORE:"<<std::endl;
    SortArrays::printTab(tab, n);
    std::cout<<std::endl;

    switch (algorithm) {
        case SELECTION:
            SortArrays::selection(tab, n, isOutput);
            break;
        case INSERTION:
            SortArrays::insertion(tab, n, isOutput);
            break;
        case BUBBLE:
            SortArrays::bubble(tab, n, isOutput);
            break;
        case MIX:
            SortArrays::mix(tab, n, isOutput);
            break;
        case COMB:
            SortArrays::comb(tab, n, isOutput);
            break;
        case HEAP:
            SortArrays::heap(tab, n, isOutput);
            break;
        case QUICK:
            SortArrays::quick(tab, n, isOutput);
            break;
        case QUICK2:
            SortArrays::quick2(tab, n, isOutput);
            break;
        case MERGE:
            SortArrays::merge(tab, n, isOutput);
            break;
        case SHELL:
            SortArrays::shell(tab, n, isOutput);
            break;
        case COUNT:
            SortArrays::count(tab, n, isOutput);
            break;
        default:
            SortArrays::bubble(tab, n, isOutput);
            break;
    }

    std::cout<<std::endl<<"AFTER:"<<std::endl;
    SortArrays::printTab(tab, n);
    std::cout<<std::endl;
}

// example usage of different list sorting algorithms
void sorting_lists_usage(SortLists::node *head, SortLists::node *tail, SortingListsAlgorithms algorithm) {
    std::cout<<"BEFORE: "; SortLists::printList(head); std::cout<<std::endl;

    switch (algorithm) {
        case BUCKET:
            SortLists::bucket(head, tail);
            std::cout<<std::endl;
            break;
        case MERGE_LIST:
            SortLists::merge(head, tail);
            std::cout<<std::endl;
            break;
        default:
            break;
    }

    std::cout<<"AFTER:  "; SortLists::printList(head); std::cout<<std::endl;
}

// example usage of different priority queues implementations
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

// example usage of different dictionaries implementations
void dictionaries_usage(int tab[], int n, Dictionaries dictionary) {
    switch (dictionary) {
        case UNORDERED_ARRAY: {
            std::cout<<"<<< UNORDERED ARRAY EXAMPLE >>>"<<std::endl;

            Array dict = Array(tab, n);
            std::cout<<"BEFORE INSERT:"<<std::endl;
            dict.print();
            int v = 4;
            dict.insert(v);
            std::cout<<"AFTER INSERT (v = "<<v<<", i = "<<dict.search(v)<<"):"<<std::endl;
            dict.print();
            std::cout<<"AFTER DELETION (v = "<<v<<"):"<<std::endl;
            dict.deleteV(v);
            dict.print();
            break;
        }
        case ORDERED_ARRAY: {
            std::cout<<"<<< ORDERED ARRAY EXAMPLE >>>"<<std::endl;

            OrderedArray dict = OrderedArray(tab, n);
            std::cout<<"BEFORE INSERT:"<<std::endl;
            dict.print();
            int v = 13;
            dict.insert(v);
            std::cout<<"AFTER INSERT (v = "<<v<<")"<<std::endl;
            dict.print();
            std::cout<<"BINARY SEARCH (v = "<<v<<", (steps) i = "<<dict.search(v)<<")"<<std::endl;
            std::cout<<"INTERPOLATIVE SEARCH (v = "<<v<<", (steps) i = "<<dict.qSearch(v)<<")"<<std::endl;
            std::cout<<"AFTER DELETION (v = "<<v<<"):"<<std::endl;
            dict.deleteV(v);
            dict.print();
            break;
        }
        case BST_TREE: {
            std::cout<<"<<< BST TREE EXAMPLE >>>"<<std::endl;

            BST dict = BST();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }
            std::cout<<"BEFORE INSERT:"<<std::endl;
            std::cout<<"IN ORDER: "; dict.print();
            std::cout<<"LEVEL ORDER: "; dict.printLevelOrder();
            std::cout<<std::endl;

            int v1 = 13;
            dict.insert(v1);
            std::cout<<"AFTER INSERT (v = "<<v1<<")"<<std::endl;
            std::cout<<"IN ORDER: "; dict.print();
            std::cout<<"LEVEL ORDER: "; dict.printLevelOrder();
            std::cout<<std::endl;

            int v2 = 7;
            dict.deleteV(v2);
            std::cout<<"AFTER DELETION (v = "<<v2<<")"<<std::endl;
            std::cout<<"IN ORDER: "; dict.print();
            std::cout<<"LEVEL ORDER: "; dict.printLevelOrder();
            std::cout<<std::endl;
            break;
        }
        case AVL_TREE: {
            std::cout<<"<<< AVL TREE EXAMPLE >>>"<<std::endl;

            AVL dict = AVL();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }
            std::cout<<"BEFORE INSERT:"<<std::endl;
            std::cout<<"IN ORDER: "; dict.print();
            std::cout<<"LEVEL ORDER: "; dict.printLevelOrder();
            std::cout<<std::endl;

            int v1 = 13;
            dict.insert(v1);
            std::cout<<"AFTER INSERT (v = "<<v1<<")"<<std::endl;
            std::cout<<"IN ORDER: "; dict.print();
            std::cout<<"LEVEL ORDER: "; dict.printLevelOrder();
            std::cout<<std::endl;

            int v2 = 7;
            dict.deleteV(v2);
            std::cout<<"AFTER DELETION (v = "<<v2<<")"<<std::endl;
            std::cout<<"IN ORDER: "; dict.print();
            std::cout<<"LEVEL ORDER: "; dict.printLevelOrder();
            std::cout<<std::endl;
            break;
        }
        // TODO fix b_tree insert and/or delete
        case B_TREE: {
            std::cout<<"<<< B-TREE EXAMPLE (not working) >>>"<<std::endl;

            BTree dict = BTree();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }
            std::cout<<"BEFORE INSERT:"<<std::endl;
            std::cout<<"LEVEL ORDER: "<<std::endl; dict.printLevelOrder();
            std::cout<<std::endl;

            int v1 = 23;
            dict.insert(v1);
            std::cout<<"AFTER INSERT (v = "<<v1<<")"<<std::endl;
            std::cout<<"LEVEL ORDER: "<<std::endl; dict.printLevelOrder();
            std::cout<<std::endl;

            int v2 = 2;
            dict.deleteV(v2);
            std::cout<<"AFTER DELETION (v = "<<v2<<")"<<std::endl;
            std::cout<<"LEVEL ORDER: "<<std::endl; dict.printLevelOrder();
            std::cout<<std::endl;

            break;
        }
        case SPLAY_TREE: {
            std::cout<<"<<< SPLAY TREE EXAMPLE >>>"<<std::endl;

            SplayTree dict = SplayTree();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }
            std::cout<<"BEFORE SEARCH:"<<std::endl;
            std::cout<<"LEVEL ORDER: "; dict.printLevelOrder();
            std::cout<<std::endl;

            dict.search(1);

            std::cout<<"AFTER SEARCH (SPLAY(1)):"<<std::endl;
            std::cout<<"LEVEL ORDER: "; dict.printLevelOrder();
            std::cout<<std::endl;

            dict.deleteV(5);

            std::cout<<"AFTER DELETE (SPLAY(5)):"<<std::endl;
            std::cout<<"LEVEL ORDER: "; dict.printLevelOrder();
            std::cout<<std::endl;
        }
        case RST_TREE: {
            std::cout<<"<<< RST TREE EXAMPLE >>>"<<std::endl;

            RST dict = RST();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }

            std::cout<<"BEFORE INSERT:"<<std::endl;
            std::cout<<"LEVEL ORDER: "<<std::endl; dict.printLevelOrder();

            dict.insert(10);

            std::cout<<"AFTER INSERT (10):"<<std::endl;
            std::cout<<"LEVEL ORDER: "<<std::endl; dict.printLevelOrder();

            dict.deleteV(5);

            std::cout<<"AFTER DELETION (5):"<<std::endl;
            std::cout<<"LEVEL ORDER: "<<std::endl; dict.printLevelOrder();
        }
        case HASH: {
            std::cout<<"<<< SIMPLE HASH EXAMPLE >>>"<<std::endl;

            Hash dict = Hash();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }
            std::cout<<"BEFORE INSERT:"<<std::endl;
            dict.print();

            dict.insert(2);

            std::cout<<"AFTER INSERT (2):"<<std::endl;
            dict.print();

            dict.deleteV(4);

            std::cout<<"AFTER DELETION (4):"<<std::endl;
            dict.print();

        }
        case CHAIN_HASH: {
            std::cout<<"<<< CHAIN HASH EXAMPLE >>>"<<std::endl;

            ChainHash dict = ChainHash();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }
            std::cout<<"BEFORE INSERT:"<<std::endl;
            dict.print();

            dict.insert(11);
            dict.insert(14);
            dict.insert(24);

            std::cout<<"AFTER INSERT (11 & 14 & 24):"<<std::endl;
            dict.print();

            dict.deleteV(10);
            dict.deleteV(4);
            dict.deleteV(11);

            std::cout<<"AFTER DELETION (10 & 4 & 11):"<<std::endl;
            dict.print();
        }
        case OPEN_HASH: {
            std::cout<<"<<< OPEN HASH EXAMPLE >>>"<<std::endl;

            OpenHash dict = OpenHash();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }
            std::cout<<"BEFORE INSERT:"<<std::endl;
            dict.print();

            dict.insert(11);
            dict.insert(14);
            dict.insert(24);
            dict.insert(21);

            std::cout<<"AFTER INSERT (11 & 14 & 24 & 21):"<<std::endl;
            dict.print();

            dict.deleteV(10);
            dict.deleteV(4);
            dict.deleteV(11);

            std::cout<<"AFTER DELETION (10 & 4 & 11):"<<std::endl;
            dict.print();

            std::cout<<"SEARCH FOR 21: i="<<dict.search(21)<<std::endl;
        }
        case DOUBLE_HASH: {
            std::cout<<"<<< DOUBLE HASH EXAMPLE >>>"<<std::endl;

            DoubleHash dict = DoubleHash();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }
            std::cout<<"BEFORE INSERT:"<<std::endl;
            dict.print();

            dict.insert(11);
            dict.insert(14);
            dict.insert(24);
            dict.insert(21);

            std::cout<<"AFTER INSERT (11 & 14 & 24 & 21):"<<std::endl;
            dict.print();

            dict.deleteV(10);
            dict.deleteV(4);
            dict.deleteV(11);

            std::cout<<"AFTER DELETION (10 & 4 & 11):"<<std::endl;
            dict.print();

            std::cout<<"SEARCH FOR 21: i="<<dict.search(21)<<std::endl;
        }
        // TODO delete in sbb_tree
        case SBB_TREE: {
            std::cout<<"<<< SBB TREE (2-3-4) EXAMPLE >>>"<<std::endl;

            SBBTree dict = SBBTree();
            for (int i = 0; i < n; i++) {
                dict.insert(tab[i]);
            }
            std::cout<<"BEFORE INSERT:"<<std::endl;
            dict.printLevelOrder();

            dict.insert(10);

            std::cout<<"AFTER INSERT (10):"<<std::endl;
            dict.printLevelOrder();
        }
        default:
            break;
    }
}

