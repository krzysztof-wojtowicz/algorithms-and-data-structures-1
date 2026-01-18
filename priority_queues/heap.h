//
// Created by Krzysztof Wójtowicz on 29/11/2025.
//

#ifndef HEAP_H
#define HEAP_H

#define MAX_HL 30

namespace priority_queues {

class Heap {
protected:
    int A[MAX_HL];
    int hl;

    [[nodiscard]] int heapHeight() const;

private:
    static void spaces(int n);

public:
    Heap();
    void downHeap(int i);
    void upHeap(int i);
    void insert(int v);
    int delMax();
    void printHeap() const;
    void printTab() const;
    void buildHeapFromTop(int tab[], int n);
    void buildHeapFromBottom(int tab[], int n);
    int getHl();
};

} // priority_queues

#endif //HEAP_H
