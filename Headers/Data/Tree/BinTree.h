/* Classe para leitura de arquivo
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef BinTree_h
#define BinTree_h

#include <tuple>
#include <iostream>
#include <list>
#include "../Curve/CurvaParametrica.h"

using namespace std;


struct BinTree
{
    unsigned short nivel; // nível d
    double	ti; // coordenada paramétrica do início da célula
    double	tf; // coordenada paramétrica do final da célula

    BinTree* pai;
    BinTree* filhoDir;
    BinTree* filhoEsq;
    BinTree* vizinhoEsq;
    BinTree* vizinhoDir;

    bool folha ( ); // diz se uma célula é folha
    bool raiz ( ); // diz se uma célula é a raiz
    double get_tam ( ); // retorna o tamanho da célula
    bool restringir ( CurvaParametrica *curv );
    void subdividir ( CurvaParametrica *curv );
    void subdividir ( double t, double t_par, CurvaParametrica *curv ); // subdivide uma célula e define suas duas células filhas
    BinTree* localiza ( double t ); // retorna uma célula que contém ti <= t <=tf
    void percorre ( BinTree* pt, list < double > & lista );
    list < double > rediscretizacao ( ); // retorna as coordenadas das folhas

    BinTree ( double t_i = 0.0, double t_f = 1.0, BinTree* p = NULL );
    ~BinTree ( );
};
#endif
