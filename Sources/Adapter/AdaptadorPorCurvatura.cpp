/* Classe encarregada de fazer a adaptação das malhas baseando-se nas curvaturas
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Adapter/AdaptadorPorCurvatura.h"

extern double TOLERANCIA;
extern double TOLERANCIA_AFT;
extern double TOLERANCIA_CURVATURA;
extern double PROPORCAO;
extern double SUAVIZACAO;
extern double FATOR_SUAVIZACAO;
extern double DISCRETIZACAO_CURVA;
extern double DISCRETIZACAO_INTER;

#if USE_OPENMP
list<Ponto *> AdaptadorPorCurvatura::adaptaCurvaByCurvaOmp(
    Curva *c, Performer::IdManager *idManager, double fator_dis) {
  double h_velho = 0;  // o tamanho velho de cada segmento
  double h_novo = 0;   // o tamanho novo de cada segmento
  double h_par = 0;    // tamanho paramétrico de cada segmento
  double t = 0;        // parametro correspondente ao ponto central do segmento
  double f =
      DISCRETIZACAO_CURVA;  // pow ( 2, exp ); // o fator de rediscretização
  double ka = 0;  // curvatura analítica do ponto central de um segmento
  double kd = 0;  // média das curvaturas discretas dos extremos de um segmento
  list<double> parametros;  // os parametros gerados na rediscretização
  list<Ponto *> pontos;     // os pontos da curva
  list<Ponto *>::iterator atual;
  list<Ponto *>::iterator proxi;
  Ponto C_seg;  // ponto médio do segmentos

  static_cast<CurvaParametrica *>(c)->ordenaLista();

  pontos = c->getPontos();
  atual = pontos.begin();
  proxi = pontos.begin();
  ++proxi;

  // 1.1. Inicialize a árvore binária com a raiz para toda a curva
  BinTree bt;

  // 1.2. Para cada segmento da curva
  while (proxi != pontos.end()) {
    // cout << "entrou no while" << endl;
    //  1.2.1. Calcule o comprimento do segmento e guarde em h_velho
    h_velho = c->calcularTamanho(*(*atual), *(*proxi));

    // cout << "tamanho do segmento de curva"<<h_velho<< endl;

    // cout << "calculou novo tamanho" << endl;

    // 1.2.2. Calcule o ponto médio do segmento
    C_seg =
        static_cast<CurvaParametrica *>(c)->pontoMedio(*(*atual), *(*proxi));
    C_seg.id = idManager->next(0);

    //        cout<<"Id atual:"<<(*atual)->getId()<<" Id
    //        proxi:"<<(*proxi)->getId()<<" C_seg:"<<C_seg.getId()<<endl;

    // 1.2.2.1 Encontre o parâmetro do ponto médio
    t = static_cast<CurvaParametrica *>(c)->encontrar_t(C_seg);
    //        cout<<"t:"<<t<<endl;

    // 1.2.3. Calcule as curvaturas analítica e discreta do ponto médio

    ka = c->calcularCurvatura(t);

    kd = (c->calcularCurvatura(0) + c->calcularCurvatura(1)) / 2.0;

    // 1.2.4. O novo tamanho é calculado de acordo com os cenários
    h_novo = novoTamanho(ka, kd, f, h_velho);

    // cout << "calculou novo tamanho" << endl;

    // 1.2.5. Calcule o tamanho paramétrico
    h_par = h_novo / c->get_L();

    bt.subdividir(t, h_par * fator_dis, (CurvaParametrica *)c);

    ++proxi;
    ++atual;
  }

  // transforma a bintree numa bintree restrita
  while (bt.restringir((CurvaParametrica *)c)) {
  }

  // 1.3. Atualiza a lista de pontos da curva de acordo com as folhas da
  // BinTree
  parametros = bt.rediscretizacao();
  ((CurvaParametrica *)c)->atualizarParametros(parametros);

  list<Ponto *> novosPontos;

  Noh *p1 = (Noh *)pontos.front();
  // p1->id = idManager->next(0);
  Noh *p2 = (Noh *)pontos.back();

  // p2->id = idManager->next(0);

  novosPontos.push_front(p1);

  for (list<double>::iterator it = ++parametros.begin();
       it != --parametros.end(); it++) {
    Noh *n = new Noh(((CurvaParametrica *)c)->parametrizar((*it)));
    n->id = idManager->next(0);
    novosPontos.push_back(n);
  }

  novosPontos.push_back(p2);

  return novosPontos;

  //    for (list<double>::iterator it = ++parametros.begin();
  //         it != --parametros.end(); it++)
  //    {
  //        Noh *n = new Noh(((CurvaParametrica *)c)->parametrizar((*it)));
  //        n->id = idManager->next(0);
  //        c->inserePonto(n);
  //    }

  //    return c;
}

list<Ponto *> AdaptadorPorCurvatura::adaptaCurvaBySuperficieOmp(
    Curva *c, Performer::IdManager *idManager, double fator_dis) {
  double h_velho = 0;  // o tamanho velho de cada segmento
  double h_novo = 0;   // o tamanho novo de cada segmento
  double h_par = 0;    // tamanho paramétrico de cada segmento
  double t = 0;        // parametro correspondente ao ponto central do segmento
  double f =
      DISCRETIZACAO_CURVA;  // pow ( 2, exp ); // o fator de rediscretização
  double ka = 0;  // curvatura analítica do ponto central de um segmento
  double kd = 0;  // média das curvaturas discretas dos extremos de um segmento
  list<double> parametros;  // os parametros gerados na rediscretização
  list<Ponto *> pontos;     // os pontos da curva
  list<Ponto *>::iterator atual;
  list<Ponto *>::iterator proxi;
  Ponto C_seg;  // ponto médio do segmentos

  static_cast<CurvaParametrica *>(c)->ordenaLista();

  pontos = c->getPontos();
  atual = pontos.begin();
  proxi = pontos.begin();
  ++proxi;

  // 1.1. Inicialize a árvore binária com a raiz para toda a curva
  BinTree bt;

  // 1.2. Para cada segmento da curva
  while (proxi != pontos.end()) {
    // 1.2.1. Calcule o comprimento do segmento e guarde em h_velho
    h_velho = c->calcularTamanho(*(*atual), *(*proxi));

    // cout << "tamanho do segmento de curva"<<h_velho<< endl;

    // cout << "calculou novo tamanho" << endl;

    // 1.2.2. Calcule o ponto médio do segmento
    C_seg = ((CurvaParametrica *)(c))->pontoMedio(*(*atual), *(*proxi));
    // C_seg.id = idManager->next(0);

    // Teste para curvatura com a curva
    // t = static_cast < CurvaParametrica* > ( c )->encontrar_t ( C_seg );
    // double k = c->calcularCurvatura(t);
    // cout << "curvatura  da curva = "<<k<<" com t = "<<t<< endl;

    // cout << "determinou o ponto médio" << endl;

    // 1.2.3. Calcule as curvaturas analítica e discreta do ponto médio
    CurvaturaAnalitica ka_p0(C_seg, *((CoonsPatch *)c->getPatch(0)));
    ka = ka_p0.gauss();

    if (c->getNumDePatches() == 1) {
      if (fabs(ka) < TOLERANCIA)  // testamos se ka é ZERO!
      {
        ka = ka_p0.media();
        kd = (((Noh *)(*atual))->Hd + ((Noh *)(*proxi))->Hd) / 2.0;
      } else {
        kd = (((Noh *)(*atual))->Gd + ((Noh *)(*proxi))->Gd) / 2.0;
      }
    } else {
      double Ha = ka_p0.media();

      for (unsigned int i = 1; i < c->getNumDePatches(); i++) {
        CurvaturaAnalitica ka_pi(C_seg, *((CoonsPatch *)c->getPatch(i)));
        double Ga_pi = ka_pi.gauss();

        ka = (fabs(ka) > fabs(Ga_pi)) ? ka : Ga_pi;

        if (fabs(ka) < TOLERANCIA)  // testamos se ka é ZERO!
        {
          double Ha_pi = ka_pi.media();

          ka = (Ha > Ha_pi) ? Ha : Ha_pi;
          kd = (((Noh *)(*atual))->Hd + ((Noh *)(*proxi))->Hd) / 2.0;
        } else {
          kd = (((Noh *)(*atual))->Gd + ((Noh *)(*proxi))->Gd) / 2.0;
        }
      }
    }

    // 1.2.4. O novo tamanho é calculado de acordo com os cenários
    h_novo = novoTamanho(ka, kd, f, h_velho);

    // 1.2.5. Calcule o tamanho paramétrico
    h_par = h_novo / c->get_L();

    // 1.2.6. Encontre o parâmetro do ponto médio
    t = static_cast<CurvaParametrica *>(c)->encontrar_t(C_seg);

    // cout << "encontrou t do ponto médio: " << t << endl;

    bt.subdividir(t, h_par * fator_dis, (CurvaParametrica *)c);

    // cout << "subdividiu a bintree" << endl;

    ++proxi;
    ++atual;
  }

  // transforma a bintree numa bintree restrita
  while (bt.restringir((CurvaParametrica *)c)) {
  }

  // 1.3. Atualiza a lista de pontos da curva de acordo com as folhas da
  // BinTree
  parametros = bt.rediscretizacao();
  ((CurvaParametrica *)c)->atualizarParametros(parametros);

  list<Ponto *> novosPontos;

  Noh *p1 = (Noh *)pontos.front();
  // p1->id = idManager->next(0);
  novosPontos.push_front(p1);

  for (list<double>::iterator it = ++parametros.begin();
       it != --parametros.end(); it++) {
    Noh *n = new Noh(((CurvaParametrica *)c)->parametrizar((*it)));
    n->id = idManager->next(0);
    novosPontos.push_back(n);
  }

  Noh *p2 = (Noh *)pontos.back();
  // p2->id = idManager->next(0);
  novosPontos.push_back(p2);

  return novosPontos;
}

SubMalha *AdaptadorPorCurvatura::adaptaDominioOmp(
    CoonsPatch *patch, Performer::IdManager *idManager, double fator_dis) {
  SubMalha *novaSub = new SubMalha;
  double fator =
      DISCRETIZACAO_INTER;  // pow ( 2, exp ); // o fator de rediscretização

  // avanço ( proporção do triângulo, tolerância, número de vezes o refinamento)
  AdvancingFront avanco(PROPORCAO, TOLERANCIA_AFT, SUAVIZACAO,
                        FATOR_SUAVIZACAO);
  map<Vertex *, Noh *> mapa;

  // 1. Para cada curva do patch
  for (unsigned int i = 0; i < patch->getNumDeCurvas(); ++i) {
    Curva *c = patch->getCurva(i);
    //((CurvaParametrica*)c)->ordenaLista ( );
    //#pragma omp critical
    //        {
    //            ((CurvaParametrica*)c)->ordenaLista ( );
    //        }

    if (i == 0 or i == 1) {
      list<double>::iterator ultimo = ((CurvaParametrica *)c)->parametros.end();
      --ultimo;

      int parametro = 0;

      for (list<double>::iterator it =
               ((CurvaParametrica *)c)->parametros.begin();
           it != ultimo; ++it) {
        Vertex *v;

        if (i == 0)
          v = avanco.getBoundary()->addVertex(*it, 0.0, (CurvaParametrica *)c);
        else if (i == 1)
          v = avanco.getBoundary()->addVertex(1.0, *it, (CurvaParametrica *)c);

        Noh *n = (Noh *)c->getPonto(parametro);

        mapa[v] = n;

        novaSub->insereNoh(n);

        parametro++;
      }
    } else if (i == 2 or i == 3) {
      list<double>::reverse_iterator ultimo =
          ((CurvaParametrica *)c)->parametros.rend();
      --ultimo;

      int parametro = ((CurvaParametrica *)c)->getNumDePontos() - 1;

      for (list<double>::reverse_iterator it =
               ((CurvaParametrica *)c)->parametros.rbegin();
           it != ultimo; ++it) {
        Vertex *v;

        if (i == 2)
          v = avanco.getBoundary()->addVertex(*it, 1.0, (CurvaParametrica *)c);
        else if (i == 3)
          v = avanco.getBoundary()->addVertex(0.0, *it, (CurvaParametrica *)c);

        Noh *n = (Noh *)c->getPonto(parametro);

        mapa[v] = n;

        novaSub->insereNoh(n);

        parametro--;
      }
    }
  }

  avanco.getBoundary()->close(
      (CurvaParametrica *)patch->getCurva(patch->getNumDeCurvas() - 1));

  SubMalha *sub = patch->getMalha();  // essa é a malha anterior!

  // constroi a lista de triangulos antigos para o gerador de malha
  FaceList oldMesh;

  double A_total = 0;  // área de todos os elementos

  for (unsigned int i = 0; i < sub->getNumDeElementos(); ++i) {
    Triangulo *tri = (Triangulo *)sub->getElemento(i);

    /*Noh centro (	( tri->getN ( 1 ).x + tri->getN ( 2 ).x + tri->getN ( 3 ).x
    ) / 3.0 , ( tri->getN ( 1 ).y + tri->getN ( 2 ).y + tri->getN ( 3 ).y  )
    / 3.0 , ( tri->getN ( 1 ).z + tri->getN ( 2 ).z + tri->getN ( 3 ).z  ) / 3.0
    ); tuple < double, double > centro_par = patch->encontrar_u_v ( centro );*/

    Vertex *v1 = new Vertex(get<0>(tri->p1), get<1>(tri->p1));
    Vertex *v2 = new Vertex(get<0>(tri->p2), get<1>(tri->p2));
    Vertex *v3 = new Vertex(get<0>(tri->p3), get<1>(tri->p3));
    // Vertex* c = new Vertex  ( get<0>( centro_par ), get<1>( centro_par ) );

    // cout << "APC.cpp: u = " << get<0>( centro_par ) << " v = " << get<1>(
    // centro_par ) << endl;

    Face *f = new Face(v1, v2, v3, tri->getId() /*, c*/);
    A_total += tri->getArea();

    oldMesh.push_back(f);
  }

  FaceList::iterator it = oldMesh.begin();

  for (unsigned int i = 0; i < sub->getNumDeElementos(); ++i) {
    double h_velho = 0;

    Triangulo *tri = (Triangulo *)sub->getElemento(i);
    Face *f = (*it);

    h_velho = sqrt(tri->getArea() / A_total);

    double h_novo = 0.0;
    double ka = 0.0;
    double kd = 0.0;

    if (fabs(tri->getN(1).Ga) >= TOLERANCIA and
        fabs(tri->getN(2).Ga) >= TOLERANCIA and
        fabs(tri->getN(3).Ga) >= TOLERANCIA) {
      ka = (tri->getN(1).Ga + tri->getN(2).Ga + tri->getN(3).Ga) / 3.0;
      kd = (tri->getN(1).Gd + tri->getN(2).Gd + tri->getN(3).Gd) / 3.0;
    } else {
      ka = (tri->getN(1).Ha + tri->getN(2).Ha + tri->getN(3).Ha) / 3.0;
      kd = (tri->getN(1).Hd + tri->getN(2).Hd + tri->getN(3).Hd) / 3.0;
    }

    h_novo = novoTamanho(ka, kd, fator, h_velho);

    /*if ( h_novo > h_velho )
        cout << "desrefina" << endl;
    else
        cout << "refina" << endl;*/

    f->h = h_novo * fator_dis;

    it++;
  }

  // FaceList emptyMesh;

  if (!avanco.execute(oldMesh)) {
    VertexList vertices = avanco.getVertices();

    while (!vertices.empty()) {
      vertices.pop_front();
    }

    EdgeList edges = avanco.getEdges();

    while (!edges.empty()) {
      edges.pop_front();
    }

    FaceList faces = avanco.getMesh();

    while (!faces.empty()) {
      faces.pop_front();
    }

    exit(0);
  }

  // pega os triangulos gerados pelo avanco de fronteira
  FaceList newMesh = avanco.getMesh();

  VertexList newVertices = avanco.getInnerVertices();

  while (!newVertices.empty()) {
    Vertex *v = newVertices.front();
    newVertices.pop_front();

    Noh *n = new Noh(patch->parametrizar(v->getX(), v->getY()));

    n->id = /*id_noh++*/ idManager->next(0);

    mapa[v] = n;
    novaSub->insereNoh(n);
  }

  // id_ele = 1;

  // gera os triangulos
  while (!newMesh.empty()) {
    Face *f = newMesh.front();
    newMesh.pop_front();

    Elemento *tri =
        new Triangulo((Noh *)mapa[f->getV1()], (Noh *)mapa[f->getV2()],
                      (Noh *)mapa[f->getV3()]);

    tri->setId(/*id_ele++*/ idManager->next(1));

    ((Triangulo *)tri)->p1 = make_tuple(f->getV1()->getX(), f->getV1()->getY());
    ((Triangulo *)tri)->p2 = make_tuple(f->getV2()->getX(), f->getV2()->getY());
    ((Triangulo *)tri)->p3 = make_tuple(f->getV3()->getX(), f->getV3()->getY());

    novaSub->insereElemento(tri);
  }

  // apaga os triangulos da malha antiga
  while (!oldMesh.empty()) {
    Face *f = oldMesh.front();
    oldMesh.pop_front();

    delete f;
  }

  return novaSub;
}
#endif  //#USE_OPENMP

