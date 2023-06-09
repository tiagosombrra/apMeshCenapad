#include "../../Headers/Estimate/ChargeEstimateProcess.h"

ChargeEstimateProcess::ChargeEstimateProcess() {
  menor_erro = 10000;
  menor_grau = 0;
}

static bool sortByNt(const BezierPatch* lhs, const BezierPatch* rhs) {
  return lhs->getKaMedio() > rhs->getKaMedio();
}

// retonar uma lista de patch de bezier ordenados de acordo com sua estimativa
// de carga em ordem decrescente.
std::list<BezierPatch*> ChargeEstimateProcess::chargeEstimateProcess(
    Geometria* geo, Timer* timer, std::string entrada) {
  std::list<BezierPatch*> listBezierPt;
  std::list<BezierPatch*> listBezierPtOrder;

  PatchBezierReader* pt = new PatchBezierReader();
  // timer->endTimerParallel(0, 0, 10); //Full
  //    cout<<"INIT >> LOADBPFILE"<< endl;
  listBezierPt = pt->loaderBPFile(entrada);
  //    cout<<"END >> LOADBPFILE"<< endl;
  // timer->initTimerParallel(0, 0, 10); //Full
  //  timer->initTimerParallel(0, 0, 8); // Over

  delete pt;

  Ponto* p00;
  Ponto* p01;
  Ponto* p02;
  Ponto* p03;
  Ponto* p10;
  Ponto* p11;
  Ponto* p12;
  Ponto* p13;
  Ponto* p20;
  Ponto* p21;
  Ponto* p22;
  Ponto* p23;
  Ponto* p30;
  Ponto* p31;
  Ponto* p32;
  Ponto* p33;

  Curva* patch_c1;
  Curva* patch_c2;
  Curva* patch_c3;
  Curva* patch_c4;

  double areaMenor = 1000;
  double areaMaior = 0;
  double kamMenor = 1000;
  double kamMaior = 0;

  double elementos = 0;

  // timer->endTimerParallel(0, 0, 8); // Over
  // timer->initTimerParallel(0, 0, 1); // Estimativa de carga process 0

  //     cout<<"INIT >> ESTIMATIVE"<< endl;

  for (std::list<BezierPatch*>::iterator it = listBezierPt.begin();
       it != listBezierPt.end(); it++) {
    p00 =
        new Vertice((*it)->getPt00().x, (*it)->getPt00().y, (*it)->getPt00().z);
    p10 =
        new Vertice((*it)->getPt10().x, (*it)->getPt10().y, (*it)->getPt10().z);
    p20 =
        new Vertice((*it)->getPt20().x, (*it)->getPt20().y, (*it)->getPt20().z);
    p30 =
        new Vertice((*it)->getPt30().x, (*it)->getPt30().y, (*it)->getPt30().z);

    p01 =
        new Vertice((*it)->getPt01().x, (*it)->getPt01().y, (*it)->getPt01().z);
    p11 =
        new Vertice((*it)->getPt11().x, (*it)->getPt11().y, (*it)->getPt11().z);
    p21 =
        new Vertice((*it)->getPt21().x, (*it)->getPt21().y, (*it)->getPt21().z);
    p31 =
        new Vertice((*it)->getPt31().x, (*it)->getPt31().y, (*it)->getPt31().z);

    p02 =
        new Vertice((*it)->getPt02().x, (*it)->getPt02().y, (*it)->getPt02().z);
    p12 =
        new Vertice((*it)->getPt12().x, (*it)->getPt12().y, (*it)->getPt12().z);
    p22 =
        new Vertice((*it)->getPt22().x, (*it)->getPt22().y, (*it)->getPt22().z);
    p32 =
        new Vertice((*it)->getPt32().x, (*it)->getPt32().y, (*it)->getPt32().z);

    p03 =
        new Vertice((*it)->getPt03().x, (*it)->getPt03().y, (*it)->getPt03().z);
    p13 =
        new Vertice((*it)->getPt13().x, (*it)->getPt13().y, (*it)->getPt13().z);
    p23 =
        new Vertice((*it)->getPt23().x, (*it)->getPt23().y, (*it)->getPt23().z);
    p33 =
        new Vertice((*it)->getPt33().x, (*it)->getPt33().y, (*it)->getPt33().z);

    if (geo->verifyCurveGeometria(p00, p10, p20, p30) == NULL) {
      patch_c1 = new CurvParamBezier(*p00, *p10, *p20, *p30);
      geo->insereCurva(patch_c1);
    } else {
      patch_c1 = geo->verifyCurveGeometria(p00, p10, p20, p30);
    }

    if (geo->verifyCurveGeometria(p30, p31, p32, p33) == NULL) {
      patch_c2 = new CurvParamBezier(*p30, *p31, *p32, *p33);
      geo->insereCurva(patch_c2);
    } else {
      patch_c2 = geo->verifyCurveGeometria(p30, p31, p32, p33);
    }

    if (geo->verifyCurveGeometria(p03, p13, p23, p33) == NULL) {
      patch_c3 = new CurvParamBezier(*p03, *p13, *p23, *p33);
      geo->insereCurva(patch_c3);
    } else {
      patch_c3 = geo->verifyCurveGeometria(p03, p13, p23, p33);
    }

    if (geo->verifyCurveGeometria(p00, p01, p02, p03) == NULL) {
      patch_c4 = new CurvParamBezier(*p00, *p01, *p02, *p03);
      geo->insereCurva(patch_c4);
    } else {
      patch_c4 = geo->verifyCurveGeometria(p00, p01, p02, p03);
    }

    (*it) = new BezierPatch(patch_c1, patch_c2, patch_c3, patch_c4, *p11, *p21,
                            *p12, *p22);

    (*it)->setArea(calculateAreaPatch((*it), 4));
    // cout << "Área do patch: " << (*it)->getArea() << endl;

    if ((*it)->getArea() < areaMenor) {
      areaMenor = (*it)->getArea();
    } else if ((*it)->getArea() > areaMaior) {
      areaMaior = (*it)->getArea();
    }

    //(*it)->setKaMedio(calculateKaMedioPatch((*it), 4));
    // cout << "KAM: " << (*it)->getKaMedio() << endl;

    //        (*it)->setKaMedio(calculateKaMedioPatch((*it), 9));
    //        cout << "KAM: " << (*it)->getKaMedio() << endl;

    //    (*it)->setKaMedio(calculateKaMedioPatch((*it), 17));
    //    cout << "KAM: " << (*it)->getKaMedio() << endl;
    //
    (*it)->setKaMedio(calculateKaMedioPatch((*it), 25));
    //    cout << "KAM: " << (*it)->getKaMedio() << endl;

    if ((*it)->getKaMedio() < kamMenor) {
      kamMenor = (*it)->getKaMedio();
    } else if ((*it)->getKaMedio() > kamMaior) {
      kamMaior = (*it)->getKaMedio();
    }

    (*it)->setAreaTriangle(calculateAreaTriangleMedioRad((*it)));
    TRIANGLE_MEDIO = (*it)->getAreaTriangle();
    // cout << "Triângulo Medio 1: " << (*it)->getAreaTriangle() << endl;

    (*it)->setNumberTriangle((*it)->getArea() / (*it)->getAreaTriangle());
    // cout << "Quant. de triângulos do patch: " << (*it)->getNumberTriangle()
    // << endl;
    elementos += (*it)->getNumberTriangle();
    //        (*it)->setAreaTriangle(calculateAreaTriangleMedio((*it),4));
    //        cout << "Triângulo Medio 2: " << (*it)->getAreaTriangle() << endl;
    //
    //        (*it)->setNumberTriangle((*it)->getArea() /
    //        (*it)->getAreaTriangle()); cout << "Quant. de triângulos do patch:
    //        " << (*it)->getNumberTriangle() << endl;

    geo->inserePatch((*it));

    listBezierPtOrder.push_back((*it));

    vecCurvature.push_back((*it)->getKaMedio());
  }

  //    cout<<"INIT >> ANALISE CURVATURE"<< endl;
  if (WRITE_MESH == std::string("writeMeshOn")) {
    write.writeCurvaturePatches(vecCurvature, kamMaior);
  }
  //    cout<<"area menor: "<<areaMenor<<endl;
  //    cout<<"area maior: "<<areaMaior<<endl;
  //    cout<<"kam menor: "<<kamMenor<<endl;
  //    cout<<"kam maior: "<<kamMaior<<endl;
  //    cout<<"#elementos_estimados: "<<elementos<<endl;

  if (listBezierPtOrder.size() > 1) {
    listBezierPtOrder.sort(sortByNt);
  }
  //    for (std::list<BezierPatch*>::iterator it = listBezierPtOrder.begin();
  //    it != listBezierPtOrder.end(); it++) {
  //	// cout << "ordenado: " << (*it)->getNumberTriangle() << " area: " <<
  //(*it)->getArea()
  //	//     << " kam: " << (*it)->getKaMedio() << endl;
  //	// cout<<(*it)->getNumberTriangle()<<endl;
  //    }
  return listBezierPtOrder;
}

