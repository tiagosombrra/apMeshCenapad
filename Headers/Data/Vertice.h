/* Classe que define um vértice
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Vertice_h
#define Vertice_h

#include "Ponto.h"

struct Vertice : public Ponto
{
    Vertice ();
    Vertice ( double x, double y, double z);
    Vertice ( Ponto* p );
};
#endif
