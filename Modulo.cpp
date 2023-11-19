#include <list>
#include "Modulo.h"

using namespace std;

Modulo::Modulo(){
}

list<CircuitoSISO*>* Modulo::getCircuitos(){
    return Circuitos; //retorna a lista de circuitos
}

void Modulo::adicionar(CircuitoSISO* circ){
    this->circ = circ; 
    Circuitos->push_front(circ); //adiciona na frente da lista o circuito dado
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
    while(!Circuitos->empty()){
        CircuitoSISO* circ = Circuitos->front();
        Circuitos->pop_front();
        delete circ;
    }
    
}