std::vector<Ponto> ChargeEstimateProcess::interpolateControlPointsCurve(
    Ponto p0, Ponto p1, Ponto p2, Ponto p3, double u, double v) {
  double a = 0.0, b = 0.0, c = 0.0, d = 0.0, det = 0.0;

  Ponto q1;
  Ponto q2;
  Ponto pc1;
  Ponto pc2;

  if ((u <= 0.0) || (u >= 1.0) || (v <= 0.0) || (v >= 1.0) || (u >= v)) {
    std::cout << "erro u or v out of range" << std::endl;
  }

  a = 3 * (1 - u) * (1 - u) * u;
  b = 3 * (1 - u) * u * u;
  c = 3 * (1 - v) * (1 - v) * v;
  d = 3 * (1 - v) * v * v;
  det = a * d - b * c;

  /* unnecessary, but just in case... */
  if (det == 0.0) {
    std::cout << "erro det == 0" << std::endl;
  }

  q1.x = (p1.x - ((1 - u) * (1 - u) * (1 - u) * p0.x + u * u * u * p3.x));
  q1.y = (p1.y - ((1 - u) * (1 - u) * (1 - u) * p0.y + u * u * u * p3.y));
  q1.z = (p1.z - ((1 - u) * (1 - u) * (1 - u) * p0.z + u * u * u * p3.z));

  q2.x = (p2.x - ((1 - v) * (1 - v) * (1 - v) * p0.x + v * v * v * p3.x));
  q2.y = (p2.y - ((1 - v) * (1 - v) * (1 - v) * p0.y + v * v * v * p3.y));
  q2.z = (p2.z - ((1 - v) * (1 - v) * (1 - v) * p0.z + v * v * v * p3.z));

  pc1.x = (d * q1.x - b * q2.x);
  pc1.y = (d * q1.y - b * q2.y);
  pc1.z = (d * q1.z - b * q2.z);

  pc1.x = (pc1.x / det);
  pc1.y = (pc1.y / det);
  pc1.z = (pc1.z / det);

  pc2.x = ((-c) * q1.x + a * q2.x);
  pc2.y = ((-c) * q1.y + a * q2.y);
  pc2.z = ((-c) * q1.z + a * q2.z);

  pc2.x = (pc2.x / det);
  pc2.y = (pc2.y / det);
  pc2.z = (pc2.z / det);

  std::vector<Ponto> list_pcs;

  list_pcs.push_back(pc1);
  list_pcs.push_back(pc2);

  return list_pcs;
}

