/* Classe que define uma curva paramétrica
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../../Headers/Data/Curve/CurvaParametrica.h"

extern double DELTA;       // distância entre um parâmetro e outro
extern double TOLERANCIA;  // distância máxima entre dois pontos

// calcula o comprimento de curva de p1 a p2
double CurvaParametrica::calcularTamanho(const Ponto& p1, const Ponto& p2) {
  double t1 = encontrar_t(p1);  // parâmetro do ponto p1
  double t2 = encontrar_t(p2);  // parâmetro do ponto p2

  //#pragma omp critical
  //    cout<<"t1 "<<t1<<" t2 "<<t2<<endl;

  if (t1 < t2) return comprimento(t1, t2);
  if (t1 > t2) return comprimento(t2, t1);

  return 0.0;
}

// calcula o comprimento de curva de P0 até p
double CurvaParametrica::calcularTamanho(const Ponto& p) {
  return comprimento(0.0, encontrar_t(p));
}

// calcula comprimento total "L" da curva
void CurvaParametrica::calcular_L() { this->L = comprimento(0.0, 1.0); }

double CurvaParametrica::calcularCurvatura(double) { return -1; }

double CurvaParametrica::comprimento(double t1, double t2, int parts,
                                     int points) {
  double total = 0.0, ui = 0.0, uf = t1;
  double partitionLength = (t2 - t1) / (double)parts;

  for (int k = 1; k <= parts; k++) {
    double localTotal = 0.0;

    ui = uf;
    uf = t1 + (double)k * partitionLength;

    for (int i = 0; i < points; i++) {
      double alfa = 0.0, weight = 0.0;

      switch (i) {
        case (0):
          switch (points) {
            case (2):
              alfa = -1.0 / sqrt(3.0);  // 2PTOS
              weight = 1.0;
              break;
            case (3):
              alfa = -0.774596669;  // 3PTOS
              weight = 5.0 / 9.0;
              break;
            case (4):
              alfa = -0.861136312;  // 4PTOS
              weight = 0.347854845;
              break;
            case (5):
              alfa = -0.9061798459;  // 5PTOS
              weight = 0.2369268850;
              break;
            case (6):
              alfa = -0.9324695142;  // 6PTOS
              weight = 0.1713244923;
              break;
            case (7):
              alfa = -0.9491079123;  // 7PTOS
              weight = 0.1294849661;
              break;
            case (8):
              alfa = -0.9602898564;  // 8PTOS
              weight = 0.1012285362;
              break;
          }
          break;
        case (1):
          switch (points) {
            case (2):
              alfa = 1.0 / sqrtf(3.0);  // 2PTOS
              weight = 1.0;
              break;
            case (3):
              alfa = 0.0;  // 3PTOS
              weight = 8.0 / 9.0;
              break;
            case (4):
              alfa = -0.339981043;  // 4PTOS
              weight = 0.652145155;
              break;
            case (5):
              alfa = -0.5384693101;  // 5PTOS
              weight = 0.4786286704;
              break;
            case (6):
              alfa = -0.6612093864;  // 6PTOS
              weight = 0.3607615730;
              break;
            case (7):
              alfa = -0.7415311855;  // 7PTOS
              weight = 0.2797053914;
              break;
            case (8):
              alfa = -0.7966664774;  // 8PTOS
              weight = 0.2223810344;
              break;
          }
          break;
        case (2):
          switch (points) {
            case (3):
              alfa = 0.774596669;  // 3PTOS
              weight = 5.0 / 9.0;
              break;
            case (4):
              alfa = 0.339981043;  // 4PTOS
              weight = 0.652145155;
              break;
            case (5):
              alfa = 0.0;  // 5PTOS
              weight = 0.5688888888;
              break;
            case (6):
              alfa = -0.2386191860;  // 6PTOS
              weight = 0.4679139345;
              break;
            case (7):
              alfa = -0.4058451513;  // 7PTOS
              weight = 0.3818300505;
              break;
            case (8):
              alfa = -0.5255324099;  // 8PTOS
              weight = 0.3137066458;
              break;
          }
          break;
        case (3):
          switch (points) {
            case (4):
              alfa = 0.861136312;  // 4PTOS
              weight = 0.347854845;
              break;
            case (5):
              alfa = 0.5384693101;  // 5PTOS
              weight = 0.4786286704;
              break;
            case (6):
              alfa = 0.2386191860;  // 6PTOS
              weight = 0.4679139345;
              break;
            case (7):
              alfa = 0.0;  // 7PTOS
              weight = 0.4179591836;
              break;
            case (8):
              alfa = -0.1834346424;  // 8PTOS
              weight = 0.3626837833;
              break;
          }
          break;
        case (4):
          switch (points) {
            case (5):
              alfa = 0.9061798459;  // 5PTOS
              weight = 0.2369268850;
              break;
            case (6):
              alfa = 0.6612093864;  // 6PTOS
              weight = 0.3607615730;
              break;
            case (7):
              alfa = 0.4058451513;  // 7PTOS
              weight = 0.3818300505;
              break;
            case (8):
              alfa = 0.1834346424;  // 8PTOS
              weight = 0.3626837833;
              break;
          }
          break;
        case (5):
          switch (points) {
            case (6):
              alfa = 0.9324695142;  // 6PTOS
              weight = 0.1713244923;
              break;
            case (7):
              alfa = 0.7415311855;  // 7PTOS
              weight = 0.2797053914;
              break;
            case (8):
              alfa = 0.5255324099;  // 8PTOS
              weight = 0.3137066458;
              break;
          }
          break;
        case (6):
          switch (points) {
            case (7):
              alfa = 0.9491079123;  // 7PTOS
              weight = 0.1294849661;
              break;
            case (8):
              alfa = 0.7966664774;  // 8PTOS
              weight = 0.2223810344;
              break;
          }
          break;
        case (7):
          alfa = 0.9602898564;  // 8PTOS
          weight = 0.1012285362;
          break;
      }

      double tOfAlfa = ((uf + ui) / 2.0) + ((uf - ui) / 2.0) * alfa;

      Vetor p = Qt(tOfAlfa);

      double f = p ^ p;

      localTotal += weight * sqrt(f);
    }

    localTotal *= (uf - ui) / 2.0;
    total += localTotal;
  }

  return total;
}

// calcula o comprimento de curva entre os parâmetros t1 e t2
double CurvaParametrica::comprimento(double t1, double t2) {
  /* A cada incremento de t,
     p recebe as coordenadas do ponto na curva correspondente
     a t; a distância entre p e o ponto anterior
     p_ant é calculada.

     Essa distância é somada a distância total d. */

  /*if ( t1 > t2 ) // caso t1 esteja à direita de t2 na curva
  {
      double aux = t1;
      t1 = t2;
      t2 = aux;
  }

  Ponto p; // ponto da iteração atual
  Ponto p_ant; // ponto da iteracao anterior

  double t = t1; // parâmetro de iteração
  double d = 0.0; // distância total entre os dois pontos

  // 1. cria Ponto 'p_ant'
  p_ant = this->parametrizar ( t1 );

  do
  {
      t += DELTA;

      // 2. cria Ponto 'p'
      p = this->parametrizar ( t );

      // incrementa distancia
      d += p_ant.distanciaPara ( p );

      // copia o conteudo de 'p' para o ponto anterior
      p_ant = p;
  }
  while ( t <= ( t2 - DELTA ) );

  return d;*/

  // encontrando o comprimento por gauss legendre
  return comprimento(t1, t2, 9, 4);
}

