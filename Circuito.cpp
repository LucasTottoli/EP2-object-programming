#include "Circuito.h"
#include <iostream>
using namespace std;

int Circuito::UltimoID=0;

Circuito::Circuito() {
    UltimoID++;
    ID = UltimoID;
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
