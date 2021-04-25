/* Classe que define um patch de Coons
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../../Headers/Data/Patch/CoonsPatch.h"

void CoonsPatch::insereCurva ( Curva* c )
{
    this->curvas.push_back ( c );
}

Curva* CoonsPatch::getCurva ( const unsigned int i )
{
    // adicionar excessão caso i > curvas.size();
    /*list <Curva*>::iterator it = this->curvas.begin();

    advance ( it, i );

    return *it;*/

    return (i < this->curvas.size()) ? this->curvas[i] : NULL;
}

CoonsPatch::CoonsPatch() {

}

CoonsPatch::CoonsPatch(CoonsPatch *antigo) : Patch ( antigo ) {

}

CoonsPatch::CoonsPatch(vector<Curva *> listaDeCurvas) : curvas ( listaDeCurvas ) {

}

CoonsPatch::~CoonsPatch ( )
{
    // 1. apaga a lista de curvas
    this->curvas.clear ( );
}
