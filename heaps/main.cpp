#include "MaxHeap.h"
#include "MinHeap.h"
#include <iostream>
using namespace std;

int main() {
    MaxHeap heapmax;
    MinHeap heapmin;
    cout << "Digite o numero da estrutura que deseja testar" << endl;
    cout << "[ 1 ] - Min-Heap" << endl;
    cout << "[ 2 ] - Max-Heap" << endl;
    cout << "==================================================" << endl << endl;
    
    int choice;
    cin >> choice;

    if (choice == 1) {
        while (true){

            cout << "Digite qual operacao deseja realizar" << endl;
            cout << "[ 1 ] - Inserir valores na Min-Heap" << endl;
            cout << "[ 2 ] - Imprimir Heap" << endl;
            cout << "[ 3 ] - Selecionar valor de uma posicao" << endl;
            cout << "[ 4 ] - Sair" << endl;
            cout << "==================================================" << endl << endl;

            int op;
            cin >> op;
            if (op == 1) {
                cout << "Digite valores para inserir no Min-Heap (-1 para parar):" << endl;

                int value;
                while (true) {
                    cin >> value;
                    if (value == -1) break;
                    heapmin.insert(value);
                }
            }
            if (op == 2)
            {
                heapmin.print();
            }
            if (op == 3){
                cout << "Digite a posicao que deseja selecionar" << endl;
                int value;
                cin >> value;
                heapmin.select(value);
            }
            if(op == 4){
                break;
            }
        }            
    }
    if (choice == 2) {
        while(true){
            cout << "Digite qual operacao deseja realizar" << endl;
            cout << "[ 1 ] - Inserir valores na Max-Heap" << endl;
            cout << "[ 2 ] - Imprimir Heap" << endl;
            cout << "[ 3 ] - Selecionar valor de uma posicao" << endl;
            cout << "[ 4 ] - Sair" << endl;
            cout << "==================================================" << endl << endl;

            int op;
            cin >> op;
            if (op == 1) {
                cout << "Digite valores para inserir no Max-Heap (-1 para parar):" << endl;

                int value;
                    while (true) {
                    cin >> value;
                    if (value == -1) break;
                    heapmax.insert(value);
                }
            }
            if (op == 2){
                heapmax.print();
            }
            if (op == 3){
                cout << "Digite a posicao que deseja selecionar" << endl;
                int value;
                cin >> value;
                heapmax.select(value);
            }
            if(op == 4){
                break;
            }
        }
    }
    
    return 0;
}
