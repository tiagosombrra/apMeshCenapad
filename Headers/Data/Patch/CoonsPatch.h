/* Classe que define um patch de Coons
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef CoonsPatch_h
#define CoonsPatch_h

#include <cstdlib>
#include <vector>
#include <tuple>
#include "Patch.h"
#include "../Curve/Curva.h"
#include "../Vetor.h"
#include "../../Data/Definitions.h"
#include "../Ponto.h"

using namespace std;

class CoonsPatch : public Patch
{
protected:
    vector <Curva*> curvas;

public :
    void insereCurva (Curva* c);
    unsigned int getNumDeCurvas ( ) const { return ( int ) curvas.size(); }
    Curva* getCurva (const unsigned int i); // retorna a i-ésima curva

    // encontra as coordenadas parâmetricas u, v de um dado ponto p no patch,
    // ou a projeção desse ponto na superfície
    virtual tuple < double, double > encontrar_u_v ( const Ponto& p ) = 0;
    virtual tuple < double, double > find_u_v ( const Ponto& p ) = 0;


    // encontra o ponto p na curva dado um parâmetro p
    virtual Ponto parametrizar ( double u, double v ) = 0;

    // calcula as derivadas parciais nas direçõe u e v
    virtual Vetor Qu  ( double u, double v ) = 0;
    virtual Vetor Qv  ( double u, double v ) = 0;
    virtual Vetor Quu ( double u, double v ) = 0;
    virtual Vetor Quv ( double u, double v ) = 0;
    virtual Vetor Qvu ( double u, double v ) = 0;
    virtual Vetor Qvv ( double u, double v ) = 0;

    // calcula as derivadas parciais de um ponto p
    virtual Vetor Qu  ( const Ponto& p ) = 0;
    virtual Vetor Qv  ( const Ponto& p ) = 0;
    virtual Vetor Quu ( const Ponto& p ) = 0;
    virtual Vetor Quv ( const Ponto& p ) = 0;
    virtual Vetor Qvu ( const Ponto& p ) = 0;
    virtual Vetor Qvv ( const Ponto& p ) = 0;

    CoonsPatch ( );
    CoonsPatch ( CoonsPatch * antigo);
    CoonsPatch ( vector <Curva*> listaDeCurvas );
    virtual ~CoonsPatch ( );
};

#endif
