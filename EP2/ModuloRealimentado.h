#ifndef MODULOREALIMENTADO_H
#define	MODULOREALIMENTADO_H

#include "Sinal.h"
#include "Modulo.h"
#include "ModuloEmSerie.h"
#include <list>
using namespace std;

class ModuloRealimentado : public Modulo{ //herda de modulo
protected:
    CircuitoSISO* circ; //troca-se o tipo de váriavel, de CircuitoSISO* vai para ModuloEmSerie*
    list<CircuitoSISO*>* Modulos;

public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    virtual Sinal* processar(Sinal* sinalIN);//implementa o método que é abstrato na superClasse, logo, é uma classe concreta
    void adicionar(CircuitoSISO* circ); //redefinição de void adicionar
    list<CircuitoSISO*>* getCircuitos(); //redefinição de getCircuitos
};

#endif