#include "ModuloEmSerie.h"
#include <list>
#include "Sinal.h"
#include <stdexcept>

using namespace std;

ModuloEmSerie::ModuloEmSerie(){
}

Sinal* ModuloEmSerie::processar(Sinal* sinalIN){
    this->sinalIN = sinalIN;
    
    if(Circuitos->empty()){
        throw new logic_error("Erro");
    }

    list<CircuitoSISO*>::iterator i = Circuitos->begin(); //cria-se um iterador para percorrer a lista
    
    while(i != Circuitos->end()){
        sinalIN = (*i)->processar(sinalIN);
        i++;
    }
    return sinalIN;
}

ModuloEmSerie::~ModuloEmSerie(){
}
