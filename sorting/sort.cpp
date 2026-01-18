//
// Created by Krzysztof Wójtowicz on 18/01/2026.
//

#include "sort.h"
#include <iostream>
#include <algorithm>
#include "../priority_queues/leftist_skew_heap.h"
#include "../priority_queues/heap.h"

using namespace priority_queues;

namespace sorting {

// selection sort algorithm
void Sort::selection(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< SELECTION SORT >>>"<<std::endl;

    for (int i = 1; i < n; i++) {
        int iMin = i;
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < tab[iMin])
                iMin = j;
        }

        std::swap(tab[i], tab[iMin]);
        if (isOutput) {
            std::cout<<"TAB: [i="<<i<<"]"<<std::endl;
            printTab(tab, n);
        }

    }
}

// insertion sort algorithm
void Sort::insertion(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< INSERTION SORT >>>"<<std::endl;

    // sentinel
    tab[0] = -10000;

    for (int i = 2; i <= n; i++) {
        int j = i-1;
        int v = tab[i];
        while (tab[j] > v) {
            tab[j+1] = tab[j];
            j--;
        }

        tab[j+1] = v;

        if (isOutput) {
            std::cout<<"TAB: [i="<<i<<"]"<<std::endl;
            printTab(tab, n);
        }
    }
}

// bubble sort algorithm
void Sort::bubble(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< BUBBLE SORT >>>"<<std::endl;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (tab[j] > tab[j+1]) {
                std::swap(tab[j], tab[j+1]);
            }
        }

        if (isOutput) {
            std::cout<<"TAB: [i="<<i<<"]"<<std::endl;
            printTab(tab, n);
        }
    }
}

// mix sort algorithm (bubble sort from both sides)
void Sort::mix(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< MIX SORT >>>"<<std::endl;

    int l = 1;
    int r = n - 1;
    int k = 1;

    do {
        // from left side
        for (int i = l; i <= r; i++) {
            if (tab[i] > tab[i+1]) {
                std::swap(tab[i], tab[i+1]);
                k = i;
            }
        }

        // update r
        r = k - 1;
        if (isOutput) {
            std::cout<<"TAB: [l="<<l<<",r="<<r<<"]"<<std::endl;
            printTab(tab, n);
        }

        // from right side
        for (int i = r; i >= l; i--) {
            if (tab[i] > tab[i+1]) {
                std::swap(tab[i], tab[i+1]);
                k = i;
            }
        }

        // update l
        l = k + 1;
        if (isOutput) {
            std::cout<<"TAB: [l="<<l<<",r="<<r<<"]"<<std::endl;
            printTab(tab, n);
        }
    } while (l <= r);
}

// comb sort algorithm
void Sort::comb(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< COMB SORT >>>"<<std::endl;

    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap = gap * 10/13; // ratio from lecture
        if (gap == 0)
            gap = 1;

        swapped = false;
        for (int i = 1; i + gap <= n; i++) {
            if (tab[i+gap] < tab[i]) {
                std::swap(tab[i], tab[i+gap]);
                swapped = true;
            }
        }

        if (isOutput) {
            std::cout<<"TAB: [g="<<gap<<",s="<<swapped<<"]"<<std::endl;
            printTab(tab, n);
        }
    }
}

// heap sort algorithm using regular heap (implemented in priority_queues)
void Sort::heap(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< HEAP SORT (regular heap) >>>"<<std::endl;

    // create heap from tab
    auto heap = Heap();
    heap.buildHeapFromBottom(&tab[1], n);
    if (isOutput) {
        std::cout<<"HEAP STATE:"<<std::endl;
        heap.printHeap();
    }

    // insert elements from heap to tab
    int i = n;
    while (heap.getHl() > 0) {
        int val = heap.delMax();
        tab[i] = val;
        i--;

        if (isOutput) {
            std::cout<<"TAB: [i="<<i<<"]"<<std::endl;
            printTab(tab, n);
            std::cout<<"HEAP STATE:"<<std::endl;
            heap.printHeap();
        }
    }
}

// heap sort algorithm using leftist heap (implemented in priority_queues)
void Sort::heap2(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< HEAP SORT (leftist heap) >>>"<<std::endl;

    // create heap from tab
    auto heap = LeftistHeap();
    for (int i = 1; i <= n; i++) {
        heap.insert(tab[i]);
    }
    if (isOutput) {
        std::cout<<"HEAP STATE (level order):"<<std::endl;
        LeftistHeap::printLevelOrder(heap.getRoot());
        std::cout<<std::endl;
    }

    // insert elements from heap to tab
    int i = n;
    while (heap.getRoot()) {
        int val = heap.delMax()->val;
        tab[i] = val;
        i--;

        if (isOutput) {
            std::cout<<"TAB: [i="<<i<<"]"<<std::endl;
            printTab(tab, n);
            std::cout<<"HEAP STATE (level order):"<<std::endl;
            LeftistHeap::printLevelOrder(heap.getRoot());
            std::cout<<std::endl;
        }
    }
}

// quick sort algorithm using partition 1 (Hoare method)
void Sort::quick(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< QUICK SORT (Hoare method) >>>"<<std::endl;

    quickR(tab, 1, n, isOutput, 1);
}

// quick sort algorithm using partition 2 (Lomuto method)
void Sort::quick2(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< QUICK SORT (Lomuto method) >>>"<<std::endl;

    quickR(tab, 1, n, isOutput, 2);
}

// partition function for quick sort algorithm (version 1)
int Sort::partition1(int tab[], int l, int r) {
    // select first element as pivot
    int v = tab[l];
    // two indexes
    int i = l;
    int j = r + 1;

    do {
        do {
            i++;
        } while (tab[i] < v && i < r);

        do {
            j--;
        } while (tab[j] > v && j > l);

        if (i < j) {
            std::swap(tab[i], tab[j]);
        }
    } while (i < j);

    // insert pivot in its position
    tab[l] = tab[j];
    tab[j] = v;
    return j;
}

// partition function for quick sort algorithm (version 2)
int Sort::partition2(int tab[], int l, int r) {
    // select last elements as pivot
    int v = tab[r];
    // one index
    int i = l - 1;

    for (int j = l; j <= r-1; j++) {
        if (tab[j] <= v) {
            i++;
            std::swap(tab[i], tab[j]);
        }
    }

    std::swap(tab[i+1], tab[r]);

    return i + 1;
}

// recursive function for quick sort
void Sort::quickR(int tab[], int l, int r, bool isOutput, int partitionType) {
    int j;
    // partition
    switch (partitionType) {
        case 1:
            j = partition1(tab, l, r);
            break;
        case 2:
            j = partition2(tab, l, r);
            break;
    }

    if (isOutput) {
        std::cout<<"TAB [pivot="<<tab[j]<<"]"<<std::endl;
        printTab(tab,r,l);
    }

    // recursive call for the left part
    if (j - 1 > l) {
        quickR(tab, l, j - 1, isOutput, partitionType);
    }

    // recursive call for the right part
    if (j + 1 < r) {
        quickR(tab, j + 1, r, isOutput, partitionType);
    }
}

// prints tab with visualization
void Sort::printTab(int tab[], int n, int start) {
    for (int i = start; i <= n; i++) {
        for (int j = 0; j < tab[i]; j++) {
            std::cout<<"-";
        }
        std::cout<<tab[i]<<std::endl;
    }
}

} // sorting