double ChargeEstimateProcess::calculateKaMedioPatch(BezierPatch* patch,
                                                    int points) {
  if (points < 4) {
    cout << "Numero Mínimo de Pontos para o cálculo da curvatara média é 4 ou "
            "9 ou 17 ou 25"
         << endl;
    return 0.0;
  }

  double arrayKAM[points];
  int i = 0;

  if (points <= 25) {
    if (points >= 4) {
      Ponto* ponto_a = new Ponto();
      Ponto ponto_aa = patch->parametrizar(0.25, 0.25);
      ponto_a = &ponto_aa;

      Ponto* ponto_b = new Ponto();
      Ponto ponto_bb = patch->parametrizar(0.75, 0.25);
      ponto_b = &ponto_bb;

      Ponto* ponto_c = new Ponto();
      Ponto ponto_cc = patch->parametrizar(0.25, 0.75);
      ponto_c = &ponto_cc;

      Ponto* ponto_d = new Ponto();
      Ponto ponto_dd = patch->parametrizar(0.75, 0.75);
      ponto_d = &ponto_dd;

      CurvaturaAnalitica kaa(*(static_cast<Noh*>(ponto_a)),
                             *(static_cast<CoonsPatch*>(patch)));
      CurvaturaAnalitica kab(*(static_cast<Noh*>(ponto_b)),
                             *(static_cast<CoonsPatch*>(patch)));
      CurvaturaAnalitica kac(*(static_cast<Noh*>(ponto_c)),
                             *(static_cast<CoonsPatch*>(patch)));
      CurvaturaAnalitica kad(*(static_cast<Noh*>(ponto_d)),
                             *(static_cast<CoonsPatch*>(patch)));

      double ka_ponto_a = kaa.gauss();
      // if (fabs(ka_ponto_a) < 0, 0001) {
      if (fabs(ka_ponto_a) < 0.0001) {
        ka_ponto_a = kaa.media();
      }

      arrayKAM[i] = fabs(ka_ponto_a);
      i++;

      double kb_ponto_b = kab.gauss();
      // if (fabs(kb_ponto_b) < 0, 0001) {
      if (fabs(kb_ponto_b) < 0.0001) {
        kb_ponto_b = kab.media();
      }

      arrayKAM[i] = fabs(kb_ponto_b);
      i++;

      double kc_ponto_c = kac.gauss();
      // if (fabs(kc_ponto_c) < 0, 0001) {
      if (fabs(kc_ponto_c) < 0.0001) {
        kc_ponto_c = kac.media();
      }

      arrayKAM[i] = fabs(kc_ponto_c);
      i++;

      double kd_ponto_d = kad.gauss();
      // if (fabs(kd_ponto_d) < 0, 0001) {
      if (fabs(kd_ponto_d) < 0.0001) {
        kd_ponto_d = kad.media();
      }

      arrayKAM[i] = fabs(kd_ponto_d);
      i++;

      if (points >= 9) {
        Ponto* ponto_e = new Ponto();
        Ponto ponto_ee = patch->parametrizar(0.5, 0.5);
        ponto_e = &ponto_ee;

        Ponto* ponto_f = new Ponto();
        Ponto ponto_ff = patch->parametrizar(0.0, 0.0);
        ponto_f = &ponto_ff;

        Ponto* ponto_g = new Ponto();
        Ponto ponto_gg = patch->parametrizar(1.0, 0.0);
        ponto_g = &ponto_gg;

        Ponto* ponto_h = new Ponto();
        Ponto ponto_hh = patch->parametrizar(0.0, 1.0);
        ponto_h = &ponto_hh;

        Ponto* ponto_i = new Ponto();
        Ponto ponto_ii = patch->parametrizar(1.0, 1.0);
        ponto_i = &ponto_ii;

        CurvaturaAnalitica kae(*(static_cast<Noh*>(ponto_e)),
                               *(static_cast<CoonsPatch*>(patch)));
        CurvaturaAnalitica kaf(*(static_cast<Noh*>(ponto_f)),
                               *(static_cast<CoonsPatch*>(patch)));
        CurvaturaAnalitica kag(*(static_cast<Noh*>(ponto_g)),
                               *(static_cast<CoonsPatch*>(patch)));
        CurvaturaAnalitica kah(*(static_cast<Noh*>(ponto_h)),
                               *(static_cast<CoonsPatch*>(patch)));
        CurvaturaAnalitica kai(*(static_cast<Noh*>(ponto_i)),
                               *(static_cast<CoonsPatch*>(patch)));

        double ke_ponto_e = kae.gauss();
        // if (fabs(ke_ponto_e) < 0, 0001) {
        if (fabs(ke_ponto_e) < 0.0001) {
          ke_ponto_e = kae.media();
        }

        arrayKAM[i] = fabs(ke_ponto_e);
        i++;

        double kf_ponto_f = kaf.gauss();
        // if (fabs(kf_ponto_f) < 0, 0001) {
        if (fabs(kf_ponto_f) < 0.0001) {
          kf_ponto_f = kaf.media();
        }

        arrayKAM[i] = fabs(kf_ponto_f);
        i++;

        double kg_ponto_g = kag.gauss();
        // if (fabs(kg_ponto_g) < 0, 0001) {
        if (fabs(kg_ponto_g) < 0.0001) {
          kg_ponto_g = kag.media();
        }

        arrayKAM[i] = fabs(kg_ponto_g);
        i++;

        double kh_ponto_h = kah.gauss();
        // if (fabs(kh_ponto_h) < 0, 0001) {
        if (fabs(kh_ponto_h) < 0.0001) {
          kh_ponto_h = kah.media();
        }

        arrayKAM[i] = fabs(kh_ponto_h);
        i++;

        double ki_ponto_i = kai.gauss();
        // if (fabs(ki_ponto_i) < 0, 0001) {
        if (fabs(ki_ponto_i) < 0.0001) {
          ki_ponto_i = kai.media();
        }

        arrayKAM[i] = fabs(ki_ponto_i);
        i++;

        if (points >= 17) {
          Ponto* ponto_j = new Ponto();
          Ponto ponto_jj = patch->parametrizar(0.125, 0.125);
          ponto_j = &ponto_jj;

          Ponto* ponto_l = new Ponto();
          Ponto ponto_ll = patch->parametrizar(0.5, 0.125);
          ponto_l = &ponto_ll;

          Ponto* ponto_m = new Ponto();
          Ponto ponto_mm = patch->parametrizar(0.875, 0.125);
          ponto_m = &ponto_mm;

          Ponto* ponto_n = new Ponto();
          Ponto ponto_nn = patch->parametrizar(0.125, 0.5);
          ponto_n = &ponto_nn;

          Ponto* ponto_o = new Ponto();
          Ponto ponto_oo = patch->parametrizar(0.875, 0.5);
          ponto_o = &ponto_oo;

          Ponto* ponto_p = new Ponto();
          Ponto ponto_pp = patch->parametrizar(0.125, 0.875);
          ponto_p = &ponto_pp;

          Ponto* ponto_q = new Ponto();
          Ponto ponto_qq = patch->parametrizar(0.5, 0.875);
          ponto_q = &ponto_qq;

          Ponto* ponto_r = new Ponto();
          Ponto ponto_rr = patch->parametrizar(0.875, 0.875);
          ponto_r = &ponto_rr;

          CurvaturaAnalitica kaj(*(static_cast<Noh*>(ponto_j)),
                                 *(static_cast<CoonsPatch*>(patch)));
          CurvaturaAnalitica kal(*(static_cast<Noh*>(ponto_l)),
                                 *(static_cast<CoonsPatch*>(patch)));
          CurvaturaAnalitica kam(*(static_cast<Noh*>(ponto_m)),
                                 *(static_cast<CoonsPatch*>(patch)));
          CurvaturaAnalitica kan(*(static_cast<Noh*>(ponto_n)),
                                 *(static_cast<CoonsPatch*>(patch)));
          CurvaturaAnalitica kao(*(static_cast<Noh*>(ponto_o)),
                                 *(static_cast<CoonsPatch*>(patch)));
          CurvaturaAnalitica kap(*(static_cast<Noh*>(ponto_p)),
                                 *(static_cast<CoonsPatch*>(patch)));
          CurvaturaAnalitica kaq(*(static_cast<Noh*>(ponto_q)),
                                 *(static_cast<CoonsPatch*>(patch)));
          CurvaturaAnalitica kar(*(static_cast<Noh*>(ponto_r)),
                                 *(static_cast<CoonsPatch*>(patch)));

          double kj_ponto_j = kaj.gauss();
          // if (fabs(kj_ponto_j) < 0, 0001) {
          if (fabs(kj_ponto_j) < 0.0001) {
            kj_ponto_j = kaj.media();
          }

          arrayKAM[i] = fabs(kj_ponto_j);
          i++;

          double kl_ponto_l = kal.gauss();
          // if (fabs(kl_ponto_l) < 0, 0001) {
          if (fabs(kl_ponto_l) < 0.0001) {
            kl_ponto_l = kal.media();
          }

          arrayKAM[i] = fabs(kl_ponto_l);
          i++;

          double km_ponto_m = kam.gauss();
          // if (fabs(km_ponto_m) < 0, 0001) {
          if (fabs(km_ponto_m) < 0.0001) {
            km_ponto_m = kam.media();
          }

          arrayKAM[i] = fabs(km_ponto_m);
          i++;

          double kn_ponto_n = kan.gauss();
          // if (fabs(kn_ponto_n) < 0, 0001) {
          if (fabs(kn_ponto_n) < 0.0001) {
            kn_ponto_n = kan.media();
          }

          arrayKAM[i] = fabs(kn_ponto_n);
          i++;

          double ko_ponto_o = kao.gauss();
          // if (fabs(ko_ponto_o) < 0, 0001) {
          if (fabs(ko_ponto_o) < 0.0001) {
            ko_ponto_o = kao.media();
          }

          arrayKAM[i] = fabs(ko_ponto_o);
          i++;

          double kp_ponto_p = kap.gauss();
          // if (fabs(kp_ponto_p) < 0, 0001) {
          if (fabs(kp_ponto_p) < 0.0001) {
            kp_ponto_p = kap.media();
          }

          arrayKAM[i] = fabs(kp_ponto_p);
          i++;

          double kq_ponto_q = kaq.gauss();
          // if (fabs(kq_ponto_q) < 0, 0001) {
          if (fabs(kq_ponto_q) < 0.0001) {
            kq_ponto_q = kaq.media();
          }

          arrayKAM[i] = fabs(kq_ponto_q);
          i++;

          double kr_ponto_r = kar.gauss();
          // if (fabs(kr_ponto_r) < 0, 0001) {
          if (fabs(kr_ponto_r) < 0.0001) {
            kr_ponto_r = kar.media();
          }

          arrayKAM[i] = fabs(kr_ponto_r);
          i++;

          if (points == 25) {
            Ponto* ponto_s = new Ponto();
            Ponto ponto_ss = patch->parametrizar(0.25, 0.0);
            ponto_s = &ponto_ss;

            Ponto* ponto_t = new Ponto();
            Ponto ponto_tt = patch->parametrizar(0.75, 0.0);
            ponto_t = &ponto_tt;

            Ponto* ponto_u = new Ponto();
            Ponto ponto_uu = patch->parametrizar(0.0, 0.25);
            ponto_u = &ponto_uu;

            Ponto* ponto_v = new Ponto();
            Ponto ponto_vv = patch->parametrizar(1.0, 0.25);
            ponto_v = &ponto_vv;

            Ponto* ponto_w = new Ponto();
            Ponto ponto_ww = patch->parametrizar(0.0, 0.75);
            ponto_w = &ponto_ww;

            Ponto* ponto_x = new Ponto();
            Ponto ponto_xx = patch->parametrizar(1.0, 0.75);
            ponto_x = &ponto_xx;

            Ponto* ponto_y = new Ponto();
            Ponto ponto_yy = patch->parametrizar(0.25, 1.0);
            ponto_y = &ponto_yy;

            Ponto* ponto_z = new Ponto();
            Ponto ponto_zz = patch->parametrizar(0.75, 1.0);
            ponto_z = &ponto_zz;

            CurvaturaAnalitica kas(*(static_cast<Noh*>(ponto_s)),
                                   *(static_cast<CoonsPatch*>(patch)));
            CurvaturaAnalitica kat(*(static_cast<Noh*>(ponto_t)),
                                   *(static_cast<CoonsPatch*>(patch)));
            CurvaturaAnalitica kau(*(static_cast<Noh*>(ponto_u)),
                                   *(static_cast<CoonsPatch*>(patch)));
            CurvaturaAnalitica kav(*(static_cast<Noh*>(ponto_v)),
                                   *(static_cast<CoonsPatch*>(patch)));
            CurvaturaAnalitica kaw(*(static_cast<Noh*>(ponto_w)),
                                   *(static_cast<CoonsPatch*>(patch)));
            CurvaturaAnalitica kax(*(static_cast<Noh*>(ponto_x)),
                                   *(static_cast<CoonsPatch*>(patch)));
            CurvaturaAnalitica kay(*(static_cast<Noh*>(ponto_y)),
                                   *(static_cast<CoonsPatch*>(patch)));
            CurvaturaAnalitica kaz(*(static_cast<Noh*>(ponto_z)),
                                   *(static_cast<CoonsPatch*>(patch)));

            double ks_ponto_s = kas.gauss();
            // if (fabs(ks_ponto_s) < 0, 0001) {
            if (fabs(ks_ponto_s) < 0.0001) {
              ks_ponto_s = kas.media();
            }

            arrayKAM[i] = fabs(ks_ponto_s);
            i++;

            double kt_ponto_t = kat.gauss();
            // if (fabs(kt_ponto_t) < 0, 0001) {
            if (fabs(kt_ponto_t) < 0.0001) {
              kt_ponto_t = kat.media();
            }

            arrayKAM[i] = fabs(kt_ponto_t);
            i++;

            double ku_ponto_u = kau.gauss();
            // if (fabs(ku_ponto_u) < 0, 0001) {
            if (fabs(ku_ponto_u) < 0.0001) {
              ku_ponto_u = kau.media();
            }

            arrayKAM[i] = fabs(ku_ponto_u);
            i++;

            double kv_ponto_v = kav.gauss();
            // if (fabs(kv_ponto_v) < 0, 0001) {
            if (fabs(kv_ponto_v) < 0.0001) {
              kv_ponto_v = kav.media();
            }

            arrayKAM[i] = fabs(kv_ponto_v);
            i++;

            double kw_ponto_w = kaw.gauss();
            // if (fabs(kw_ponto_w) < 0, 0001) {
            if (fabs(kw_ponto_w) < 0.0001) {
              kw_ponto_w = kaw.media();
            }

            arrayKAM[i] = fabs(kw_ponto_w);
            i++;

            double kx_ponto_x = kax.gauss();
            // if (fabs(kx_ponto_x) < 0, 0001) {
            if (fabs(kx_ponto_x) < 0.0001) {
              kx_ponto_x = kax.media();
            }

            arrayKAM[i] = fabs(kx_ponto_x);
            i++;

            double ky_ponto_y = kay.gauss();
            // if (fabs(ky_ponto_y) < 0, 0001) {
            if (fabs(ky_ponto_y) < 0.0001) {
              ky_ponto_y = kay.media();
            }

            arrayKAM[i] = fabs(ky_ponto_y);
            i++;

            double kz_ponto_z = kaz.gauss();
            // if (fabs(kz_ponto_z) < 0, 0001) {
            if (fabs(kz_ponto_z) < 0.0001) {
              kz_ponto_z = kaz.media();
            }

            arrayKAM[i] = fabs(kz_ponto_z);
            i++;
          }
        }
      }
    }
  }

  double result = 0.0;
  for (int j = 0; j < i; j++) {
    // cout<<arrayKAM[j]<<endl;
    result += arrayKAM[j];
  }

  return result / points;
}

