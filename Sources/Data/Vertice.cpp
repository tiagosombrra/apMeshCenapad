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

#include "../../Headers/Data/Vertice.h"

Vertice::Vertice() {}

Vertice::Vertice(double x, double y, double z) : Ponto(x, y, z) {}

Vertice::Vertice(Ponto *p) {
  this->x = p->x;
  this->y = p->y;
  this->z = p->z;
}
