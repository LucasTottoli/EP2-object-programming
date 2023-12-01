#include "PersistenciaDeModulo.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "ModuloRealimentado.h"
#include "Modulo.h"
#include "Integrador.h"
#include "Derivador.h"
#include "Amplificador.h"
#include <list>
#include <fstream>
#include <stdexcept>

using namespace std;

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo)
{
    this->nomeDoArquivo = nomeDoArquivo;
    mod = new ModuloEmParalelo;
}

void PersistenciaDeModulo::RecursaoLeitura(ifstream &entrada, Modulo *mod)
{
    double gain;
    string leitura;
    entrada >> leitura;

    while (entrada)
    {
        if (leitura == "P")
        {
            ModuloEmParalelo *P = new ModuloEmParalelo;
            RecursaoLeitura(entrada, P);
            mod->adicionar(P);
        }
        else if (leitura == "S")
        {
            ModuloEmSerie *S = new ModuloEmSerie;
            RecursaoLeitura(entrada, S);
            mod->adicionar(S);
        }
        else if (leitura == "R")
        {
            ModuloRealimentado* R = new ModuloRealimentado;
            RecursaoLeitura(entrada, R);
            mod->adicionar(R);
        }
        if (leitura == "I")
        {
            Integrador *I = new Integrador;
            mod->adicionar(I);
        }
        else if (leitura == "D")
        {
            Derivador *D = new Derivador;
            mod->adicionar(D);
        }
        else if (leitura == "A")
        {
            entrada >> gain;
            Amplificador *A = new Amplificador(gain);
            mod->adicionar(A);
        }
        else if (leitura == "f")
        { // caso base
            return;
        }
        else if(leitura == "P"){
            return;
        }
        else if(leitura == "S"){
            return;
        }
        else if(leitura == "R"){
            return;
        }
        else{
        throw new logic_error("Erro em Persistencia de Modulo, nao e' possivel ler o arquivo completo");
        }
        entrada >> leitura;
    }
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo *mod)
{

    ofstream output;
    output.open(nomeDoArquivo);
    double gain;
    list<CircuitoSISO *>::iterator i = mod->getCircuitos()->begin();

    while (i != mod->getCircuitos()->end())
    {   
            if(dynamic_cast<ModuloEmSerie*>(*i)!=NULL) {
                output<<"S"<<endl;
            }
            else if(dynamic_cast<ModuloEmParalelo*>(*i)!=NULL){
                output<<"P"<<endl;
             }
            else if(dynamic_cast<ModuloRealimentado*>(*i)!=NULL) {
                output<<"R"<<endl;
            }

            else if(dynamic_cast<Integrador*>(*i) !=NULL) {
                output<<"I"<<endl;
            }
            else if( dynamic_cast<Derivador*>(*i)!=NULL) {
                output<<"D"<<endl;
            }
            else if(dynamic_cast<Amplificador*>(*i)!=NULL){  
                output<<"A"<<" "<<gain<<endl;
            }
            output<<"f"<<endl;
            i++;
    }

    output.close();
}

Modulo *PersistenciaDeModulo::lerDeArquivo()
{
    string leitura;
    double gain;

    ifstream entrada;

    entrada.open(nomeDoArquivo);

    if (entrada.fail())
    { // caso nao consiga abrir o arquivo
        throw new invalid_argument("Erro em Persistencia de Modulo, nao e' possivel abrir o arquivo");
    }

    if(!entrada.eof()) { // Adicionei Depois!
        throw new logic_error("Nao foi possivel ler todo o arquivo");
    }
    RecursaoLeitura(entrada, mod);

    entrada.close();

    return mod;
}

PersistenciaDeModulo::~PersistenciaDeModulo()
{
}