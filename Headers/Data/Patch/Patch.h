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

#ifndef Patch_h
#define Patch_h

#include "../../Data/Mesh/SubMalha.h"

//class SubMalha;

class Patch
{
protected :
    SubMalha* malha;

public :
    unsigned long id;
    void setMalha ( SubMalha* m );
    SubMalha* getMalha (  ) const ;

    Patch  ( );
    Patch ( Patch * );
    ~Patch ( );
    unsigned long getId() const;
    void setId(unsigned long value);
};

#endif
