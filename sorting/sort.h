//
// Created by Krzysztof Wójtowicz on 18/01/2026.
//

#ifndef SORT_H
#define SORT_H

namespace sorting {

class Sort {
public:
    static void selection(int tab[], int n, bool isAnim = false);
    static void insertion(int tab[], int n, bool isAnim = false);
    static void bubble(int tab[], int n, bool isAnim = false);
    static void mix(int tab[], int n, bool isAnim = false);
    static void comb(int tab[], int n, bool isAnim = false);
    static void heap(int tab[], int n, bool isAnim = false);
    static void heap2(int tab[], int n, bool isAnim = false);
    static void printTab(int tab[], int n);
};

} // sorting

#endif //SORT_H