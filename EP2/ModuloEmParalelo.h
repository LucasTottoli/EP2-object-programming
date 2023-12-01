#ifndef MODULOEMPARALELO_H
#define	MODULOEMPARALELO_H
#include "Modulo.h"

using namespace std;

class ModuloEmParalelo : public Modulo{
protected:
    Sinal* sinalIN;

public:
    ModuloEmParalelo();
    virtual ~ModuloEmParalelo();
    virtual Sinal* processar(Sinal* sinalIN);
};

#endif