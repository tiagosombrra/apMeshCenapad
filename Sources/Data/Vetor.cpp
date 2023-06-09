/* Classe que define um vetor
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Data/Vetor.h"

Vetor::Vetor() : x(0), y(0), z(0) {}

Vetor::Vetor(double c_x, double c_y, double c_z) : x(c_x), y(c_y), z(c_z) {}

Vetor::Vetor(const Vetor& v) : x(v.x), y(v.y), z(v.z) {}

Vetor::Vetor(const Ponto& p) : x(p.x), y(p.y), z(p.z) {}

Vetor::Vetor(const Ponto& p, const Ponto& q)
    : x(q.x - p.x), y(q.y - p.y), z(q.z - p.z) {}

Vetor Vetor::operator+(const Vetor& v) const {
  Vetor soma(this->x + v.x, this->y + v.y, this->z + v.z);

  return soma;
}

Vetor Vetor::operator-(const Vetor& v) const {
  Vetor subt(this->x - v.x, this->y - v.y, this->z - v.z);

  return subt;
}

Vetor Vetor::operator-() const {
  Vetor invr(-1 * this->x, -1 * this->y, -1 * this->z);

  return invr;
}

double Vetor::operator^(const Vetor& v) const {
  return (this->x * v.x + this->y * v.y + this->z * v.z);
}

Vetor Vetor::operator^(const double d) const {
  Vetor prod(d * this->x, d * this->y, d * this->z);
  return prod;
}

Vetor Vetor::operator*(const Vetor& v) const {
  Vetor prod(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z,
             this->x * v.y - this->y * v.x);

  return prod;
}

const Vetor& Vetor::operator=(const Vetor& v) {
  this->x = v.x;
  this->y = v.y;
  this->z = v.z;

  return *this;
}

const Vetor& Vetor::operator=(const Ponto& p) {
  this->x = p.x;
  this->y = p.y;
  this->z = p.z;

  return *this;
}

double Vetor::modulo() const {
  return (sqrt(this->x * this->x + this->y * this->y + this->z * this->z));
}

double Vetor::anguloCom(Vetor& v) const {
  Vetor c(this->x, this->y, this->z);

  double cos = static_cast<double>(c ^ v) / (c.modulo() * v.modulo());

  return (acos((cos > 1.0) ? 1.0 : ((cos < -1.0) ? -1.0 : cos)));
}

Vetor Vetor::unitario() {
  double modulo = this->modulo();

  Vetor N(static_cast<double>(this->x) / modulo,
          static_cast<double>(this->y) / modulo,
          static_cast<double>(this->z) / modulo);

  return N;
}
