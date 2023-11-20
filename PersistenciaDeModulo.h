#ifndef PERSISTENCIADEMODULO_H
#define	PERSISTENCIADEMODULO_H
#include "Modulo.h"

using namespace std;

class PersistenciaDeModulo{
protected:
    string nomeDoArquivo;
    Modulo* mod;

public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();
};

#endif