/* Classe para leitura de um ponto
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Data/Ponto.h"

using namespace std;

Ponto::Ponto() {
  this->id = -1;
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

Ponto::Ponto(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

Ponto::Ponto(double _x, double _y, double _z, unsigned long i)
    : id(i), x(_x), y(_y), z(_z) {}

unsigned long Ponto::getId() const { return id; }

void Ponto::setId(unsigned long value) { id = value; }

bool Ponto::operator==(const Ponto& p) const {
  if ((fabs(this->x - p.x) <= 0.000001) and
      (fabs(this->y - p.y) <= 0.000001) and (fabs(this->z - p.z) <= 0.000001))
    return true;

  return false;
}

bool Ponto::operator==(const Ponto* p) const {
  if ((fabs(this->x - p->x) <= 0.000001) and
      (fabs(this->y - p->y) <= 0.000001) and (fabs(this->z - p->z) <= 0.000001))
    return true;

  return false;
}

double Ponto::distanciaPara(const Ponto& p) const {
  return (sqrt(pow((p.x - this->x), 2.0) + pow((p.y - this->y), 2.0) +
               pow((p.z - this->z), 2.0)));
}

void Ponto::mostraPonto() {
  cout << "Ponto " << this->id << " = ( " << this->x << ", " << this->y << ", "
       << this->z << ")" << endl;
}
