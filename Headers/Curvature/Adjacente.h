/* Classe que encontra um triângulo adjacente à direita ou esquerda
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Adjacente_h
#define Adjacente_h

#include <cmath>
#include <iostream>
#include <list>
using namespace std;

#include "../Data/Noh.h"
#include "../Data/Triangulo.h"

// OBS: Essa classe foi implementada para triâgulos !!!
class Adjacente {
  static bool confirmaEsq(const Noh& noh, const Elemento& P, const Elemento& U);
  static bool confirmaDir(const Noh& noh, const Elemento& P, const Elemento& U);
  static Elemento* esquerdo(const Noh& noh, Elemento* elem,
                            list<Elemento*>& lista);
  static Elemento* direito(const Noh& noh, Elemento* elem,
                           list<Elemento*>& lista);
  static short concavidade(const Noh& noh, const Elemento& pri,
                           const Elemento& seg);
  static double angulo(const Elemento& pri, const Elemento& seg);
  // virtual void naoFazNada ( ) = 0;

  friend class CurvaturaDiscreta;
};
#endif
