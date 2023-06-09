/* Classe que define uma malha
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Malha_h
#define Malha_h

#include <iostream>
#include <vector>

#include "SubMalha.h"

using namespace std;

class Malha {
  vector<SubMalha*> subMalhas;

 public:
  void insereSubMalha(SubMalha* sub, Data::Int pos);
  void insereSubMalha(SubMalha* sub);
  void removeSubMalha();

  unsigned int getNumDeSubMalhas() const;
  SubMalha* getSubMalha(const unsigned int i);  // retorna a i-ésima submalha
  void resizeSubmalha(Data::Int pos);
  ~Malha();
};

#endif
