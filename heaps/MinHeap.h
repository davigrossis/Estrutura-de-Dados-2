#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
private:
    int heap[100]; 
    int size; 

    int parent(int i);
    int left(int i);
    int right(int i);
    void troca(int &a, int &b);

public:
    MinHeap();              
    void insert(int value); 
    void print();
    void select(int value);
};

#endif
