#include <iostream>
#include <cmath>
#include "Grafico.h"
#include "Sinal.h"

using namespace std;

void menu(){
   double NovoSinal=5;
   int comprimento=6;
   int tamanho=5;
   Sinal *sinal= new Sinal(NovoSinal,comprimento);
   sinal->imprimir(tamanho);
}
