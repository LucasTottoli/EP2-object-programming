#include "Amplificador.h"

Amplificador::Amplificador(double ganho){
    this->ganho = ganho; 
}

Sinal* Amplificador::processar(Sinal* sinalIN){
    double *seqIN = sinalIN->getSequencia(); 
    double *seqOUT = new double[sinalIN->getComprimento()]; 
    
    
    for (int i = 0; i < sinalIN->getComprimento() ;i++){
        seqOUT[i] = seqIN[i]*ganho; 
    }
    Sinal* sinalOUT = new Sinal(seqOUT, sinalIN->getComprimento()); 
    
    return sinalOUT;
}


double Amplificador::getGanho(){
    return ganho;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}

Amplificador::~Amplificador(){
}