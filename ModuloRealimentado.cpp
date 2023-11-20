#include "ModuloRealimentado.h"
#include "Somador.h"
#include "ModuloEmSerie.h"
#include "Amplificador.h"

using namespace std;

ModuloRealimentado::ModuloRealimentado(){
    Modulos = new list<ModuloEmSerie*>();
}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN){
    Sinal* saida = nullptr;
    Sinal* diferenca = nullptr;
    Sinal* saidaInvertida = nullptr;

    double* sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];    

    Amplificador* inversor = new Amplificador(-1);
    Somador* sum = new Somador();
    ModuloEmSerie* Pilot = new ModuloEmSerie();

    sequenciaSaidaInvertida[0] = 0;
    diferenca = new Sinal(sinalIN->getSequencia(), 1);
    saida = Pilot->processar(diferenca);
    delete diferenca;

    for(int i = 1; i < sinalIN->getComprimento(); i++){
        inversor->processar(saida);
        sequenciaSaidaInvertida[i] = inversor->processar(saida)->getSequencia()[i-1];
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i+1);
        diferenca = sum->processar(sinalIN, saidaInvertida);
        diferenca = new Sinal(diferenca->getSequencia(), i+1);
        delete saida;
        saida = Pilot->processar(diferenca);
        delete saidaInvertida;
        delete diferenca;
    }
    delete[] sequenciaSaidaInvertida;

    return saida;
}

list<ModuloEmSerie*>* ModuloRealimentado::getCircuitos(){
    return Modulos;
}

void ModuloRealimentado::adicionar(ModuloEmSerie* circ){
    this->circ = circ; 
    Modulos->push_front(circ); //adiciona na frente da lista o circuito do modulo em serie dado
}

ModuloRealimentado::~ModuloRealimentado(){
    while(!Modulos->empty()){ //verifica se a lista está vazia
        ModuloEmSerie* circ = Modulos->front(); //variável circ recebe o elemento da frente da lista para que possa deleta-lo
        Circuitos->pop_front(); //joga fora o elemento da frente da lista, mas não o deleta
        delete circ; //deleta o elemento da frente da lista
}
}