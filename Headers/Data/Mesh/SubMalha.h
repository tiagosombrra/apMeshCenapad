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

#ifndef SubMalha_h
#define SubMalha_h

#include <iostream>
#include <vector>
#include "../Noh.h"
#include "../Elemento.h"
#include "../Definitions.h"
using namespace std;

class Noh;
class Elemento;
class Patch;

class SubMalha
{
    Patch* patch;
    vector <Noh*> nos;
    vector <Elemento*> elementos;

public :
    void setPatch ( Patch* p );
    Patch* getPatch (  ) const ;

    void insereNoh ( Noh* n );
    unsigned int getNumDeNos (  ) const { return ( unsigned int ) nos.size(); }
    Noh* getNoh ( const unsigned int i ); // retorna o i-ésimo nó

    void insereElemento (Elemento* elem);
    unsigned int getNumDeElementos (  ) const { return ( unsigned int ) elementos.size(); }
    Elemento* getElemento ( const unsigned int i ); // retorna o i-ésimo elemento

    ~SubMalha (  );
};

#endif
