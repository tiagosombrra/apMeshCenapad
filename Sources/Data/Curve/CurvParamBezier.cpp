/* Classe que define uma curva paramétrica de Bezier
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da dissertação de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../../Headers/Data/Curve/CurvParamBezier.h"

Ponto CurvParamBezier::getP2() const { return this->P2; }

Ponto CurvParamBezier::getP3() const { return this->P3; }

void CurvParamBezier::setP2(const Ponto &p) { this->P2 = p; }

void CurvParamBezier::setP3(const Ponto &p) { this->P3 = p; }

CurvParamBezier::CurvParamBezier() : CurvaParametrica() {
  // 1. Preenche a matriz 'M' de 'CurvaParamétrica com a matriz de Bezier
  //
  //    M->setElement( 0, 0,-1 ); M->setElement( 0, 1, 3 ); M->setElement( 0,
  //    2,-3 ); M->setElement( 0, 3, 1 ); M->setElement( 1, 0, 3 );
  //    M->setElement( 1, 1,-6 ); M->setElement( 1, 2, 3 ); M->setElement( 1, 3,
  //    0 ); M->setElement( 2, 0,-3 ); M->setElement( 2, 1, 3 ); M->setElement(
  //    2, 2, 0 ); M->setElement( 2, 3, 0 ); M->setElement( 3, 0, 1 );
  //    M->setElement( 3, 1, 0 ); M->setElement( 3, 2, 0 ); M->setElement( 3, 3,
  //    0 );

  M(0, 0) = -1;
  M(0, 1) = 3;
  M(0, 2) = -3;
  M(0, 3) = 1;
  M(1, 0) = 3;
  M(1, 1) = -6;
  M(1, 2) = 3;
  M(1, 3) = 0;
  M(2, 0) = -3;
  M(2, 1) = 3;
  M(2, 2) = 0;
  M(2, 3) = 0;
  M(3, 0) = 1;
  M(3, 1) = 0;
  M(3, 2) = 0;
  M(3, 3) = 0;

  // 2. Preenche as matrizes geométricas com G de Bezier
  //
  //    Gx->setElement( 0, 0, P0.x );
  //    Gx->setElement( 1, 0, P1.x );
  //    Gx->setElement( 2, 0, P2.x );
  //    Gx->setElement( 3, 0, P3.x );

  Gx(0, 0) = P0.x;
  Gx(1, 0) = P1.x;
  Gx(2, 0) = P2.x;
  Gx(3, 0) = P3.x;

  //    Gy->setElement( 0, 0, P0.y );
  //    Gy->setElement( 1, 0, P1.y );
  //    Gy->setElement( 2, 0, P2.y );
  //    Gy->setElement( 3, 0, P3.y );

  Gy(0, 0) = P0.y;
  Gy(1, 0) = P1.y;
  Gy(2, 0) = P2.y;
  Gy(3, 0) = P3.y;

  //    Gz->setElement( 0, 0, P0.z );
  //    Gz->setElement( 1, 0, P1.z );
  //    Gz->setElement( 2, 0, P2.z );
  //    Gz->setElement( 3, 0, P3.z );

  Gz(0, 0) = P0.z;
  Gz(1, 0) = P1.z;
  Gz(2, 0) = P2.z;
  Gz(3, 0) = P3.z;

  Matrix4x1 m;
  m = this->getM() * this->getGx();
  // delete &this->Gx;
  this->setGx(m);

  m = this->getM() * this->getGy();
  // delete &this->Gx;
  this->setGy(m);

  m = this->getM() * this->getGz();
  // delete &this->Gx;
  this->setGz(m);

  // delete &M;

  // IMPORTANTE: Ao usar esse construtor, não esquecer de setar os pontos
  // inicial e final e os vetores tangentes inicial e final !!!
}

CurvParamBezier::CurvParamBezier(Ponto p0, Ponto p1, Ponto p2, Ponto p3)
    : CurvaParametrica(p0, p1), P2(p2), P3(p3) {
  // 1. Preenche a matriz 'M' de 'CurvaParamétrica com a matriz de Bezier

  //    M->setElement( 0, 0,-1 ); M->setElement( 0, 1, 3 ); M->setElement( 0,
  //    2,-3 ); M->setElement( 0, 3, 1 ); M->setElement( 1, 0, 3 );
  //    M->setElement( 1, 1,-6 ); M->setElement( 1, 2, 3 ); M->setElement( 1, 3,
  //    0 ); M->setElement( 2, 0,-3 ); M->setElement( 2, 1, 3 ); M->setElement(
  //    2, 2, 0 ); M->setElement( 2, 3, 0 ); M->setElement( 3, 0, 1 );
  //    M->setElement( 3, 1, 0 ); M->setElement( 3, 2, 0 ); M->setElement( 3, 3,
  //    0 );

  M(0, 0) = -1;
  M(0, 1) = 3;
  M(0, 2) = -3;
  M(0, 3) = 1;
  M(1, 0) = 3;
  M(1, 1) = -6;
  M(1, 2) = 3;
  M(1, 3) = 0;
  M(2, 0) = -3;
  M(2, 1) = 3;
  M(2, 2) = 0;
  M(2, 3) = 0;
  M(3, 0) = 1;
  M(3, 1) = 0;
  M(3, 2) = 0;
  M(3, 3) = 0;

  // 2. Preenche as matrizes geométricas com G de Bezier

  //    Gx->setElement( 0, 0, P0.x );
  //    Gx->setElement( 1, 0, P1.x );
  //    Gx->setElement( 2, 0, P2.x );
  //    Gx->setElement( 3, 0, P3.x );

  Gx(0, 0) = P0.x;
  Gx(1, 0) = P1.x;
  Gx(2, 0) = P2.x;
  Gx(3, 0) = P3.x;

  //    Gy->setElement( 0, 0, P0.y );
  //    Gy->setElement( 1, 0, P1.y );
  //    Gy->setElement( 2, 0, P2.y );
  //    Gy->setElement( 3, 0, P3.y );

  Gy(0, 0) = P0.y;
  Gy(1, 0) = P1.y;
  Gy(2, 0) = P2.y;
  Gy(3, 0) = P3.y;

  //    Gz->setElement( 0, 0, P0.z );
  //    Gz->setElement( 1, 0, P1.z );
  //    Gz->setElement( 2, 0, P2.z );
  //    Gz->setElement( 3, 0, P3.z );

  Gz(0, 0) = P0.z;
  Gz(1, 0) = P1.z;
  Gz(2, 0) = P2.z;
  Gz(3, 0) = P3.z;

  Matrix4x1 m;
  m = this->getM() * this->getGx();
  // delete &this->Gx;
  this->setGx(m);

  m = this->getM() * this->getGy();
  // delete &this->Gx;
  this->setGy(m);

  m = this->getM() * this->getGz();
  // delete &this->Gx;
  this->setGz(m);

  // 3. Calcula o comprimento da curva
  //
  calcular_L();
  //
  ///////////////
}

CurvParamBezier::CurvParamBezier(CurvParamBezier *antiga)
    : CurvaParametrica(antiga) {
  this->P2 = antiga->P2;
  this->P3 = antiga->P3;
}

double CurvParamBezier::calcularCurvatura(double t) {
  // B'(t)= 3(1-t)²(P1-P0)+6t(1-t)(P2-P1)+3t²(P3-P2)
  double v0 = 3 * pow((1 - t), 2) * (P1.x - P0.x) +
              6 * t * (1 - t) * (P2.x - P1.x) + 3 * pow(t, 2) * (P3.x - P2.x);
  double v1 = 3 * pow((1 - t), 2) * (P1.y - P0.y) +
              6 * t * (1 - t) * (P2.y - P1.y) + 3 * pow(t, 2) * (P3.y - P2.y);
  double v2 = 3 * pow((1 - t), 2) * (P1.z - P0.z) +
              6 * t * (1 - t) * (P2.z - P1.z) + 3 * pow(t, 2) * (P3.z - P2.z);

  // B''(t)= 6(1-t)(P2-2P1+P0)+6t(P3-2P2+P1)
  double v00 =
      6 * (1 - t) * (P2.x - 2 * P1.x + P0.x) + 6 * t * (P3.x - 2 * P2.x + P1.x);
  double v10 =
      6 * (1 - t) * (P2.y - 2 * P1.y + P0.y) + 6 * t * (P3.y - 2 * P2.y + P1.y);
  double v20 =
      6 * (1 - t) * (P2.z - 2 * P1.z + P0.z) + 6 * t * (P3.z - 2 * P2.z + P1.z);

  Vetor d1Vetor(v0, v1, v2);
  Vetor d2Vetor(v00, v10, v20);

  double k =
      ((d1Vetor.operator*(d2Vetor)).modulo()) / (pow(d1Vetor.modulo(), 3));

  return k;
}

CurvParamBezier::~CurvParamBezier() {}