list<Ponto *> AdaptadorPorCurvatura::adaptaCurvaByCurva(
    Curva *c, map<Ponto *, Ponto *> &mapaPontos,
    Performer::IdManager *idManager, double fator_dis) {
  // cout << "entrou no adaptaCurva" << endl;
  double h_velho = 0;  // o tamanho velho de cada segmento
  double h_novo = 0;   // o tamanho novo de cada segmento
  double h_par = 0;    // tamanho paramétrico de cada segmento
  double t = 0;        // parametro correspondente ao ponto central do segmento
  double f =
      DISCRETIZACAO_CURVA;  // pow ( 2, exp ); // o fator de rediscretização
  double ka = 0;  // curvatura analítica do ponto central de um segmento
  double kd = 0;  // média das curvaturas discretas dos extremos de um segmento
  list<double> parametros;  // os parametros gerados na rediscretização
  list<Ponto *> pontos;     // os pontos da curva
  list<Ponto *>::iterator atual;
  list<Ponto *>::iterator proxi;
  Ponto C_seg;  // ponto médio do segmentos

  static_cast<CurvaParametrica *>(c)->ordenaLista();

  pontos = c->getPontos();
  atual = pontos.begin();
  proxi = pontos.begin();
  ++proxi;

  // 1.1. Inicialize a árvore binária com a raiz para toda a curva
  BinTree bt;
  //#pragma omp parallel for num_threads(NUM_THREADS) firstprivate(atual,proxi)
  //shared(bt)
  //    // 1.2. Para cada segmento da curva
  //    for (int i = 0; i < pontos.size(); ++i)
  //    {
  //        // 1.2.1. Calcule o comprimento do segmento e guarde em h_velho
  //        h_velho = c->calcularTamanho ( *(*atual), *(*proxi) );

  //        // cout << "tamanho do segmento de curva"<<h_velho<< endl;

  //        //cout << "calculou novo tamanho" << endl;

  //        // 1.2.2. Calcule o ponto médio do segmento
  //        C_seg = static_cast < CurvaParametrica* > ( c )->pontoMedio (
  //        *(*atual), *(*proxi) );

  //        // 1.2.2.1 Encontre o parâmetro do ponto médio
  //        t = static_cast < CurvaParametrica* > ( c )->encontrar_t ( C_seg );

  //        // 1.2.3. Calcule as curvaturas analítica e discreta do ponto médio

  //        ka = c->calcularCurvatura(t);

  //        kd = (c->calcularCurvatura(0) + c->calcularCurvatura(1)) / 2.0;

  //        // 1.2.4. O novo tamanho é calculado de acordo com os cenários
  //        h_novo = novoTamanho ( ka, kd, f, h_velho );

  //        //cout << "calculou novo tamanho" << endl;

  //        // 1.2.5. Calcule o tamanho paramétrico
  //        h_par = h_novo / c->get_L ( );

  //        bt.subdividir( t, h_par*fator_dis, (CurvaParametrica*)c );

  //        ++proxi;
  //        ++atual;
  //    }

  // 1.2. Para cada segmento da curva
  while (proxi != pontos.end()) {
    // 1.2.1. Calcule o comprimento do segmento e guarde em h_velho
    h_velho = c->calcularTamanho(*(*atual), *(*proxi));

    // cout << "tamanho do segmento de curva"<<h_velho<< endl;

    // cout << "calculou novo tamanho" << endl;

    // 1.2.2. Calcule o ponto médio do segmento
    C_seg =
        static_cast<CurvaParametrica *>(c)->pontoMedio(*(*atual), *(*proxi));

    // 1.2.2.1 Encontre o parâmetro do ponto médio
    t = static_cast<CurvaParametrica *>(c)->encontrar_t(C_seg);

    // 1.2.3. Calcule as curvaturas analítica e discreta do ponto médio

    ka = c->calcularCurvatura(t);

    kd = (c->calcularCurvatura(0) + c->calcularCurvatura(1)) / 2.0;

    // 1.2.4. O novo tamanho é calculado de acordo com os cenários
    h_novo = novoTamanho(ka, kd, f, h_velho);

    // cout << "calculou novo tamanho" << endl;

    // 1.2.5. Calcule o tamanho paramétrico
    h_par = h_novo / c->get_L();

    bt.subdividir(t, h_par * fator_dis, (CurvaParametrica *)c);

    ++proxi;
    ++atual;
  }

  // transforma a bintree numa bintree restrita
  while (bt.restringir((CurvaParametrica *)c)) {
  }

  // 1.3. Atualiza a lista de pontos da curva de acordo com as folhas da
  // BinTree
  parametros = bt.rediscretizacao();
  ((CurvaParametrica *)c)->atualizarParametros(parametros);

  // cout << "discretização da curva: ";
  // for ( list < double >::iterator it = parametros.begin();
  // it!=parametros.end(); ++it ) cout << *it << " "; cout << endl;

  list<Ponto *> novosPontos;

  Noh *p1 = (Noh *)pontos.front();
  p1->id = idManager->next(0);
  Noh *p2 = (Noh *)pontos.back();
  p2->id = idManager->next(0);

  Noh *novoP1, *novoP2;

  map<Ponto *, Ponto *>::iterator it = mapaPontos.find(p1);

  if (it == mapaPontos.end()) {
    novoP1 = new Noh(*p1);
    novoP1->id = idManager->next(0);
    mapaPontos[p1] = novoP1;
  } else {
    novoP1 = (Noh *)mapaPontos[p1];
  }

  it = mapaPontos.find(p2);

  if (it == mapaPontos.end()) {
    novoP2 = new Noh(*p2);
    novoP2->id = idManager->next(0);
    mapaPontos[p2] = novoP2;
  } else {
    novoP2 = (Noh *)mapaPontos[p2];
  }

  for (list<double>::iterator it = ++parametros.begin();
       it != --parametros.end(); it++) {
    Noh *n = new Noh(((CurvaParametrica *)c)->parametrizar((*it)));
    n->id = idManager->next(0);
    novosPontos.push_back(n);
  }

  novosPontos.push_front(novoP1);
  novosPontos.push_back(novoP2);

  return novosPontos;
}