double ChargeEstimateProcess::calculateAreaPatch(BezierPatch* patch,
                                                 int pointesGauusLegandre) {
  Vetor V;
  double I = 0.0;
  double beta[pointesGauusLegandre];
  double peso[pointesGauusLegandre];
  double u = 0.0, v = 0.0;

  switch (pointesGauusLegandre) {
    case 3: {
      // Gauss–Legendre, valores para 3 pontos
      beta[0] = -sqrt(3.0 / 5.0);
      beta[1] = 0.0;
      beta[2] = sqrt(3.0 / 5.0);
      peso[0] = 5.0 / 9.0;
      peso[1] = 8.0 / 9.0;
      peso[2] = 5.0 / 9.0;
      //   mult = 0.25;
      break;
    }

    case 4: {
      // Gauss–Legendre, valores para 4 pontos
      beta[0] = -0.861136;
      beta[1] = -0.339981;
      beta[2] = 0.339981;
      beta[3] = 0.861136;
      peso[0] = 0.347855;
      peso[1] = peso[2] = 0.652145;
      peso[3] = 0.347855;
      //  mult = 0.25;
      break;
    }
    case 5: {
      // Gauss–Legendre, valores para 5 pontos
      //  beta[0] = -sqrt(3.0/5.0); beta[1] = 0.0; beta[2] = sqrt(3.0/5.0);
      //  peso[0] = 5.0/9.0; peso[1] = 8.0/9.0; peso[2] = 5.0/9.0;
      //  mult = 0.;

      break;
    }
  }

  for (int i = 0; i < pointesGauusLegandre; ++i) {
    u = 0.5 * (1 + beta[i]);

    for (int j = 0; j < pointesGauusLegandre; ++j) {
      v = 0.5 * (1 + beta[j]);

      Vetor Pu = patch->Qu(u, v);
      Vetor Pv = patch->Qv(u, v);

      V.x = Pu.y * Pv.z - Pu.z * Pv.y;
      V.y = Pu.z * Pv.x - Pu.x * Pv.z;
      V.z = Pu.x * Pv.y - Pu.y * Pv.x;

      I = I + 0.25 * ((sqrt(pow(V.x, 2) + pow(V.y, 2) + pow(V.z, 2))) *
                      peso[i] * peso[j]);
    }
  }

  return I;
}

