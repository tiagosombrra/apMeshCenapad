/* Classe encarregada de fazer a geração das malhas
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Gerador_h
#define Gerador_h

#include <cmath>

#include "../Data/Modelo.h"
#include "../Data/Mesh/SubMalha.h"

extern double TOLERANCIA;
extern double EPSYLON; // define a qualidade mínima da malha

class Gerador
{
protected :
    unsigned int passo;

    virtual SubMalha* malhaInicial ( );
    virtual double erroGlobal ( );

public :
    double erro; // erro global da malha

    Gerador (  );
    //Gerador ( Modelo& modelo );
};

#endif
