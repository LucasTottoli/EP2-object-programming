#ifndef PILOTO_H
#define PILOTO_H

#include "Sinal.h"
#include "Integrador.h"
#include "Amplificador.h"

class Piloto {
private:
    double ganho;

public:
    Piloto(double ganho);
    virtual ~Piloto();
    Sinal* processar(Sinal* sinalIN);
};

#endif