/* Classe que define um patch
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../../Headers/Data/Patch/Patch.h"

unsigned long Patch::getId() const { return id; }

void Patch::setId(unsigned long value) { id = value; }

void Patch::setMalha(SubMalha* m) { this->malha = m; }

SubMalha* Patch::getMalha() const { return this->malha; }

Patch::Patch() { this->malha = NULL; }

Patch::Patch(Patch*) { this->malha = NULL; }

Patch::~Patch() {
  // não delete o que não for alocado com new!
  if (this->malha != NULL) delete this->malha;
}
