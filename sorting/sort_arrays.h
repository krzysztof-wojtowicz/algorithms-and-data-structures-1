//
// Created by Krzysztof Wójtowicz on 18/01/2026.
//

#ifndef SORT_ARRAYS_H
#define SORT_ARRAYS_H

namespace sorting {

class SortArrays {
private:
    static int partition1(int tab[], int l, int r);
    static int partition2(int tab[], int l, int r);
    static void quickR(int tab[], int l, int r, bool isOutput = false, int partitionType = 1);
    static void mergeR(int tab[], int l, int r, bool isOutput = false);
    static void mergeSub(int tab[], int l1, int r1, int l2, int r2);
    static int max(int tab[], int n);

public:
    static void selection(int tab[], int n, bool isOutput = false);
    static void insertion(int tab[], int n, bool isOutput = false);
    static void bubble(int tab[], int n, bool isOutput = false);
    static void mix(int tab[], int n, bool isOutput = false);
    static void comb(int tab[], int n, bool isOutput = false);
    static void heap(int tab[], int n, bool isOutput = false);
    static void quick(int tab[], int n, bool isOutput = false);
    static void quick2(int tab[], int n, bool isOutput = false);
    static void merge(int tab[], int n, bool isOutput = false);
    static void shell(int tab[], int n, bool isOutput = false);
    static void count(int tab[], int n, bool isOutput = false);
    static void printTab(int tab[], int n, int start = 1);
};

} // sorting

#endif //SORT_ARRAYS_H