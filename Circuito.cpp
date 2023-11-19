#include "Circuito.h"
#include <iostream>
using namespace std;

int Circuito::UltimoID = 0; //atribui-se o valor inicial do atributo estático

Circuito::Circuito() {
    Circuito::UltimoID++;
    ID = Circuito::UltimoID; //indica que é um atributo de escopo de classe
}

Circuito::~Circuito() {

}

int Circuito::getID() {
    return ID;
}

int Circuito::getUltimoID() {
    return Circuito::UltimoID;
}

void Circuito::imprimir() {
    cout<<"Circuito com ID"<<" "<<"["<<ID<<"]"<<endl; 
}
