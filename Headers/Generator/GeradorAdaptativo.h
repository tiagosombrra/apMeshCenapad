/* Classe encarregada de fazer a geração adaptativa das malhas
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef GeradorAdaptativo_h
#define GeradorAdaptativo_h

#include "Gerador.h"

class GeradorAdaptativo : public Gerador
{
protected :
    virtual SubMalha* malhaInicial ( );
    virtual double erroGlobal ( );

public :
    GeradorAdaptativo (  );
    //GeradorAdaptativo ( Modelo& modelo );
};

#endif
