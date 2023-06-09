/* Classe que define um triangulo
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Data/Triangulo.h"

extern double TOLERANCIA;

Triangulo::Triangulo(Noh* v1, Noh* v2, Noh* v3) {
  this->n1 = v1;
  this->n2 = v2;
  this->n3 = v3;

  this->n1->insereElemento(this);
  this->n2->insereElemento(this);
  this->n3->insereElemento(this);

  this->angN1 = setAnguloN1();
  this->angN2 = setAnguloN2();
  this->angN3 = setAnguloN3();

  calcularNormal();
  calcularArea();
}

Triangulo::~Triangulo() {}

// retorna o i-ésimo nó
Noh Triangulo::getN(unsigned const int i) const {
  if (i == 1)
    return *(this->n1);
  else if (i == 2)
    return *(this->n2);
  else if (i == 3)
    return *(this->n3);
  else
    cout << "Índice inválido para Noh Triangulo::getN ( " << i << " )!" << endl;

  Noh* n = NULL;

  return *n;
}

// calcula o ângulo no nó 1
double Triangulo::setAnguloN1() {
  Vetor vet_1(*(this->n1), *(this->n2));
  Vetor vet_2(*(this->n1), *(this->n3));

  return vet_1.anguloCom(vet_2);
}

// calcula o ângulo no nó 2
double Triangulo::setAnguloN2() {
  Vetor vet_1(*(this->n2), *(this->n3));
  Vetor vet_2(*(this->n2), *(this->n1));

  return vet_1.anguloCom(vet_2);
}

// calcula o ângulo no nó 3
double Triangulo::setAnguloN3() {
  Vetor vet_1(*(this->n3), *(this->n1));
  Vetor vet_2(*(this->n3), *(this->n2));

  return vet_1.anguloCom(vet_2);
}

// retorna o ângulo do nó n
double Triangulo::getAngulo(const Noh& n) {
  if (this->n1->distanciaPara(n) <= TOLERANCIA) return this->angN1;

  if (this->n2->distanciaPara(n) <= TOLERANCIA) return this->angN2;

  if (this->n3->distanciaPara(n) <= TOLERANCIA) return this->angN3;

  return -1;  // erro
}

// calcula a área do triângulo
void Triangulo::calcularArea() { this->area = 0.5 * (this->normal.modulo()); }

// calcula a normal do triângulo
void Triangulo::calcularNormal() {
  Vetor vet_1(*(this->n1), *(this->n2));
  Vetor vet_2(*(this->n1), *(this->n3));

  this->normal = vet_1 * vet_2;
}

void Triangulo::substituir(Noh* velho, Noh* novo) {
  if (this->n1 == velho)
    this->n1 = novo;
  else if (this->n2 == velho)
    this->n2 = novo;
  else if (this->n3 == velho)
    this->n3 = novo;
}
