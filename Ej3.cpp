/*Crear una función que reciba una pila por referencia y un número. La función debe sacar
la primera ocurrencia de dicho valor de la pila sino se repite el valor en la pila, de lo contrario
debe eliminar todos los valores repetidos a excepción de la primera ocurrencia, si el valor no
se encuentra en la pila muestra un mensaje indicando que no pertenece el valor a la pila.
Imprimir la pila al final para verificar si hubo o no modificaciones.*/

#include <iostream>
#include "Pila/Pila.h"
using namespace std;

void eliminarPrimeraOcurrencia(Pila<int> &p, int valor) {
    Pila<int> aux;
    bool encontrado = false;
    int contador=0;
    
    while (!p.esVacia()) {
        int elemento = p.pop();
        if (elemento == valor) {
            if(!encontrado){
                encontrado = true;
                aux.push(elemento);
            }
            contador++;
        
        }
        else {
            aux.push(elemento);
        }
    }
    if (!encontrado) {
        cout << "El valor no pertenece a la pila" << endl;
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

    cout << "Pila antes de eliminar la primera ocurrencia: ";
    mostrarPila(p);
    cout << endl;

    eliminarPrimeraOcurrencia(p, 3);

    cout << "Pila despues de eliminar la primera ocurrencia: ";
    mostrarPila(p);
    cout << endl;
}
