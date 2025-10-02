#include "MaxHeap.h"
#include <iostream>
using namespace std;

int main() {
    MaxHeap heap;
    cout << "Digite valores para inserir no Max-Heap (-1 para parar):" << endl;

    int value;
    while (true) {
        cin >> value;
        if (value == -1) break;
        heap.insert(value);
    }

    heap.print();
    return 0;
}
