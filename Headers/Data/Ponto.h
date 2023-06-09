/* Classe para leitura de um ponto
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Ponto_h
#define Ponto_h

#include <cmath>
#include <iostream>

using namespace std;

struct Ponto {
  unsigned long id;  // identificador
  // coordenadas
  double x;
  double y;
  double z;
  bool operator==(const Ponto& p) const;  // comparação
  bool operator==(const Ponto* p) const;  // comparação
  double distanciaPara(const Ponto& p) const;
  void mostraPonto();
  Ponto();
  Ponto(double _x, double _y, double _z);
  Ponto(double _x, double _y, double _z, unsigned long i);

 public:
  unsigned long getId() const;
  void setId(unsigned long value);
};
#endif
