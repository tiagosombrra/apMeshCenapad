/* Classe para leitura de arquivo
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../../Headers/Data/Tree/BinTree.h"

extern double TOLERANCIA;

// diz se uma célula é folha
bool BinTree::folha() {
  if (this->filhoEsq or this->filhoDir) return false;
  return true;
}

// diz se uma célula é a raiz
bool BinTree::raiz() {
  if (this->pai) return false;
  return true;
}

// retorna o tamanho da célula
double BinTree::get_tam() { return (this->tf - this->ti); }

bool BinTree::restringir(CurvaParametrica* curv) {
  if (!this->folha()) {
    return this->filhoEsq->restringir(curv);
  }

  if (!this->vizinhoDir) {
    return false;
  }

  if (this->vizinhoDir->nivel > this->nivel + 1) {
    this->subdividir(curv);

    this->filhoEsq->restringir(curv);

    return true;
  } else if (this->vizinhoDir->nivel < this->nivel - 1) {
    this->vizinhoDir->subdividir(curv);

    this->restringir(curv);

    return true;
  }

  return this->vizinhoDir->restringir(curv);
}

void BinTree::subdividir(CurvaParametrica* curv) {
  double novo_t;  // t que divide a curva ao meio
  novo_t = curv->pontoMedio(this->ti, this->tf);

  BinTree* esq = new BinTree(this->ti, novo_t, this);
  this->filhoEsq = esq;

  BinTree* dir = new BinTree(novo_t, this->tf, this);
  this->filhoDir = dir;

  this->filhoEsq->vizinhoEsq = this->vizinhoEsq;
  this->filhoEsq->vizinhoDir = this->filhoDir;

  this->filhoDir->vizinhoEsq = this->filhoEsq;
  this->filhoDir->vizinhoDir = this->vizinhoDir;

  if (this->vizinhoEsq) this->vizinhoEsq->vizinhoDir = this->filhoEsq;
  if (this->vizinhoDir) this->vizinhoDir->vizinhoEsq = this->filhoDir;
}

// subdivide uma célula e define suas duas células filhas
void BinTree::subdividir(double t, double t_par, CurvaParametrica* curv) {
  if (this->folha()) {
    if ((this->get_tam() - t_par) < TOLERANCIA) return;

    subdividir(curv);
  }

  double meio = curv->pontoMedio(this->ti, this->tf);

  if (t <= meio + TOLERANCIA) this->filhoEsq->subdividir(t, t_par, curv);

  if (t >= meio - TOLERANCIA) this->filhoDir->subdividir(t, t_par, curv);
}

// retorna uma célula que contém ti <= t <=tf
BinTree* BinTree::localiza(double t) {
  BinTree* cel = this;
  double meio = 0.0;

  while (!cel->folha()) {
    meio = 0.5 * cel->get_tam();
    if (t <= cel->ti + meio)
      cel = cel->filhoEsq;
    else
      cel = cel->filhoDir;
  }

  return cel;
}

// percorre a árvore em pré-ordem
void BinTree::percorre(BinTree* pt, list<double>& lista) {
  if (pt->folha()) {
    lista.push_back(pt->ti);
  }
  if (pt->filhoEsq) this->percorre(pt->filhoEsq, lista);
  if (pt->filhoDir) this->percorre(pt->filhoDir, lista);
}

// retorna as coordenadas das folhas
// essa lista deve ser usada pelo adaptador de curva para gerar a nova
// lista de pontos da curva rediscretizada
list<double> BinTree::rediscretizacao() {
  // essa lista deve ser usada pelo adaptador de curva para gerar a nova
  // lista de pontos da curva rediscretizada
  list<double> parametros;

  this->percorre(this, parametros);

  parametros.push_back(1.0);

  return parametros;
}

BinTree::BinTree(double t_i, double t_f, BinTree* p) {
  this->ti = t_i;
  this->tf = t_f;
  this->pai = p;
  if (p)
    this->nivel = p->nivel + 1;
  else
    this->nivel = 0;
  this->filhoEsq = this->filhoDir = NULL;
  this->vizinhoEsq = this->vizinhoDir = NULL;
}

BinTree::~BinTree() {
  if (this->filhoEsq) delete (this->filhoEsq);
  if (this->filhoDir) delete (this->filhoDir);
}