// encontra o parâmetro t de um dado ponto p na curva
double CurvaParametrica::encontrar_t(const Ponto& p) {
  //    // markos
  struct DistanceFunction : public Data::Numerical::EquationRootFunction {
    const Ponto* pt;
    CurvaParametrica* curva;

    double min() { return 0.0; };

    double max() { return 1.0; };

    using Data::Numerical::EquationRootFunction::f;

    double f(double t) {
      Ponto p = curva->parametrizar(t);

      return pt->distanciaPara(p);
    };
  };

  DistanceFunction f;

  f.curva = this;
  f.pt = &p;

  Data::Numerical::ClosestBisectionEquationRoot eqRoot;

  bool ok = true;

  double t = eqRoot.execute(&f, ok);

  return ok ? t : -1.0;

  //    // end markos

  //        long double d_min = 1.0e50; // distância mínima entre p e a curva
  //        long double di = 0; // distância do palpite até p
  //        long double t_min = 0.0; // parâmetro do pondo da curva mais próximo
  //        a p Ponto *pi = new Ponto; // ponto de palpite

  //        for ( long double t = 0.0; t <= 1.0; t += DELTA )
  //        {
  //            *pi = parametrizar ( t );
  //            di = pi->distanciaPara ( p );
  //            if ( di < d_min )
  //            {
  //                    d_min = di;
  //                    t_min = t;
  //            }
  //        }

  //        delete pi;

  //        return t_min;

  //	/* Método utilizando projeção vetorial, de forma
  //		semelhante ao método da bisseção. Quanto mais próximo
  //		p estiver dos extremos, menor será a precisão */

  //	double frp = DELTA; // fator de reposicionamento
  //	double tm = 0.5; // método da bisseção
  //	double delta_t = 0.0; // o quanto o parâmetro terá de percorrer
  //	double d_P0 = this->P0.distanciaPara ( p ); // distância de P0 a p
  //	double d_P1 = this->P1.distanciaPara ( p ); // distância de P1 a p

  //	// o ponto está muuuuito próximo de P0 ?
  //	if ( d_P0 <= DELTA )
  //		tm = 0.0; // retorna tm = 0.0

  //	// o ponto está muuuuito próximo de P1 ?
  //	if ( d_P1 <= DELTA )
  //		tm = 1.0; // retorna tm = 1.0

  //	Ponto Si;

  //	do
  //	{
  //		// 1. cria Si (modificou T)
  //		Si = this->parametrizar ( tm );

  //		// 2. cria Vj
  //		Vetor Vj ( Si, p );

  //		// 3. cria Tu (modificou T)
  //		Vetor Tu ( this->Qt ( tm ) );

  //		// 4. calcula a projecao de Vj em Tu
  //		delta_t = Vj ^ Tu;

  //		// 5. calcula 'tm' (este eh o ultimo valor de 'tm' calculado)
  //		tm += delta_t * frp;
  //	}
  //	while ( Si.distanciaPara ( p ) > TOLERANCIA );

  //	if ( tm < DELTA ) tm = 0.0; // t está muito próximo a 0
  //	else if ( tm > ( 1.0 - DELTA ) ) tm = 1.0; // t está muito próximo a 1

  //	return tm; // retorna o ultimo valor de 'tm' calculado
}

