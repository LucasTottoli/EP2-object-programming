#ifndef CIRCUITOSISO_H
#define CIRCUITOSISO_H

#include "Circuito.h"
#include "Sinal.h"

class CircuitoSISO : public Circuito {
protected:
    
public:
    CircuitoSISO();  //construtor sem parâmetro, ou seja, os filhos não precisam inicializa-lo
    virtual ~CircuitoSISO();
    virtual Sinal* processar(Sinal* sinalIN) = 0; //torna a classe abstrata

};

#endif