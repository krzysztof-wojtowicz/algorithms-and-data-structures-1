//
// Created by Krzysztof Wójtowicz on 18/01/2026.
//

#include "sort_arrays.h"
#include <iostream>
#include <algorithm>
#include "../priority_queues/heap.h"

using namespace priority_queues;

namespace sorting {

// selection sort algorithm
void SortArrays::selection(int tab[], int n, bool isOutput) {
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
void SortArrays::insertion(int tab[], int n, bool isOutput) {
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
            std::cout<<"TAB: [i="<<i<<",j="<<j<<"]"<<std::endl;
            printTab(tab, n);
        }
    }
}

// bubble sort algorithm
void SortArrays::bubble(int tab[], int n, bool isOutput) {
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
void SortArrays::mix(int tab[], int n, bool isOutput) {
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
void SortArrays::comb(int tab[], int n, bool isOutput) {
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
void SortArrays::heap(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< HEAP SORT (regular heap) >>>"<<std::endl;

    // create heap from tab
    auto heap = Heap();
    heap.buildHeapFromBottom(&tab[1], n);
    if (isOutput) {
        std::cout<<"HEAP STATE:"<<std::endl;
        heap.printHeap();
    }

    // insert elements from heap to tab
    while (heap.getHl() > 0) {
        tab[heap.getHl()+1] = heap.delMax();

        if (isOutput) {
            std::cout<<"TAB: [i="<<heap.getHl()<<"]"<<std::endl;
            printTab(tab, n);
            std::cout<<"HEAP STATE:"<<std::endl;
            heap.printHeap();
        }
    }
}

// quick sort algorithm using partition 1 (Hoare method)
void SortArrays::quick(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< QUICK SORT (Hoare method) >>>"<<std::endl;

    quickR(tab, 1, n, isOutput, 1);
}

// quick sort algorithm using partition 2 (Lomuto method)
void SortArrays::quick2(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< QUICK SORT (Lomuto method) >>>"<<std::endl;

    quickR(tab, 1, n, isOutput, 2);
}

// partition function for quick sort algorithm (version 1)
int SortArrays::partition1(int tab[], int l, int r) {
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
int SortArrays::partition2(int tab[], int l, int r) {
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
void SortArrays::quickR(int tab[], int l, int r, bool isOutput, int partitionType) {
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

// merge sort algorithm
void SortArrays::merge(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< MERGE SORT >>>"<<std::endl;

    mergeR(tab, 1, n, isOutput);
}

// recursive method for merge sort
void SortArrays::mergeR(int tab[], int l, int r, bool isOutput) {
    // final step
    if (l == r)
        return;

    // split to two sub arrays
    int m = (l + r)/2;

    // recursive call for two sub arrays
    mergeR(tab, l, m, isOutput);
    mergeR(tab, m + 1, r, isOutput);

    // merge two subarrays (they are now ordered after recursive call)
    mergeSub(tab, l, m, m + 1, r);

    if (isOutput) {
        std::cout<<"  MERGE STEP: ";
        for (int i = l; i <= r; i++) {
            std::cout<<tab[i]<<" ";
        }
        std::cout<<std::endl;
    }
}

// merge two subarrays for merge sort method
void SortArrays::mergeSub(int tab[], int l1, int r1, int l2, int r2) {
    // iterate from left side of each part and
    // insert values in correct order to temp array
    int i = l1;
    int j = l2;
    int k = 0;

    // temp array
    int size = (r1 - l1 + 1) + (r2 - l2 + 1);
    int temp[size];

    // insert values in correct order from both parts
    while (i <= r1 && j <= r2) {
        if (tab[i] <= tab[j]) {
            temp[k++] = tab[i++];
        } else {
            temp[k++] = tab[j++];
        }
    }

    // insert rest of the values form left part
    while (i <= r1) {
        temp[k++] = tab[i++];
    }

    // insert rest of the values from right part
    while (j <= r2) {
        temp[k++] = tab[j++];
    }

    // insert values to original tab
    for (int m = 0; m < size; m++) {
        tab[l1 + m] = temp[m];
    }
}

// shell sort (modified insertion sort)
void SortArrays::shell(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< SHELL SORT >>>"<<std::endl;

    // choose h based on array size
    int h = 2;
    while (h - 1 < n/2)
        h *= 2;
    h--;

    while (h >= 1) {
        // insertion sort for given h jump
        for (int j = h + 1; j <= n; j++) {
            int v = tab[j];
            int i = j - h;

            // move values to the right to find place for v
            while (i > 0 && tab[i] > v) {
                tab[i+h] = tab[i];
                i -= h;
            }

            // insert v
            tab[i+h] = v;

            if (isOutput) {
                std::cout<<"TAB: [h="<<h<<",j="<<j<<",i="<<i<<"]"<<std::endl;
                printTab(tab, n);
            }
        }

        // update h
        h = (h + 1)/2 - 1;
    }
}

// count sort
void SortArrays::count(int tab[], int n, bool isOutput) {
    if (isOutput) std::cout<<"<<< COUNT SORT >>>"<<std::endl;

    // all elements from array are smaller than m
    int m = max(tab, n);

    // prepare counting array
    int count[m+1];
    std::fill(count, count + m + 1, 0);

    // count values
    for (int i = 1; i <= n; i++)
        count[tab[i]]++;

    if (isOutput) {
        std::cout<<" COUNT: ";
        for (int i = 0; i <= m; i++) {
            std::cout<<i<<" ["<<count[i]<<"] ";
        }
        std::cout<<std::endl;
    }

    // calculate ending indexes of elements
    for (int i = 1; i <= m; i++)
        count[i] += count[i-1];

    if (isOutput) {
        std::cout<<" INDEX: ";
        for (int i = 0; i <= m; i++) {
            std::cout<<i<<" ["<<count[i]<<"] ";
        }
        std::cout<<std::endl;
    }

    // insert to temp array in correct order from the back
    // this way we ensure stability of this algorithm
    int temp[n+1];
    std::fill(temp, temp + n + 1, -1);

    for (int i = n; i > 0; i--) {
        temp[count[tab[i]]--] = tab[i];

        if (isOutput) {
            std::cout<<"  STEP: ";
            for (int i = 1; i <= n; i++) {
                if (temp[i] != -1) std::cout<<temp[i]<<" ";
                else std::cout<<"_ ";
            }
            std::cout<<std::endl;
        }
    }

    // insert values to original array
    for (int i = 1; i <= n; i++)
        tab[i] = temp[i];
}

// prints tab with visualization
void SortArrays::printTab(int tab[], int n, int start) {
    for (int i = start; i <= n; i++) {
        for (int j = 0; j < tab[i]; j++) {
            std::cout<<"-";
        }
        std::cout<<tab[i]<<std::endl;
    }
}

// returns max element of tab
int SortArrays::max(int tab[], int n) {
    if (n < 1)
        return -1;

    int max = tab[1];

    for (int i = 2; i <= n; i++) {
        if (tab[i] > max)
            max = tab[i];
    }

    return max;
}

} // sorting