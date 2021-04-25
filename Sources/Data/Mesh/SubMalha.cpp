/* Classe que define uma sub-malha
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */


#include "../../../Headers/Data/Mesh/SubMalha.h"

void SubMalha::setPatch ( Patch* m )
{
    this->patch = m;
}


Patch* SubMalha::getPatch (  ) const
{
    return this->patch;
}

void SubMalha::insereNoh ( Noh* n )
{
    this->nos.push_back ( n );
}

Noh* SubMalha::getNoh ( const unsigned int i )
{
    /*// adicionar excessão caso i > nos.size();
    list <Noh*>::iterator it = this->nos.begin();

    advance ( it, i );

    return *it;*/
    return (i < this->nos.size()) ? this->nos[i] : NULL;
}

void SubMalha::insereElemento (Elemento* elem)
{
//    if (position > this->elementos.size()) {
//        this->elementos.resize(position,NULL);
//    }
//    this->elementos.insert(this->elementos.begin()+position, elem);
    this->elementos.push_back ( elem );
}

Elemento* SubMalha::getElemento ( const unsigned int i )
{
    // adicionar excessão caso i > elementos.size();
    /*list <Elemento*>::iterator it = this->elementos.begin();

    advance ( it, i );

    return *it;*/
    return (i < this->elementos.size()) ? this->elementos[i] : NULL;
}

SubMalha::~SubMalha (  )
{
    // 1. apaga a lista de nós
    while ( !this->nos.empty ( ) )
    {
        Noh* N = this->nos.back ( );
        this->nos.pop_back ( );
        delete N;
    }

    // 2. apaga a lista de elementos
    while ( !this->elementos.empty ( ) )
    {
        Elemento* E = this->elementos.back ( );
        this->elementos.pop_back ( );
        delete E;
    }

}
