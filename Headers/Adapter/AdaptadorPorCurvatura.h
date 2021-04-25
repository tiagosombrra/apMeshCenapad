/* Classe encarregada de fazer a adaptação das malhas baseando-se nas curvaturas
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef AdaptadorPorCurvatura_h
#define AdaptadorPorCurvatura_h

#include <cmath>
#include <map>
#include <cstdlib>

#include "Adaptador.h"
#include "../Data/Patch/CoonsPatch.h"
#include "../Data/Mesh/SubMalha.h"
#include "../Data/Curve/CurvaParametrica.h"
#include "../Curvature/CurvaturaAnalitica.h"
#include "../Curvature/CurvaturaDiscreta.h"
#include "../Data/Tree/BinTree.h"
#include "../Crabmesh/Aft/AdvancingFront.h"
#include "../Crabmesh/Aft/Boundary.h"
#include "../Data/Face.h"
#include "../Data/Vertex.h"
#include "../Data/Definitions.h"
#include "../Data/Edge.h"
#include "../Data/Face.h"
#include "../Parallel/TMCommunicator.h"
#include "../Crabmesh/Performer/RangedIdManager.h"

class AdaptadorPorCurvatura : public Adaptador
{
#if USE_OPENMP
    static list<Ponto*> adaptaCurvaByCurvaOmp (Curva*c, Performer::IdManager *idManager, double fator_dis = 1.0);
    static list<Ponto *> adaptaCurvaBySuperficieOmp(Curva*c, Performer::IdManager *idManager, double fator_dis = 1.0);
    static SubMalha* adaptaDominioOmp (CoonsPatch* patch, Performer::IdManager *idManager, double fator_dis = 1.0 );
#endif //#USE_OPENMP

    static list < Ponto* > adaptaCurvaByCurva (Curva*, map < Ponto*, Ponto* > &, Performer::IdManager *idManager, double fator_dis = 1.0 );
    static list < Ponto* > adaptaCurvaBySuperficie ( Curva* c,  map < Ponto*, Ponto* > &, Performer::IdManager *idManager, double fator_dis = 1.0 );

    static tuple <double, double> curvatura ( CurvaturaAnalitica& ka, CurvaturaDiscreta& kd );
    static double novoTamanho ( const double, const double, const double, const double );
    static void adaptaCurvas ( CoonsPatch& patch, const unsigned int );
    static SubMalha* adaptaDominio (CoonsPatch* patch, Performer::IdManager *idManager, double fator_dis = 1.0 );
    virtual void fazNada ()=0;

    friend class GeradorAdaptativoPorCurvatura;
};

#endif
