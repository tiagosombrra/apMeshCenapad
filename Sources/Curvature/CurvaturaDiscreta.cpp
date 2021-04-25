/* Classe que define a curvatura discreta de um vértice
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Curvature/CurvaturaDiscreta.h"

// Kim, S. J., Jeong, W. K. e Kim, C. H. LOD generation with discrete curva-
// ture error metric. Em Proceedings of 2nd Korea Israel Bi-National Conference on
// Geometrical Modeling and Computer Graphics in the WWW Era (1999), pp. 97–104.

void CurvaturaDiscreta::ordenaAdjacencia ( const Noh& n )
{
    this->elementos.clear();

    // copiando os elementos da adjacência de n para a lista de elementos desta classe
    //		copie a lista n.guarda_cuva para nova_lista
    list < Elemento* > nova_lista;
    nova_lista = n.guarda_chuva;

   // Noh n1 = n;

    //		retire o primeiro elemento E da nova_lista e insira em elementos
    Elemento *E = nova_lista.front ( );
    this->elementos.push_back ( E );
    nova_lista.pop_front ( );

    //		enquanto encontrar um elemento adjacente à esquerda de E faça
    //			retire E' de nova_lista e insira ao final de elementos
    //			E recebe E'
    bool adjEsq = true; // encontrou um adjacente à esquerda

    while ( adjEsq )
    {
        Elemento *E_ = Adjacente::esquerdo ( n, E, nova_lista );
        if ( E_ )
        {
            this->elementos.push_back ( E_);
            E = E_;
        }
        else adjEsq = false;
    }

    //		se nova_lista não estiver vazia
    //			fator = M_PI ( n está na borda! )
    //			E recebe primeiro elemento da lista elementos ( sem retirar )
    //			enquanto encontrar um elemento adjacente à direita de E faça

    //				retire E' de nova_lista e insira no início de elementos
    //				E recebe E'
    if ( !nova_lista.empty ( ) )
    {
        this->fator = M_PI; // n está na borda !!!
        E = this->elementos.front ( );

        bool adjDir = true; // encontrou um adjacente à direita

        while ( adjDir )
        {
            Elemento *E_ = Adjacente::direito ( n, E, nova_lista );
            if ( E_ )
            {
                this->elementos.push_front ( E_);
                E = E_;
            }
            else adjDir = false;
        }
    }
    //		senão
    //			se o primeiro elemento P de elementos for adjacente ao último U
    //				fator = 2*M_PI ( n está no interior )
    //			senão
    //				fator = M_PI ( n está na borda )
    else
    {
        if ( Adjacente::confirmaDir (	n,	*( this->elementos.front ( ) ),
                                        *( this->elementos.back ( ) ) ) )
        {
            this->fator = 2*M_PI; // n está no interior !!!
            this->elementos.push_back ( this->elementos.front ( ) ); // lista "circular"
        }
        else
            this->fator = M_PI; // n está no interior !!!
    }
}


CurvaturaDiscreta::CurvaturaDiscreta ( const Noh& n )
{
    // O construtor ordena a lista de elementos do nó, por garantia...
    // para cada o elemento da lista de adjacências de n
    //		some sua área ao A deste objeto
    //		getAngulo ( n ) e some a sum_phi

    //	cout << "********** Curvatura discreta **********" << endl;

    //	cout << "ordenaAdjacência" << endl;

    this->ordenaAdjacencia ( n );

    this->A = 0;
    this->sum_phi = 0;

    list < Elemento* > :: const_iterator ite;

    //	cout << "for ( ite = n.guarda_chuva.begin ( ); ite != n.guarda_chuva.end ( ); ++ite )\n{" << endl;

    for ( ite = n.guarda_chuva.begin ( ); ite != n.guarda_chuva.end ( ); ++ite )
    {
        //		cout << "\tA += " << (*ite)->getArea( ) << endl;
        this->A += (*ite)->getArea( );
        //		cout << "\tA == " << this->A << endl;
        //		cout << "\tsum_phi += " << (*ite)->getAngulo ( n ) << endl;
        this->sum_phi += (*ite)->getAngulo ( n );
        //		cout << "\tsum_phi == " << this->sum_phi << endl;
    }

    this->p = n;

    //	cout << "******************************" << endl;
}

double CurvaturaDiscreta::media (  )
{
    Elemento* pri; // pri de PRImeiro elemento da lista 'elementos'
    Elemento* seg; // seg de SEGundo elemento da lista 'elementos'
    double gama = 0; // ângulo entre dois elementos adjacentes

    while ( this->elementos.size ( ) > 1 )
    {
        pri = this->elementos.front ( );
        this->elementos.pop_front ( );
        seg = this->elementos.front ( );

        short v; // v de Valor
        // verifica concavidade entre dois elementos adjacentes
        v = Adjacente::concavidade ( this->p, *pri, *seg );

        // retorna o ângulo entre dois elementos adjacentes
        if ( v ) gama += v * Adjacente::angulo ( *pri, *seg );
    }

    this->elementos.pop_front ( ); // esvazia a lista de elementos
    return 3.0 * gama / this->A;
}

double CurvaturaDiscreta::gauss (  )
{
    return (	3.0 * ( this->fator - this->sum_phi ) /  this->A  );
}
