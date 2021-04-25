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

#include "../../../Headers/Data/Curve/CurvParamHermite.h"

Vetor CurvParamHermite::getDP0() const {
    return this->DP0;
}

Vetor CurvParamHermite::getDP1() const {
    return this->DP1;
}

void CurvParamHermite::setDP0(const Vetor &v) {
    this->DP0 = v;
}

void CurvParamHermite::setDP1(const Vetor &v) {
    this->DP1 = v;
}

CurvParamHermite::CurvParamHermite (  ) : CurvaParametrica (  )
{
    // 1. Preenche a matriz 'M' de 'CurvaParamétrica com a matriz de Hermite
    //
    //    M->setElement( 0, 0, 2 ); M->setElement( 0, 1,-2 ); M->setElement( 0, 2, 1 ); M->setElement( 0, 3, 1 );
    //    M->setElement( 1, 0,-3 ); M->setElement( 1, 1, 3 ); M->setElement( 1, 2,-2 ); M->setElement( 1, 3,-1 );
    //    M->setElement( 2, 0, 0 ); M->setElement( 2, 1, 0 ); M->setElement( 2, 2, 1 ); M->setElement( 2, 3, 0 );
    //    M->setElement( 3, 0, 1 ); M->setElement( 3, 1, 0 ); M->setElement( 3, 2, 0 ); M->setElement( 3, 3, 0 );
    M(0,0) = 2;  M(0,1) = -2; M(0,2) = 1;  M(0,3) = 1;
    M(1,0) = -3; M(1,1) = 3;  M(1,2) = -2; M(1,3) = -1;
    M(2,0) = 0;  M(2,1) = 0;  M(2,2) = 1;  M(2,3) = 0;
    M(3,0) = 1;  M(3,1) = 0;  M(3,2) = 0;  M(3,3) = 0;
    //
    ////////////////////////////////////////////////////////////////////////////

    // 2. Preenche as matrizes geométricas com G de Hermite
    //
    //    Gx->setElement( 0, 0, P0.x );
    //    Gx->setElement( 1, 0, P1.x );
    //    Gx->setElement( 2, 0,DP0.x );
    //    Gx->setElement( 3, 0,DP1.x );
    Gx(0,0) = P0.x;
    Gx(1,0) = P1.x;
    Gx(2,0) = DP0.x;
    Gx(3,0) = DP1.x;
    //    Gy->setElement( 0, 0, P0.y );
    //    Gy->setElement( 1, 0, P1.y );
    //    Gy->setElement( 2, 0,DP0.y );
    //    Gy->setElement( 3, 0,DP1.y );
    Gy(0,0) = P0.y;
    Gy(1,0) = P1.y;
    Gy(2,0) = DP0.y;
    Gy(3,0) = DP1.y;
    //    Gz->setElement( 0, 0, P0.z );
    //    Gz->setElement( 1, 0, P1.z );
    //    Gz->setElement( 2, 0,DP0.z );
    //    Gz->setElement( 3, 0,DP1.z );
    Gz(0,0) = P0.z;
    Gz(1,0) = P1.z;
    Gz(2,0) = DP0.z;
    Gz(3,0) = DP1.z;
    //

    this->Gx = this->getM() * this->getGx();
    this->Gy = this->getM() * this->getGy();
    this->Gz = this->getM() * this->getGz();

    delete &M;

    // IMPORTANTE: Ao usar esse construtor, não esquecer de setar os pontos
    // inicial e final e os vetores tangentes inicial e final !!!
}


