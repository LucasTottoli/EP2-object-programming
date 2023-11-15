#ifndef SINAL_H
#define SINAL_H

#include <iostream>

using namespace std;

class Sinal{
private:
    string nomeDoSinal;
    double* sequencia;
    double* guardasequencia;
    int comprimento;
    int constante;
    int tamanho;
    double *Constante;


public:
    Sinal(double* sequencia, int comprimento);
    Sinal(double constante, int comprimento);
    virtual ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
    void imprimir(int tamanho);
    void imprimirTestes();
};

#endif