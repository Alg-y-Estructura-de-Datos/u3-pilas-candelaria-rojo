#include <iostream>
#include "Pila/Pila.h"
using namespace std;

/*Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
números en una pila y pedir también un número entero "n". Luego crear una función que
reciba una pila y un número entero “n”, si el "n" se encuentra en una de las posiciones de la
pila, devuelve la suma de los números en cada una de las posiciones de la pila hasta llegar a
"n" (sin incluir a n), si el número "n" no se encuentra en la pila, la función devuelve la suma de
todos los elementos de la pila. Imprimir primero la pila antes de sumar sus elementos.
*/

void sumaHastaN(Pila<int> &pila, int n){
  Pila<int> aux;
  int suma = 0;
  bool encontrado = false;

   while (!pila.esVacia()) {
        int valor = pila.pop();
        aux.push(valor);
        if (valor == n) {
            encontrado = true;
            break;
        }
        suma += valor;
    }

    // Restaurar la pila original
    while (!aux.esVacia()) {
        pila.push(aux.pop());
    }

    // Mostrar el resultado de la suma
    if (encontrado) {
        cout << "Suma hasta " << n << " (sin incluir): " << suma << endl;
    } else {
        cout << "Suma total de la pila: " << suma << endl;
    }
}

void imprimirPila(Pila<int> &pila)
{
    Pila<int> aux;

    // Pasar los elementos a una pila auxiliar para imprimir sin vaciar la original
    cout << "Pila original: " << endl;
    while (!pila.esVacia())
    {
        int valor = pila.pop();
        cout << valor << endl;
        aux.push(valor);
    }

    // Restaurar la pila original
    while (!aux.esVacia())
    {
        pila.push(aux.pop());
    }
}


int main()
{
    Pila<int> pila;
    int n, numero;
    char respuesta;
    cout << "Ingrese numeros enteros a la pila: " << endl;
    do{
        cin >> numero;
        pila.push(numero);
        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's');
    cout << "Ingrese un numero entero: ";
    cin >> n;
    
    imprimirPila(pila);
    sumaHastaN(pila, n);
}