double ChargeEstimateProcess::calculateAreaTriangleMedioRad(
    BezierPatch* patch) {
  double Kam = patch->getKaMedio();

  // cout << "Kam " << Kam << endl;

  double raio = 1.0 / Kam;
  // cout << "Raio " << raio << endl;

  double rad = (1.0 / 20) * raio;

  // cout << "Rad " << rad << endl;

  // double lado = (rad * 180) / M_PI;

  // cout << "Lado " << lado << endl;

  double area = pow(rad, 2) * sqrt(3) / 4;

  // cout << "Area " << area << endl;

  return area;
}

double ChargeEstimateProcess::calculateAreaTriangleMedio(BezierPatch* patch,
                                                         Timer* timer,
                                                         int grau) {
  Malha* malha = new Malha;
  SubMalha* sub = malhaInicialEstimativa(patch, grau);
  malha->insereSubMalha(sub);
  // delete sub;

  while (calculateErroEstimative(malha, timer, grau) && grau < 5) {
    ++grau;
    //        cout<<"grau: "<<grau<<endl;
    //        cout<<"sub: "<<sub<<endl;
    SubMalha* sub1 = malhaInicialEstimativa(patch, grau);
    malha->removeSubMalha();
    malha->insereSubMalha(sub1);
    // delete sub1;
  }

  // cout<<"menor_grau: "<<menor_grau<<endl;

  SubMalha* sub2 = malhaInicialEstimativa(patch, menor_grau);
  malha->removeSubMalha();
  malha->insereSubMalha(sub2);

  static_cast<BezierPatch*>(patch)->setAreaTriangle(
      malha->getSubMalha(0)->getElemento(0)->getArea());
  // delete malha;
  return patch->getAreaTriangle();
}

