/* Classe que define uma geometria
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Curvas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Data/Geometria.h"

void Geometria::insereCurva(Curva *c) { this->curvas.push_back(c); }

void Geometria::insereCurva(Curva *c, int pos) { this->curvas[pos] = c; }

unsigned int Geometria::getNumDeCurvas() const { return (int)curvas.size(); }

Curva *Geometria::getCurva(const unsigned int i) {
  // adicionar excessão caso i > curvas.size();
  /*list <Curva*>::iterator it = this->curvas.begin();

  advance ( it, i );

  return *it;*/
  return (i < this->curvas.size()) ? this->curvas[i] : NULL;
}

void Geometria::inserePatch(Patch *p) { this->patches.push_back(p); }

void Geometria::inserePatch(Patch *p, int pos) { this->patches[pos] = p; }

unsigned int Geometria::getNumDePatches() const { return (int)patches.size(); }

Patch *Geometria::getPatch(const unsigned int i) {
  return (i < this->patches.size()) ? this->patches[i] : NULL;
}

CurvParamBezier *Geometria::verifyCurveGeometria(Ponto *p0, Ponto *p1,
                                                 Ponto *p2, Ponto *p3) {
  for (vector<Curva *>::iterator it = this->curvas.begin();
       it != this->curvas.end(); it++) {
    if (static_cast<CurvParamBezier *>(*it)->getP0().operator==(p0) and
        static_cast<CurvParamBezier *>(*it)->getP1().operator==(p1) and
        static_cast<CurvParamBezier *>(*it)->getP2().operator==(p2) and
        static_cast<CurvParamBezier *>(*it)->getP3().operator==(p3)) {
      return static_cast<CurvParamBezier *>(*it);
    }
  }

  return NULL;
}

Geometria::Geometria() {}

Geometria::Geometria(Geometria *antiga) {
  map<Curva *, Curva *> mapaCurvas;
  map<Patch *, Patch *> mapaPatches;

  for (vector<Curva *>::iterator it = antiga->curvas.begin();
       it != antiga->curvas.end(); ++it) {
    Curva *c = new Curva((*it));

    mapaCurvas[(*it)] = c;
  }

  for (vector<Patch *>::iterator it = antiga->patches.begin();
       it != antiga->patches.end(); ++it) {
    Patch *p = new HermitePatch((HermitePatch *)(*it));

    for (unsigned int i = 0; i < ((HermitePatch *)(*it))->getNumDeCurvas();
         i++) {
      ((HermitePatch *)p)
          ->insereCurva(mapaCurvas[((HermitePatch *)(*it))->getCurva(i)]);
    }

    mapaPatches[(*it)] = p;
  }

  for (vector<Curva *>::iterator it = antiga->curvas.begin();
       it != antiga->curvas.end(); ++it) {
    for (unsigned int i = 0; i < (*it)->getNumDePatches(); i++) {
      mapaCurvas[(*it)]->inserePatch(mapaPatches[(*it)->getPatch(i)]);
    }
  }
}

Geometria::~Geometria() {
  // 1. apaga a lista de curvas
  while (!this->curvas.empty()) {
    Curva *C = this->curvas.back();
    this->curvas.pop_back();
    delete C;
  }

  // 3. apaga a lista de patches
  while (!this->patches.empty()) {
    Patch *P = this->patches.back();
    this->patches.pop_back();
    delete P;
  }
}
