#include "PersistenciaDeModulo.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "ModuloRealimentado.h"
#include "Modulo.h"
#include <list>
#include <fstream>
#include <stdexcept>

using namespace std;

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquvio){
    this->nomeDoArquivo = nomeDoArquivo;
}   

void PersistenciaDeModulo::salvarEmArquivo(Modulo* mod){
    this->mod = mod;

}

Modulo* PersistenciaDeModulo::lerDeArquivo(){
    Modulo* M = new ModuloEmParalelo; //cast implicito
    string modulus, circuitus;
    
    ifstream input;

    input.open(nomeDoArquivo);

    if(input.fail()){ //caso nao consiga abrir o arquivo
        throw new invalid_argument("Erro em Persistencia de Modulo, nao e' possivel abrir o arquivo");
    }

    input >> modulus >> circuitus;
    while(input){
        mod->
    }


    if(input.eof()){
        throw new logic_error("Erro em Persistencia de Modulo, nao e' possivel ler o arquivo completo");
    }

}



PersistenciaDeModulo::~PersistenciaDeModulo(){
}