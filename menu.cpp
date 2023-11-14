#include <iostream>
#include <cmath>
#include "ModuloRealimentado.h"
#include "Integrador.h"
#include "Amplificador.h"
#include "Derivador.h"
#include "Grafico.h"
#include "Somador.h"

using namespace std;

Sinal* novoSinal(){
    int entrada, tamanho = 60;
    double inclinacao, C;
    double sequencia[tamanho] = {0};

    cout << endl << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl << "1) 5+3*cos(n*pi/8)" << endl 
    << "2) constante" << endl << "3) rampa" << endl;

    cout << "Escolha: ";
    cin >> entrada;

    if(entrada == 1){
        for(int i = 0; i < tamanho; i++){
            sequencia[i] = 5 + 3*cos(i*M_PI/8);
        }
    }
    else if(entrada == 2){
        cout << endl << "Qual o valor dessa constante?" << endl << "C = ";
        cin >> C;
        
        for(int i = 0; i < tamanho; i++){
            sequencia[i] = C;
        }
    }
    else {
        cout << endl << "Qual a inclinacao dessa rampa?" << endl << "a = ";
        cin >> inclinacao;

        for(int i = 0; i < tamanho; i++){
            sequencia[i] = i*inclinacao;
        }
    }
    Sinal* novoSinal = new Sinal(sequencia, tamanho);
    
    return novoSinal;
}

void novaOperacao(Sinal* sinalIN){
    int escolha;
    double gain;

    Sinal* sinalOUT = new Sinal(sinalIN->getSequencia(), sinalIN->getComprimento());

    cout << endl << "Qual operacao voce gostaria de fazer?" << endl;
    cout << "1) Amplificar" << endl << "2) Somar" << endl << "3) Derivar" << endl << "4) Integrar" << endl;
    cout << "Escolha: ";
    cin >> escolha;

    if(escolha == 1){

        cout << endl << "Qual o ganho dessa amplificacao?" << endl << "g = ";
        cin >> gain;

        Amplificador* Amplificator = new Amplificador(gain);
        sinalOUT = Amplificator->processar(sinalIN);
    }
    else if(escolha == 2){
        
        cout << endl << "Informe mais um sinal para ser somado." << endl;
        Sinal* sinal2 = new Sinal(sinalIN->getSequencia(), sinalIN->getComprimento());
        sinal2 = novoSinal(); 

        Somador* sum = new Somador();
        sinalOUT = sum->processar(sinalIN, sinal2);
    }
    else if(escolha == 3){
        Derivador* Derivate = new Derivador();
        sinalOUT = Derivate->processar(sinalIN);
    }
    else {
        Integrador* Integrator = new Integrador();
        sinalOUT = Integrator->processar(sinalIN);
    }

    cout << endl << "O que voce quer fazer agora?" << endl;
    cout << "1) Realizar mais uma operacao no resultado" << endl << "2) Imprimir o resultado para terminar" << endl;
    cout << "Escolha: ";
    cin >> escolha;

    if(escolha == 1){
        return novaOperacao(sinalOUT);
    }

    sinalOUT->getComprimento();
    sinalOUT->getSequencia();
    sinalOUT->imprimir("Resultado Final");
}

void menu(){
    int simulacao;
    double gain;

    cout << "                 Simulink em C++" << endl << "Qual simulacao voce gostaria de fazer?" << endl 
    << "1) Piloto Automatico" << endl << "2) Sua propria sequencia de operacoes" << endl;
    
    cout << "Escolha: ";
    
    cin >> simulacao;

    Sinal* sinalOUT = novoSinal();

    if(simulacao == 1){
        cout << endl << "Qual o ganho do acelerador?" << endl << "g = ";
        cin >> gain;

        ModuloRealimentado* PilotoAutomatico = new ModuloRealimentado(gain);

        sinalOUT = PilotoAutomatico->processar(sinalOUT);

        sinalOUT->getComprimento();
        sinalOUT->getSequencia();
        sinalOUT->imprimir("Velocidade do Carro");

        delete sinalOUT;
    }
    if(simulacao == 2){
        novaOperacao(sinalOUT);
    }
}
