/* Classe que define um vetor
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Vetor_h
#define Vetor_h

#include "Ponto.h"
#include <cmath>

struct Vetor
{		
    //unsigned short id;

    // coordenadas
    double x;
    double y;
    double z;


    Vetor operator+ ( const Vetor& v ) const; // soma vetorial
    Vetor operator- ( const Vetor& v ) const; // diferença vetorial
    Vetor operator- (  ) const; // vetor inverso
    double operator^ ( const Vetor& v ) const; // produto escalar
    Vetor operator^ ( const double d ) const; // produto por escalar
    Vetor operator* ( const Vetor& v ) const; // produto vetorial

    const Vetor& operator= ( const Vetor& v ); // atribuição
    const Vetor& operator= ( const Ponto& p ); // atribuição

    double modulo (  ) const;
    double anguloCom ( Vetor& v ) const; // ângulo entre dois vetores
    Vetor unitario (  ); // vetor unitário

    Vetor ();
    Vetor ( double c_x, double c_y, double c_z);
    Vetor ( const Vetor& v );
    Vetor ( const Ponto& p );
    Vetor ( const Ponto& p, const Ponto& q ); // constrói um vetor entre dois pontos
};
#endif
