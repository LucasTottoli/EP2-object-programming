#ifndef MODULOEMSERIE_H
#define	MODULOEMSERIE_H
#include "Modulo.h"


class ModuloEmSerie : public Modulo{
protected:
    Sinal* sinalIN;
public:
    ModuloEmSerie();
    virtual ~ModuloEmSerie();
    virtual Sinal* processar(Sinal* sinalIN); //redefiniu o método que é abstrato na superClasse, logo, é uma classe concreta
};

#endif