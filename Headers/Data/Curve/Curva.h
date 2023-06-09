/* Classe que define uma curva
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Curva_h
#define Curva_h

#include <list>
#include <vector>
using namespace std;

#include "../Noh.h"
#include "../Patch/Patch.h"
#include "../Triangulo.h"

class Curva {
 protected:
  unsigned long Id;        // identificador da curva
  double L;                // comprimento total da curva
  list<Ponto*> pontos;     // será usada na discretização
  vector<Patch*> patches;  // uma curva só com um patch é de borda

 public:
  void setId(short i);
  double get_L() { return this->L; }

  // calcula o comprimento de curva de p1 a p2
  virtual double calcularTamanho(const Ponto&, const Ponto&);
  // calcula o comprimento de curva até p
  virtual double calcularTamanho(const Ponto&);
  // calcula o comprimento total "L" da curva
  virtual void calcular_L();
  // calcula a curvatuta da curva
  virtual double calcularCurvatura(double);

  void inserePonto(Ponto* p);
  unsigned int getNumDePontos() const;
  Ponto* getPonto(const unsigned int i);   // retorna o i-ésimo ponto
  void setPontos(list<Ponto*> novaLista);  // troca a lista de pontos
  void inserePatch(Patch* p);
  unsigned int getNumDePatches() const;
  Patch* getPatch(const unsigned int i);  // retorna o i-ésimo patch
  bool estaNaBorda();                     // verifica se uma curva é de borda
  list<Ponto*>& getPontos() { return this->pontos; }

  Curva();
  Curva(Curva*);
  virtual ~Curva();
};
#endif
