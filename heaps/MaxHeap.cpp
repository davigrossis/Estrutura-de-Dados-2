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

void MaxHeap::select(int value) {
    int i = value;
    if (size == 0) {
        cout << "O heap esta vazio, insira valores na heap antes" << endl;
    } else if (i < 0) {
        cout << "Esse valor e invalido , digite um valor maior ou igual a 0" << endl;
    } else if (i >= size) {
        cout << "Esse valor e invalido pois nao existe essa posicao na heap, retorne um valor entre o intervalo de 0 e " << size - 1 << endl;
    } else {
        cout << "O valor da posicao selecionada e: " << heap[i] << endl;
    }
}

void MaxHeap::remove() {
    if (size < 1) {
        cout << "Heap vazio" << endl;
        return;
    }

    troca(heap[0], heap[size - 1]);
    size--;
    down(heap, 0, size);
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
        troca(heap[maior], heap[value]);
        down(heap, maior, size);
    }
}


void MaxHeap::up(int heap[], int value){
    int p = parent(value);
    if(p >= 1){
        if(heap[value] > heap[p]){
            troca(heap[value],heap[p]);
            up(heap,p);
        }
    }    
}

//Dado o arranjo A e nó na posição i
// procedimento subir(A,i)
// p = Pai(i)
// Se (p >= 1 ) Então
//    Se A[i] > A[p] Então
//         troca(A[i],A[p])
//         subir(A,p)
//    Fim-Se
// Fim-Se