// faz as multiplicações necessárias para 'parametriar ( t )' e 'Qt ( t )'
Ponto CurvaParametrica::calculaPonto_t() {
  //  ALOCA um Ponto e retorna
  //

  Ponto C;

  // C = ( T * ( M * G ) )
  C.x = (this->getT() * (/*this->getM() * */ this->getGx()))(0, 0);
  C.y = (this->getT() * (/*this->getM() * */ this->getGy()))(0, 0);
  C.z = (this->getT() * (/*this->getM() * */ this->getGz()))(0, 0);

  return C;
}

// encontra as coordenadas 3D de um ponto p de parâmetro t
Ponto CurvaParametrica::parametrizar(double t) {
  // parametrizar:
  //
  //  -> ALTERA a matriz T
  //  -> usa calculaPonto_t
  //

  this->T(0, 0) = t * t * t;
  this->T(0, 1) = t * t;
  this->T(0, 2) = t;
  this->T(0, 3) = 1;

  return calculaPonto_t();
}

// calcula o vetor tangente no parâmetro t
Vetor CurvaParametrica::Qt(double t) {
  // Qt:
  //
  //  -> ALOCA um Ponto (mas destroi aqui mesmo)
  //	 -> ALOCA um Vetor (retorna ele)
  //  -> ALTERA a matriz T !!!
  //

  Ponto P;

  this->T(0, 0) = 3 * t * t;
  this->T(0, 1) = 2 * t;
  this->T(0, 2) = 1;
  this->T(0, 3) = 0;

  P = calculaPonto_t();
  Vetor V(P);

  return V;
}

double CurvaParametrica::pontoMedioBissecao(double t1, double t2) {
  double a = t1 < t2 ? t1 : t2;
  double b = t1 < t2 ? t2 : t1;
  double l = comprimento(a, b);
  double yA = l;   // l - 2.0*comprimento(a, a);
  double yB = -l;  // l - 2.0*comprimento(a, b);
  double half = 0.0;

  double newa = a;
  double newb = b;

  /*if (yA == 0.0)
      return a;
  if (yB == 0.0)
      return b;*/

  for (int i = 0; i < 5000; i++) {
    half = (newa + newb) / 2.0;

    if (fabs(newb - newa) < TOLERANCIA) {
      return half;
    } else {
      double yH = l - 2.0 * comprimento(a, half);

      if (fabs(yH) < TOLERANCIA) {
        // cout << "half = " << half << ", yH = " << yH << ", i = " << i <<
        // endl;

        return half;
      }

      if (yA * yH < 0.0) {
        newb = half;
        yB = yH;
      } else if (yB * yH < 0.0) {
        newa = half;
        yA = yH;
      }
    }
  }

  return -1.0;
}

Matrix4x1 CurvaParametrica::getGx() const { return this->Gx; }

Matrix4x1 CurvaParametrica::getGy() const { return this->Gy; }

Matrix4x1 CurvaParametrica::getGz() const { return this->Gz; }

Matrix4x4 CurvaParametrica::getM() const { return this->M; }

Matrix1x4 CurvaParametrica::getT() const { return this->T; }

Ponto CurvaParametrica::getP0() const { return this->P0; }

Ponto CurvaParametrica::getP1() const { return this->P1; }

void CurvaParametrica::setGx(Matrix4x1& G_x) { this->Gx = G_x; }

void CurvaParametrica::setGy(Matrix4x1& G_y) { this->Gy = G_y; }

void CurvaParametrica::setGz(Matrix4x1& G_z) { this->Gz = G_z; }

