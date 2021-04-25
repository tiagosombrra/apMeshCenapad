/* Classe que define um triangulo
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Triangulo_h
#define Triangulo_h

#include <iostream>
using namespace std;

#include "Elemento.h"
#include "Vetor.h"
#include "Noh.h"
#include <tuple>

class Triangulo : public Elemento
{
    Noh* n1;
    Noh* n2;
    Noh* n3;

    double angN1; // o ângulo no nó 1
    double angN2; // o ângulo no nó 2
    double angN3; // o ângulo no nó 3

    double setAnguloN1 (  ); // calcula o ângulo no nó 1
    double setAnguloN2 (  ); // calcula o ângulo no nó 2
    double setAnguloN3 (  ); // calcula o ângulo no nó 3

public :
    tuple < double, double > p1; // parametro do nó 1
    tuple < double, double > p2; // parametro do nó 2
    tuple < double, double > p3; // parametro do nó 3

    virtual Noh getN ( unsigned const int ) const; // retorna o i-ésimo nó
    virtual double getAngulo ( const Noh& n );
    virtual void calcularArea (  ); // OBS: Não normalizar a normal!!!!
    virtual void calcularNormal (  ); // OBS: Não normalizar a normal!

    void substituir(Noh *velho, Noh *novo);

    Triangulo ( Noh* v1, Noh* v2, Noh* v3 ); // será construído no sentido v1->v2->v3
    virtual ~Triangulo (  );
};

#endif
