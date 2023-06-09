/* Classe que define a curvatura de um vértice
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Curvatura_h
#define Curvatura_h

#include "../Data/Noh.h"

struct Curvatura {
  virtual double media() = 0;
  virtual double gauss() = 0;
};

#endif
