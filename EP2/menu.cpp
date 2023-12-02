#include <iostream>
#include <cmath>
#include "Grafico.h"
#include "Sinal.h"
#include "CircuitoSISO.h"
#include "Amplificador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "PersistenciaDeModulo.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "ModuloRealimentado.h"

using namespace std;


void SalvarArquivo(Modulo *novoModulo) {
        int escolha;
        string nome;
        cout<<"Voce gostaria de salvar o circuito em um novo arquivo?"<<endl;
        cout<<"1) Sim"<<endl;
        cout<<"2) Nao"<<endl;
        cin>>escolha;
        if(escolha==1) {
            cout<<"Qual o nome do arquivo a ser escrito?"<<endl<<"Nome:";
            cin>>nome;
            PersistenciaDeModulo *novoArquivo= new PersistenciaDeModulo(nome);
            novoArquivo->salvarEmArquivo(novoModulo);
        }
    }

void ImprimirResultado(Sinal *SinalOUT) {
    SinalOUT->getComprimento();
    SinalOUT->getSequencia();
    SinalOUT->imprimir("Resultado Final");
}


CircuitoSISO* nova_operacao() {
   int escolha;
   double gain;
   cout <<"Qual operacao voce gostaria de fazer?" << endl;
    cout << "1) Amplificar" << endl << "2) Derivar" << endl << "3) Integrar" << endl;
    cout << "Escolha: ";
    cin >> escolha;


    if(escolha == 1){
        cout << endl << "Qual o ganho dessa amplificacao?" << endl << "g = ";
        cin >> gain;
        Amplificador* Amplificator = new Amplificador(gain);
        return Amplificator;
    }

     else if(escolha==2) {
        Derivador* Derivate= new Derivador();
        return Derivate;
    }

    else {
        Integrador*Integrate= new Integrador();
        return Integrate;
    }
}



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


void menu() {
   int tamanho=60;
   double sequencia[tamanho] = {0};
   Sinal*SinalIN= new Sinal(sequencia,tamanho);
   Sinal*SinalOUT= new Sinal(sequencia,tamanho);
   int entrada;
   int escolha;
   cout<< "Simulink em C++"<<endl;
   cout<<"Qual simulacao voce gostaria de fazer?"<<endl;
   cout<<"1) Circuito advindo de arquivo"<<endl;
   cout<<"2) Sua propria sequencia de valores"<<endl;
   cout<<"Escolha:"<<endl;
   cin>>entrada; 
    


   if(entrada==1) {
    SinalIN=novoSinal();
    string nome;
    cout<<"Qual o nome do arquivo a ser lido?"<<endl<<"Nome:";
    cin>>nome;
    PersistenciaDeModulo* new_Arquivo= new PersistenciaDeModulo(nome);
    Modulo* newModulo= new ModuloEmParalelo();
    newModulo=new_Arquivo->lerDeArquivo();
    ImprimirResultado(SinalIN);
    SalvarArquivo(newModulo);
    return;
   }
    SinalIN=novoSinal();
    cout<<"Quais estruturas de operacao voce deseja ter como base?"<<endl;
    cout<<"1) operacoes em series nao realimentadas"<<endl;
    cout<< "2) operacoes em paralelo nao realimentadas"<<endl;
    cout<<"3) operacoes em serie realimentadas"<<endl;
    cin>>escolha;

    Modulo*novoMod;
    if(escolha==1) {
        novoMod= new ModuloEmSerie();
    }
    else if(escolha==2) {
        novoMod= new ModuloEmParalelo();
    }

    else {
        novoMod= new ModuloRealimentado();
    }

    int escolha1;
    do{
        novoMod->adicionar(nova_operacao());
        cout << endl << "O que voce quer fazer agora?" << endl;
        cout << "1) Realizar mais uma operacao no resultado" << endl << "2) Imprimir o resultado para terminar" << endl;
        cout << "Escolha: ";
        cin >> escolha1;
    } while(escolha1==1);
    ImprimirResultado(novoMod->processar(SinalIN));
    SalvarArquivo(novoMod);


 }







   