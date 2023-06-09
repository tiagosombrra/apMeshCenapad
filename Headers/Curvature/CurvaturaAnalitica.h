/* Classe que define a curvatura analítica de um vértice
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef CurvaturaAnalitica_h
#define CurvaturaAnalitica_h

#include <cmath>
#include <tuple>

#include "../Data/Patch/CoonsPatch.h"
#include "../Data/Vertice.h"
#include "../Data/Vetor.h"
#include "Curvatura.h"

class CurvaturaAnalitica : public Curvatura {
  Vetor Qu;
  Vetor Qv;
  Vetor Quu;
  Vetor Quv;
  Vetor Qvv;
  Vetor prod;

  double A;
  double B;
  double C;

 public:
  virtual double media();
  virtual double gauss();
  virtual double curvaturaCurva();
  CurvaturaAnalitica(const Ponto& v, CoonsPatch& p);
};

#endif
