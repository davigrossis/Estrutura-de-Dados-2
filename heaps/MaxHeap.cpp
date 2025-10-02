#include "MaxHeap.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap() {
    size = 0;
}


int MaxHeap::parent(int i) { return (i - 1) / 2; }
int MaxHeap::left(int i) { return 2 * i + 1; }
int MaxHeap::right(int i) { return 2 * i + 2; }

void MaxHeap::troca(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void MaxHeap::insert(int value) {
    heap[size] = value;
    int i = size;
    size++;

    while (i > 0 && heap[parent(i)] < heap[i]) {
        troca(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

void MaxHeap::print() {
    cout << "Max-Heap: [ ";
    for (int i = 0; i < size; i++) {
        cout << heap[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}
