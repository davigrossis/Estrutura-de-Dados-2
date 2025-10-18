#include "MinHeap.h"
#include <iostream>
using namespace std;

MinHeap::MinHeap() {
    size = 0;
}


int MinHeap::parent(int i) { return (i - 1) / 2; }
int MinHeap::left(int i) { return 2 * i + 1; }
int MinHeap::right(int i) { return 2 * i + 2; }

void MinHeap::change(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void MinHeap::insert(int value) {
    heap[size] = value;
    int i = size;
    size++;

    while (i > 0 && heap[parent(i)] > heap[i]) {
        change(heap[parent(i)], heap[i]);
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

void MinHeap::select(int value) {
    int i = value;
    if(size == 0){
        cout << "O heap esta vazio, insira valores na heap antes" << endl;
    }
    else if(i < 0){
        cout << "Esse valor e invalido , digite um valor menor ou igual a 0" << endl;
    }
    else if(i >= size){
        cout << "Esse valor e invalido pois nao existe essa posicao na heap, retorne um valor entre o intervalo de 0 e " << size - 1 << endl;       
    }
    else{
        cout << "O valor da posicao selecionada e: " << heap[i] << endl;
    }
}

void MinHeap::down(int heap[], int value, int size) {
    int l = left(value);
    int r = right(value);
    int menor = value;

    if (l < size && heap[l] < heap[menor])
        menor = l;

    if (r < size && heap[r] < heap[menor])
        menor = r;

    if (menor != value) {
        change(heap[value], heap[menor]);
        down(heap, menor, size);
    }
}

void MinHeap::up(int heap[], int value){
    if(value > 0) {
        int p = parent(value);
        if(heap[value] < heap[p]){
            change(heap[value], heap[p]);
            up(heap, p);
        }
    }    
}
