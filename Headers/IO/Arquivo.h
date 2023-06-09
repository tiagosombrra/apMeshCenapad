/* Classe para leitura do arquivo com a descrição geométrica da superfície
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#ifndef Arquivo_h
#define Arquivo_h

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "../Data/Modelo.h"

using namespace std;

class Arquivo {
  string nome;
  ifstream entrada;
  list<string> curvas;
  list<string> patches;

  void lerCurvas(const string leitura);   // lê todas as curvas do arquivo
  void lerPatches(const string leitura);  // lê todos os patches do arquivo
  void criarCurvasPara();                 // cria as curvas a partir da list
  void criarPatchesPara();                // cria os patches a partir da list
  char* convertaString(string fonte);

 public:
  string getNome();
  void lerArquivoPara(/*Modelo& modelo*/);
  Arquivo(const char* nome);
  ~Arquivo();
};
#endif
