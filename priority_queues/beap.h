//
// Created by Krzysztof Wójtowicz on 29/11/2025.
//

#ifndef BEAP_H
#define BEAP_H

#include <utility>
#define MAX_HL 30

namespace priority_queues {

class Beap {
protected:
    int A[MAX_HL];
    int bl;

private:
    static void spaces(int n);

public:
    Beap();
    void upBeap(int k);
    void downBeap(int k);
    void insert(int v);
    int delMax();
    static int ij2k(int i, int j);
    static std::pair<int,int> k2ij(int k);
    int search(int v) const;
    void printBeap() const;
};

} // priority_queues

#endif //BEAP_H
