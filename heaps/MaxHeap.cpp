#include "MaxHeap.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap() {
    size = 0;
}

int MaxHeap::parent(int i) { return (i - 1) / 2; }
int MaxHeap::left(int i) { return 2 * i + 1; }
int MaxHeap::right(int i) { return 2 * i + 2; }

void MaxHeap::change(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void MaxHeap::insert(int value) {
    this->heap[this->size] = value;
    this->size++;
    
    up(this->heap, this->size - 1);
}

void MaxHeap::print() {
    cout << "Max-Heap: [ ";
    for (int i = 0; i < this->size; i++) {
        cout << this->heap[i];
        if (i < this->size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

void MaxHeap::select(int value) {
    int i = value;
    if (this->size == 0) {
        cout << "O heap esta vazio, insira valores na heap antes" << endl;
    } else if (i < 0) {
        cout << "Esse valor e invalido , digite um valor maior ou igual a 0" << endl;
    } else if (i >= this->size) {
        cout << "Esse valor e invalido pois nao existe essa posicao na heap, retorne um valor entre o intervalo de 0 e " << this->size - 1 << endl;
    } else {
        cout << "O valor da posicao selecionada e: " << this->heap[i] << endl;
    }
}

void MaxHeap::remove() {
    if (this->size < 1) {
        cout << "Heap vazio" << endl;
        return;
    }

    change(this->heap[0], this->heap[this->size - 1]);
    this->size--;
    
    if (this->size > 0) {
        down(this->heap, 0, this->size);
    }
}

void MaxHeap::down(int heap[], int value, int size) {
    int l = left(value);
    int r = right(value);
    int maior = value;

    if (l < size && heap[l] > heap[maior])
        maior = l;

    if (r < size && heap[r] > heap[maior])
        maior = r;

    if (maior != value) {
        change(heap[value], heap[maior]);
        down(heap, maior, size);
    }
}


void MaxHeap::up(int heap[], int value){
    if(value > 0) {
        int p = parent(value);
        if(heap[value] > heap[p]){
            change(heap[value], heap[p]);
            up(heap, p);
        }
    }    
}

