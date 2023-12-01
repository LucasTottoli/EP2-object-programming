#ifndef PERSISTENCIADEMODULO_H
#define	PERSISTENCIADEMODULO_H
#include "Modulo.h"
#include "CircuitoSISO.h"
#include <fstream>

using namespace std;

class PersistenciaDeModulo{
protected:
    string nomeDoArquivo;
    Modulo* mod;
    void RecursaoLeitura(ifstream &entrada, Modulo* mod);

public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();
};

#endif