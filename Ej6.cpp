/*Implementa un programa en C++ que utilice una pila para simular el movimiento de una
persona en un edificio. Cada vez que la persona entra en un área del edificio (por ejemplo,
"Recepción", "Sala de Reuniones", "Oficina"), se debe apilar el nombre del área. Cuando la
persona sale del área, se debe desapilar el nombre. Al final del día, el programa debe mostrar
el recorrido de la persona en orden inverso al que lo hizo (último lugar visitado al primero).
*/
#include <iostream>
#include "Pila/Pila.h"
using namespace std;

int main() {
   {
    Pila<string> pila;
    string accion;
    string lugar;

    cout << "Ingrese la accion (in/out) y el lugar (escriba fin cuando hay terminado su recorrido): " << endl;
    do
    {
        cin >> accion;
        if (accion == "in")
        {
            cin >> lugar;
            pila.push(lugar);
        }
        else if (accion == "out")
        {
            pila.pop();
        }
    } while (accion != "fin");

    cout << "Recorrido completo de la persona en orden inverso: " << endl;
    while (!pila.esVacia())
    {
        cout << pila.pop() <<endl;
    }
}
}