//
// Created by Krzysztof Wójtowicz on 18/01/2026.
//

#ifndef SORT_H
#define SORT_H

namespace sorting {

class Sort {
private:
    static int partition1(int tab[], int l, int r);
    static int partition2(int tab[], int l, int r);
    static void quickR(int tab[], int l, int r, bool isOutput = false, int partitionType = 1);

public:
    static void selection(int tab[], int n, bool isOutput = false);
    static void insertion(int tab[], int n, bool isOutput = false);
    static void bubble(int tab[], int n, bool isOutput = false);
    static void mix(int tab[], int n, bool isOutput = false);
    static void comb(int tab[], int n, bool isOutput = false);
    static void heap(int tab[], int n, bool isOutput = false);
    static void heap2(int tab[], int n, bool isOutput = false);
    static void quick(int tab[], int n, bool isOutput = false);
    static void quick2(int tab[], int n, bool isOutput = false);
    static void printTab(int tab[], int n, int start = 1);
};

} // sorting

#endif //SORT_H