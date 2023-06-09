/* Classe que define uma curva paramétrica de bezier
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da dissertação de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef CurvParamBezier_h
#define CurvParamBezier_h

#include "CurvaParametrica.h"

class CurvParamBezier : public CurvaParametrica {
  Ponto P2;  // vetor tangente no ponto inicial
  Ponto P3;  // vetor tangente no ponto final

 public:
  Ponto getP2() const;
  Ponto getP3() const;

  void setP2(const Ponto &p);
  void setP3(const Ponto &p);

  friend class BezierPatch;  // patch de Bezier pode acessar os atributos

  // IMPORTANTE: Ao usar o construtor default, não esquecer de setar
  // os pontos de controle !!!
  CurvParamBezier();

  // Esse construtor é mais recomendado !!! Evita erros ao esquecer de setar
  // os valores indicados na observação do construtor default !!!
  CurvParamBezier(Ponto p0, Ponto p1, Ponto p2, Ponto p3);
  CurvParamBezier(CurvParamBezier *);

  double calcularCurvatura(double t);

  ~CurvParamBezier();
};
#endif