CurvParamHermite::CurvParamHermite ( Ponto p0, Ponto p1, Vetor dp0, Vetor dp1 )
    : CurvaParametrica ( p0, p1 ), DP0( dp0 ), DP1( dp1 )
{
    // 1. Preenche a matriz 'M' de 'CurvaParamétrica com a matriz de Hermite
    //
    //    M->setElement( 0, 0, 2 ); M->setElement( 0, 1,-2 ); M->setElement( 0, 2, 1 ); M->setElement( 0, 3, 1 );
    //    M->setElement( 1, 0,-3 ); M->setElement( 1, 1, 3 ); M->setElement( 1, 2,-2 ); M->setElement( 1, 3,-1 );
    //    M->setElement( 2, 0, 0 ); M->setElement( 2, 1, 0 ); M->setElement( 2, 2, 1 ); M->setElement( 2, 3, 0 );
    //    M->setElement( 3, 0, 1 ); M->setElement( 3, 1, 0 ); M->setElement( 3, 2, 0 ); M->setElement( 3, 3, 0 );
    M(0,0) = 2;  M(0,1) = -2; M(0,2) = 1;  M(0,3) = 1;
    M(1,0) = -3; M(1,1) = 3;  M(1,2) = -2; M(1,3) = -1;
    M(2,0) = 0;  M(2,1) = 0;  M(2,2) = 1;  M(2,3) = 0;
    M(3,0) = 1;  M(3,1) = 0;  M(3,2) = 0;  M(3,3) = 0;
    //
    // 2. Preenche as matrizes geométricas com G de Hermite
    //
    //    Gx->setElement( 0, 0, P0.x );
    //    Gx->setElement( 1, 0, P1.x );
    //    Gx->setElement( 2, 0,DP0.x );
    //    Gx->setElement( 3, 0,DP1.x );
    Gx(0,0) = P0.x;
    Gx(1,0) = P1.x;
    Gx(2,0) = DP0.x;
    Gx(3,0) = DP1.x;
    //    Gy->setElement( 0, 0, P0.y );
    //    Gy->setElement( 1, 0, P1.y );
    //    Gy->setElement( 2, 0,DP0.y );
    //    Gy->setElement( 3, 0,DP1.y );
    Gy(0,0) = P0.y;
    Gy(1,0) = P1.y;
    Gy(2,0) = DP0.y;
    Gy(3,0) = DP1.y;
    //    Gz->setElement( 0, 0, P0.z );
    //    Gz->setElement( 1, 0, P1.z );
    //    Gz->setElement( 2, 0,DP0.z );
    //    Gz->setElement( 3, 0,DP1.z );
    Gz(0,0) = P0.z;
    Gz(1,0) = P1.z;
    Gz(2,0) = DP0.z;
    Gz(3,0) = DP1.z;
    //

    this->Gx = this->getM() * this->getGx();
    this->Gy = this->getM() * this->getGy();
    this->Gz = this->getM() * this->getGz();

    // 3. Calcula o comprimento da curva
    //
    calcular_L ( );
    //
    ///////////////
}


CurvParamHermite::CurvParamHermite ( CurvParamHermite* antiga ) :
    CurvaParametrica ( antiga )
{
    this->DP0 = antiga->DP0;
    this->DP1 = antiga->DP1;
}

double CurvParamHermite::calcularCurvatura(double t)
{
    //B'(t)= 3(1-t)²(P1-P0)+6t(1-t)(P2-P1)+3t²(P3-P2)
    double v0 = 3*pow((1-t),2)*(DP0.x-P0.x)+6*t*(1-t)*(DP1.x-DP0.x)+3*pow(t,2)*(P1.x-DP1.x);
    double v1 = 3*pow((1-t),2)*(DP0.y-P0.y)+6*t*(1-t)*(DP1.y-DP0.y)+3*pow(t,2)*(P1.y-DP1.y);
    double v2 = 3*pow((1-t),2)*(P1.z-P0.z)+6*t*(1-t)*(DP1.z-DP0.z)+3*pow(t,2)*(P1.z-DP1.z);

    //B''(t)= 6(1-t)(P2-2P1+P0)+6t(P3-2P2+P1)
    double v00 = 6*(1-t)*(DP1.x-2*DP0.x+P0.x)+6*t*(P1.x-2*DP1.x+DP0.x);
    double v10 = 6*(1-t)*(DP1.y-2*DP0.y+P0.y)+6*t*(P1.y-2*DP1.y+DP0.y);
    double v20 = 6*(1-t)*(DP1.z-2*DP0.z+P0.z)+6*t*(P1.z-2*DP1.z+DP0.z);

    Vetor d1Vetor(v0,v1,v2);
    Vetor d2Vetor(v00,v10,v20);

    double k = ((d1Vetor.operator *(d2Vetor)).modulo())/(pow(d1Vetor.modulo(),3));

    return k;
}


CurvParamHermite::~CurvParamHermite (  )
{
}
