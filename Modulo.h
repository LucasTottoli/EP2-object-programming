#ifndef MODULO_H
#define	MODULO_H
#include "CircuitoSISO.h"
#include <list>

using namespace std;

class Modulo : public CircuitoSISO{ //classe herda da classe abstrata
protected:
    CircuitoSISO* circ;
    list <CircuitoSISO*>* Circuitos;
public:
    Modulo();
    virtual ~Modulo();
    void adicionar(CircuitoSISO* circ); //Não há a implementação do método que é abstrato na superClasse, logo, torna-se uma classe abstrata
    list<CircuitoSISO*>* getCircuitos();
    void imprimir(); //redefine o imprimir de Circuito.h
};

#endif