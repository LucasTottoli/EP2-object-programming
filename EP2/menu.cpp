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


CircuitoSISO* nova_operacao(Sinal *sinalIN) {
   int escolha;
   double gain;
   Sinal* sinalOUT = new Sinal(sinalIN->getSequencia(), sinalIN->getComprimento());
   cout <<"Qual operacao voce gostaria de fazer?" << endl;
    cout << "1) Amplificar" << endl << "2) Derivar" << endl << "3) Integrar" << endl;
    cout << "Escolha: ";
    cin >> escolha;


    if(escolha == 1){
        int escolha1;
        cout << endl << "Qual o ganho dessa amplificacao?" << endl << "g = ";
        cin >> gain;

        Amplificador* Amplificator = new Amplificador(gain);
        sinalOUT = Amplificator->processar(sinalIN);

        cout << endl << "O que voce quer fazer agora?" << endl;
        cout << "1) Realizar mais uma operacao no resultado" << endl << "2) Imprimir o resultado para terminar" << endl;
        cout << "Escolha: ";
        cin >> escolha1;
        CircuitoSISO*novoCircuito2=new Amplificador(gain);
        if(escolha1 == 1){
            return nova_operacao(sinalOUT);
        }

        return novoCircuito2;

    }

     else if(escolha==2) {
        int escolha2;
        string nome;
        Derivador* Derivate= new Derivador();
        sinalOUT=Derivate->processar(sinalIN);
        cout << endl << "O que voce quer fazer agora?" << endl;
        cout << "1) Realizar mais uma operacao no resultado" << endl << "2) Imprimir o resultado para terminar" << endl;
        cout << "Escolha: ";
        cin >> escolha2;

        if(escolha2 == 1){
            return nova_operacao(sinalOUT);
        }
        CircuitoSISO*novoCircuito=new Derivador();
        return novoCircuito;
    }

    else {
        Integrador*Integrate= new Integrador();
        sinalOUT=Integrate->processar(sinalIN);
        int escolha3;
        cout << endl << "O que voce quer fazer agora?" << endl;
        cout << "1) Realizar mais uma operacao no resultado" << endl << "2) Imprimir o resultado para terminar" << endl;
        cout << "Escolha: ";
        cin >> escolha3;

        if(escolha3 == 1){
            return nova_operacao(sinalOUT);
        }
        CircuitoSISO*novoCircuito=new Integrador();
        return novoCircuito;
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
   }
    SinalIN=novoSinal();
    cout<<"Quais estruturas de operacao voce deseja ter como base?"<<endl;
    cout<<"1) operacoes em series nao realimentadas"<<endl;
    cout<< "2) operacoes em paralelo nao realimentadas"<<endl;
    cout<<"3) operacoes em serie realimentadas"<<endl;
    cin>>escolha;
    if(escolha==1) {
        ModuloEmSerie* novoMod= new ModuloEmSerie();
        novoMod->adicionar(nova_operacao(SinalIN));
        ImprimirResultado(SinalIN);
        SalvarArquivo(novoMod);
    }

        
    else if(escolha==2) {
        ModuloEmParalelo* novoMod= new ModuloEmParalelo();
        novoMod->adicionar(nova_operacao(SinalIN));
        ImprimirResultado(SinalIN);
        SalvarArquivo(novoMod);
    }

    else {
        ModuloRealimentado*novoMod= new ModuloRealimentado();
        novoMod->adicionar(nova_operacao(SinalIN));
        ImprimirResultado(SinalIN);
        SalvarArquivo(novoMod);

}

 }







   