list<Ponto *> AdaptadorPorCurvatura::adaptaCurvaBySuperficie(
    Curva *c, map<Ponto *, Ponto *> &mapaPontos,
    Performer::IdManager *idManager, double fator_dis) {
  // cout << "entrou no adaptaCurva" << endl;
  double h_velho = 0;  // o tamanho velho de cada segmento
  double h_novo = 0;   // o tamanho novo de cada segmento
  double h_par = 0;    // tamanho paramétrico de cada segmento
  double t = 0;        // parametro correspondente ao ponto central do segmento
  double f =
      DISCRETIZACAO_CURVA;  // pow ( 2, exp ); // o fator de rediscretização
  double ka = 0;  // curvatura analítica do ponto central de um segmento
  double kd = 0;  // média das curvaturas discretas dos extremos de um segmento
  list<double> parametros;  // os parametros gerados na rediscretização
  list<Ponto *> pontos;     // os pontos da curva
  list<Ponto *>::iterator atual;
  list<Ponto *>::iterator proxi;
  Ponto C_seg;  // ponto médio do segmentos

  static_cast<CurvaParametrica *>(c)->ordenaLista();

  pontos = c->getPontos();
  atual = pontos.begin();
  proxi = pontos.begin();
  ++proxi;

  // 1.1. Inicialize a árvore binária com a raiz para toda a curva
  BinTree bt;

  // 1.2. Para cada segmento da curva
  while (proxi != pontos.end()) {
    // 1.2.1. Calcule o comprimento do segmento e guarde em h_velho
    h_velho = c->calcularTamanho(*(*atual), *(*proxi));

    // cout << "tamanho do segmento de curva"<<h_velho<< endl;

    // cout << "calculou novo tamanho" << endl;

    // 1.2.2. Calcule o ponto médio do segmento
    C_seg =
        static_cast<CurvaParametrica *>(c)->pontoMedio(*(*atual), *(*proxi));

    // Teste para curvatura com a curva
    t = static_cast<CurvaParametrica *>(c)->encontrar_t(C_seg);
    // double k = c->calcularCurvatura(t);
    // cout << "curvatura  da curva = "<<k<<" com t = "<<t<< endl;

    // cout << "determinou o ponto médio" << endl;

    // 1.2.3. Calcule as curvaturas analítica e discreta do ponto médio
    CurvaturaAnalitica ka_p0(C_seg, *((CoonsPatch *)c->getPatch(0)));

    for (unsigned int i = 0; i < c->getNumDePatches(); i++) {
      CurvaturaAnalitica ka_p1(C_seg, *((CoonsPatch *)c->getPatch(i)));
      double Ga_p0 = ka_p0.gauss();
      double Ga_p1 = ka_p1.gauss();

      ka = (fabs(Ga_p0) > fabs(Ga_p1)) ? Ga_p0 : Ga_p1;

      if (fabs(ka) < TOLERANCIA)  // testamos se ka é ZERO!
      {
        double Ha_p0 = ka_p0.media();
        double Ha_p1 = ka_p1.media();

        ka = (Ha_p0 > Ha_p1) ? Ha_p0 : Ha_p1;
        kd = (((Noh *)(*atual))->Hd + ((Noh *)(*proxi))->Hd) / 2.0;
      } else {
        kd = (((Noh *)(*atual))->Gd + ((Noh *)(*proxi))->Gd) / 2.0;
      }
    }

    // 1.2.4. O novo tamanho é calculado de acordo com os cenários
    h_novo = novoTamanho(ka, kd, f, h_velho);

    // 1.2.5. Calcule o tamanho paramétrico
    h_par = h_novo / c->get_L();

    // 1.2.6. Encontre o parâmetro do ponto médio
    t = static_cast<CurvaParametrica *>(c)->encontrar_t(C_seg);

    // cout << "encontrou t do ponto médio: " << t << endl;

    bt.subdividir(t, h_par * fator_dis, (CurvaParametrica *)c);

    // cout << "subdividiu a bintree" << endl;

    ++proxi;
    ++atual;
  }

  // transforma a bintree numa bintree restrita
  while (bt.restringir((CurvaParametrica *)c)) {
  }

  // 1.3. Atualiza a lista de pontos da curva de acordo com as folhas da
  // BinTree
  parametros = bt.rediscretizacao();
  ((CurvaParametrica *)c)->atualizarParametros(parametros);

  // cout << "discretização da curva: ";
  // for ( list < double >::iterator it = parametros.begin();
  // it!=parametros.end(); ++it ) cout << *it << " "; cout << endl;

  list<Ponto *> novosPontos;

  Noh *p1 = (Noh *)pontos.front();
  p1->id = idManager->next(0);
  Noh *p2 = (Noh *)pontos.back();
  p2->id = idManager->next(0);

  Noh *novoP1, *novoP2;

  map<Ponto *, Ponto *>::iterator it = mapaPontos.find(p1);

  if (it == mapaPontos.end()) {
    novoP1 = new Noh(*p1);
    novoP1->id = idManager->next(0);
    mapaPontos[p1] = novoP1;
  } else {
    novoP1 = (Noh *)mapaPontos[p1];
  }

  it = mapaPontos.find(p2);

  if (it == mapaPontos.end()) {
    novoP2 = new Noh(*p2);
    novoP2->id = idManager->next(0);
    mapaPontos[p2] = novoP2;
  } else {
    novoP2 = (Noh *)mapaPontos[p2];
  }

  for (list<double>::iterator it = ++parametros.begin();
       it != --parametros.end(); it++) {
    Noh *n = new Noh(((CurvaParametrica *)c)->parametrizar((*it)));
    n->id = idManager->next(0);
    novosPontos.push_back(n);
  }

  novosPontos.push_front(novoP1);
  novosPontos.push_back(novoP2);

  return novosPontos;
}

