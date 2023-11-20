#include "ModuloEmParalelo.h"
#include "Sinal.h"

using namespace std;

ModuloEmParalelo::ModuloEmParalelo(){
}

Sinal* ModuloEmParalelo::processar(Sinal* sinalIN){
    this->sinalIN = sinalIN; //dá o valor do sinal de entrada para a variável protegida 
    double *sinalAtual = new double[sinalIN->getComprimento()];
    double *sinalAnterior = new double[sinalIN->getComprimento()];
    for(int k = 0; k < sinalIN->getComprimento(); k++){
        sinalAnterior[k] = 0;
    }

    if(Circuitos->empty()){
        throw new logic_error("Erro no ModuloEmParalelo, pois nao possui nenhum Circuito SISO"); //verifica se a lista está vazia
    }

    list<CircuitoSISO*>::iterator i = Circuitos->begin(); //cria-se um iterador para percorrer a lista
    
    while(i != Circuitos->end()){ //percorre a lista toda
        sinalAtual = (*i)->processar(sinalIN)->getSequencia(); //sinalIN é alterado toda vez que em que anda-se 1 elemento para frente
       
       for(int j = 0; j < sinalIN->getComprimento(); j++){
            sinalAtual[j] = sinalAtual[j] + sinalAnterior[j];
       }
       
       sinalAnterior = sinalAtual;
        i++;
    }
    Sinal* sinOUT = new Sinal(sinalAtual, sinalIN->getComprimento());

    return sinOUT;
}

ModuloEmParalelo::~ModuloEmParalelo(){
}