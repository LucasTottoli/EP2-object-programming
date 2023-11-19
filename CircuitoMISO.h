#ifndef CIRCUITOMISO_H
#define CIRCUITOMISO_H
#include "Circuito.h"
#include "Sinal.h"

class CircuitoMISO : public Circuito {
protected:
    
public:
    CircuitoMISO(); //construtor sem parâmetro, ou seja, os filhos não precisam inicializa-lo
    virtual ~CircuitoMISO();
    virtual Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2) = 0; //torna a classe abstrata
};

#endif