double AdaptadorPorCurvatura::novoTamanho(const double ka, const double kd,
                                          const double f,
                                          const double h_velho) {
  // Cenário 1 : ka está muito próxima a kd
  if (((ka - TOLERANCIA_CURVATURA) < kd) and
      (kd < (ka + TOLERANCIA_CURVATURA))) {
    if (fabs(ka) < TOLERANCIA_CURVATURA)  // está próximo ao plano, desrefine
      return h_velho * f;
    else  // a discretização reflete bem a superfície, não faça nada!
      return h_velho;
  }
  // Outros cenários : refine
  else {
    return h_velho / f;
  }
}

// Usa a QuadTree. Gera uma nova malha e atualiza a malha do patch. A malha
// gerada deve ser inserida no modelo pelo Gerador Adaptativo
SubMalha *AdaptadorPorCurvatura::adaptaDominio(CoonsPatch *patch,
                                               Performer::IdManager *idManager,
                                               double fator_dis) {
  SubMalha *novaSub = new SubMalha;
  double fator =
      DISCRETIZACAO_INTER;  // pow ( 2, exp ); // o fator de rediscretização

  // avanço ( proporção do triângulo, tolerância, número de vezes o refinamento)
  AdvancingFront avanco(PROPORCAO, TOLERANCIA_AFT, SUAVIZACAO,
                        FATOR_SUAVIZACAO);
  map<Vertex *, Noh *> mapa;

  // 1. Para cada curva do patch
  for (unsigned int i = 0; i < patch->getNumDeCurvas(); ++i) {
    Curva *c = patch->getCurva(i);
    ((CurvaParametrica *)c)->ordenaLista();

    if (i == 0 or i == 1) {
      list<double>::iterator ultimo = ((CurvaParametrica *)c)->parametros.end();
      --ultimo;

      int parametro = 0;

      for (list<double>::iterator it =
               ((CurvaParametrica *)c)->parametros.begin();
           it != ultimo; ++it) {
        Vertex *v;

        if (i == 0)
          v = avanco.getBoundary()->addVertex(*it, 0.0, (CurvaParametrica *)c);
        else if (i == 1)
          v = avanco.getBoundary()->addVertex(1.0, *it, (CurvaParametrica *)c);

        Noh *n = (Noh *)c->getPonto(parametro);

        mapa[v] = n;

        novaSub->insereNoh(n);

        parametro++;
      }
    } else if (i == 2 or i == 3) {
      list<double>::reverse_iterator ultimo =
          ((CurvaParametrica *)c)->parametros.rend();
      --ultimo;

      int parametro = ((CurvaParametrica *)c)->getNumDePontos() - 1;

      for (list<double>::reverse_iterator it =
               ((CurvaParametrica *)c)->parametros.rbegin();
           it != ultimo; ++it) {
        Vertex *v;

        if (i == 2)
          v = avanco.getBoundary()->addVertex(*it, 1.0, (CurvaParametrica *)c);
        else if (i == 3)
          v = avanco.getBoundary()->addVertex(0.0, *it, (CurvaParametrica *)c);

        Noh *n = (Noh *)c->getPonto(parametro);

        mapa[v] = n;

        novaSub->insereNoh(n);

        parametro--;
      }
    }
  }

  avanco.getBoundary()->close(
      (CurvaParametrica *)patch->getCurva(patch->getNumDeCurvas() - 1));

  SubMalha *sub = patch->getMalha();  // essa é a malha anterior!

  // constroi a lista de triangulos antigos para o gerador de malha
  FaceList oldMesh;

  double A_total = 0;  // área de todos os elementos

  for (unsigned int i = 0; i < sub->getNumDeElementos(); ++i) {
    Triangulo *tri = (Triangulo *)sub->getElemento(i);

    /*Noh centro (	( tri->getN ( 1 ).x + tri->getN ( 2 ).x + tri->getN ( 3 ).x
    ) / 3.0 , ( tri->getN ( 1 ).y + tri->getN ( 2 ).y + tri->getN ( 3 ).y  )
    / 3.0 , ( tri->getN ( 1 ).z + tri->getN ( 2 ).z + tri->getN ( 3 ).z  ) / 3.0
    ); tuple < double, double > centro_par = patch->encontrar_u_v ( centro );*/

    Vertex *v1 = new Vertex(get<0>(tri->p1), get<1>(tri->p1));
    Vertex *v2 = new Vertex(get<0>(tri->p2), get<1>(tri->p2));
    Vertex *v3 = new Vertex(get<0>(tri->p3), get<1>(tri->p3));
    // Vertex* c = new Vertex  ( get<0>( centro_par ), get<1>( centro_par ) );

    // cout << "APC.cpp: u = " << get<0>( centro_par ) << " v = " << get<1>(
    // centro_par ) << endl;

    Face *f = new Face(v1, v2, v3, tri->getId() /*, c*/);
    A_total += tri->getArea();

    oldMesh.push_back(f);
  }

  FaceList::iterator it = oldMesh.begin();

  for (unsigned int i = 0; i < sub->getNumDeElementos(); ++i) {
    double h_velho = 0;

    Triangulo *tri = (Triangulo *)sub->getElemento(i);
    Face *f = (*it);

    h_velho = sqrt(tri->getArea() / A_total);

    double h_novo = 0.0;
    double ka = 0.0;
    double kd = 0.0;

    if (fabs(tri->getN(1).Ga) >= TOLERANCIA and
        fabs(tri->getN(2).Ga) >= TOLERANCIA and
        fabs(tri->getN(3).Ga) >= TOLERANCIA) {
      ka = (tri->getN(1).Ga + tri->getN(2).Ga + tri->getN(3).Ga) / 3.0;
      kd = (tri->getN(1).Gd + tri->getN(2).Gd + tri->getN(3).Gd) / 3.0;
    } else {
      ka = (tri->getN(1).Ha + tri->getN(2).Ha + tri->getN(3).Ha) / 3.0;
      kd = (tri->getN(1).Hd + tri->getN(2).Hd + tri->getN(3).Hd) / 3.0;
    }

    h_novo = novoTamanho(ka, kd, fator, h_velho);

    /*if ( h_novo > h_velho )
        cout << "desrefina" << endl;
    else
        cout << "refina" << endl;*/

    f->h = h_novo * fator_dis;

    it++;
  }

  FaceList emptyMesh;
  if (!avanco.execute(oldMesh)) {
    VertexList vertices = avanco.getVertices();

    while (!vertices.empty()) {
      vertices.pop_front();
    }

    EdgeList edges = avanco.getEdges();

    while (!edges.empty()) {
      edges.pop_front();
    }

    FaceList faces = avanco.getMesh();

    while (!faces.empty()) {
      faces.pop_front();
    }

    exit(0);
  }

  // pega os triangulos gerados pelo avanco de fronteira
  FaceList newMesh = avanco.getMesh();

  VertexList newVertices = avanco.getInnerVertices();

  while (!newVertices.empty()) {
    Vertex *v = newVertices.front();
    newVertices.pop_front();

    Noh *n = new Noh(patch->parametrizar(v->getX(), v->getY()));

    n->id = idManager->next(0);

    mapa[v] = n;
    novaSub->insereNoh(n);
  }

  // id_ele = 1;

  // gera os triangulos
  while (!newMesh.empty()) {
    Face *f = newMesh.front();
    newMesh.pop_front();

    Elemento *tri =
        new Triangulo((Noh *)mapa[f->getV1()], (Noh *)mapa[f->getV2()],
                      (Noh *)mapa[f->getV3()]);

    tri->setId(idManager->next(1));

    ((Triangulo *)tri)->p1 = make_tuple(f->getV1()->getX(), f->getV1()->getY());
    ((Triangulo *)tri)->p2 = make_tuple(f->getV2()->getX(), f->getV2()->getY());
    ((Triangulo *)tri)->p3 = make_tuple(f->getV3()->getX(), f->getV3()->getY());

    novaSub->insereElemento(tri);
  }

  // apaga os triangulos da malha antiga
  while (!oldMesh.empty()) {
    Face *f = oldMesh.front();
    oldMesh.pop_front();

    delete f;
  }

  return novaSub;
}
