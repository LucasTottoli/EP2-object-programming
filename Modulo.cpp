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
    cout << "Modulo com ID [" << ID << "] e:" << endl;
    for(int i = 0; i < Circuitos->size(); i++){
        cout << "Circuito com ID [" << circ->getID() << "]" << endl;
    }
}

Modulo::~Modulo(){
    while(!Circuitos->empty()){
        CircuitoSISO* circ = Circuitos->front();
        Circuitos->pop_front();
        delete circ;
    }
    
}

