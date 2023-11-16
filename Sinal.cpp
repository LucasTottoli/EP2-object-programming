#include "Sinal.h"
#include "Grafico.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Sinal::Sinal(double* sequencia, int comprimento){  
    this->comprimento = comprimento;
    
    if(comprimento <= 0) {
        throw new invalid_argument("Comprimento inválido");
    }
    guardasequencia = new double[comprimento];

    for(int i = 0; i < comprimento; i++){
        guardasequencia[i] = sequencia[i];
    }
    this->sequencia = guardasequencia;
}


double* Sinal::getSequencia(){
    return sequencia;
}

int Sinal::getComprimento(){
    return comprimento;
}

Sinal::Sinal(double constante, int comprimento) {
    this->constante = constante;
    this->comprimento = comprimento;

    if(comprimento <= 0) {
        throw new invalid_argument("Comprimento inválido");
    }
    Const = new double[comprimento];
    
    for(int i = 0; i < comprimento; i++) {
        Const[i] = constante;
    }
    this->sequencia = Const;
}

void Sinal::imprimir(string nomeDoSinal){
    this->nomeDoSinal = nomeDoSinal;

    Grafico* G = new Grafico(nomeDoSinal, sequencia, comprimento);
    G->plot();
}


void Sinal::imprimir(int tamanho) {
    this->tamanho = tamanho;
    if(comprimento < tamanho) {
        for(int i = 0; i < comprimento-1; i++) {
        cout << i << "-" << " " << sequencia[i] <<endl;
    }
        cout << "--" << endl;
    }

    else {
        for(int i = 0; i < tamanho; i++) {
        cout << i << "-" << " " << sequencia[i]<<endl;
    }
        cout << "--" << endl;
    }

}

void Sinal::imprimir() {

    for(int i = 0 ; i < comprimento; i++) {
        cout << i << "-" << " " << sequencia[i]<<endl;
    }
    cout << "--" << endl;
}

Sinal::~Sinal(){
   delete[] guardasequencia;
   delete[] Const;
}