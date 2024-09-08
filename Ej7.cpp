#include <iostream>
#include "Pila/Pila.h"
#include <string>

using namespace std;

void realizarAccion(Pila<string>& pilaAcciones, Pila<string>& pilaTexto,const string& accion, const string& palabra) {
    string accionCompleta = accion + " " + palabra;
    pilaAcciones.push(accionCompleta);
    pilaTexto.push(palabra);
}

void deshacerAccion(Pila<string>& pilaAcciones, Pila<string>& pilaTexto) {
    if (!pilaAcciones.esVacia()) {
        string ultimaAccion = pilaAcciones.pop();
        pilaTexto.pop();
        cout << "Deshaciendo accion: " << ultimaAccion <<endl;
    } else {
        cout << "No hay acciones para deshacer." <<endl;
    }
}

int main() {
    Pila<string> pilaAcciones;
    Pila<string> pilaTexto;

    realizarAccion(pilaAcciones, pilaTexto, "Escribir", "Hola");
    realizarAccion(pilaAcciones,pilaTexto,  "Escribir", "Mundo");
    realizarAccion(pilaAcciones,pilaTexto, "Borrar", "Mundo");
    deshacerAccion(pilaAcciones,pilaTexto);  // Deshacerá "Borrar Mundo"
    deshacerAccion(pilaAcciones,pilaTexto);  // Deshacerá "Escribir Mundo"

    cout << "Texto actual:" << endl;

    while(pilaTexto.esVacia()==0){
       cout << pilaTexto.pop() << endl;
   }
    return 0;
}