#ifndef SINAL_H
#define SINAL_H

#include <iostream>

using namespace std;

class Sinal{
private:
    string nomeDoSinal;
    int comprimento;
    int tamanho;
    double* sequencia;
    double* guardasequencia;
    double *Const;
    double constante;


public:
    Sinal(double* sequencia, int comprimento);
    Sinal(double constante, int comprimento);
    virtual ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
    void imprimir(int tamanho);
    void imprimir(); //para testes
};

#endif