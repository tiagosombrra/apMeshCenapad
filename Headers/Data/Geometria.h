/* Classe que define uma geometria
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Geometria_h
#define Geometria_h

#include <map>
#include <vector>

#include "../Data/Curve/CurvParamBezier.h"
#include "../Data/Curve/Curva.h"
#include "../Data/Patch/HermitePatch.h"
using namespace std;

class Geometria {
  vector<Curva*> curvas;
  vector<Patch*> patches;

 public:
  void insereCurva(Curva* c);
  void insereCurva(Curva* c, int pos);
  unsigned int getNumDeCurvas() const;
  Curva* getCurva(const unsigned int i);  // retorna a i-ésima curva
  void inserePatch(Patch* p);
  void inserePatch(Patch* p, int pos);
  unsigned int getNumDePatches() const;
  Patch* getPatch(const unsigned int i);  // retorna o i-ésimo patch
  CurvParamBezier* verifyCurveGeometria(Ponto*, Ponto*, Ponto*, Ponto*);
  Geometria();
  Geometria(Geometria*);
  ~Geometria();
};
#endif
