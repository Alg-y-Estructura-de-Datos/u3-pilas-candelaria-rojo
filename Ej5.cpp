/*Crear un programa e implementar una función que reciba una pila de números enteros y
dado un número “n” por el usuario devuelva una nueva pila con la suma de cada uno de los
elementos de la pila original más el n dado por el usuario. Los elementos en la nueva pila
deben tener el orden que tenían en la pila original, y la pila original debe quedar en el mismo
estado a la inicial, mostrar por pantalla ambas pilas.
Por ejemplo, se tiene la pila de enteros [ 1, 2, 3, 6, 2] (tope es el número 2), y la función
sumarNro recibe como parámetros la pila y n=1 (devuelve la suma entre el número 1 y el
número recibido en cada posición de la pila original), la pila resultante debe ser [ 2, 3, 4, 7, 3]
(el tope es el número 3)
*/
#include <iostream>
#include "Pila/Pila.h"
using namespace std;

void sumarNro(Pila<int>& pila, int n)
{
  Pila<int> aux;
  Pila<int> pilaSuma;

  while (!pila.esVacia())
  {
    aux.push(pila.pop());
  }

  while (!aux.esVacia())
  {
    int valor = aux.pop();
    pilaSuma.push(valor + n);
    pila.push(valor);
  }

  cout << "Pila con la suma de los elementos de la pila original mas " << n << ": " << endl;
  while (!pilaSuma.esVacia())
  {
    cout << pilaSuma.pop() << endl;
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
    int n;
    int numero;
    char respuesta;
  
    cout << "Ingrese numeros enteros a la pila: " << endl;
    do
    {
        cin >> numero;
        pila.push(numero);
        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's');

    imprimirPila(pila);

    cout << "Ingrese un numero entero: ";
    cin >> n;
    
    sumarNro(pila, n);
    
    
}


