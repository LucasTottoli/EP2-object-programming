#include "Sinal.h"
#include "Grafico.h"
#include <stdexcept>
Sinal::Sinal(double* sequencia, int comprimento){
    
    this->comprimento = comprimento;
    if(comprimento<=0) {
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
    this->constante=constante;
    int i;
    this->comprimento=comprimento;
    if(comprimento<=0) {
        throw new invalid_argument("Comprimento inválido");
}
Constante = new double[comprimento];
for(i=0;i<comprimento;i++) {
    Constante[i]=constante;
}
this->sequencia=Constante;
}

void Sinal::imprimir(string nomeDoSinal){
    this->nomeDoSinal = nomeDoSinal;

    Grafico* G = new Grafico(nomeDoSinal, sequencia, comprimento);
    G->plot();
}

Sinal::~Sinal(){
   delete[] guardasequencia;
   delete[] Constante;
}

void Sinal::imprimir(int comprimento) {
    int i;
    this->tamanho=tamanho;
    if(comprimento<tamanho) {
        for(i=0;i<comprimento-1;i++) {
        cout<<i<<"-"<<" "<<sequencia[i]<<endl;
    }
        cout<<"--"<<endl;
    }

    else if(comprimento>=tamanho) {
        for(i=0;i<tamanho-1;i++) {
        cout<<i<<"-"<<" "<<sequencia[i]<<endl;
    }
        cout<<"--"<<endl;
    }

}

void Sinal::imprimirTestes() {
    int i;
    for(i=0;i<comprimento;i++) {
        cout<<i<<"-"<<" "<<sequencia[i]<<endl;
    }
    cout<<"--"<<endl;
}