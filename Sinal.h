#ifndef SINAL_H
#define SINAL_H

#include <iostream>

using namespace std;

class Sinal{
private:
    double *sequencia;
    int comprimento;
    double constante;
    string NomeDoSinal;
    double *guardaSequencia;
    double *guardaConstante;
    int tamanho;

public:
    Sinal(int constante, double comprimento);
    Sinal(int *sequencia, double comprimento);
    ~Sinal();
    double *getSequencia();
    int getComprimento();
    void imprimir(string NomeDoSinal);
    void imprimirTESTE();
    void imprimir(int tamanho);

};

#endif
