#include "MinHeap.h"
#include <iostream>
using namespace std;

MinHeap::MinHeap() {
    size = 0;
}


int MinHeap::parent(int i) { return (i - 1) / 2; }
int MinHeap::left(int i) { return 2 * i + 1; }
int MinHeap::right(int i) { return 2 * i + 2; }

void MinHeap::troca(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void MinHeap::insert(int value) {
    heap[size] = value;
    int i = size;
    size++;

    while (i > 0 && heap[parent(i)] > heap[i]) {
        troca(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void MinHeap::print() {
    cout << "Min-Heap: [ ";
    for (int i = 0; i < size; i++) {
        cout << heap[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}
