/* Classe que define uma curva paramétrica de hermite
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef CurvParamHermite_h
#define CurvParamHermite_h

#include "CurvaParametrica.h"

class CurvParamHermite : public CurvaParametrica {
  Vetor DP0;  // vetor tangente no ponto inicial
  Vetor DP1;  // vetor tangente no ponto final

 public:
  Vetor getDP0() const;
  Vetor getDP1() const;
  void setDP0(const Vetor& v);
  void setDP1(const Vetor& v);
  friend class HermitePatch;  // patch de Hermite pode acessar os atributos
  // IMPORTANTE: Ao usar o construtor default, não esquecer de setar
  // os pontos inicial e final e os vetores tangentes inicial e final !!!
  CurvParamHermite();
  // Esse construtor é mais recomendado !!! Evita erros ao esquecer de setar
  // os valores indicados na observação do construtor default !!!
  CurvParamHermite(Ponto p0, Ponto p1, Vetor dp0, Vetor dp1);
  CurvParamHermite(CurvParamHermite*);
  double calcularCurvatura(double t);
  ~CurvParamHermite();
};
#endif
