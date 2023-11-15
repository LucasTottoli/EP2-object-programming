#ifndef MODULOREALIMENTADO_H
#define	MODULOREALIMENTADO_H

#include "Sinal.h"

class ModuloRealimentado{
private:
    double ganho;

public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif