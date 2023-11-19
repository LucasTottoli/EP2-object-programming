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
    Sinal(double* sequencia, int comprimento); //sobrecarga
    Sinal(double constante, int comprimento); //sobrecarga
    virtual ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal); //sobrecarga
    void imprimir(int tamanho); //sobrecarga
    void imprimir(); //sobrecarga
};

#endif