/* Classe que define um elemento
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Data/Elemento.h"

void Elemento::setId(unsigned long i) {
    this->id = i;
}

unsigned long Elemento::getId() {
    return this->id;
}

double Elemento::getArea() const {
    return this->area;
}

Vetor Elemento::getNormal() const {
    return this->normal;
}

Elemento::~Elemento() {

}
