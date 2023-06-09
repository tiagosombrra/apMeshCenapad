/* Classe que define um modelo
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Modelo_h
#define Modelo_h

#include <iostream>
#include <list>

#include "../Data/Mesh/Malha.h"
#include "Geometria.h"
#include "Ponto.h"
using namespace std;

class Modelo {
  Geometria* geometria;
  vector<Malha*> malhas;

 public:
  void setGeometria(Geometria* g);
  Geometria* getGeometria();
  void insereMalha(Malha* m);
  unsigned int getNumDeMalhas() const;
  Malha* getMalha(const unsigned int i);  // retorna a i-ésima malha
  Modelo();
  Modelo(Geometria*);
  ~Modelo();
};

#endif
