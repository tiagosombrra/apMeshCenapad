/* Classe que encontra um Elemento adjacente à direita ou esquerda
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Curvature/Adjacente.h"

extern double TOLERANCIA;

// P de Primeiro, U de Último !!! :D
// confirma que U é adjacente à esquerda de P
bool Adjacente::confirmaEsq(const Noh& noh, const Elemento& P,
                            const Elemento& U) {
  //	quem é o noh para P? ( n1, n2 ou n3? )
  //	se noh = P.n1 então verifique se U possui a sequência P.n1 P.n3

  if (noh == P.getN(1)) {
    if (((P.getN(1) == U.getN(1)) and (P.getN(3) == U.getN(2))) or

        ((P.getN(1) == U.getN(3)) and (P.getN(3) == U.getN(1))) or

        ((P.getN(1) == U.getN(2)) and (P.getN(3) == U.getN(3))))
      return true;
  }

  //	se noh = P.n2 então verifique se U possui a sequência P.n2 P.n1
  if (noh == P.getN(2)) {
    if (((P.getN(2) == U.getN(1)) and (P.getN(1) == U.getN(2))) or

        ((P.getN(2) == U.getN(3)) and (P.getN(1) == U.getN(1))) or

        ((P.getN(2) == U.getN(2)) and (P.getN(1) == U.getN(3))))
      return true;
  }

  //	se noh = P.n3 então verifique se U possui a sequência P.n3 P.n2
  if (noh == P.getN(3)) {
    if (((P.getN(3) == U.getN(1)) and (P.getN(2) == U.getN(2))) or

        ((P.getN(3) == U.getN(3)) and (P.getN(2) == U.getN(1))) or

        ((P.getN(3) == U.getN(2)) and (P.getN(2) == U.getN(3))))
      return true;
  }

  return false;
}

// confirma que U é adjacente à direita de P
bool Adjacente::confirmaDir(const Noh& noh, const Elemento& P,
                            const Elemento& U) {
  //	quem é o noh para P? ( n1, n2 ou n3? )
  //	se noh = P.n1 então verifique se U possui a sequência P.n2 P.n1
  if (noh == P.getN(1)) {
    if (((U.getN(1) == P.getN(1)) and (U.getN(3) == P.getN(2))) or

        ((U.getN(3) == P.getN(1)) and (U.getN(2) == P.getN(2))) or

        ((U.getN(2) == P.getN(1)) and (U.getN(1) == P.getN(2))))
      return true;
  }

  //	se noh = P.n2 então verifique se U possui a sequência P.n3 P.n2
  if (noh == P.getN(2)) {
    if (((U.getN(1) == P.getN(2)) and (U.getN(3) == P.getN(3))) or

        ((U.getN(3) == P.getN(2)) and (U.getN(2) == P.getN(3))) or

        ((U.getN(2) == P.getN(2)) and (U.getN(1) == P.getN(3))))
      return true;
  }

  //	se noh = P.n3 então verifique se U possui a sequência P.n1 P.n3
  if (noh == P.getN(3)) {
    if (((U.getN(1) == P.getN(3)) and (U.getN(3) == P.getN(1))) or

        ((U.getN(3) == P.getN(3)) and (U.getN(2) == P.getN(1))) or

        ((U.getN(2) == P.getN(3)) and (U.getN(1) == P.getN(1))))
      return true;
  }

  return false;
}

Elemento* Adjacente::esquerdo(const Noh& noh, Elemento* elem,
                              list<Elemento*>& lista) {
  Elemento* e = NULL;
  list<Elemento*>::iterator it;

  for (it = lista.begin(); it != lista.end(); ++it) {
    if (Adjacente::confirmaEsq(noh, *elem, *(*it))) {
      e = *it;
      lista.erase(it);
      break;
    }
  }

  return e;
}

// busca na lista um elemento adjacente à direita de elem
Elemento* Adjacente::direito(const Noh& noh, Elemento* elem,
                             list<Elemento*>& lista) {
  Elemento* e = NULL;
  list<Elemento*>::iterator it;

  for (it = lista.begin(); it != lista.end(); ++it) {
    if (Adjacente::confirmaDir(noh, *elem, *(*it))) {
      e = *it;
      lista.erase(it);
      break;
    }
  }

  return e;
}

// verifica a concavidade de dois elementos adjacentes
short Adjacente::concavidade(const Noh& noh, const Elemento& pri,
                             const Elemento& seg) {
  Vetor vet;

  if (noh == seg.getN(1))
    vet = Vetor(seg.getN(1), seg.getN(3));
  else if (noh == seg.getN(2))
    vet = Vetor(seg.getN(2), seg.getN(1));
  else
    vet = Vetor(seg.getN(3), seg.getN(2));

  double d;
  d = pri.getNormal() ^ vet;

  if (fabs(d) <= TOLERANCIA) return 0;

  if (d > 0)
    return -1;
  else
    return 1;
}

double Adjacente::angulo(const Elemento& pri, const Elemento& seg) {
  Vetor v1 = pri.getNormal();
  Vetor v2 = seg.getNormal();

  return v1.anguloCom(v2);
}