void CurvaParametrica::setM(Matrix4x4& M_) { this->M = M_; }

void CurvaParametrica::setT(Matrix1x4& T_) { this->T = T_; }

void CurvaParametrica::setP0(const Ponto& p) { this->P0 = p; }

void CurvaParametrica::setP1(const Ponto& p) {
  this->P1 = p;
  calcular_L();
}

void CurvaParametrica::setPontos(const Ponto& p0, const Ponto& p1) {
  this->P0 = p0;
  this->P1 = p1;
}

double CurvaParametrica::pontoMedio(double t_p1, double t_p2) {
  if (true) {
    return pontoMedioBissecao(t_p1, t_p2);
  }

  double L_total;  // tamanho total do segmento
  double L_medio;  // metade do comprimento do segmento
  double Li;       // comprimento da curva até palpite
  double t_medio;  // parâmetro do palpite inicial

  // 1. Calcule o comprimento do segmento
  L_total = this->comprimento(t_p1, t_p2);
  L_medio = L_total / 2.0;

  // 2. faz um palpite inicial
  //
  t_medio = (t_p1 + t_p2) / 2.0;

  // 3. p1 é menor que p2 ?
  //
  if (t_p1 < t_medio)  // p1 é "menor" que p2
    Li = comprimento(t_p1, t_medio);
  else if (t_p1 > t_medio)  // p1 é "maior" que p2
    Li = comprimento(t_p2, t_medio);
  else
    return t_p1;  // p1 e p2 são muito próximos ou iguais

  // 4. Li é maior que L/2 ?
  //
  //    -> Achar um parametro que dá o ponto aproximado
  //       na metade da curva
  //
  if (Li > L_medio) {
    while (Li >= L_medio)  // Li é maior que L_medio
    {
      Li -= comprimento(t_medio - DELTA, t_medio);
      t_medio -= DELTA;
    }
    t_medio += DELTA;
  } else {
    while (Li <= L_medio)  // Li é menor que L_medio
    {
      Li += comprimento(t_medio, t_medio + DELTA);
      t_medio += DELTA;
    }
    t_medio -= DELTA;
  }

  return t_medio;
}

// retorna o ponto que fica na metade de um segmento
Ponto CurvaParametrica::pontoMedio(const Ponto& p1, const Ponto& p2) {
  return this->parametrizar(
      this->pontoMedio(this->encontrar_t(p1), this->encontrar_t(p2)));
}

vector<CurvaParametrica*> ptr_aux;
#if USE_OPENMP
//#pragma omp threadprivate (ptr_aux)
#endif  // USE_OPENMP

bool compara(Ponto* a, Ponto* b) {
  double t_a, t_b;

  //#pragma omp critical
  //   cout<<&ptr_aux<<" "<<omp_get_thread_num()<<endl;

#if USE_OPENMP
  t_a = ptr_aux[omp_get_thread_num()]->encontrar_t(*a);
  t_b = ptr_aux[omp_get_thread_num()]->encontrar_t(*b);
#else
  t_a = ptr_aux[0]->encontrar_t(*a);
  t_b = ptr_aux[0]->encontrar_t(*b);
#endif  // USE_OPENMP

  return t_a < t_b;
}

// ordena a lista de pontos de acordo com suas coordenadas paramétricas
void CurvaParametrica::ordenaLista() {
//    list < Ponto* > & pts = this->getPontos();
//    ptr_aux = this;
//    pts.sort( compara );
//    return;
#if USE_OPENMP
  ptr_aux[omp_get_thread_num()] = this;
#else
  ptr_aux[0] = this;
#endif  // USE_OPENMP

  this->pontos.sort(compara);
}

void CurvaParametrica::atualizarParametros(list<double> novaLista) {
  this->parametros = novaLista;
}

CurvaParametrica::CurvaParametrica() {
  Gx.setZero(4, 1);
  Gy.setZero(4, 1);
  Gz.setZero(4, 1);
  M.setZero(4, 4);
  T.setZero(1, 4);
}

CurvaParametrica::CurvaParametrica(Ponto p0, Ponto p1) : P0(p0), P1(p1) {
  Gx.setZero(4, 1);
  Gy.setZero(4, 1);
  Gz.setZero(4, 1);
  M.setZero(4, 4);
  T.setZero(1, 4);
}

CurvaParametrica::CurvaParametrica(CurvaParametrica* antiga) : Curva(antiga) {
  this->P0 = antiga->P0;
  this->P1 = antiga->P1;
  this->Gx = antiga->Gx;
  this->Gy = antiga->Gy;
  this->Gz = antiga->Gz;
  this->M = antiga->M;
  this->T = antiga->T;
}

CurvaParametrica::~CurvaParametrica() {
  delete &Gx;
  delete &Gy;
  delete &Gz;
  delete &M;
  delete &T;
}
