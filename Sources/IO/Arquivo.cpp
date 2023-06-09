/* Classe para leitura de arquivo com a descrição geométrica da superfície
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/IO/Arquivo.h"

// ler as linhas que definem as curvas
void Arquivo::lerCurvas(const string leitura) {
  // "P" de P1 ou P2, os pontos inicial e final da curva
  // "D" de DP1 ou DP2, as derivadas nos pontos inicial e final
  if (leitura[0] == 'P' or leitura[0] == 'D') this->curvas.push_back(leitura);
}

// ler as linhas que definem os patches
void Arquivo::lerPatches(const string leitura) {
  // "D" de DEFINE_PATCH
  if (leitura[0] == 'D') this->patches.push_back(leitura);
}

// converta uma string em um char*, por causa do strtok() do C
char* Arquivo::convertaString(string fonte) {
  char* destino;

  destino = (char*)malloc(fonte.length() * sizeof(char));

  for (unsigned int i = 0; i < fonte.length(); ++i) destino[i] = fonte[i];

  return destino;
}

string Arquivo::getNome() { return nome; }

// criar as curvas
void Arquivo::criarCurvasPara(/*Modelo& modelo*/) {
  char* temp = NULL;
  char* str = NULL;
  double pt0[3];   // ponto inicial
  double pt1[3];   // ponto final
  double dpt0[3];  // derivada no ponto inicial
  double dpt1[3];  // derivada no ponto final

  list<string>::iterator itr = this->curvas.begin();
  list<string>::iterator fim = this->curvas.end();

  // leia quatro strings da list para definir uma curva
  while (itr != fim) {
    // lê o ponto inicial
    temp = convertaString(*itr);  // aloca temp em convertaString
    str = strtok(temp, " <");
    str = strtok(NULL, "<,");
    pt0[0] = atof(str);
    str = strtok(NULL, ",,");
    pt0[1] = atof(str);
    str = strtok(NULL, ",>");
    pt0[2] = atof(str);
    ++itr;

    delete temp;  // deleta o temp alocado em convertaString

    // lê o ponto final
    temp = convertaString(*itr);
    str = strtok(temp, " <");
    str = strtok(NULL, "<,");
    pt1[0] = atof(str);
    str = strtok(NULL, ",,");
    pt1[1] = atof(str);
    str = strtok(NULL, ",>");
    pt1[2] = atof(str);
    ++itr;

    delete temp;  // deleta o temp alocado em convertaString

    // lê a derivada no ponto inicial
    temp = convertaString(*itr);
    str = strtok(temp, " <");
    str = strtok(NULL, "<,");
    dpt0[0] = atof(str);
    str = strtok(NULL, ",,");
    dpt0[1] = atof(str);
    str = strtok(NULL, ",>");
    dpt0[2] = atof(str);
    ++itr;

    delete temp;  // deleta o temp alocado em convertaString

    // lê a derivada no ponto final
    temp = convertaString(*itr);
    str = strtok(temp, " <");
    str = strtok(NULL, "<,");
    dpt1[0] = atof(str);
    str = strtok(NULL, ",,");
    dpt1[1] = atof(str);
    str = strtok(NULL, ",>");
    dpt1[2] = atof(str);
    ++itr;

    delete temp;  // deleta o temp alocado em convertaString

    // substituir pelo construtor de curvas
    cout << "\nContrui uma curva com ponto inicial ( " << pt0[0] << ", "
         << pt0[1] << ", " << pt0[2] << ")\n"
         << "ponto final: (" << pt1[0] << ", " << pt1[1] << ", " << pt1[2]
         << ")\n"
         << "Derivada no ponto inicial: (" << dpt0[0] << ", " << dpt0[1] << ", "
         << dpt0[2] << ")\n"
         << "Derivada no ponto final: (" << dpt1[0] << ", " << dpt1[1] << ", "
         << dpt1[2] << ")" << endl;

  }  // fim do while

  delete str;
}

// criar os patches
void Arquivo::criarPatchesPara(/*Modelo& modelo*/) {
  char* temp = NULL;
  char* str = NULL;

  list<string>::iterator itr = this->patches.begin();
  list<string>::iterator fim = this->patches.end();

  while (itr != fim) {
    temp = convertaString(*itr);
    str = strtok(temp, " <");
    str = strtok(NULL, "<,");
    cout << str << endl;
    str = strtok(NULL, ",,");
    cout << str << endl;
    str = strtok(NULL, ",,");
    cout << str << endl;
    str = strtok(NULL, ",>");
    cout << str << endl;
    ++itr;

    delete temp;  // deleta o temp alocado em convertaString
  }               // fim do while

  delete str;
}

// ler um arquivo para definir um Modelo
void Arquivo::lerArquivoPara() {
  string linha;  // linha lida do arquivo

  string inicioDasCurvas = "CURVAS_HERMITE";   // inicio do bloco de curvas
  bool leiaCurvas = false;                     // pode ler uma linha de curva
  string fimDasCurvas = "FIM_CURVAS_HERMITE";  // fim do bloco de curvas

  string inicioDosPatches = "PATCHS_HERMITE";  // inicio do bloco de patches
  bool leiaPatches = false;                    // pode ler uma linha de patch
  string fimDosPatches = "FIM_DE_PATCHS_HERMITES";  // fim do bloco de patches

  while (entrada.good()) {
    getline(entrada, linha);  // pega uma linha do arquivo

    if (linha == inicioDasCurvas)  // começa a definição das curvas no arquivo
    {
      leiaCurvas = true;  // você pode ler as linhas e definir os pontos e suas
                          // derivadas das curvas
      continue;
    } else if (linha == fimDasCurvas)  // não há mais definições de curvas
    {
      leiaCurvas = false;  // pare de definir os pontos e derivadas
      continue;
    } else if (linha == "")  // ignore linhas em branco
      continue;
    else if (leiaCurvas)  // se está dentro de um bloco de definição de curvas
      lerCurvas(linha);   // leia a linha e forme uma curva
    else if (linha ==
             inicioDosPatches)  // começa a definição dos patches no arquivo
    {
      leiaPatches = true;  // você pode ler as linhas e definir os patches
      continue;
    } else if (linha == fimDosPatches)  // não há mais definições de patches
    {
      leiaPatches = false;  // pare de definir os patches
      break;
    } else if (leiaPatches)  // leia a linha e defina um patch
      lerPatches(linha);
  }  // fim do while
  criarCurvasPara();
  criarPatchesPara();
}

Arquivo::Arquivo(const char* nome) {
  this->entrada.open(nome);
  if (this->entrada.fail())
    cout << "não abriu o arquivo em disco!" << endl;
  else
    this->nome = nome;
}

Arquivo::~Arquivo() { this->entrada.close(); }
