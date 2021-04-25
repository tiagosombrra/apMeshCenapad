/* Classe que define um modelo
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Data/Modelo.h"

void Modelo::setGeometria(Geometria *g) {
    this->geometria = g;
}

Geometria *Modelo::getGeometria() {
    return this->geometria;
}

void Modelo::insereMalha ( Malha* m )
{
    this->malhas.push_back ( m );
}

unsigned int Modelo::getNumDeMalhas() const {
    return ( int ) malhas.size();
}

Malha* Modelo::getMalha ( const unsigned int i )
{
    // adicionar excessão caso i > malhas.size();
    /*list <Malha*>::iterator it = this->malhas.begin();

    advance ( it, i );

    return *it;*/

    return (i < this->malhas.size()) ? this->malhas[i] : NULL;
}

Modelo::Modelo() {

}

Modelo::Modelo ( Geometria* g )
{
    this->geometria = g;
}

Modelo::~Modelo (  )
{	
    // 1. apaga a lista de malha
    while ( !this->malhas.empty ( ) )
    {
        Malha *M = this->malhas.back ( );
        this->malhas.pop_back ( );
        delete M;
    }

  //  cout<<"saida Modelo"<<endl;


}
