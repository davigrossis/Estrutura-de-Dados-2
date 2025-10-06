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

void MinHeap::select(int value) {
    int i = value;
    if(size == 0){
        cout << "O heap esta vazio, insira valores na heap antes" << endl;
    }
    else if(i < 0){
        cout << "Esse valor e invalido , digite um valor maior ou igual a 0" << endl;
    }
    else if(i >= size){
        cout << "Esse valor e invalido pois nao existe essa posicao na heap, retorne um valor entre o intervalo de 0 e " << size - 1 << endl;       
    }
    else{
        cout << "O valor da posicao selecionada e: " << heap[i] << endl;
    }
}
