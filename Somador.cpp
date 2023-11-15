#include "Somador.h"

Somador::Somador() {
}

Somador::~Somador() {
}

Sinal* Somador::processar(Sinal *sinalIN1, Sinal *sinalIN2) {
    double *s1 = new double[sinalIN1->getComprimento()];
        s1 = sinalIN1->getSequencia();
    double *s2 = new double[sinalIN2->getComprimento()];
        s2 = sinalIN2->getSequencia();
    
    double *s3;


    if (sinalIN1->getComprimento() > sinalIN2->getComprimento()) {
        s3 = new double[sinalIN1->getComprimento()];
        
        for(int i = 0; i < sinalIN2->getComprimento();i++) {
            s3[i]=s1[i]+s2[i];
        }
        Sinal *sinalOUT = new Sinal(s3,sinalIN2->getComprimento());
        return sinalOUT;
    }

    else if(sinalIN1->getComprimento() < sinalIN2->getComprimento()) {
        s3 = new double[sinalIN2->getComprimento()];
        
        for(int i = 0; i < sinalIN1->getComprimento();i++) {
            s3[i]=s1[i]+s2[i];
        }
        Sinal *sinalOUT = new Sinal(s3,sinalIN1->getComprimento());
        return sinalOUT;
    }
    else {
        s3 = new double[sinalIN1->getComprimento()];
        
        for(int i = 0; i < sinalIN1->getComprimento();i++) {
            s3[i]=s1[i]+s2[i];
        }
        Sinal *sinalOUT= new Sinal(s3,sinalIN1->getComprimento());
        return sinalOUT;
    }
}