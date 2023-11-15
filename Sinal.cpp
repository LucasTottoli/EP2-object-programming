#include "Sinal.h"
#include "Grafico.h"
using namespace std;

Sinal::Sinal(double* sequencia, int comprimento){
    
    this->comprimento = comprimento;
    guardaSequencia = new double[comprimento];

    for(int i = 0; i < comprimento; i++){
        guardaSequencia[i] = sequencia[i];
    }
    this->sequencia = guardaSequencia;

}

Sinal::Sinal(double constante, int comprimento) {
    this->comprimento=comprimento;
    this->constante=constante;
    int i=0;
    guardaConstante= new double[comprimento];
    for(i=0;i<comprimento;i++) {
        guardaConstante[i]=constante;
    }
    this->sequencia=guardaConstante;
}

Sinal::~Sinal() {
    delete[] guardaSequencia;
    delete[] guardaConstante;
}

int Sinal::getComprimento() {
    return comprimento;
}
 double *Sinal::getSequencia() {
    return sequencia;
 }

 void Sinal::imprimir(string nomeDoSinal) {
    this->nomeDoSinal = nomeDoSinal;

    Grafico* G = new Grafico(nomeDoSinal, sequencia, comprimento);
    G->plot();
 }

void Sinal::imprimirTestes() {
    int i;
    for(i=0;i<comprimento;i++) {
        cout<<i<<"-"<<" "<<sequencia[i]<<endl;
    }
    cout<<"--"<<endl;
}

void Sinal::imprimir(int tamanho) {
    int i;
    this->tamanho=tamanho;
    if(comprimento<tamanho) {
        for(i=0;i<comprimento;i++) {
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