long ChargeEstimateProcess::calculateNumbersTriangle(BezierPatch* patch,
                                                     int grau) {
  SubMalha* sub = malhaInicialEstimativa(patch, grau);

  return sub->getNumDeElementos();
}

// grau tem que ser multiplo de grau == 2^n
SubMalha* ChargeEstimateProcess::malhaInicialEstimativa(CoonsPatch* patch,
                                                        int grau) {
  int idv = 1;
  int ide = 1;
  int salto = grau;
  int comprimento = grau + 1;
  int total_1 = 0;
  int total_2 = 0;

  Curva* c1 = patch->getCurva(0);
  Curva* c2 = patch->getCurva(1);
  Curva* c3 = patch->getCurva(2);
  Curva* c4 = patch->getCurva(3);

  // 1. verifica quais curvas ainda não foram discretizadas
  if (c1->getNumDePontos()) c1 = NULL;  // c1 já foi trabalhada no patch vizinho
  if (c2->getNumDePontos()) c2 = NULL;  // c2 já foi trabalhada no patch vizinho
  if (c3->getNumDePontos()) c3 = NULL;  // c3 já foi trabalhada no patch vizinho
  if (c4->getNumDePontos()) c4 = NULL;  // c4 já foi trabalhada no patch vizinho

  SubMalha* sub = new SubMalha;

  for (double v = 0.0; v <= 1.0; v += 1.0 / grau) {
    for (double u = 0.0; u <= 1.0; u += 1.0 / grau) {
      Ponto* p = new Noh(patch->parametrizar(u, v));
      p->id = idv++;

      // cout << "u = " << u << " v = " << v << endl;
      if (v == 0 and c1)  // p está na curva 1
        c1->inserePonto(p);
      else if (v == 1 and c3)  // p está na curva 3
        c3->inserePonto(p);

      if (u == 0 and c4)  // p está na curva 4
        c4->inserePonto(p);
      else if (u == 1 and c2)  // p está na curva 2
        c2->inserePonto(p);

      sub->insereNoh(static_cast<Noh*>(p));
      total_1++;
    }
  }

  for (double v = 1.0 / (2.0 * grau); v <= 1.0 - (1.0 / (2.0 * grau));
       v += 1.0 / grau) {
    for (double u = 1.0 / (2.0 * grau); u <= 1.0 - (1.0 / (2.0 * grau));
         u += 1.0 / grau) {
      //   cout << "u = " << u << " v = " << v << endl;
      Ponto* p = new Noh(patch->parametrizar(u, v));
      sub->insereNoh(static_cast<Noh*>(p));
      p->id = idv++;
    }
  }

  total_2 = total_1;

  for (int i = 0; i < (total_2 - comprimento - 1); ++i) {
    if (i == salto) {
      salto = salto + comprimento;
      ++i;
      total_1 = total_1 - 1;
    }

    Elemento* e1 = new Triangulo(sub->getNoh(i), sub->getNoh(i + 1),
                                 sub->getNoh(i + total_1));
    ((Triangulo*)e1)->p1 = patch->encontrar_u_v(*(sub->getNoh(i)));
    ((Triangulo*)e1)->p2 = patch->encontrar_u_v(*(sub->getNoh(i + 1)));
    ((Triangulo*)e1)->p3 = patch->encontrar_u_v(*(sub->getNoh(i + total_1)));
    e1->setId(ide++);
    sub->insereElemento(e1);

    Elemento* e2 =
        new Triangulo(sub->getNoh(i + 1), sub->getNoh(i + comprimento + 1),
                      sub->getNoh(i + total_1));
    ((Triangulo*)e2)->p1 = patch->encontrar_u_v(*(sub->getNoh(i + 1)));
    ((Triangulo*)e2)->p2 =
        patch->encontrar_u_v(*(sub->getNoh(i + comprimento + 1)));
    ((Triangulo*)e2)->p3 = patch->encontrar_u_v(*(sub->getNoh(i + total_1)));
    e2->setId(ide++);
    sub->insereElemento(e2);

    Elemento* e3 =
        new Triangulo(sub->getNoh(i + comprimento + 1),
                      sub->getNoh(i + comprimento), sub->getNoh(i + total_1));
    ((Triangulo*)e3)->p1 =
        patch->encontrar_u_v(*(sub->getNoh(i + comprimento + 1)));
    ((Triangulo*)e3)->p2 =
        patch->encontrar_u_v(*(sub->getNoh(i + comprimento)));
    ((Triangulo*)e3)->p3 = patch->encontrar_u_v(*(sub->getNoh(i + total_1)));
    e3->setId(ide++);
    sub->insereElemento(e3);

    Elemento* e4 = new Triangulo(sub->getNoh(i + comprimento), sub->getNoh(i),
                                 sub->getNoh(i + total_1));
    ((Triangulo*)e4)->p1 =
        patch->encontrar_u_v(*(sub->getNoh(i + comprimento)));
    ((Triangulo*)e4)->p2 = patch->encontrar_u_v(*(sub->getNoh(i)));
    ((Triangulo*)e4)->p3 = patch->encontrar_u_v(*(sub->getNoh(i + total_1)));
    e4->setId(ide++);
    sub->insereElemento(e4);
    // cout<<"i "<<i<<endl;
  }

  // 5. define a submalha do patch
  patch->setMalha(sub);
  sub->setPatch(patch);

  Malha* malha = new Malha;
  malha->insereSubMalha(sub);

  return sub;
}

bool ChargeEstimateProcess::calculateErroEstimative(Malha* malha, Timer* timer,
                                                    int grau) {
  GeradorAdaptativoPorCurvatura* ger = new GeradorAdaptativoPorCurvatura();
#if USE_OPENMP
  double erro = ger->erroGlobalOmp(malha, timer);
#else
  double erro = ger->erroGlobal(malha);
#endif
  // delete ger;

  // cout << "erro: " << erro << " tolerancia: " << TOLERANCIA_ESTIMATIVE <<
  // endl;

  if (erro < menor_erro) {
    menor_grau = grau;
  }

  if (erro <= TOLERANCIA_ESTIMATIVE) {
    //  cout<<"return: false" <<endl;
    return false;
  }
  // cout<<"return: true" <<endl;

  return true;
}

ChargeEstimateProcess::~ChargeEstimateProcess() {}
