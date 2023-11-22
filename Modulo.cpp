#include <list>
#include "Modulo.h"

using namespace std;

Modulo::Modulo(){
    Circuitos = new list<CircuitoSISO*>(); //cria-se uma nova lista
} 

list<CircuitoSISO*>* Modulo::getCircuitos(){
    return Circuitos; //retorna a lista de circuitos
}

void Modulo::adicionar(CircuitoSISO* circ){
    Circuitos->push_back(circ); //adiciona atras da lista o circuito dado
}

void Modulo::imprimir(){
    list<CircuitoSISO*>::iterator i = Circuitos->begin(); //cria-se um iterador para percorrer a lista

    cout << "Modulo com ID [" << ID << "] e:" << endl;
    while(i != Circuitos->end()){
        cout << "Circuito com ID [" << (*i)->getID() << "]" << endl; //percorre a lista do primeiro elemento até o último
        i++;
    }
}

Modulo::~Modulo(){
   delete Circuitos;
}

