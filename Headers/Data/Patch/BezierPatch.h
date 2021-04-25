/* Classe que define um patch de Bezier
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da dissertação de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef BezierPatch_h
#define BezierPatch_h

#include "CoonsPatch.h"
#include "../../Data/Curve/CurvParamBezier.h"


// As curvas devem ser definidas da esquerda para a direita, de baixo para
// cima em relação ao Patch !!!

class BezierPatch : public CoonsPatch
{
public :

    // Pontos de controle
    Ponto Pt03;   Ponto Pt13;	Ponto Pt23;   Ponto Pt33;
    Ponto Pt02;   Ponto Pt12;	Ponto Pt22;   Ponto Pt32;
    Ponto Pt01;   Ponto Pt11;	Ponto Pt21;   Ponto Pt31;
    Ponto Pt00;   Ponto Pt10;	Ponto Pt20;   Ponto Pt30;

    Matrix1x4 U;  // matriz do parâmetro u
    Matrix4x4 Gx; // Matriz geométrica (x)
    Matrix4x4 Gy; // Matriz geométrica (y)
    Matrix4x4 Gz; // Matriz geométrica (z)
    Matrix4x1 V;  // matriz do parâmetro v
    Matrix4x4 B;  // matriz de Bezier

    Matrix1x4 getU  (  ) const;
    Matrix4x4 getGx (  ) const;
    Matrix4x4 getGy (  ) const;
    Matrix4x4 getGz (  ) const;
    Matrix4x1 getV  (  ) const;
    Matrix4x4 getB  (  ) const;

    Ponto calculaPonto_u_v ( ); // faz a multiplicação das matrizes

    Ponto getPt00 (  ) const;
    Ponto getPt01 (  ) const;
    Ponto getPt02 (  ) const;
    Ponto getPt03 (  ) const;

    Ponto getPt10 (  ) const;
    Ponto getPt11 (  ) const;
    Ponto getPt12 (  ) const;
    Ponto getPt13 (  ) const;

    Ponto getPt20 (  ) const;
    Ponto getPt21 (  ) const;
    Ponto getPt22 (  ) const;
    Ponto getPt23 (  ) const;

    Ponto getPt30 (  ) const;
    Ponto getPt31 (  ) const;
    Ponto getPt32 (  ) const;
    Ponto getPt33 (  ) const;

    void setPt00(Ponto value);
    void setPt01(Ponto value);
    void setPt02(Ponto value);
    void setPt03(Ponto value);

    void setPt10(Ponto value);
    void setPt11(Ponto value);
    void setPt12(Ponto value);
    void setPt13(Ponto value);

    void setPt20(Ponto value);
    void setPt21(Ponto value);
    void setPt22(Ponto value);
    void setPt23(Ponto value);

    void setPt30(Ponto value);
    void setPt31(Ponto value);
    void setPt32(Ponto value);
    void setPt33(Ponto value);

    bool sinal_c1;
    bool sinal_c2;
    bool sinal_c3;
    bool sinal_c4;

    void mostraMatrizes ( );

    // encontra as coordenadas parâmetricas u, v de um dado ponto p no patch,
    // ou a projeção desse ponto na superfície
    tuple < double, double > encontrar_u_v ( const Ponto& p );
    tuple < double, double > find_u_v ( const Ponto& p );


    // encontra o ponto p na curva dado um parâmetro p
    virtual Ponto parametrizar ( double u, double v );

    // calcula as derivadas parciais nas direçõe u e v
    virtual Vetor Qu  ( double u, double v );
    virtual Vetor Qv  ( double u, double v );
    virtual Vetor Quu ( double u, double v );
    virtual Vetor Quv ( double u, double v );
    virtual Vetor Qvu ( double u, double v );
    virtual Vetor Qvv ( double u, double v );

    // calcula as derivadas parciais de um ponto p
    virtual Vetor Qu  ( const Ponto& p );
    virtual Vetor Qv  ( const Ponto& p );
    virtual Vetor Quu ( const Ponto& p );
    virtual Vetor Quv ( const Ponto& p );
    virtual Vetor Qvu ( const Ponto& p );
    virtual Vetor Qvv ( const Ponto& p );

    // Ordem das curvas:
    //		C3
    //	C4		C2
    //		C1
    BezierPatch ( Curva* C1, Curva* C2, Curva* C3, Curva* C4,
                  Ponto Pt_11, Ponto Pt_21, Ponto Pt_12, Ponto Pt_22,
                  bool sinal_c1 = true,
                  bool sinal_c2 = true,
                  bool sinal_c3 = true,
                  bool sinal_c4 = true );

    BezierPatch (  Ponto Pt_00, Ponto Pt_01, Ponto Pt_02, Ponto Pt_03,
                   Ponto Pt_10, Ponto Pt_11, Ponto Pt_12, Ponto Pt_13,
                   Ponto Pt_20, Ponto Pt_21, Ponto Pt_22, Ponto Pt_23,
                   Ponto Pt_30, Ponto Pt_31, Ponto Pt_32, Ponto Pt_33,
                   bool sinal_c1 = true,
                   bool sinal_c2 = true,
                   bool sinal_c3 = true,
                   bool sinal_c4 = true );

    BezierPatch ( BezierPatch * );

    BezierPatch ();

    ~BezierPatch ( );

    //gets and sets para estimativa de carga
    double getArea() const;
    void setArea(double value);

    double getKaMedio() const;
    void setKaMedio(double value);

    double getSegmentMedio() const;
    void setSegmentMedio(double value);
    double getAreaTriangle() const;
    void setAreaTriangle(double value);
    double getNumberTriangle() const;
    void setNumberTriangle(double value);
    int getIdProcess() const;
    void setIdProcess(int value);
    int getId_bezierPatch() const;
    void setId_bezierPatch(int value);

    //variaveis para estimativa de carga
   double area;
   double kaMedio;
   double segmentMedio;
   double areaTriangle;
   double NumberTriangle;
   int idProcess;
   int id_bezierPatch;

};
#endif
