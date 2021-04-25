/* Classe que define a curvatura discreta de um vértice
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef CurvaturaDiscreta_h
#define CurvaturaDiscreta_h

#include <cmath>
#include <list>
#include <cstdlib>
#include "Curvatura.h"
#include "Adjacente.h"

using namespace std;

class Elemento;

class CurvaturaDiscreta : public Curvatura
{
    Noh p;
    list <Elemento*> elementos; // lista dos elementos de 'm' incidentes em 'n'
    double A; // área dos elementos incidentes em 'n'
    double fator;	// assume M_PI ou 2 * M_PI
    double sum_phi; // soma dos ângulos em 'n'

    void ordenaAdjacencia ( const Noh& n );

public :
    virtual double media ( );
    virtual double gauss ( );

    CurvaturaDiscreta ( const Noh& n );
};

#endif

