/*Escribir una función Reemplazar que tenga como argumentos una pila con tipo de
elemento int y dos valores int: nuevo y viejo de forma que, si el segundo valor aparece en algún
lugar de la pila, sea reemplazado por el segundo.*/

#include <iostream>
#include "Pila/Pila.h"
using namespace std;

void Reemplazar(Pila<int> &p, int nuevo, int viejo) {
    Pila<int> aux;
    while (!p.esVacia()) {
        int elemento = p.pop();
        if (elemento == viejo) {
            aux.push(nuevo);
        } else {
            aux.push(elemento);
        }
    }
    while (!aux.esVacia()) {
        p.push(aux.pop());
    }
}

void mostrarPila(Pila<int>& p) {
    Pila<int> aux;

    // Desapilar elementos para mostrar sin perderlos
    while (!p.esVacia()) {
        int valor = p.pop();
        cout << valor << " ";
        aux.push(valor);
    }
    cout << endl;

    // Restaurar la pila original
    while (!aux.esVacia()) {
        p.push(aux.pop());
    }
}

int main() {
    Pila<int> p;
    p.push(3);
    p.push(3);
    p.push(2);
    p.push(5);
    p.push(3);
    p.push(9);

    cout << "Pila antes del reemplazo: ";
    mostrarPila(p);
    cout << endl;

    Reemplazar(p, 1, 3);

    cout << "Pila despues del reemplazo: ";
    while (!p.esVacia()) {
        cout << p.pop() << " ";
    }
     cout << endl;

}
