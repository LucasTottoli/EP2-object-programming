#include "ModuloEmSerie.h"
#include <list>
#include "Sinal.h"
#include <stdexcept>

using namespace std;

ModuloEmSerie::ModuloEmSerie(){
} //não faz nada

Sinal* ModuloEmSerie::processar(Sinal* sinalIN){
    this->sinalIN = sinalIN; //dá o valor do sinal de entrada para a variável protegida 
    
    if(Circuitos->empty()){
        throw new logic_error("Erro"); //verifica se a lista está vazia
    }

    list<CircuitoSISO*>::iterator i = Circuitos->begin(); //cria-se um iterador para percorrer a lista
    
    while(i != Circuitos->end()){ //percorre a lista toda
        sinalIN = (*i)->processar(sinalIN); //sinalIN é alterado toda vez que em que anda-se 1 elemento para frente
        i++;
    }
    return sinalIN;
}

ModuloEmSerie::~ModuloEmSerie(){
} //não faz nada 

 //não foi implementado nenhum método adicionar ou getCircuitos pois já é herdado
