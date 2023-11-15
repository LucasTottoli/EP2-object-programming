#ifndef CIRCUITO_H
#define CIRCUITO_H

class Circuito {
protected:
    int ID=0;
    static int UltimoID;

public:
    Circuito();
    virtual ~Circuito()=0;
    int getID();
    void imprimir();
    static int getUltimoID();
};

#endif