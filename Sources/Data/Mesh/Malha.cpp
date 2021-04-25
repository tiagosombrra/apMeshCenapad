/* Classe que define uma malha
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../../Headers/Data/Mesh/Malha.h"

void Malha::insereSubMalha (SubMalha* sub, Data::Int pos)
{
    this->subMalhas[pos] = sub;
}

void Malha::insereSubMalha ( SubMalha* sub )
{
    this->subMalhas.push_back ( sub );
}

void Malha::removeSubMalha()
{
    this->subMalhas.pop_back();
}

unsigned int Malha::getNumDeSubMalhas (  ) const
{
    return ( unsigned int ) this->subMalhas.size();
}


SubMalha* Malha::getSubMalha ( const unsigned int i )
{
    // adicionar excessão caso i > malhas.size();
    /*list <SubMalha*>::iterator it = this->subMalhas.begin();

    advance ( it, i );

    return *it;*/

    return (i < this->subMalhas.size()) ? this->subMalhas[i] : NULL;
}

void Malha::resizeSubmalha(Data::Int pos)
{
    this->subMalhas.resize(pos, NULL);
}

Malha::~Malha (  )
{
    // 1. apaga a lista de SubMalhas
    while ( !this->subMalhas.empty ( ) )
    {
        //SubMalha* SM = this->subMalhas.back ( );
        this->subMalhas.pop_back ( );
        //delete SM;
    }
}
