#ifndef MAXHEAP_H
#define MAXHEAP_H

class MaxHeap {
private:
    int heap[100]; 
    int size; 

    int parent(int i);
    int left(int i);
    int right(int i);
    void troca(int &a, int &b);

public:
    MaxHeap();              
    void insert(int value); 
    void print();   
    void select(int value);        
    void remove(int heap[], int size);
    void down(int heap[], int value, int size);

};

#endif
