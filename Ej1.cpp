/*Escriba un programa que introduzca una palabra y utilice una pila para imprimir la
misma palabra invertida.*/

#include <iostream>
#include <Pila/Pila.h>
using namespace std;

int main() {
    Pila<char> p;
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    for (int i = 0; i < palabra.size(); i++) {
        p.push(palabra[i]);
    }
    cout << "Palabra invertida: ";
    while (!p.esVacia()) {
        cout << p.pop();
    }
    cout << endl;
    return 0;
}
