/* Classe que define um patch de Hermite
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef HermitePatch_h
#define HermitePatch_h

#include "../../Data/Curve/CurvParamHermite.h"
#include "CoonsPatch.h"

// As curvas devem ser definidas da esquerda para a direita, de baixo para
// cima em relação ao Patch !!!

class HermitePatch : public CoonsPatch {
 public:
  // Pontos de controle ///////////////////////////////
  //
  Ponto Pt00;
  Ponto Pt01;
  Vetor Qv00;
  Vetor Qv01;
  Ponto Pt10;
  Ponto Pt11;
  Vetor Qv10;
  Vetor Qv11;
  Vetor Qu00;
  Vetor Qu01;
  Vetor Tw00;
  Vetor Tw01;
  Vetor Qu10;
  Vetor Qu11;
  Vetor Tw10;
  Vetor Tw11;
  //
  /////////////////////////////////////////////////////

  Matrix1x4 U;   // matriz do parâmetro u
  Matrix4x4 Gx;  // matriz geométrica para coordenada x
  Matrix4x4 Gy;  // matriz geométrica para coordenada y
  Matrix4x4 Gz;  // matriz geométrica para coordenada z
  Matrix4x1 V;   // matriz do parâmetro v
  Matrix4x4 H;   // matriz de Hermite
  // static const Matriz* H;  // matriz de Hermite

  Ponto calculaPonto_u_v();  // faz a multiplicação das matrizes

  Matrix1x4 getU() const;
  Matrix4x4 getGx() const;
  Matrix4x4 getGy() const;
  Matrix4x4 getGz() const;
  Matrix4x1 getV() const;
  Matrix4x4 getH() const;

  Ponto getPt00() const;
  Ponto getPt01() const;
  Ponto getPt10() const;
  Ponto getPt11() const;

  Vetor getQu00() const;
  Vetor getQu01() const;
  Vetor getQu10() const;
  Vetor getQu11() const;

  Vetor getQv00() const;
  Vetor getQv01() const;
  Vetor getQv10() const;
  Vetor getQv11() const;

  Vetor getTw00() const;
  Vetor getTw01() const;
  Vetor getTw10() const;
  Vetor getTw11() const;

  bool sinal_c1;
  bool sinal_c2;
  bool sinal_c3;
  bool sinal_c4;

  void mostraMatrizes();

  // encontra as coordenadas parâmetricas u, v de um dado ponto p no patch,
  // ou a projeção desse ponto na superfície
  tuple<double, double> encontrar_u_v(const Ponto& p);
  tuple<double, double> find_u_v(const Ponto& p);

  // encontra o ponto p na curva dado um parâmetro p
  virtual Ponto parametrizar(double u, double v);

  // calcula as derivadas parciais nas direçõe u e v
  virtual Vetor Qu(double u, double v);
  virtual Vetor Qv(double u, double v);
  virtual Vetor Quu(double u, double v);
  virtual Vetor Quv(double u, double v);
  virtual Vetor Qvu(double u, double v);
  virtual Vetor Qvv(double u, double v);

  // calcula as derivadas parciais de um ponto p
  virtual Vetor Qu(const Ponto& p);
  virtual Vetor Qv(const Ponto& p);
  virtual Vetor Quu(const Ponto& p);
  virtual Vetor Quv(const Ponto& p);
  virtual Vetor Qvu(const Ponto& p);
  virtual Vetor Qvv(const Ponto& p);

  // Ordem das curvas:
  //		C3
  //	C4		C2
  //		C1
  HermitePatch(Curva* C1, Curva* C2, Curva* C3, Curva* C4, Vetor TW_00,
               Vetor TW_10, Vetor TW_01, Vetor TW_11, bool sinal_c1 = true,
               bool sinal_c2 = true, bool sinal_c3 = true,
               bool sinal_c4 = true);

  /*	HermitePatch (  Ponto Pt_00, Ponto Pt_01, Vetor Qv_00, Vetor Qv_01,
                              Ponto Pt_10, Ponto Pt_11, Vetor Qv_10, Vetor
     Qv_11, Vetor Qu_00, Ponto Qu_01, Vetor Tw_00, Vetor Tw_01, Vetor Qu_10,
     Ponto Qu_11, Vetor Tw_10, Vetor Tw_11, bool sinal_c1 = true, bool sinal_c2
     = true, bool sinal_c3 = true, bool sinal_c4 = true );*/

  HermitePatch(HermitePatch*);

  HermitePatch();

  ~HermitePatch();
};
#endif
