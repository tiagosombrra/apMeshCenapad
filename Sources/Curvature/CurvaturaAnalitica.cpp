/* Classe que define a curvatura analitica de um vértice
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da tese de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../Headers/Curvature/CurvaturaAnalitica.h"
extern double TOLERANCIA;

// Dill, J. C. (1981). An Application of Color Graphics to the Display of
// Surface Curvature. Comp. Graph., Vol. 15, pag. 153-161. SIGGRAPH 81.

CurvaturaAnalitica::CurvaturaAnalitica(const Ponto& v, CoonsPatch& p) {
  tuple<double, double> t = p.find_u_v(v);

  this->Qu = p.Qu(get<0>(t), get<1>(t));
  this->Qv = p.Qv(get<0>(t), get<1>(t));
  this->Quu = p.Quu(get<0>(t), get<1>(t));
  this->Quv = p.Quv(get<0>(t), get<1>(t));
  this->Qvv = p.Qvv(get<0>(t), get<1>(t));
  // Vetor * Vetor -> produto vetorial
  this->prod = Qu * Qv;

  //#pragma omp critical
  //    {
  //        if (std::isnan(get < 0 > ( t )) || std::isnan(get < 1 > ( t ))) {
  //            cout<<"-nan t"<<endl;
  //        }
  //        cout << "=========================================================="
  //        << endl; cout << "P - " << v.id << ": ( " << get < 0 > ( t ) << ", "
  //        << get < 1 > ( t ) << ")" << endl; cout << "Qu ( " << Qu.x << ", "
  //        << Qu.y << ", " << Qu.z << " )" << endl; cout << "Qv ( " << Qv.x <<
  //        ", " << Qv.y << ", " << Qv.z << " )" << endl; cout << "Quu ( " <<
  //        Quu.x << ", " << Quu.y << ", " << Quu.z << " )" << endl; cout <<
  //        "Quv ( " << Quv.x << ", " << Quv.y << ", " << Quv.z << " )" << endl;
  //        cout << "Qvv ( " << Qvv.x << ", " << Qvv.y << ", " << Qvv.z << " )"
  //        << endl; if ( 0 == prod.modulo() )
  //            cout << "Qu X Qv = 0 no ponto p" << v.id << " (" << v.x << ", "
  //            << v.y << ", " << v.z << ")" << endl;
  //    }
  // Vetor ^ Vetor -> produto escalar
  this->A = prod ^ Quu;
  this->B = prod ^ Quv;
  this->C = prod ^ Qvv;

  //	cout << "A = " << this->A << endl;
  //	cout << "B = " << this->B << endl;
  //	cout << "C = " << this->C << endl;
}

double CurvaturaAnalitica::media() {
  // Vetor ^ Vetor -> produto escalar
  if (prod.modulo() <= TOLERANCIA) return 0.0;  // regra de L'Hôpital

  // H = ( A.|Qv|² - 2.B.Qu.Qv + C.|Qu|² ) / ( 2.| Qu x Qv |³ )
  double resultado =
      (static_cast<double>(A * Qv.modulo() * Qv.modulo() - 2 * B * (Qu ^ Qv) +
                           C * Qu.modulo() * Qu.modulo()) /
       (2 * pow(prod.modulo(), 3)));

  // cout << "Ha = " << resultado << endl;
  // cout << "==========================================================" <<
  // endl;

  return (fabs(resultado) <= TOLERANCIA) ? 0.0 : resultado;
}

double CurvaturaAnalitica::gauss() {
  if (prod.modulo() <= TOLERANCIA) return 0.0;  // regra de L'Hôpital

  // K = ( A.C - B² ) / | Qu x Qv |⁴
  double resultado =
      static_cast<double>(this->A * this->C - (this->B * this->B)) /
      pow(this->prod.modulo(), 4);

  // cout << "Ga = " << resultado << endl;

  return (fabs(resultado) <= TOLERANCIA) ? 0.0 : resultado;
}

double CurvaturaAnalitica::curvaturaCurva() {
  // formula curvatura
  //  k = |r'(t)Xr''(t)| / |r'(t)|³
  return -1;
}
