#include "../../Headers/IO/Modelos3d.h"

Modelos3d::Modelos3d() {}

Geometria* Modelos3d::modelPlanBook(Geometria* geo) {
  //=============================== PATCH 1 ==================================
  Ponto* p100 = new Vertice(0.00000, 1.00000, 0.00000);
  Ponto* p110 = new Vertice(0.00000, 0.50000, 0.00000);
  Ponto* p120 = new Vertice(0.00000, -0.50000, 0.00000);
  Ponto* p130 = new Vertice(0.00000, -1.00000, 0.00000);

  Ponto* p101 = new Vertice(-0.50000, 1.00000, 0.00000);
  Ponto* p111 = new Vertice(-0.50000, 0.50000, 0.00000);
  Ponto* p121 = new Vertice(-0.50000, -0.50000, 0.00000);
  Ponto* p131 = new Vertice(-0.50000, -1.00000, 0.00000);

  Ponto* p102 = new Vertice(-1.50000, 1.00000, 0.00000);
  Ponto* p112 = new Vertice(-1.50000, 0.50000, 0.00000);
  Ponto* p122 = new Vertice(-1.50000, -0.50000, 0.00000);
  Ponto* p132 = new Vertice(-1.50000, -1.00000, 0.00000);

  Ponto* p103 = new Vertice(-2.00000, 1.00000, 0.00000);
  Ponto* p113 = new Vertice(-2.00000, 0.50000, 0.00000);
  Ponto* p123 = new Vertice(-2.00000, -0.50000, 0.00000);
  Ponto* p133 = new Vertice(-2.00000, -1.00000, 0.00000);

  Curva* patch1_c1 = new CurvParamBezier(*p100, *p110, *p120, *p130);
  Curva* patch1_c2 = new CurvParamBezier(*p130, *p131, *p132, *p133);
  Curva* patch1_c3 = new CurvParamBezier(*p103, *p113, *p123, *p133);
  Curva* patch1_c4 = new CurvParamBezier(*p100, *p101, *p102, *p103);

  Patch* patch1 = new BezierPatch(patch1_c1, patch1_c2, patch1_c3, patch1_c4,
                                  *p111, *p121, *p112, *p122);

  geo->inserePatch(patch1);
  geo->insereCurva(patch1_c1);
  geo->insereCurva(patch1_c2);
  geo->insereCurva(patch1_c3);
  geo->insereCurva(patch1_c4);
  //======================== FIM DO PATCH 1 ==================================

  //=============================== PATCH 2 ==================================
  Ponto* p200 = new Vertice(0.00000, 1.00000, 0.00000);
  // Ponto* p210 = new Vertice ( 0.00000, 0.50000, 0.00000 );
  // Ponto* p220 = new Vertice ( 0.00000, -0.50000, 0.00000 );
  Ponto* p230 = new Vertice(0.00000, -1.00000, 0.00000);

  Ponto* p201 = new Vertice(0.00000, 1.00000, 0.50000);
  Ponto* p211 = new Vertice(0.00000, 0.50000, 0.50000);
  Ponto* p221 = new Vertice(0.00000, -0.50000, 0.50000);
  Ponto* p231 = new Vertice(0.00000, -1.00000, 0.50000);

  Ponto* p202 = new Vertice(0.00000, 1.00000, 1.50000);
  Ponto* p212 = new Vertice(0.00000, 0.50000, 1.50000);
  Ponto* p222 = new Vertice(0.00000, -0.50000, 1.50000);
  Ponto* p232 = new Vertice(0.00000, -1.00000, 1.50000);

  Ponto* p203 = new Vertice(0.00000, 1.00000, 2.00000);
  Ponto* p213 = new Vertice(0.00000, 0.50000, 2.00000);
  Ponto* p223 = new Vertice(0.00000, -0.50000, 2.00000);
  Ponto* p233 = new Vertice(0.00000, -1.00000, 2.00000);

  // Curva* patch2_c1 = new CurvParamBezier ( *p200, *p210, *p220, *p230 );
  Curva* patch2_c2 = new CurvParamBezier(*p230, *p231, *p232, *p233);
  Curva* patch2_c3 = new CurvParamBezier(*p203, *p213, *p223, *p233);
  Curva* patch2_c4 = new CurvParamBezier(*p200, *p201, *p202, *p203);

  Patch* patch2 = new BezierPatch(patch1_c1, patch2_c2, patch2_c3, patch2_c4,
                                  *p211, *p221, *p212, *p222);

  geo->inserePatch(patch2);
  // geo->insereCurva ( patch2_c1 );
  geo->insereCurva(patch2_c2);
  geo->insereCurva(patch2_c3);
  geo->insereCurva(patch2_c4);
  //======================== FIM DO PATCH 2 ==================================

  //=============================== PATCH 3 ==================================
  Ponto* p300 = new Vertice(0.00000, 1.00000, 0.00000);
  // Ponto* p310 = new Vertice ( 0.00000, 0.50000, 0.00000 );
  // Ponto* p320 = new Vertice ( 0.00000, -0.50000, 0.00000 );
  Ponto* p330 = new Vertice(0.00000, -1.00000, 0.00000);

  Ponto* p301 = new Vertice(0.50000, 1.00000, 0.00000);
  Ponto* p311 = new Vertice(0.50000, 0.50000, 0.00000);
  Ponto* p321 = new Vertice(0.50000, -0.50000, 0.00000);
  Ponto* p331 = new Vertice(0.50000, -1.00000, 0.00000);

  Ponto* p302 = new Vertice(1.50000, 1.00000, 0.00000);
  Ponto* p312 = new Vertice(1.50000, 0.50000, 0.00000);
  Ponto* p322 = new Vertice(1.50000, -0.50000, 0.00000);
  Ponto* p332 = new Vertice(1.50000, -1.00000, 0.00000);

  Ponto* p303 = new Vertice(2.00000, 1.00000, 0.00000);
  Ponto* p313 = new Vertice(2.00000, 0.50000, 0.00000);
  Ponto* p323 = new Vertice(2.00000, -0.50000, 0.00000);
  Ponto* p333 = new Vertice(2.00000, -1.00000, 0.00000);

  // Curva* patch3_c1 = new CurvParamBezier ( *p300, *p310, *p320, *p330 );
  Curva* patch3_c2 = new CurvParamBezier(*p330, *p331, *p332, *p333);
  Curva* patch3_c3 = new CurvParamBezier(*p303, *p313, *p323, *p333);
  Curva* patch3_c4 = new CurvParamBezier(*p300, *p301, *p302, *p303);

  Patch* patch3 = new BezierPatch(patch1_c1, patch3_c2, patch3_c3, patch3_c4,
                                  *p311, *p321, *p312, *p322);

  geo->inserePatch(patch3);
  // geo->insereCurva ( patch3_c1 );
  geo->insereCurva(patch3_c2);
  geo->insereCurva(patch3_c3);
  geo->insereCurva(patch3_c4);
  //======================== FIM DO PATCH 3 ==================================

  //=============================== PATCH 4 ==================================
  Ponto* p400 = new Vertice(0.00000, 1.00000, 0.00000);
  // Ponto* p410 = new Vertice ( 0.00000, 0.50000, 0.00000 );
  // Ponto* p420 = new Vertice ( 0.00000, -0.50000, 0.00000 );
  Ponto* p430 = new Vertice(0.00000, -1.00000, 0.00000);

  Ponto* p401 = new Vertice(-0.50000, 1.00000, 1.00000);
  Ponto* p411 = new Vertice(-0.50000, 0.50000, 1.00000);
  Ponto* p421 = new Vertice(-0.50000, -0.50000, 1.00000);
  Ponto* p431 = new Vertice(-0.50000, -1.00000, 1.00000);

  Ponto* p402 = new Vertice(-1.50000, 1.00000, 1.00000);
  Ponto* p412 = new Vertice(-1.50000, 0.50000, 1.00000);
  Ponto* p422 = new Vertice(-1.50000, -0.50000, 1.00000);
  Ponto* p432 = new Vertice(-1.50000, -1.00000, 1.00000);

  Ponto* p403 = new Vertice(-2.00000, 1.00000, 1.00000);
  Ponto* p413 = new Vertice(-2.00000, 0.50000, 1.00000);
  Ponto* p423 = new Vertice(-2.00000, -0.50000, 0.50000);
  Ponto* p433 = new Vertice(-2.00000, -1.00000, 1.00000);

  // Curva* patch4_c1 = new CurvParamBezier ( *p400, *p410, *p420, *p430 );
  Curva* patch4_c2 = new CurvParamBezier(*p430, *p431, *p432, *p433);
  Curva* patch4_c3 = new CurvParamBezier(*p403, *p413, *p423, *p433);
  Curva* patch4_c4 = new CurvParamBezier(*p400, *p401, *p402, *p403);

  Patch* patch4 = new BezierPatch(patch1_c1, patch4_c2, patch4_c3, patch4_c4,
                                  *p411, *p421, *p412, *p422);

  geo->inserePatch(patch4);
  // geo->insereCurva ( patch4_c1 );
  geo->insereCurva(patch4_c2);
  geo->insereCurva(patch4_c3);
  geo->insereCurva(patch4_c4);
  //======================== FIM DO PATCH 4 ==================================

  //=============================== PATCH 5 ==================================

  Ponto* p500 = new Vertice(0.00000, 1.00000, 0.00000);
  // Ponto* p510 = new Vertice ( 0.00000, 0.50000, 0.00000 );
  // Ponto* p520 = new Vertice ( 0.00000, -0.50000, 0.00000 );
  Ponto* p530 = new Vertice(0.00000, -1.00000, 0.00000);

  Ponto* p501 = new Vertice(0.50000, 1.00000, 0.28371);
  Ponto* p511 = new Vertice(0.50000, 0.50000, 0.15342);
  Ponto* p521 = new Vertice(0.50000, -0.50000, 0.50617);
  Ponto* p531 = new Vertice(0.50000, -1.00000, 0.28371);

  Ponto* p502 = new Vertice(1.50000, 1.00000, 0.69502);
  Ponto* p512 = new Vertice(1.50000, 0.50000, 0.8342);
  Ponto* p522 = new Vertice(1.50000, -0.50000, 1.094);
  Ponto* p532 = new Vertice(1.50000, -1.00000, 0.8342);

  Ponto* p503 = new Vertice(2.00000, 1.00000, 0.96197);
  Ponto* p513 = new Vertice(2.00000, 0.50000, 0.96197);
  Ponto* p523 = new Vertice(2.00000, -0.50000, 1.2141);
  Ponto* p533 = new Vertice(2.00000, -1.00000, 0.76172);

  // Curva* patch5_c1 = new CurvParamBezier ( *p500, *p510, *p520, *p530 );
  Curva* patch5_c2 = new CurvParamBezier(*p530, *p531, *p532, *p533);
  Curva* patch5_c3 = new CurvParamBezier(*p503, *p513, *p523, *p533);
  Curva* patch5_c4 = new CurvParamBezier(*p500, *p501, *p502, *p503);

  Patch* patch5 = new BezierPatch(patch1_c1, patch5_c2, patch5_c3, patch5_c4,
                                  *p511, *p521, *p512, *p522);

  geo->inserePatch(patch5);
  // geo->insereCurva ( patch5_c1 );
  geo->insereCurva(patch5_c2);
  geo->insereCurva(patch5_c3);
  geo->insereCurva(patch5_c4);
  //======================== FIM DO PATCH 5 ==================================

  return geo;
}

Geometria* Modelos3d::modelTresPatches(Geometria* geo) {
  //==============================================================================
  // Exemplo do three_patches_curve
  //==============================================================================

  //=============================== PATCH 1 ==================================
  Ponto* p100 = new Vertice(-1.00000, 1.00000, -1.00000);
  Ponto* p110 = new Vertice(-1.00000, 0.50000, -1.00000);
  Ponto* p120 = new Vertice(-1.00000, -0.50000, -1.00000);
  Ponto* p130 = new Vertice(-1.00000, -1.00000, -1.00000);

  Ponto* p101 = new Vertice(-1.00000, 1.00000, -0.50000);
  Ponto* p111 = new Vertice(-1.00000, 0.50000, -0.50000);
  Ponto* p121 = new Vertice(-1.00000, -0.50000, -0.50000);
  Ponto* p131 = new Vertice(-1.00000, -1.00000, -0.50000);

  Ponto* p102 = new Vertice(-1.00000, 1.00000, 0.50000);
  Ponto* p112 = new Vertice(-0.95046, 0.50000, 0.50000);
  Ponto* p122 = new Vertice(-1.19780, -0.50000, 0.50000);
  Ponto* p132 = new Vertice(-1.22350, -1.00000, 0.50000);

  Ponto* p103 = new Vertice(-1.00000, 1.00000, 1.00000);
  Ponto* p113 = new Vertice(-0.59827, 0.50000, 1.00000);
  Ponto* p123 = new Vertice(-1.7191, -0.50000, 1.00000);
  Ponto* p133 = new Vertice(-1.00000, -1.00000, 1.00000);

  Curva* patch1_c1 = new CurvParamBezier(*p100, *p110, *p120, *p130);
  Curva* patch1_c2 = new CurvParamBezier(*p130, *p131, *p132, *p133);
  Curva* patch1_c3 = new CurvParamBezier(*p103, *p113, *p123, *p133);
  Curva* patch1_c4 = new CurvParamBezier(*p100, *p101, *p102, *p103);

  Patch* patch1 = new BezierPatch(patch1_c1, patch1_c2, patch1_c3, patch1_c4,
                                  *p111, *p121, *p112, *p122);

  geo->inserePatch(patch1);
  geo->insereCurva(patch1_c1);
  geo->insereCurva(patch1_c2);
  geo->insereCurva(patch1_c3);
  geo->insereCurva(patch1_c4);
  //======================== FIM DO PATCH 1 ==================================
  //=============================== PATCH 2 ==================================
  Ponto* p200 = new Vertice(-1.00000, 1.00000, 1.00000);
  // Ponto* p210 = new Vertice ( -0.78827, 0.50000, 1.00000 );
  // Ponto* p220 = new Vertice ( -1.2291, -0.50000, 1.00000 );
  Ponto* p230 = new Vertice(-1.00000, -1.00000, 1.00000);

  Ponto* p201 = new Vertice(-0.50000, 1.00000, 1.00000);
  Ponto* p211 = new Vertice(-0.50000, 0.50000, 1.00000);
  Ponto* p221 = new Vertice(-0.50000, -0.50000, 1.00000);
  Ponto* p231 = new Vertice(-0.50000, -1.00000, 1.00000);

  Ponto* p202 = new Vertice(0.50000, 1.00000, 1.00000);
  Ponto* p212 = new Vertice(0.50000, 0.50000, 1.00000);
  Ponto* p222 = new Vertice(0.50000, -0.50000, 1.00000);
  Ponto* p232 = new Vertice(0.50000, -1.00000, 1.00000);

  Ponto* p203 = new Vertice(1.00000, 1.00000, 1.00000);
  Ponto* p213 = new Vertice(1.00000, 0.50000, 1.00000);
  Ponto* p223 = new Vertice(1.00000, -0.50000, 1.00000);
  Ponto* p233 = new Vertice(1.00000, -1.00000, 1.00000);

  // Curva* patch2_c1 = new CurvParamBezier ( *p200, *p210, *p220, *p230 );
  Curva* patch2_c2 = new CurvParamBezier(*p230, *p231, *p232, *p233);
  Curva* patch2_c3 = new CurvParamBezier(*p203, *p213, *p223, *p233);
  Curva* patch2_c4 = new CurvParamBezier(*p200, *p201, *p202, *p203);

  Patch* patch2 = new BezierPatch(patch1_c3, patch2_c2, patch2_c3, patch2_c4,
                                  *p211, *p221, *p212, *p222);

  geo->inserePatch(patch2);
  // geo->insereCurva ( patch2_c1 );
  geo->insereCurva(patch2_c2);
  geo->insereCurva(patch2_c3);
  geo->insereCurva(patch2_c4);
  //======================== FIM DO PATCH 2 ==================================

  //=============================== PATCH 3 ==================================
  Ponto* p300 = new Vertice(-1.00000, 1.00000, 1.00000);
  // Ponto* p310 = new Vertice ( -0.78827, 0.50000, 1.00000 );
  // Ponto* p320 = new Vertice ( -1.2291, -0.50000, 1.00000 );
  Ponto* p330 = new Vertice(-1.00000, -1.00000, 1.00000);

  Ponto* p301 = new Vertice(0.12941, 0.65856, 0.66782);
  Ponto* p311 = new Vertice(0.46925, 0.26552, 0.78358);
  Ponto* p321 = new Vertice(-0.21486, -0.30157, 0.8773);
  Ponto* p331 = new Vertice(0.047791, -0.93912, 0.15139);

  Ponto* p302 = new Vertice(0.45814, 0.79803, 0.11771);
  Ponto* p312 = new Vertice(0.98101, 0.080047, 0.56072);
  Ponto* p322 = new Vertice(0.51486, -0.22225, 0.522937);
  Ponto* p332 = new Vertice(0.57169, -0.90869, -0.24963);

  Ponto* p303 = new Vertice(0.41625, 0.64127, -0.58839);
  Ponto* p313 = new Vertice(1.0956, 0.12175, 0.12245);
  Ponto* p323 = new Vertice(1.0956, -0.37825, 0.12405);
  Ponto* p333 = new Vertice(1.0956, -0.87825, -0.51823);

  // Curva* patch2_c1 = new CurvParamBezier ( *p200, *p210, *p220, *p230 );
  Curva* patch3_c2 = new CurvParamBezier(*p330, *p331, *p332, *p333);
  Curva* patch3_c3 = new CurvParamBezier(*p303, *p313, *p323, *p333);
  Curva* patch3_c4 = new CurvParamBezier(*p300, *p301, *p302, *p303);

  Patch* patch3 = new BezierPatch(patch1_c3, patch3_c2, patch3_c3, patch3_c4,
                                  *p311, *p321, *p312, *p322);

  geo->inserePatch(patch3);
  // geo->insereCurva ( patch2_c1 );
  geo->insereCurva(patch3_c2);
  geo->insereCurva(patch3_c3);
  geo->insereCurva(patch3_c4);
  //======================== FIM DO PATCH 3 ==================================
  //==============================================================================
  // FIM do Exemplo three_patches_curve
  //==============================================================================
  return geo;
}
Geometria* Modelos3d::modelDoisPatchesPlanosCurva1(Geometria* geo) {
  //==============================================================================
  // Exemplo do two_patches_curve
  //==============================================================================

  //=============================== PATCH 1 ==================================
  Ponto* p100 = new Vertice(-1.00000, 1.00000, -1.00000);
  Ponto* p110 = new Vertice(-1.00000, 0.50000, -1.00000);
  Ponto* p120 = new Vertice(-1.00000, -0.50000, -1.00000);
  Ponto* p130 = new Vertice(-1.00000, -1.00000, -1.00000);

  Ponto* p101 = new Vertice(-1.00000, 1.00000, -0.50000);
  Ponto* p111 = new Vertice(-1.00000, 0.50000, -0.50000);
  Ponto* p121 = new Vertice(-1.00000, -0.50000, -0.50000);
  Ponto* p131 = new Vertice(-1.00000, -1.00000, -0.50000);

  Ponto* p102 = new Vertice(-1.00000, 1.00000, 0.50000);
  Ponto* p112 = new Vertice(-0.95046, 0.50000, 0.50000);
  Ponto* p122 = new Vertice(-1.19780, -0.50000, 0.50000);
  Ponto* p132 = new Vertice(-1.22350, -1.00000, 0.50000);

  Ponto* p103 = new Vertice(-1.00000, 1.00000, 1.00000);
  Ponto* p113 = new Vertice(-0.59827, 0.50000, 1.00000);
  Ponto* p123 = new Vertice(-1.7191, -0.50000, 1.00000);
  Ponto* p133 = new Vertice(-1.00000, -1.00000, 1.00000);

  Curva* patch1_c1 = new CurvParamBezier(*p100, *p110, *p120, *p130);
  Curva* patch1_c2 = new CurvParamBezier(*p130, *p131, *p132, *p133);
  Curva* patch1_c3 = new CurvParamBezier(*p103, *p113, *p123, *p133);
  Curva* patch1_c4 = new CurvParamBezier(*p100, *p101, *p102, *p103);

  Patch* patch1 = new BezierPatch(patch1_c1, patch1_c2, patch1_c3, patch1_c4,
                                  *p111, *p121, *p112, *p122);

  geo->inserePatch(patch1);
  geo->insereCurva(patch1_c1);
  geo->insereCurva(patch1_c2);
  geo->insereCurva(patch1_c3);
  geo->insereCurva(patch1_c4);
  //======================== FIM DO PATCH 1 ==================================
  //=============================== PATCH 2 ==================================
  Ponto* p200 = new Vertice(-1.00000, 1.00000, 1.00000);
  // Ponto* p210 = new Vertice ( -0.78827, 0.50000, 1.00000 );
  // Ponto* p220 = new Vertice ( -1.2291, -0.50000, 1.00000 );
  Ponto* p230 = new Vertice(-1.00000, -1.00000, 1.00000);

  Ponto* p201 = new Vertice(-0.50000, 1.00000, 1.00000);
  Ponto* p211 = new Vertice(-0.50000, 0.50000, 1.00000);
  Ponto* p221 = new Vertice(-0.50000, -0.50000, 1.00000);
  Ponto* p231 = new Vertice(-0.50000, -1.00000, 1.00000);

  Ponto* p202 = new Vertice(0.50000, 1.00000, 1.00000);
  Ponto* p212 = new Vertice(0.50000, 0.50000, 1.00000);
  Ponto* p222 = new Vertice(0.50000, -0.50000, 1.00000);
  Ponto* p232 = new Vertice(0.50000, -1.00000, 1.00000);

  Ponto* p203 = new Vertice(1.00000, 1.00000, 1.00000);
  Ponto* p213 = new Vertice(1.00000, 0.50000, 1.00000);
  Ponto* p223 = new Vertice(1.00000, -0.50000, 1.00000);
  Ponto* p233 = new Vertice(1.00000, -1.00000, 1.00000);

  // Curva* patch2_c1 = new CurvParamBezier ( *p200, *p210, *p220, *p230 );
  Curva* patch2_c2 = new CurvParamBezier(*p230, *p231, *p232, *p233);
  Curva* patch2_c3 = new CurvParamBezier(*p203, *p213, *p223, *p233);
  Curva* patch2_c4 = new CurvParamBezier(*p200, *p201, *p202, *p203);

  Patch* patch2 = new BezierPatch(patch1_c3, patch2_c2, patch2_c3, patch2_c4,
                                  *p211, *p221, *p212, *p222);

  geo->inserePatch(patch2);
  // geo->insereCurva ( patch2_c1 );
  geo->insereCurva(patch2_c2);
  geo->insereCurva(patch2_c3);
  geo->insereCurva(patch2_c4);
  //======================== FIM DO PATCH 2 ==================================
  //==============================================================================
  // FIM do Exemplo two_patches
  //==============================================================================
  return geo;
}

Geometria* Modelos3d::modelDoisPatchesPlanosCurva(Geometria* geo) {
  //==============================================================================
  // Exemplo do Utahteapot
  //==============================================================================

  //=============================== PATCH 1 ==================================
  Ponto* p100 = new Vertice(-6.0, 0.0, 0.0);
  Ponto* p110 = new Vertice(-2.0, 2.0, 0.0);
  Ponto* p120 = new Vertice(2.0, -2.0, 1.0);
  Ponto* p130 = new Vertice(6.0, 0.0, 0.0);

  Ponto* p101 = new Vertice(-6.0, 4.0, 0.0);
  Ponto* p111 = new Vertice(-2.0, 4.0, 0.0);
  Ponto* p121 = new Vertice(2.0, 4.0, 0.0);
  Ponto* p131 = new Vertice(6.0, 4.0, 0.0);

  Ponto* p102 = new Vertice(-6.0, 8.0, 0.0);
  Ponto* p112 = new Vertice(-2.0, 8.0, 0.0);
  Ponto* p122 = new Vertice(2.0, 8.0, 0.0);
  Ponto* p132 = new Vertice(6.0, 8.0, 0.0);

  Ponto* p103 = new Vertice(-6.0, 12.0, 0.0);
  Ponto* p113 = new Vertice(-2.0, 12.0, 0.0);
  Ponto* p123 = new Vertice(2.0, 12.0, 0.0);
  Ponto* p133 = new Vertice(6.0, 12.0, 0.0);

  Curva* patch1_c1 = new CurvParamBezier(*p100, *p110, *p120, *p130);
  Curva* patch1_c2 = new CurvParamBezier(*p130, *p131, *p132, *p133);
  Curva* patch1_c3 = new CurvParamBezier(*p103, *p113, *p123, *p133);
  Curva* patch1_c4 = new CurvParamBezier(*p100, *p101, *p102, *p103);

  Patch* patch1 = new BezierPatch(patch1_c1, patch1_c2, patch1_c3, patch1_c4,
                                  *p111, *p121, *p112, *p122);

  geo->inserePatch(patch1);
  geo->insereCurva(patch1_c1);
  geo->insereCurva(patch1_c2);
  geo->insereCurva(patch1_c3);
  geo->insereCurva(patch1_c4);
  //======================== FIM DO PATCH 1 ==================================

  //=============================== PATCH 2 ==================================
  Ponto* p200 = new Vertice(-6.0, -12.0, 0.0);
  Ponto* p210 = new Vertice(-2.0, -12.0, 0.0);
  Ponto* p220 = new Vertice(2.0, -12.0, 0.0);
  Ponto* p230 = new Vertice(6.0, -12.0, 0.0);

  Ponto* p201 = new Vertice(-6.0, -8.0, 0.0);
  Ponto* p211 = new Vertice(-2.0, -8.0, 0.0);
  Ponto* p221 = new Vertice(2.0, -8.0, 0.0);
  Ponto* p231 = new Vertice(6.0, -8.0, 0.0);

  Ponto* p202 = new Vertice(-6.0, -4.0, 0.0);
  Ponto* p212 = new Vertice(-2.0, -4.0, 0.0);
  Ponto* p222 = new Vertice(2.0, -4.0, 1.0);
  Ponto* p232 = new Vertice(6.0, -4.0, 0.0);

  Ponto* p203 = p100;  // new Vertice (  0.00000, -1.50000, 2.40000 );
  // Ponto* p213 = p110;//new Vertice ( -0.84000,-1.50000, 2.40000 );
  // Ponto* p223 = p120;//new Vertice ( -1.50000,-0.84000, 2.40000 );
  Ponto* p233 = p130;  // new Vertice ( -1.50000, 0.00000, 2.40000 );

  Curva* patch2_c1 = new CurvParamBezier(*p200, *p210, *p220, *p230);
  Curva* patch2_c2 = new CurvParamBezier(*p230, *p231, *p232, *p233);
  Curva* patch2_c3 =
      patch1_c1;  // new CurvParamBezier ( *p133, *p213, *p223, *p233 );
  Curva* patch2_c4 = new CurvParamBezier(*p200, *p201, *p202, *p203);

  Patch* patch2 = new BezierPatch(patch2_c1, patch2_c2, patch2_c3, patch2_c4,
                                  *p211, *p221, *p212, *p222);

  geo->inserePatch(patch2);
  geo->insereCurva(patch2_c1);
  geo->insereCurva(patch2_c2);
  // geo->insereCurva ( patch2_c3 );
  geo->insereCurva(patch2_c4);
  //======================== FIM DO PATCH 2 ==================================
  return geo;
}

Geometria* Modelos3d::modelCurvaBezier(Geometria* geo) {
  //==============================================================================
  // Exemplo usando curva de Bezier
  //==============================================================================
  // ============================= Patch 1 ===================================

  Ponto* p00 = new Vertice(1.0, -1.0, 0.0);
  Ponto* p10 = new Vertice(0.5, -0.5, 0.0);
  Ponto* p20 = new Vertice(0.5, 0.5, 0.0);
  Ponto* p30 = new Vertice(1.0, 1.0, 0.0);

  Ponto* p01 = new Vertice(0.5, -1.0, 0.0);
  Ponto* p11 = new Vertice(0.5, -0.5, 0.5);
  Ponto* p21 = new Vertice(0.5, 0.5, 0.0);
  Ponto* p31 = new Vertice(0.5, 1.0, 0.0);

  Ponto* p02 = new Vertice(-0.5, -1.0, 0.0);
  Ponto* p12 = new Vertice(-0.5, -0.5, 0.0);
  Ponto* p22 = new Vertice(-0.5, 0.5, 0.0);
  Ponto* p32 = new Vertice(-0.5, 1.0, 0.0);

  Ponto* p03 = new Vertice(-1.0, -1.0, 0.0);
  Ponto* p13 = new Vertice(-1.0, -0.5, 0.0);
  Ponto* p23 = new Vertice(-1.0, 0.5, 0.0);
  Ponto* p33 = new Vertice(-1.0, 1.0, 0.0);

  Curva* patch1_c1 = new CurvParamBezier(*p00, *p10, *p20, *p30);
  Curva* patch1_c2 = new CurvParamBezier(*p30, *p31, *p32, *p33);
  Curva* patch1_c3 = new CurvParamBezier(*p03, *p13, *p23, *p33);
  Curva* patch1_c4 = new CurvParamBezier(*p00, *p01, *p02, *p03);

  Patch* patch1 = new BezierPatch(patch1_c1, patch1_c2, patch1_c3, patch1_c4,
                                  *p11, *p21, *p12, *p22);

  geo->inserePatch(patch1);
  geo->insereCurva(patch1_c1);
  geo->insereCurva(patch1_c2);
  geo->insereCurva(patch1_c3);
  geo->insereCurva(patch1_c4);
  //==============================================================================
  // Fim do exemplo usando curva de Bezier
  //==============================================================================
  return geo;
}

Geometria* Modelos3d::modelParaboloide(Geometria* geo) {
  //==============================================================================
  // Exemplo do PARABOLÓIDE HIPERBÓLICO
  //==============================================================================

  //=============================== PATCH 1 ==================================
  Ponto* patch1_p00 = new Vertice(-5.0, -5.0, 0.0);
  Ponto* patch1_p10 = new Vertice(5.0, -5.0, 0.0);
  Ponto* patch1_p01 = new Vertice(-5.0, 5.0, 0.0);
  Ponto* patch1_p11 = new Vertice(5.0, 5.0, 0.0);

  Vetor* patch1_Qu00 = new Vetor(1.0, 0.0, 18.25);
  Vetor* patch1_Qu10 =
      new Vetor(patch1_Qu00->x, -patch1_Qu00->y, -patch1_Qu00->z);
  Vetor* patch1_Qu01 = new Vetor(1.0, 0.0, 18.25);
  Vetor* patch1_Qu11 =
      new Vetor(patch1_Qu01->x, -patch1_Qu01->y, -patch1_Qu01->z);

  Vetor* patch1_Qv00 = new Vetor(0.0, 1.0, -18.25);
  Vetor* patch1_Qv10 = new Vetor(0.0, 1.0, -18.25);
  Vetor* patch1_Qv01 =
      new Vetor(-patch1_Qv00->x, patch1_Qv00->y, -patch1_Qv00->z);
  Vetor* patch1_Qv11 =
      new Vetor(-patch1_Qv10->x, patch1_Qv10->y, -patch1_Qv10->z);

  Vetor* patch1_tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch1_tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch1_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch1_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch1_c1 = new CurvParamHermite(*patch1_p00, *patch1_p10,
                                          *patch1_Qu00, *patch1_Qu10);
  Curva* patch1_c2 = new CurvParamHermite(*patch1_p10, *patch1_p11,
                                          *patch1_Qv10, *patch1_Qv11);
  Curva* patch1_c3 = new CurvParamHermite(*patch1_p01, *patch1_p11,
                                          *patch1_Qu01, *patch1_Qu11);
  Curva* patch1_c4 = new CurvParamHermite(*patch1_p00, *patch1_p01,
                                          *patch1_Qv00, *patch1_Qv01);

  Patch* patch1 =
      new HermitePatch(patch1_c1, patch1_c2, patch1_c3, patch1_c4, *patch1_tw00,
                       *patch1_tw10, *patch1_tw01, *patch1_tw11);

  geo->inserePatch(patch1);
  geo->insereCurva(patch1_c1);
  geo->insereCurva(patch1_c2);
  geo->insereCurva(patch1_c3);
  geo->insereCurva(patch1_c4);

  //======================== FIM DO PATCH 1 ===================================
  //==============================================================================
  // FIM do Exemplo do PARABOLÓIDE HIPERBÓLICO
  //==============================================================================
  return geo;
}

Geometria* Modelos3d::modelPneu(Geometria* geo) {
  //==============================================================================
  // Exemplo do pneu
  //==============================================================================
  Ponto* p00 = new Vertice(-5.0, 0.0, -5.0);
  Ponto* p10 = new Vertice(5.0, 0.0, -5.0);
  Ponto* p01 = new Vertice(-5.0, 0.0, 5.0);
  Ponto* p11 = new Vertice(5.0, 0.0, 5.0);

  Vetor* Qu00 = new Vetor(0.0, -20.0, 0.0);
  Vetor* Qu10 = new Vetor(0.0, 20.0, 0.0);
  Vetor* Qu01 = new Vetor(0.0, -20.0, 0.0);
  Vetor* Qu11 = new Vetor(0.0, 20.0, 0.0);

  Vetor* Qv00 = new Vetor(-15.0, 0.0, -15.0);
  Vetor* Qv10 = new Vetor(15.0, 0.0, -15.0);
  Vetor* Qv01 = new Vetor(15.0, 0.0, -15.0);
  Vetor* Qv11 = new Vetor(-15.0, 0.0, -15.0);

  Curva* c1 = new CurvParamHermite(*p00, *p10, *Qu00, *Qu10);
  Curva* c2 = new CurvParamHermite(*p10, *p11, *Qv10, *Qv11);
  Curva* c3 = new CurvParamHermite(*p01, *p11, *Qu01, *Qu11);
  Curva* c4 = new CurvParamHermite(*p00, *p01, *Qv00, *Qv01);
  Curva* c5 = new CurvParamHermite(*p10, *p00, *Qu10, *Qu00);
  Curva* c6 = new CurvParamHermite(*p11, *p01, *Qu11, *Qu01);

  Vetor* tw_00 = new Vetor(0.0, 60.0, 0.0);
  Vetor* tw_10 = new Vetor(0.0, -60.0, 0.0);
  Vetor* tw_01 = new Vetor(0.0, -60.0, 0.0);
  Vetor* tw_11 = new Vetor(0.0, 60.0, 0.0);

  Vetor* tw00 = new Vetor(0.0, -60.0, 0.0);
  Vetor* tw10 = new Vetor(0.0, 60.0, 0.0);
  Vetor* tw01 = new Vetor(0.0, 60.0, 0.0);
  Vetor* tw11 = new Vetor(0.0, -60.0, 0.0);

  Patch* patch1 = new HermitePatch(c1, c2, c3, c4, *tw00, *tw10, *tw01, *tw11);
  Patch* patch2 =
      new HermitePatch(c5, c4, c6, c2, *tw_00, *tw_10, *tw_01, *tw_11);

  geo->inserePatch(patch1);
  geo->inserePatch(patch2);
  geo->insereCurva(c1);
  geo->insereCurva(c2);
  geo->insereCurva(c3);
  geo->insereCurva(c4);
  geo->insereCurva(c5);
  geo->insereCurva(c6);
  return geo;
  //==============================================================================
  // Fim do Exemplo do pneu
  //==============================================================================
}

Geometria* Modelos3d::modelLadoDescendente(Geometria* geo) {
  //==============================================================================
  // Exemplo de uma superfície com um dos lados descendentes
  //==============================================================================
  Ponto* p00 = new Vertice(-0.5, 0.0, 0.5);
  Ponto* p10 = new Vertice(0.5, 0.0, 0.5);
  Ponto* p01 = new Vertice(-0.5, 0.0, -0.5);
  Ponto* p11 = new Vertice(0.5, -0.5, -0.5);

  Vetor* Qu00 = new Vetor(1.0, 0.0, 0.0);
  Vetor* Qu10 = new Vetor(1.0, 0.0, 0.0);
  Vetor* Qu01 = new Vetor(3.0, 0.0, 0.0);
  Vetor* Qu11 = new Vetor(1.0, 0.0, 0.0);

  Vetor* Qv00 = new Vetor(0.0, 0.0, -1.0);
  Vetor* Qv10 = new Vetor(0.0, 0.0, -3.0);
  Vetor* Qv01 = new Vetor(0.0, 0.0, -1.0);
  Vetor* Qv11 = new Vetor(0.0, 0.0, -1.0);

  Vetor* tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* c1 = new CurvParamHermite(*p00, *p10, *Qu00, *Qu10);
  Curva* c2 = new CurvParamHermite(*p10, *p11, *Qv10, *Qv11);
  Curva* c3 = new CurvParamHermite(*p01, *p11, *Qu01, *Qu11);
  Curva* c4 = new CurvParamHermite(*p00, *p01, *Qv00, *Qv01);
  Patch* patch1 = new HermitePatch(c1, c2, c3, c4, *tw00, *tw10, *tw01, *tw11);

  geo->inserePatch(patch1);
  geo->insereCurva(c1);
  geo->insereCurva(c2);
  geo->insereCurva(c3);
  geo->insereCurva(c4);

  return geo;

  //==============================================================================
  // FIM do Exemplo de uma superfície com um dos lados descendentes
  //==============================================================================
}

Geometria* Modelos3d::modelBaseCircular(Geometria* geo) {
  //==============================================================================
  // Exemplo da base circular
  //==============================================================================
  Ponto* p00 = new Vertice(0.0, -5.0, 0.0);
  Ponto* p10 = new Vertice(5.0, 0.0, 0.0);
  Ponto* p11 = new Vertice(0.0, 5.0, 0.0);
  Ponto* p01 = new Vertice(-5.0, 0.0, 0.0);

  Vetor* Qu00 = new Vetor(8.25, 0.0, 0.0);
  Vetor* Qu10 = new Vetor(0.0, 8.25, 0.0);
  Vetor* Qu01 = new Vetor(0.0, 8.25, 0.0);
  Vetor* Qu11 = new Vetor(8.25, 0.0, 0.0);
  Vetor* Qv00 = new Vetor(-8.25, 0.0, 0.0);
  Vetor* Qv10 = new Vetor(0.0, 8.25, 0.0);
  Vetor* Qv01 = new Vetor(0.0, 8.25, 0.0);
  Vetor* Qv11 = new Vetor(-8.25, 0.0, 0.0);

  Vetor* tw00 = new Vetor(0.0, 0.0, 10.0);
  Vetor* tw10 = new Vetor(0.0, 0.0, -10.0);
  Vetor* tw01 = new Vetor(0.0, 0.0, -10.0);
  Vetor* tw11 = new Vetor(0.0, 0.0, 10.0);

  Curva* c1 = new CurvParamHermite(*p00, *p10, *Qu00, *Qu10);
  Curva* c2 = new CurvParamHermite(*p10, *p11, *Qv10, *Qv11);
  Curva* c3 = new CurvParamHermite(*p01, *p11, *Qu01, *Qu11);
  Curva* c4 = new CurvParamHermite(*p00, *p01, *Qv00, *Qv01);

  Patch* patch1 = new HermitePatch(c1, c2, c3, c4, *tw00, *tw10, *tw01, *tw11);

  geo->inserePatch(patch1);
  geo->insereCurva(c1);
  geo->insereCurva(c2);
  geo->insereCurva(c3);
  geo->insereCurva(c4);
  return geo;
  //==============================================================================
  // FIM do Exemplo da base circular
  //==============================================================================
}

Geometria* Modelos3d::modelBaseQuadrada(Geometria* geo) {
  //==============================================================================
  // Exemplo do patch com base quadrada
  //==============================================================================
  Ponto* p00 = new Vertice(-0.5, 0.0, 0.5);
  Ponto* p10 = new Vertice(0.5, 0.0, 0.5);
  Ponto* p01 = new Vertice(-0.5, 0.0, -0.5);
  Ponto* p11 = new Vertice(0.5, 0.0, -0.5);

  Vetor* Qu00 = new Vetor(1.0, 0.0, 0.0);
  Vetor* Qu10 = new Vetor(1.0, 0.0, 0.0);
  Vetor* Qu01 = new Vetor(1.0, 0.0, 0.0);
  Vetor* Qu11 = new Vetor(1.0, 0.0, 0.0);

  Vetor* Qv00 = new Vetor(0.0, 0.0, -1.0);
  Vetor* Qv10 = new Vetor(0.0, 0.0, -1.0);
  Vetor* Qv01 = new Vetor(0.0, 0.0, -1.0);
  Vetor* Qv11 = new Vetor(0.0, 0.0, -1.0);

  Vetor* tw00 = new Vetor(0.0, 20.0, 0.0);
  Vetor* tw10 = new Vetor(0.0, -20.0, 0.0);
  Vetor* tw01 = new Vetor(0.0, -20.0, 0.0);
  Vetor* tw11 = new Vetor(0.0, 20.0, 0.0);

  Curva* c1 = new CurvParamHermite(*p00, *p10, *Qu00, *Qu10);
  Curva* c2 = new CurvParamHermite(*p10, *p11, *Qv10, *Qv11);
  Curva* c3 = new CurvParamHermite(*p01, *p11, *Qu01, *Qu11);
  Curva* c4 = new CurvParamHermite(*p00, *p01, *Qv00, *Qv01);

  Patch* patch1 = new HermitePatch(c1, c2, c3, c4, *tw00, *tw10, *tw01, *tw11);

  geo->inserePatch(patch1);
  geo->insereCurva(c1);
  geo->insereCurva(c2);
  geo->insereCurva(c3);
  geo->insereCurva(c4);
  return geo;
  //==============================================================================
  // FIM do exemplo do patch com base quadrada
  //==============================================================================
}

Geometria* Modelos3d::modelBordaCurva(Geometria* geo) {
  //==============================================================================
  // Exemplo do patch com borda curva
  //==============================================================================
  Ponto* p00 = new Vertice(-5.0, -5.0, 0.0);
  Ponto* p10 = new Vertice(5.0, -5.0, 0.0);
  Ponto* p01 = new Vertice(-5.0, 5.0, 0.0);
  Ponto* p11 = new Vertice(5.0, 5.0, 0.0);

  Vetor* Qu00 = new Vetor(10.0, 10.0, 0.0);
  Vetor* Qu10 = new Vetor(10.0, 10.0, 0.0);
  Vetor* Qu01 = new Vetor(10.0, 10.0, 0.0);
  Vetor* Qu11 = new Vetor(10.0, 10.0, 0.0);

  Vetor* Qv00 = new Vetor(-10.0, 10.0, 0.0);
  Vetor* Qv10 = new Vetor(-10.0, 10.0, 0.0);
  Vetor* Qv01 = new Vetor(-10.0, 10.0, 0.0);
  Vetor* Qv11 = new Vetor(-10.0, 10.0, 0.0);

  Vetor* tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* c1 = new CurvParamHermite(*p00, *p10, *Qu00, *Qu10);
  Curva* c2 = new CurvParamHermite(*p10, *p11, *Qv10, *Qv11);
  Curva* c3 = new CurvParamHermite(*p01, *p11, *Qu01, *Qu11);
  Curva* c4 = new CurvParamHermite(*p00, *p01, *Qv00, *Qv01);

  Patch* patch1 = new HermitePatch(c1, c2, c3, c4, *tw00, *tw10, *tw01, *tw11);

  geo->inserePatch(patch1);
  geo->insereCurva(c1);
  geo->insereCurva(c2);
  geo->insereCurva(c3);
  geo->insereCurva(c4);
  return geo;
  //==============================================================================
  // FIM do exemplo do patch com borda curva
  //==============================================================================
}

Geometria* Modelos3d::modelDoisPatches(Geometria* geo) {
  //==============================================================================
  // Exemplo de dois patches vizinhos
  //==============================================================================
  Ponto* p100 = new Vertice(-1.0, 0.0, 0.5);
  Ponto* p110 = new Vertice(0.0, 0.0, 0.5);
  Ponto* p101 = new Vertice(-1.0, 0.0, -0.5);
  Ponto* p111 = new Vertice(0.0, 0.0, -0.5);

  Ponto* p200 = new Vertice(0.0, 0.0, 0.5);
  Ponto* p210 = new Vertice(1.0, 0.0, 0.5);
  Ponto* p201 = new Vertice(0.0, 0.0, -0.5);
  Ponto* p211 = new Vertice(1.0, 0.0, -0.5);

  Vetor* Qu00 = new Vetor(0.1, 0.0, 0.0);
  Vetor* Qu10 = new Vetor(0.1, 0.0, 0.0);
  Vetor* Qu01 = new Vetor(0.1, 0.0, 0.0);
  Vetor* Qu11 = new Vetor(0.1, 0.0, 0.0);

  Vetor* Qv00 = new Vetor(0.0, 0.0, -0.1);
  Vetor* Qv10 = new Vetor(0.0, 0.0, -0.1);
  Vetor* Qv01 = new Vetor(0.0, 0.0, -0.1);
  Vetor* Qv11 = new Vetor(0.0, 0.0, -0.1);

  Vetor* tw100 = new Vetor(0.0, 20.0, 0.0);
  Vetor* tw110 = new Vetor(0.0, -20.0, 0.0);
  Vetor* tw101 = new Vetor(0.0, -20.0, 0.0);
  Vetor* tw111 = new Vetor(0.0, 20.0, 0.0);

  Vetor* tw200 = new Vetor(0.0, 20.0, 0.0);
  Vetor* tw210 = new Vetor(0.0, -20.0, 0.0);
  Vetor* tw201 = new Vetor(0.0, -20.0, 0.0);
  Vetor* tw211 = new Vetor(0.0, 20.0, 0.0);

  Curva* c1 = new CurvParamHermite(*p100, *p110, *Qu00, *Qu10);
  Curva* c2 = new CurvParamHermite(*p110, *p111, *Qv10, *Qv11);
  Curva* c3 = new CurvParamHermite(*p101, *p111, *Qu01, *Qu11);
  Curva* c4 = new CurvParamHermite(*p100, *p101, *Qv00, *Qv01);

  Curva* c5 = new CurvParamHermite(*p200, *p210, *Qu00, *Qu10);
  Curva* c6 = new CurvParamHermite(*p210, *p211, *Qv10, *Qv11);
  Curva* c7 = new CurvParamHermite(*p201, *p211, *Qu01, *Qu11);
  // Curva* c8 = new CurvParamHermite ( *p200, *p201, *Qv00, *Qv01 );

  Patch* patch1 =
      new HermitePatch(c1, c2, c3, c4, *tw100, *tw110, *tw101, *tw111);
  Patch* patch2 =
      new HermitePatch(c5, c6, c7, c2, *tw200, *tw210, *tw201, *tw211);

  geo->inserePatch(patch1);
  geo->inserePatch(patch2);
  geo->insereCurva(c1);
  geo->insereCurva(c2);
  geo->insereCurva(c3);
  geo->insereCurva(c4);
  geo->insereCurva(c5);
  geo->insereCurva(c6);
  geo->insereCurva(c7);
  return geo;
  //==============================================================================
  // Fim do Exemplo de dois patches vizinhos
  //==============================================================================
}

Geometria* Modelos3d::modelNariz(Geometria* geo) {
  //==============================================================================
  // Exemplo do nariz
  //==============================================================================
  //=============================== PATCH 1 ===================================
  Ponto* patch1_p00 = new Vertice(-8.00, 2.5, 0.0);
  Ponto* patch1_p10 = new Vertice(-2.50, 0.0, 0.0);
  Ponto* patch1_p01 = new Vertice(-7.00, 2.5, 5.0);
  Ponto* patch1_p11 = new Vertice(-3.50, 0.0, 7.5);

  Vetor* patch1_Qu00 = new Vetor(5.5, -2.5, 18.0);
  Vetor* patch1_Qu10 =
      new Vetor(patch1_Qu00->x, patch1_Qu00->y, -patch1_Qu00->z);
  Vetor* patch1_Qu01 = new Vetor(3.5, -2.5, 2.5);
  Vetor* patch1_Qu11 =
      new Vetor(patch1_Qu01->x, patch1_Qu01->y, patch1_Qu01->z);

  Vetor* patch1_Qv00 = new Vetor(-7.5, 2.5, 0.0);
  Vetor* patch1_Qv10 = new Vetor(3.5, -5.0, 7.5);
  Vetor* patch1_Qv01 = new Vetor(5.5, 2.5, 0.0);
  Vetor* patch1_Qv11 =
      new Vetor(-patch1_Qv10->x, -patch1_Qv10->y, patch1_Qv10->z);

  Vetor* patch1_tw00 = new Vetor(0.0, -10.0, 0.0);
  Vetor* patch1_tw10 = new Vetor(0.0, 10.0, 0.0);
  Vetor* patch1_tw01 = new Vetor(0.0, 10.0, 0.0);
  Vetor* patch1_tw11 = new Vetor(0.0, -10.0, 0.0);

  Curva* patch1_c1 = new CurvParamHermite(*patch1_p00, *patch1_p10,
                                          *patch1_Qu00, *patch1_Qu10);
  Curva* patch1_c2 = new CurvParamHermite(*patch1_p10, *patch1_p11,
                                          *patch1_Qv10, *patch1_Qv11);
  Curva* patch1_c3 = new CurvParamHermite(*patch1_p01, *patch1_p11,
                                          *patch1_Qu01, *patch1_Qu11);
  Curva* patch1_c4 = new CurvParamHermite(*patch1_p00, *patch1_p01,
                                          *patch1_Qv00, *patch1_Qv01);

  Patch* patch1 =
      new HermitePatch(patch1_c1, patch1_c2, patch1_c3, patch1_c4, *patch1_tw00,
                       *patch1_tw10, *patch1_tw01, *patch1_tw11);

  geo->inserePatch(patch1);
  geo->insereCurva(patch1_c1);
  geo->insereCurva(patch1_c2);
  geo->insereCurva(patch1_c3);
  geo->insereCurva(patch1_c4);
  //======================== FIM DO PATCH 1 ===================================

  //=============================== PATCH 2 ===================================
  Ponto* patch2_p00 = patch1_p10;
  Ponto* patch2_p10 = new Vertice(-patch1_p10->x, patch1_p10->y, patch1_p10->z);
  Ponto* patch2_p01 = patch1_p11;
  Ponto* patch2_p11 = new Vertice(-patch1_p11->x, patch1_p11->y, patch1_p11->z);

  Vetor* patch2_Qu00 = new Vetor(7.5, -2.5, 0.0);
  Vetor* patch2_Qu10 = new Vetor(7.5, 2.5, 0.0);
  Vetor* patch2_Qu01 = new Vetor(7.0, -5.0, 5.0);
  Vetor* patch2_Qu11 = new Vetor(7.0, 5.0, -5.0);

  // Vetor* patch2_Qv00 = new Vetor ( *patch2_p00, *patch2_p01 );
  Vetor* patch2_Qv10 =
      new Vetor(-patch1_Qv10->x, patch1_Qv10->y, patch1_Qv10->z);
  // Vetor* patch2_Qv01 = new Vetor ( *patch2_p00, *patch2_p01 );
  Vetor* patch2_Qv11 =
      new Vetor(-patch1_Qv11->x, patch1_Qv11->y, patch1_Qv11->z);

  Vetor* patch2_tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch2_tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch2_tw01 = new Vetor(0.0, 10.0, 0.0);
  Vetor* patch2_tw11 = new Vetor(0.0, -10.0, 0.0);

  Curva* patch2_c1 = new CurvParamHermite(*patch2_p00, *patch2_p10,
                                          *patch2_Qu00, *patch2_Qu10);
  Curva* patch2_c2 = new CurvParamHermite(*patch2_p10, *patch2_p11,
                                          *patch2_Qv10, *patch2_Qv11);
  Curva* patch2_c3 = new CurvParamHermite(*patch2_p01, *patch2_p11,
                                          *patch2_Qu01, *patch2_Qu11);
  Curva* patch2_c4 = patch1_c2;

  Patch* patch2 =
      new HermitePatch(patch2_c1, patch2_c2, patch2_c3, patch2_c4, *patch2_tw00,
                       *patch2_tw10, *patch2_tw01, *patch2_tw11);

  geo->inserePatch(patch2);
  geo->insereCurva(patch2_c1);
  geo->insereCurva(patch2_c2);
  geo->insereCurva(patch2_c3);
  // geo->insereCurva ( patch2_c4 );
  //======================== FIM DO PATCH 2 ===================================

  //=============================== PATCH 3 ===================================
  Ponto* patch3_p00 = patch2_p10;
  Ponto* patch3_p10 = new Vertice(-patch1_p00->x, patch1_p00->y, patch1_p00->z);
  Ponto* patch3_p01 = patch2_p11;
  Ponto* patch3_p11 = new Vertice(-patch1_p01->x, patch1_p01->y, patch1_p01->z);

  Vetor* patch3_Qu00 =
      new Vetor(-(-(*patch1_Qu10)).x, (-(*patch1_Qu10)).y, (-(*patch1_Qu10)).z);
  Vetor* patch3_Qu10 =
      new Vetor(-(-(*patch1_Qu00)).x, (-(*patch1_Qu00)).y, (-(*patch1_Qu00)).z);
  Vetor* patch3_Qu01 =
      new Vetor(-(-(*patch1_Qu11)).x, (-(*patch1_Qu11)).y, (-(*patch1_Qu11)).z);
  Vetor* patch3_Qu11 =
      new Vetor(-(-(*patch1_Qu01)).x, (-(*patch1_Qu01)).y, (-(*patch1_Qu01)).z);

  // Vetor* patch3_Qv00 = new Vetor ( -patch1_Qv10->x, patch1_Qv10->y,
  // patch1_Qv10->z );
  Vetor* patch3_Qv10 =
      new Vetor(-patch1_Qv00->x, patch1_Qv00->y, patch1_Qv00->z);
  // Vetor* patch3_Qv01 = new Vetor ( -patch1_Qv11->x, patch1_Qv11->y,
  // patch1_Qv11->z );
  Vetor* patch3_Qv11 =
      new Vetor(-patch1_Qv01->x, patch1_Qv01->y, patch1_Qv01->z);

  Vetor* patch3_tw00 =
      new Vetor(patch1_tw00->x, patch1_tw00->y, patch1_tw00->z);
  Vetor* patch3_tw10 =
      new Vetor(patch1_tw10->x, patch1_tw10->y, patch1_tw10->z);
  Vetor* patch3_tw01 =
      new Vetor(patch1_tw01->x, patch1_tw01->y, patch1_tw01->z);
  Vetor* patch3_tw11 =
      new Vetor(patch1_tw11->x, patch1_tw11->y, patch1_tw11->z);

  Curva* patch3_c1 = new CurvParamHermite(*patch3_p00, *patch3_p10,
                                          *patch3_Qu00, *patch3_Qu10);
  Curva* patch3_c2 = new CurvParamHermite(*patch3_p10, *patch3_p11,
                                          *patch3_Qv10, *patch3_Qv11);
  Curva* patch3_c3 = new CurvParamHermite(*patch3_p01, *patch3_p11,
                                          *patch3_Qu01, *patch3_Qu11);
  Curva* patch3_c4 = patch2_c2;

  Patch* patch3 =
      new HermitePatch(patch3_c1, patch3_c2, patch3_c3, patch3_c4, *patch3_tw00,
                       *patch3_tw10, *patch3_tw01, *patch3_tw11);

  geo->inserePatch(patch3);
  geo->insereCurva(patch3_c1);
  geo->insereCurva(patch3_c2);
  geo->insereCurva(patch3_c3);
  // geo->insereCurva ( patch3_c4 );
  //======================== FIM DO PATCH 3 ===================================

  //=============================== PATCH 4 ===================================
  Ponto* patch4_p00 = patch1_p01;
  Ponto* patch4_p10 = patch1_p11;
  Ponto* patch4_p01 = new Vertice(-6.00, 5.0, 2.5);
  Ponto* patch4_p11 = new Vertice(-3.50, 4.0, 7.5);

  // Vetor* patch4_Qu00 = new Vetor ( *patch4_p00, *patch4_p10 );
  // Vetor* patch4_Qu10 = new Vetor ( *patch4_p00, *patch4_p10 );
  Vetor* patch4_Qu01 = new Vetor(*patch4_p01, *patch4_p11);
  Vetor* patch4_Qu11 = new Vetor(*patch4_p01, *patch4_p11);

  Vetor* patch4_Qv00 = new Vetor(*patch4_p00, *patch4_p01);
  Vetor* patch4_Qv10 = new Vetor(*patch4_p10, *patch4_p11);
  Vetor* patch4_Qv01 = new Vetor(*patch4_p00, *patch4_p01);
  Vetor* patch4_Qv11 = new Vetor(*patch4_p10, *patch4_p11);

  Vetor* patch4_tw00 = new Vetor(0.0, 0.0, 10.0);
  Vetor* patch4_tw10 = new Vetor(0.0, 0.0, -10.0);
  Vetor* patch4_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch4_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch4_c1 = patch1_c3;
  Curva* patch4_c2 = new CurvParamHermite(*patch4_p10, *patch4_p11,
                                          *patch4_Qv10, *patch4_Qv11);
  Curva* patch4_c3 = new CurvParamHermite(*patch4_p01, *patch4_p11,
                                          *patch4_Qu01, *patch4_Qu11);
  Curva* patch4_c4 = new CurvParamHermite(*patch4_p00, *patch4_p01,
                                          *patch4_Qv00, *patch4_Qv01);

  Patch* patch4 =
      new HermitePatch(patch4_c1, patch4_c2, patch4_c3, patch4_c4, *patch4_tw00,
                       *patch4_tw10, *patch4_tw01, *patch4_tw11);

  geo->inserePatch(patch4);
  // geo->insereCurva ( patch4_c1 );
  geo->insereCurva(patch4_c2);
  geo->insereCurva(patch4_c3);
  geo->insereCurva(patch4_c4);
  //======================== FIM DO PATCH 4 ===================================

  //=============================== PATCH 5 ===================================
  // Ponto* patch5_p00 = patch1_p11;
  Ponto* patch5_p10 = patch2_p11;
  Ponto* patch5_p01 = patch4_p11;
  Ponto* patch5_p11 = new Vertice(-patch4_p11->x, patch4_p11->y, patch4_p11->z);

  // Vetor* patch5_Qu00 = new Vetor ( *patch5_p00, *patch5_p10 );
  // Vetor* patch5_Qu10 = new Vetor ( *patch5_p00, *patch5_p10 );
  Vetor* patch5_Qu01 =
      new Vetor(patch4_Qu11->x, patch4_Qu11->y, patch4_Qu11->z);
  Vetor* patch5_Qu11 =
      new Vetor(patch5_Qu01->x, -patch5_Qu01->y, -patch5_Qu01->z);

  // Vetor* patch5_Qv00 = new Vetor ( *patch5_p00, *patch5_p01 );
  Vetor* patch5_Qv10 =
      new Vetor(-patch4_Qv10->x, patch4_Qv10->y, patch4_Qv10->z);
  // Vetor* patch5_Qv01 = new Vetor ( *patch5_p00, *patch5_p01 );
  Vetor* patch5_Qv11 =
      new Vetor(-patch4_Qv11->x, patch4_Qv11->y, patch4_Qv11->z);

  Vetor* patch5_tw00 = new Vetor(0.0, 0.0, 20.0);
  Vetor* patch5_tw10 = new Vetor(0.0, 0.0, -20.0);
  Vetor* patch5_tw01 = new Vetor(0.0, 0.0, -5.0);
  Vetor* patch5_tw11 = new Vetor(0.0, 0.0, 5.0);

  Curva* patch5_c1 = patch2_c3;
  Curva* patch5_c2 = new CurvParamHermite(*patch5_p10, *patch5_p11,
                                          *patch5_Qv10, *patch5_Qv11);
  Curva* patch5_c3 = new CurvParamHermite(*patch5_p01, *patch5_p11,
                                          *patch5_Qu01, *patch5_Qu11);
  Curva* patch5_c4 = patch4_c2;

  Patch* patch5 =
      new HermitePatch(patch5_c1, patch5_c2, patch5_c3, patch5_c4, *patch5_tw00,
                       *patch5_tw10, *patch5_tw01, *patch5_tw11);

  geo->inserePatch(patch5);
  // geo->insereCurva ( patch4_c1 );
  geo->insereCurva(patch5_c2);
  geo->insereCurva(patch5_c3);
  // geo->insereCurva ( patch5_c4 );
  //======================== FIM DO PATCH 5 ===================================

  //=============================== PATCH 6 ===================================
  // Ponto* patch6_p00 = patch2_p11;
  Ponto* patch6_p10 = patch3_p11;
  Ponto* patch6_p01 = patch5_p11;
  Ponto* patch6_p11 = new Vertice(-patch4_p01->x, patch4_p01->y, patch4_p01->z);

  // Vetor* patch6_Qu00 = new Vetor ( patch5_Qu11->x, patch5_Qu11->y,
  // patch5_Qu11->z ); Vetor* patch6_Qu10 = new Vetor (
  // patch6_Qu00->x,-patch6_Qu00->y,-patch6_Qu00->z );
  Vetor* patch6_Qu01 =
      new Vetor(patch4_Qu11->x, -patch4_Qu11->y, -patch4_Qu11->z);
  Vetor* patch6_Qu11 =
      new Vetor(patch4_Qu01->x, -patch4_Qu01->y, -patch4_Qu01->z);

  // Vetor* patch6_Qv00 = new Vetor ( *patch6_p00, *patch6_p01 );
  Vetor* patch6_Qv10 =
      new Vetor(-patch4_Qv00->x, patch4_Qv00->y, patch4_Qv00->z);
  // Vetor* patch6_Qv01 = new Vetor ( *patch6_p00, *patch6_p01 );
  Vetor* patch6_Qv11 =
      new Vetor(-patch4_Qv01->x, patch4_Qv01->y, patch4_Qv01->z);

  Vetor* patch6_tw00 = new Vetor(0.0, 0.0, 10.0);
  Vetor* patch6_tw10 = new Vetor(0.0, 0.0, -10.0);
  Vetor* patch6_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch6_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch6_c1 = patch3_c3;
  Curva* patch6_c2 = new CurvParamHermite(*patch6_p10, *patch6_p11,
                                          *patch6_Qv10, *patch6_Qv11);
  Curva* patch6_c3 = new CurvParamHermite(*patch6_p01, *patch6_p11,
                                          *patch6_Qu01, *patch6_Qu11);
  Curva* patch6_c4 = patch5_c2;

  Patch* patch6 =
      new HermitePatch(patch6_c1, patch6_c2, patch6_c3, patch6_c4, *patch6_tw00,
                       *patch6_tw10, *patch6_tw01, *patch6_tw11);

  geo->inserePatch(patch6);
  // geo->insereCurva ( patch4_c1 );
  geo->insereCurva(patch6_c2);
  geo->insereCurva(patch6_c3);
  // geo->insereCurva ( patch5_c4 );
  //======================== FIM DO PATCH 6 ===================================

  //=============================== PATCH 8 ===================================
  Ponto* patch8_p00 = patch4_p11;
  Ponto* patch8_p10 = patch5_p11;
  Ponto* patch8_p01 = new Vertice(-2.5, 7.5, 6.5);
  Ponto* patch8_p11 = new Vertice(2.5, 7.5, 6.5);

  // Vetor* patch8_Qu00 = new Vetor ( patch4_Qu11->x, patch4_Qu11->y,
  // patch4_Qu11->z ); Vetor* patch8_Qu10 = new Vetor (
  // patch5_Qu01->x,-patch5_Qu01->y,-patch5_Qu01->z );
  Vetor* patch8_Qu01 = new Vetor(5.0, -3.5, 3.5);
  Vetor* patch8_Qu11 =
      new Vetor(patch8_Qu01->x, -patch8_Qu01->y, -patch8_Qu01->z);

  Vetor* patch8_Qv00 = new Vetor(*patch5_Qv10);
  Vetor* patch8_Qv10 = new Vetor(*patch5_Qv11);
  Vetor* patch8_Qv01 = new Vetor(*patch8_p00, *patch8_p01);
  Vetor* patch8_Qv11 = new Vetor(*patch8_p10, *patch8_p11);

  Vetor* patch8_tw00 = new Vetor(0.0, 0.0, -8.0);
  Vetor* patch8_tw10 = new Vetor(0.0, 0.0, 8.0);
  Vetor* patch8_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch8_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch8_c1 = patch5_c3;
  Curva* patch8_c2 = new CurvParamHermite(*patch8_p10, *patch8_p11,
                                          *patch8_Qv10, *patch8_Qv11);
  Curva* patch8_c3 = new CurvParamHermite(*patch8_p01, *patch8_p11,
                                          *patch8_Qu01, *patch8_Qu11);
  Curva* patch8_c4 = new CurvParamHermite(*patch8_p00, *patch8_p01,
                                          *patch8_Qv00, *patch8_Qv01);

  Patch* patch8 =
      new HermitePatch(patch8_c1, patch8_c2, patch8_c3, patch8_c4, *patch8_tw00,
                       *patch8_tw10, *patch8_tw01, *patch8_tw11);

  geo->inserePatch(patch8);
  // geo->insereCurva ( patch8_c1 );
  geo->insereCurva(patch8_c2);
  geo->insereCurva(patch8_c3);
  geo->insereCurva(patch8_c4);
  //======================== FIM DO PATCH 8 ===================================

  //=============================== PATCH 10 ==================================
  Ponto* patch10_p00 = patch8_p01;
  Ponto* patch10_p10 = patch8_p11;
  Ponto* patch10_p01 = new Vertice(-2.0, 22.5, 2.5);
  Ponto* patch10_p11 =
      new Vertice(-patch10_p01->x, patch10_p01->y, patch10_p01->z);

  // Vetor* patch10_Qu00 = new Vetor ( *patch8_Qu01 );
  // Vetor* patch10_Qu10 = new Vetor ( *patch8_Qu11 );
  Vetor* patch10_Qu01 = new Vetor(1.0, 2.5, 3.5);
  Vetor* patch10_Qu11 =
      new Vetor(patch10_Qu01->x, -patch10_Qu01->y, -patch10_Qu01->z);

  Vetor* patch10_Qv00 = new Vetor(*patch8_Qv01);
  Vetor* patch10_Qv10 = new Vetor(*patch8_Qv11);
  Vetor* patch10_Qv01 = new Vetor(-1.0, 2.5, 0.0);
  Vetor* patch10_Qv11 =
      new Vetor(-patch10_Qv01->x, patch10_Qv01->y, patch10_Qv01->z);

  Vetor* patch10_tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch10_tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch10_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch10_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch10_c1 = patch8_c3;
  Curva* patch10_c2 = new CurvParamHermite(*patch10_p10, *patch10_p11,
                                           *patch10_Qv10, *patch10_Qv11);
  Curva* patch10_c3 = new CurvParamHermite(*patch10_p01, *patch10_p11,
                                           *patch10_Qu01, *patch10_Qu11);
  Curva* patch10_c4 = new CurvParamHermite(*patch10_p00, *patch10_p01,
                                           *patch10_Qv00, *patch10_Qv01);

  Patch* patch10 = new HermitePatch(patch10_c1, patch10_c2, patch10_c3,
                                    patch10_c4, *patch10_tw00, *patch10_tw10,
                                    *patch10_tw01, *patch10_tw11);

  geo->inserePatch(patch10);
  // geo->insereCurva ( patch10_c1 );
  geo->insereCurva(patch10_c2);
  geo->insereCurva(patch10_c3);
  geo->insereCurva(patch10_c4);
  //======================== FIM DO PATCH 10 ==================================

  //=============================== PATCH 7 ===================================
  Ponto* patch7_p00 = patch4_p01;
  // Ponto* patch7_p10 = patch4_p11;
  Ponto* patch7_p01 = patch10_p01;
  Ponto* patch7_p11 = patch10_p00;

  // Vetor* patch7_Qu00 = new Vetor ( *patch4_Qu01  );
  // Vetor* patch7_Qu10 = new Vetor ( *patch4_Qu11  );
  Vetor* patch7_Qu01 = new Vetor(-(*patch10_Qv01));
  Vetor* patch7_Qu11 = new Vetor(-(*patch10_Qv00));

  Vetor* patch7_Qv00 = new Vetor(5.0, 1.5, -8.0);
  // Vetor* patch7_Qv10 = new Vetor ( *patch8_Qv00 );
  Vetor* patch7_Qv01 =
      new Vetor(-patch7_Qv00->x, patch7_Qv00->y, -patch7_Qv00->z);
  // Vetor* patch7_Qv11 = new Vetor ( *patch8_Qv00 );

  Vetor* patch7_tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch7_tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch7_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch7_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch7_c1 = patch4_c3;
  Curva* patch7_c2 = patch8_c4;
  Curva* patch7_c3 = new CurvParamHermite(*patch7_p01, *patch7_p11,
                                          *patch7_Qu01, *patch7_Qu11);
  Curva* patch7_c4 = new CurvParamHermite(*patch7_p00, *patch7_p01,
                                          *patch7_Qv00, *patch7_Qv01);

  Patch* patch7 =
      new HermitePatch(patch7_c1, patch7_c2, patch7_c3, patch7_c4, *patch7_tw00,
                       *patch7_tw10, *patch7_tw01, *patch7_tw11);

  geo->inserePatch(patch7);
  // geo->insereCurva ( patch7_c1 );
  // geo->insereCurva ( patch7_c2 );
  geo->insereCurva(patch7_c3);
  geo->insereCurva(patch7_c4);
  //======================== FIM DO PATCH 7 ===================================

  //=============================== PATCH 9 ===================================
  // Ponto* patch9_p00 = patch6_p01;
  Ponto* patch9_p10 = patch6_p11;
  // Ponto* patch9_p01 = patch8_p11;
  Ponto* patch9_p11 = patch10_p11;

  // Vetor* patch9_Qu00 = new Vetor ( *patch8_Qu10 );
  // Vetor* patch9_Qu10 = new Vetor ( *patch9_p00, *patch9_p10 );
  // Vetor* patch9_Qu01 = new Vetor ( *patch9_p01, *patch9_p11 );
  // Vetor* patch9_Qu11 = new Vetor ( *patch9_p01, *patch9_p11 );

  // Vetor* patch9_Qv00 = new Vetor ( *patch9_p00, *patch9_p01 );
  Vetor* patch9_Qv10 =
      new Vetor(-patch7_Qv00->x, patch7_Qv00->y, patch7_Qv00->z);
  // Vetor* patch9_Qv01 = new Vetor ( *patch9_p00, *patch9_p01 );
  Vetor* patch9_Qv11 =
      new Vetor(-patch9_Qv10->x, patch9_Qv10->y, -patch9_Qv10->z);

  Vetor* patch9_tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch9_tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch9_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch9_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch9_c1 = patch6_c3;
  Curva* patch9_c2 = new CurvParamHermite(*patch9_p10, *patch9_p11,
                                          *patch9_Qv10, *patch9_Qv11);
  Curva* patch9_c3 = patch10_c2;
  Curva* patch9_c4 = patch8_c2;

  Patch* patch9 =
      new HermitePatch(patch9_c1, patch9_c2, patch9_c3, patch9_c4, *patch9_tw00,
                       *patch9_tw10, *patch9_tw01, *patch9_tw11);

  geo->inserePatch(patch9);
  // geo->insereCurva ( patch9_c1 );
  geo->insereCurva(patch9_c2);
  // geo->insereCurva ( patch9_c3 );
  // geo->insereCurva ( patch9_c4 );
  //======================== FIM DO PATCH 9 ===================================

  //=============================== PATCH 11 ==================================
  Ponto* patch11_p00 = patch1_p00;
  // Ponto* patch11_p10 = patch1_p01;
  Ponto* patch11_p01 = new Vertice(-8.0, 5.0, 0.0);
  Ponto* patch11_p11 = patch4_p01;

  // Vetor* patch11_Qu00 = new Vetor ( *patch11_p00, *patch11_p10 );
  // Vetor* patch11_Qu10 = new Vetor ( *patch11_p00, *patch11_p10 );
  Vetor* patch11_Qu01 = new Vetor(*patch11_p01, *patch11_p11);
  Vetor* patch11_Qu11 = new Vetor(*patch11_p01, *patch11_p11);

  Vetor* patch11_Qv00 = new Vetor(*patch11_p00, *patch11_p01);
  // Vetor* patch11_Qv10 = new Vetor ( *patch11_p10, *patch11_p11 );
  Vetor* patch11_Qv01 = new Vetor(*patch11_p00, *patch11_p01);
  // Vetor* patch11_Qv11 = new Vetor ( *patch11_p10, *patch11_p11 );

  Vetor* patch11_tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch11_tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch11_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch11_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch11_c1 = patch1_c4;
  Curva* patch11_c2 = patch4_c4;
  Curva* patch11_c3 = new CurvParamHermite(*patch11_p01, *patch11_p11,
                                           *patch11_Qu01, *patch11_Qu11);
  Curva* patch11_c4 = new CurvParamHermite(*patch11_p00, *patch11_p01,
                                           *patch11_Qv00, *patch11_Qv01);

  Patch* patch11 = new HermitePatch(patch11_c1, patch11_c2, patch11_c3,
                                    patch11_c4, *patch11_tw00, *patch11_tw10,
                                    *patch11_tw01, *patch11_tw11);

  geo->inserePatch(patch11);
  // geo->insereCurva ( patch11_c1 );
  // geo->insereCurva ( patch11_c2 );
  geo->insereCurva(patch11_c3);
  geo->insereCurva(patch11_c4);
  //======================== FIM DO PATCH 11 ==================================

  //=============================== PATCH 12 ==================================
  Ponto* patch12_p00 = patch3_p10;
  Ponto* patch12_p10 =
      new Vertice(-patch11_p01->x, patch11_p01->y, patch11_p01->z);
  // Ponto* patch12_p01 = patch3_p11;
  Ponto* patch12_p11 = patch6_p11;

  Vetor* patch12_Qu00 = new Vetor(*patch12_p00, *patch12_p10);
  Vetor* patch12_Qu10 = new Vetor(*patch12_p00, *patch12_p10);
  // Vetor* patch12_Qu01 = new Vetor ( *patch12_p01, *patch12_p11 );
  // Vetor* patch12_Qu11 = new Vetor ( *patch12_p01, *patch12_p11 );

  // Vetor* patch12_Qv00 = new Vetor ( *patch12_p00, *patch12_p01 );
  Vetor* patch12_Qv10 = new Vetor(*patch12_p10, *patch12_p11);
  // Vetor* patch12_Qv01 = new Vetor ( *patch12_p00, *patch12_p01 );
  Vetor* patch12_Qv11 = new Vetor(*patch12_p10, *patch12_p11);

  Vetor* patch12_tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch12_tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch12_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch12_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch12_c1 = new CurvParamHermite(*patch12_p00, *patch12_p10,
                                           *patch12_Qu00, *patch12_Qu10);
  Curva* patch12_c2 = new CurvParamHermite(*patch12_p10, *patch12_p11,
                                           *patch12_Qv10, *patch12_Qv11);
  Curva* patch12_c3 = patch6_c2;
  Curva* patch12_c4 = patch3_c2;

  Patch* patch12 = new HermitePatch(patch12_c1, patch12_c2, patch12_c3,
                                    patch12_c4, *patch12_tw00, *patch12_tw10,
                                    *patch12_tw01, *patch12_tw11);

  geo->inserePatch(patch12);
  geo->insereCurva(patch12_c1);
  geo->insereCurva(patch12_c2);
  // geo->insereCurva ( patch12_c3 );
  // geo->insereCurva ( patch12_c4 );
  //======================== FIM DO PATCH 12 ==================================

  //=============================== PATCH 13 ==================================
  Ponto* patch13_p00 = patch11_p01;
  // Ponto* patch13_p10 = patch11_p11;
  Ponto* patch13_p01 = new Vertice(-1.0, 21.5, 2.0);
  Ponto* patch13_p11 = patch10_p01;

  // Vetor* patch13_Qu00 = new Vetor ( *patch13_p00, *patch13_p10 );
  // Vetor* patch13_Qu10 = new Vetor ( *patch13_p00, *patch13_p10 );
  Vetor* patch13_Qu01 = new Vetor(*patch13_p01, *patch13_p11);
  Vetor* patch13_Qu11 = new Vetor(*patch13_p01, *patch13_p11);

  Vetor* patch13_Qv00 = new Vetor(*patch13_p00, *patch13_p01);
  // Vetor* patch13_Qv10 = new Vetor ( *patch13_p10, *patch13_p11 );
  Vetor* patch13_Qv01 = new Vetor(*patch13_p00, *patch11_p01);
  // Vetor* patch13_Qv11 = new Vetor ( *patch13_p10, *patch13_p11 );

  Vetor* patch13_tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch13_tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch13_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch13_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch13_c1 = patch11_c3;
  Curva* patch13_c2 = patch7_c4;
  Curva* patch13_c3 = new CurvParamHermite(*patch13_p01, *patch13_p11,
                                           *patch13_Qu01, *patch13_Qu11);
  Curva* patch13_c4 = new CurvParamHermite(*patch13_p00, *patch13_p01,
                                           *patch13_Qv00, *patch13_Qv01);

  Patch* patch13 = new HermitePatch(patch13_c1, patch13_c2, patch13_c3,
                                    patch13_c4, *patch13_tw00, *patch13_tw10,
                                    *patch13_tw01, *patch13_tw11);

  geo->inserePatch(patch13);
  // geo->insereCurva ( patch13_c1 );
  // geo->insereCurva ( patch13_c2 );
  geo->insereCurva(patch13_c3);
  geo->insereCurva(patch13_c4);
  //======================== FIM DO PATCH 13 ==================================

  //=============================== PATCH 14 ==================================
  Ponto* patch14_p00 = patch12_p10;
  Ponto* patch14_p10 =
      new Vertice(-patch13_p01->x, patch13_p01->y, patch13_p01->z);
  // Ponto* patch14_p01 = patch6_p11;
  Ponto* patch14_p11 = patch10_p11;

  Vetor* patch14_Qu00 = new Vetor(*patch14_p00, *patch14_p10);
  Vetor* patch14_Qu10 = new Vetor(*patch14_p00, *patch14_p10);
  // Vetor* patch14_Qu01 = new Vetor ( *patch14_p01, *patch14_p11 );
  // Vetor* patch14_Qu11 = new Vetor ( *patch14_p01, *patch14_p11 );

  // Vetor* patch14_Qv00 = new Vetor ( *patch14_p00, *patch14_p01 );
  Vetor* patch14_Qv10 = new Vetor(*patch14_p10, *patch14_p11);
  // Vetor* patch14_Qv01 = new Vetor ( *patch14_p00, *patch14_p01 );
  Vetor* patch14_Qv11 = new Vetor(*patch14_p10, *patch14_p11);

  Vetor* patch14_tw00 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch14_tw10 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch14_tw01 = new Vetor(0.0, 0.0, 0.0);
  Vetor* patch14_tw11 = new Vetor(0.0, 0.0, 0.0);

  Curva* patch14_c1 = new CurvParamHermite(*patch14_p00, *patch14_p10,
                                           *patch14_Qu00, *patch14_Qu10);
  Curva* patch14_c2 = new CurvParamHermite(*patch14_p10, *patch14_p11,
                                           *patch14_Qv10, *patch14_Qv11);
  Curva* patch14_c3 = patch9_c2;
  Curva* patch14_c4 = patch12_c2;

  Patch* patch14 = new HermitePatch(patch14_c1, patch14_c2, patch14_c3,
                                    patch14_c4, *patch14_tw00, *patch14_tw10,
                                    *patch14_tw01, *patch14_tw11);

  geo->inserePatch(patch14);
  geo->insereCurva(patch14_c1);
  geo->insereCurva(patch14_c2);
  // geo->insereCurva ( patch14_c3 );
  // geo->insereCurva ( patch14_c4 );
  return geo;
  //=========================== FIM DO PATCH 14
  //==================================
  // Fim do Exemplo do Nariz
  //==============================================================================
}

Geometria* Modelos3d::modelUtahteapot(Geometria* geo) {
  //==============================================================================
  // Exemplo do Utahteapot
  //==============================================================================

  //=============================== PATCH 1 ==================================
  Ponto* p100 = new Vertice(1.40000, 0.00000, 2.40000);
  Ponto* p110 = new Vertice(1.40000, -0.78400, 2.40000);
  Ponto* p120 = new Vertice(0.78400, -1.40000, 2.40000);
  Ponto* p130 = new Vertice(0.00000, -1.40000, 2.40000);

  Ponto* p101 = new Vertice(1.33750, 0.00000, 2.53125);
  Ponto* p111 = new Vertice(1.33750, -0.74900, 2.53125);
  Ponto* p121 = new Vertice(0.74900, -1.33750, 2.53125);
  Ponto* p131 = new Vertice(0.00000, -1.33750, 2.53125);

  Ponto* p102 = new Vertice(1.43750, 0.00000, 2.53125);
  Ponto* p112 = new Vertice(1.43750, -0.80500, 2.53125);
  Ponto* p122 = new Vertice(0.80500, -1.43750, 2.53125);
  Ponto* p132 = new Vertice(0.00000, -1.43750, 2.53125);

  Ponto* p103 = new Vertice(1.50000, 0.00000, 2.40000);
  Ponto* p113 = new Vertice(1.50000, -0.84000, 2.40000);
  Ponto* p123 = new Vertice(0.84000, -1.50000, 2.40000);
  Ponto* p133 = new Vertice(0.00000, -1.50000, 2.40000);

  Curva* patch1_c1 = new CurvParamBezier(*p100, *p110, *p120, *p130);
  Curva* patch1_c2 = new CurvParamBezier(*p130, *p131, *p132, *p133);
  Curva* patch1_c3 = new CurvParamBezier(*p103, *p113, *p123, *p133);
  Curva* patch1_c4 = new CurvParamBezier(*p100, *p101, *p102, *p103);

  Patch* patch1 = new BezierPatch(patch1_c1, patch1_c2, patch1_c3, patch1_c4,
                                  *p111, *p121, *p112, *p122);

  geo->inserePatch(patch1);
  geo->insereCurva(patch1_c1);
  geo->insereCurva(patch1_c2);
  geo->insereCurva(patch1_c3);
  geo->insereCurva(patch1_c4);
  //======================== FIM DO PATCH 1 ==================================

  //=============================== PATCH 2 ==================================
  //		Ponto* p200 = p130; // new Vertice (  0.00000, -1.40000,  2.40000
  //);
  Ponto* p210 = new Vertice(-0.78400, -1.40000, 2.40000);
  Ponto* p220 = new Vertice(-1.40000, -0.78400, 2.40000);
  Ponto* p230 = new Vertice(-1.40000, 0.00000, 2.40000);

  //		Ponto* p201 = p131; // new Vertice (  0.00000, -1.33750, 2.53125
  //);
  Ponto* p211 = new Vertice(-0.74900, -1.33750, 2.53125);
  Ponto* p221 = new Vertice(-1.33750, -0.74900, 2.53125);
  Ponto* p231 = new Vertice(-1.33750, 0.00000, 2.53125);

  //		Ponto* p202 = p132; //new Vertice (  0.00000, -1.43750, 2.53125
  //);
  Ponto* p212 = new Vertice(-0.80500, -1.43750, 2.53125);
  Ponto* p222 = new Vertice(-1.43750, -0.80500, 2.53125);
  Ponto* p232 = new Vertice(-1.43750, 0.00000, 2.53125);

  //		Ponto* p203 = p133; //new Vertice (  0.00000, -1.50000, 2.40000
  //);
  Ponto* p213 = new Vertice(-0.84000, -1.50000, 2.40000);
  Ponto* p223 = new Vertice(-1.50000, -0.84000, 2.40000);
  Ponto* p233 = new Vertice(-1.50000, 0.00000, 2.40000);

  Curva* patch2_c1 = new CurvParamBezier(
      *p130, *p210, *p220, *p230);  //( *p200, *p210, *p220, *p230 );
  Curva* patch2_c2 = new CurvParamBezier(*p230, *p231, *p232, *p233);
  Curva* patch2_c3 = new CurvParamBezier(*p133, *p213, *p223, *p233);
  // Curva* patch2_c4 = patch1_c2; //new CurvParamBezier ( *p130, *p131, *p132,
  // *p133 ); //( *p200, *p201, *p202, *p203 );

  Patch* patch2 = new BezierPatch(patch2_c1, patch2_c2, patch2_c3, patch1_c2,
                                  *p211, *p221, *p212, *p222);

  geo->inserePatch(patch2);
  geo->insereCurva(patch2_c1);
  geo->insereCurva(patch2_c2);
  geo->insereCurva(patch2_c3);
  // geo->insereCurva ( patch2_c4 );
  //======================== FIM DO PATCH 2 ==================================

  //=============================== PATCH 3 ==================================
  //		Ponto* p300 = p230; //new Vertice ( -1.40000, 0.00000, 2.40000
  //);
  Ponto* p310 = new Vertice(-1.40000, 0.78400, 2.40000);
  Ponto* p320 = new Vertice(-0.78400, 1.40000, 2.40000);
  Ponto* p330 = new Vertice(0.00000, 1.40000, 2.40000);

  //		Ponto* p301 = p231; //new Vertice ( -1.33750, 0.00000, 2.53125
  //);
  Ponto* p311 = new Vertice(-1.33750, 0.74900, 2.53125);
  Ponto* p321 = new Vertice(-0.74900, 1.33750, 2.53125);
  Ponto* p331 = new Vertice(0.00000, 1.33750, 2.53125);

  //		Ponto* p302 = p232; //new Vertice ( -1.43750, 0.00000, 2.53125
  //);
  Ponto* p312 = new Vertice(-1.43750, 0.80500, 2.53125);
  Ponto* p322 = new Vertice(-0.80500, 1.43750, 2.53125);
  Ponto* p332 = new Vertice(0.00000, 1.43750, 2.53125);

  //		Ponto* p303 = p233; //new Vertice ( -1.50000, 0.00000, 2.40000
  //);
  Ponto* p313 = new Vertice(-1.50000, 0.84000, 2.40000);
  Ponto* p323 = new Vertice(-0.84000, 1.50000, 2.40000);
  Ponto* p333 = new Vertice(0.00000, 1.50000, 2.40000);

  Curva* patch3_c1 = new CurvParamBezier(*p230, *p310, *p320, *p330);
  Curva* patch3_c2 = new CurvParamBezier(*p330, *p331, *p332, *p333);
  Curva* patch3_c3 = new CurvParamBezier(*p233, *p313, *p323, *p333);
  //		Curva* patch3_c4 = new CurvParamBezier ( *p230, *p231, *p232, *p233
  //);

  Patch* patch3 = new BezierPatch(patch3_c1, patch3_c2, patch3_c3, patch2_c2,
                                  *p311, *p321, *p312, *p322);

  geo->inserePatch(patch3);
  geo->insereCurva(patch3_c1);
  geo->insereCurva(patch3_c2);
  geo->insereCurva(patch3_c3);
  //		geo->insereCurva ( patch3_c4 );
  //======================== FIM DO PATCH 3 ==================================

  //=============================== PATCH 4 ==================================
  // Ponto* p400 = p330; //new Vertice ( 0.00000, 1.40000, 2.40000 );
  Ponto* p410 = new Vertice(0.78400, 1.40000, 2.40000);
  Ponto* p420 = new Vertice(1.40000, 0.78400, 2.40000);
  // Ponto* p430 = p100; // new Vertice ( 1.40000, 0.00000, 2.40000 );

  // Ponto* p401 = p331; //new Vertice (	0.00000, 1.33750, 2.53125 );
  Ponto* p411 = new Vertice(0.74900, 1.33750, 2.53125);
  Ponto* p421 = new Vertice(1.33750, 0.74900, 2.53125);
  // Ponto* p431 = p101; // new Vertice ( 1.33750, 0.00000, 2.53125 );

  // Ponto* p402 = p332; //new Vertice (	0.00000, 1.43750, 2.53125 );
  Ponto* p412 = new Vertice(0.80500, 1.43750, 2.53125);
  Ponto* p422 = new Vertice(1.43750, 0.80500, 2.53125);
  // Ponto* p432 = p102; //new Vertice ( 1.43750, 0.00000, 2.53125 );

  // Ponto* p403 = p333; //new Vertice (	0.00000, 1.50000, 2.40000 );
  Ponto* p413 = new Vertice(0.84000, 1.50000, 2.40000);
  Ponto* p423 = new Vertice(1.50000, 0.84000, 2.40000);
  // Ponto* p433 = p103; //new Vertice ( 1.50000, 0.00000, 2.40000 );

  Curva* patch4_c1 = new CurvParamBezier(
      *p330, *p410, *p420, *p100);  // ( *p400, *p410, *p420, *p430 );
  // Curva* patch4_c2 = new CurvParamBezier ( *p100, *p101, *p102, *p103 ); // (
  // *p430, *p431, *p432, *p433 );
  Curva* patch4_c3 = new CurvParamBezier(
      *p333, *p413, *p423, *p103);  // ( *p403, *p413, *p423, *p433 );
  // Curva* patch4_c4 = new CurvParamBezier ( *p330, *p331, *p332, *p333 ); // (
  // *p400, *p401, *p402, *p403 );

  Patch* patch4 = new BezierPatch(patch4_c1, patch1_c4, patch4_c3, patch3_c2,
                                  *p411, *p421, *p412, *p422);

  geo->inserePatch(patch4);
  geo->insereCurva(patch4_c1);
  // geo->insereCurva ( patch4_c2 );
  geo->insereCurva(patch4_c3);
  // geo->insereCurva ( patch4_c4 );
  //======================== FIM DO PATCH 4 ==================================

  //=============================== PATCH 5 ==================================
  //		Ponto* p500 = p103; //new Vertice (	1.50000, 0.00000, 2.40000
  //); 		Ponto* p510 = p113; //new Vertice ( 1.50000, -0.84000, 2.40000 ); 		Ponto*
  //p520 = p123; //new Vertice ( 0.84000, -1.50000, 2.40000 ); 		Ponto* p530 =
  //p133; //new Vertice ( 0.00000, -1.50000, 2.40000 );

  Ponto* p501 = new Vertice(1.75000, 0.00000, 1.87500);
  Ponto* p511 = new Vertice(1.75000, -0.98000, 1.87500);
  Ponto* p521 = new Vertice(0.98000, -1.75000, 1.87500);
  Ponto* p531 = new Vertice(0.00000, -1.75000, 1.87500);

  Ponto* p502 = new Vertice(2.00000, 0.00000, 1.35000);
  Ponto* p512 = new Vertice(2.00000, -1.12000, 1.35000);
  Ponto* p522 = new Vertice(1.12000, -2.00000, 1.35000);
  Ponto* p532 = new Vertice(0.00000, -2.00000, 1.35000);

  Ponto* p503 = new Vertice(2.00000, 0.00000, 0.90000);
  Ponto* p513 = new Vertice(2.00000, -1.12000, 0.90000);
  Ponto* p523 = new Vertice(1.12000, -2.00000, 0.90000);
  Ponto* p533 = new Vertice(0.00000, -2.00000, 0.90000);

  // Curva* patch5_c1 = patch1_c3; //new CurvParamBezier ( *p103, *p113, *p123,
  // *p133 ); // ( *p500, *p510, *p520, *p530 );
  Curva* patch5_c2 = new CurvParamBezier(
      *p133, *p531, *p532, *p533);  // ( *p530, *p531, *p532, *p533 );
  Curva* patch5_c3 = new CurvParamBezier(
      *p503, *p513, *p523, *p533);  // ( *p503, *p513, *p523, *p533 );
  Curva* patch5_c4 = new CurvParamBezier(
      *p103, *p501, *p502, *p503);  // ( *p500, *p501, *p502, *p503 );

  Patch* patch5 = new BezierPatch(patch1_c3, patch5_c2, patch5_c3, patch5_c4,
                                  *p511, *p521, *p512, *p522);

  geo->inserePatch(patch5);
  // geo->insereCurva ( patch5_c1 );
  geo->insereCurva(patch5_c2);
  geo->insereCurva(patch5_c3);
  geo->insereCurva(patch5_c4);
  //======================== FIM DO PATCH 5 ==================================

  //=============================== PATCH 6 ==================================
  // Ponto* p600 = p133; //new Vertice (	0.00000, -1.50000, 2.40000 );
  //		Ponto* p610 = p213; //new Vertice ( -0.84000, -1.50000, 2.40000
  //); 		Ponto* p620 = p223; //new Vertice ( -1.50000, -0.84000, 2.40000 ); 		Ponto*
  //p630 = p303; //new Vertice ( -1.50000, 0.00000, 2.40000 );

  //		Ponto* p601 = p531; //new Vertice (	0.00000, -1.75000, 1.87500
  //);
  Ponto* p611 = new Vertice(-0.98000, -1.75000, 1.87500);
  Ponto* p621 = new Vertice(-1.75000, -0.98000, 1.87500);
  Ponto* p631 = new Vertice(-1.75000, 0.00000, 1.87500);

  //		Ponto* p602 = p532; //new Vertice (	0.00000, -2.00000, 1.35000
  //);
  Ponto* p612 = new Vertice(-1.12000, -2.00000, 1.35000);
  Ponto* p622 = new Vertice(-2.00000, -1.12000, 1.35000);
  Ponto* p632 = new Vertice(-2.00000, 0.00000, 1.35000);

  //		Ponto* p603 = p533; //new Vertice (	0.00000, -2.00000, 0.90000
  //);
  Ponto* p613 = new Vertice(-1.12000, -2.00000, 0.90000);
  Ponto* p623 = new Vertice(-2.00000, -1.12000, 0.90000);
  Ponto* p633 = new Vertice(-2.00000, 0.00000, 0.90000);

  //		Curva* patch6_c1 = new CurvParamBezier ( *p133, *p213, *p223, *p233
  //); // ( *p600, *p610, *p620, *p630 );
  Curva* patch6_c2 = new CurvParamBezier(
      *p233, *p631, *p632, *p633);  // ( *p630, *p631, *p632, *p633 );
  Curva* patch6_c3 = new CurvParamBezier(
      *p533, *p613, *p623, *p633);  // ( *p603, *p613, *p623, *p633 );
  //		Curva* patch6_c4 = new CurvParamBezier ( *p133, *p531, *p532, *p533
  //); // ( *p600, *p601, *p602, *p603 );

  Patch* patch6 = new BezierPatch(patch2_c3, patch6_c2, patch6_c3, patch5_c2,
                                  *p611, *p621, *p612, *p622);

  geo->inserePatch(patch6);
  //		geo->insereCurva ( patch6_c1 );
  geo->insereCurva(patch6_c2);
  geo->insereCurva(patch6_c3);
  //		geo->insereCurva ( patch6_c4 );
  //======================== FIM DO PATCH 6 ==================================

  //=============================== PATCH 7 ==================================
  //		Ponto* p700 = p233; //new Vertice (	-1.50000, 0.00000, 2.40000
  //); 		Ponto* p710 = p313; //new Vertice ( -1.50000, 0.84000, 2.40000 ); 		Ponto*
  //p720 = p323; //new Vertice ( -0.84000, 1.50000, 2.40000 ); 		Ponto* p730 =
  //p333; //new Vertice ( 0.00000, 1.50000, 2.40000 );

  //		Ponto* p701 = p631; //new Vertice (-1.75000, 0.00000, 1.87500 );
  Ponto* p711 = new Vertice(-1.75000, 0.98000, 1.87500);
  Ponto* p721 = new Vertice(-0.98000, 1.75000, 1.87500);
  Ponto* p731 = new Vertice(0.00000, 1.75000, 1.87500);

  //		Ponto* p702 = p632; //new Vertice (-2.00000, 0.00000, 1.35000 );
  Ponto* p712 = new Vertice(-2.00000, 1.12000, 1.35000);
  Ponto* p722 = new Vertice(-1.12000, 2.00000, 1.35000);
  Ponto* p732 = new Vertice(0.00000, 2.00000, 1.35000);

  //		Ponto* p703 = p633; //new Vertice (-2.00000, 0.00000, 0.90000 );
  Ponto* p713 = new Vertice(-2.00000, 1.12000, 0.90000);
  Ponto* p723 = new Vertice(-1.12000, 2.00000, 0.90000);
  Ponto* p733 = new Vertice(0.00000, 2.00000, 0.90000);

  //		Curva* patch7_c1 = new CurvParamBezier ( *p233, *p313, *p323, *p333
  //);
  Curva* patch7_c2 = new CurvParamBezier(*p333, *p731, *p732, *p733);
  Curva* patch7_c3 = new CurvParamBezier(*p633, *p713, *p723, *p733);
  //		Curva* patch7_c4 = new CurvParamBezier ( *p233, *p631, *p632, *p633
  //);

  Patch* patch7 = new BezierPatch(patch3_c3, patch7_c2, patch7_c3, patch6_c2,
                                  *p711, *p721, *p712, *p722);

  geo->inserePatch(patch7);
  //		geo->insereCurva ( patch7_c1 );
  geo->insereCurva(patch7_c2);
  geo->insereCurva(patch7_c3);
  //		geo->insereCurva ( patch7_c4 );
  //======================== FIM DO PATCH 7 ==================================

  //=============================== PATCH 8 ==================================
  //		Ponto* p800 = p333; //new Vertice (	0.00000, 1.50000, 2.40000
  //); 		Ponto* p810 = p413; //new Vertice ( 0.84000, 1.50000, 2.40000 ); 		Ponto*
  //p820 = p423; //new Vertice ( 1.50000, 0.84000, 2.40000 ); 		Ponto* p830 =
  //p103; //new Vertice ( 1.50000, 0.00000, 2.40000 );

  //		Ponto* p801 = p731; //new Vertice (	0.00000, 1.75000, 1.87500
  //);
  Ponto* p811 = new Vertice(0.98000, 1.75000, 1.87500);
  Ponto* p821 = new Vertice(1.75000, 0.98000, 1.87500);
  //		Ponto* p831 = p501; //new Vertice ( 1.75000, 0.00000, 1.87500 );

  //		Ponto* p802 = p732; //new Vertice (	0.00000, 2.00000, 1.35000
  //);
  Ponto* p812 = new Vertice(1.12000, 2.00000, 1.35000);
  Ponto* p822 = new Vertice(2.00000, 1.12000, 1.35000);
  //		Ponto* p832 = p502; //new Vertice ( 2.00000, 0.00000, 1.35000 );

  //		Ponto* p803 = p733; //new Vertice (	0.00000, 2.00000, 0.90000
  //);
  Ponto* p813 = new Vertice(1.12000, 2.00000, 0.90000);
  Ponto* p823 = new Vertice(2.00000, 1.12000, 0.90000);
  //		Ponto* p833 = p503; //new Vertice ( 2.00000, 0.00000, 0.90000 );

  //		Curva* patch8_c1 = new CurvParamBezier ( *p333, *p413, *p423, *p103
  //); 		Curva* patch8_c2 = new CurvParamBezier ( *p103, *p501, *p502, *p503 );
  Curva* patch8_c3 = new CurvParamBezier(*p733, *p813, *p823, *p503);
  //		Curva* patch8_c4 = new CurvParamBezier ( *p333, *p731, *p732, *p733
  //);

  Patch* patch8 = new BezierPatch(patch4_c3, patch5_c4, patch8_c3, patch7_c2,
                                  *p811, *p821, *p812, *p822);

  geo->inserePatch(patch8);
  //		geo->insereCurva ( patch8_c1 );
  //		geo->insereCurva ( patch8_c2 );
  geo->insereCurva(patch8_c3);
  //		geo->insereCurva ( patch8_c4 );
  //======================== FIM DO PATCH 8 ==================================

  //=============================== PATCH 9 ==================================
  //		Ponto* p900 = p503; //new Vertice (	2.00000, 0.00000, 0.90000
  //); 		Ponto* p910 = p513; //new Vertice ( 2.00000, -1.12000, 0.90000 ); 		Ponto*
  //p920 = p523; //new Vertice ( 1.12000, -2.00000, 0.90000 ); 		Ponto* p930 =
  //p533; //new Vertice ( 0.00000, -2.00000, 0.90000 );

  Ponto* p901 = new Vertice(2.00000, 0.00000, 0.45000);
  Ponto* p911 = new Vertice(2.00000, -1.12000, 0.45000);
  Ponto* p921 = new Vertice(1.12000, -2.00000, 0.45000);
  Ponto* p931 = new Vertice(0.00000, -2.00000, 0.45000);

  Ponto* p902 = new Vertice(1.50000, 0.00000, 0.22500);
  Ponto* p912 = new Vertice(1.50000, -0.84000, 0.22500);
  Ponto* p922 = new Vertice(0.84000, -1.50000, 0.22500);
  Ponto* p932 = new Vertice(0.00000, -1.50000, 0.22500);

  Ponto* p903 = new Vertice(1.50000, 0.00000, 0.15000);
  Ponto* p913 = new Vertice(1.50000, -0.84000, 0.15000);
  Ponto* p923 = new Vertice(0.84000, -1.50000, 0.15000);
  Ponto* p933 = new Vertice(0.00000, -1.50000, 0.15000);

  //		Curva* patch9_c1 = new CurvParamBezier ( *p503, *p513, *p523, *p533
  //);
  Curva* patch9_c2 = new CurvParamBezier(*p533, *p931, *p932, *p933);
  Curva* patch9_c3 = new CurvParamBezier(*p903, *p913, *p923, *p933);
  Curva* patch9_c4 = new CurvParamBezier(*p503, *p901, *p902, *p903);

  Patch* patch9 = new BezierPatch(patch5_c3, patch9_c2, patch9_c3, patch9_c4,
                                  *p911, *p921, *p912, *p922);

  geo->inserePatch(patch9);
  //		geo->insereCurva ( patch9_c1 );
  geo->insereCurva(patch9_c2);
  geo->insereCurva(patch9_c3);
  geo->insereCurva(patch9_c4);
  //======================== FIM DO PATCH 9 ==================================

  //============================== PATCH 10 ==================================
  //		Ponto* p1000 = p533; //new Vertice ( 0.00000,-2.00000, 0.90000
  //); 		Ponto* p1010 = p613; //new Vertice (-1.12000,-2.00000, 0.90000 ); 		Ponto*
  //p1020 = p623; //new Vertice (-2.00000,-1.12000, 0.90000 ); 		Ponto* p1030 =
  //p633; //new Vertice ( -2.00000, 0.00000, 0.90000 );

  //		Ponto* p1001 = p931; //new Vertice ( 0.00000,-2.00000, 0.45000
  //);
  Ponto* p1011 = new Vertice(-1.12000, -2.00000, 0.45000);
  Ponto* p1021 = new Vertice(-2.00000, -1.12000, 0.45000);
  Ponto* p1031 = new Vertice(-2.00000, 0.00000, 0.45000);

  //		Ponto* p1002 = p932; //new Vertice ( 0.00000,-1.50000, 0.22500
  //);
  Ponto* p1012 = new Vertice(-0.84000, -1.50000, 0.22500);
  Ponto* p1022 = new Vertice(-1.50000, -0.84000, 0.22500);
  Ponto* p1032 = new Vertice(-1.50000, 0.00000, 0.22500);

  //		Ponto* p1003 = p933; //new Vertice ( 0.00000,-1.50000, 0.15000
  //);
  Ponto* p1013 = new Vertice(-0.84000, -1.50000, 0.15000);
  Ponto* p1023 = new Vertice(-1.50000, -0.84000, 0.15000);
  Ponto* p1033 = new Vertice(-1.50000, 0.00000, 0.15000);

  //		Curva* patch10_c1 = new CurvParamBezier ( *p533, *p613, *p623, *p633
  //);
  Curva* patch10_c2 = new CurvParamBezier(*p633, *p1031, *p1032, *p1033);
  Curva* patch10_c3 = new CurvParamBezier(*p933, *p1013, *p1023, *p1033);
  //		Curva* patch10_c4 = new CurvParamBezier ( *p533, *p931, *p932, *p933
  //);

  Patch* patch10 = new BezierPatch(patch6_c3, patch10_c2, patch10_c3, patch9_c2,
                                   *p1011, *p1021, *p1012, *p1022);

  geo->inserePatch(patch10);
  //		geo->insereCurva ( patch10_c1 );
  geo->insereCurva(patch10_c2);
  geo->insereCurva(patch10_c3);
  //		geo->insereCurva ( patch10_c4 );
  //======================== FIM DO PATCH 10 =================================

  //============================== PATCH 11 ==================================
  //		Ponto* p633 = p633; //new Vertice ( -2.00000, 0.00000, 0.90000
  //); 		Ponto* p713 = p713; //new Vertice ( -2.00000, 1.12000, 0.90000 ); 		Ponto*
  //p723 = p723; //new Vertice ( -1.12000, 2.00000, 0.90000 ); 		Ponto* p733 =
  //p733; //new Vertice ( 0.00000, 2.00000, 0.90000 );

  //		Ponto* p1031 = p1031; //new Vertice (-2.00000, 0.00000, 0.45000
  //);
  Ponto* p1111 = new Vertice(-2.00000, 1.12000, 0.45000);
  Ponto* p1121 = new Vertice(-1.12000, 2.00000, 0.45000);
  Ponto* p1131 = new Vertice(0.00000, 2.00000, 0.45000);

  //		Ponto* p1032 = p1032; //new Vertice (-1.50000, 0.00000, 0.22500
  //);
  Ponto* p1112 = new Vertice(-1.50000, 0.84000, 0.22500);
  Ponto* p1122 = new Vertice(-0.84000, 1.50000, 0.22500);
  Ponto* p1132 = new Vertice(0.00000, 1.50000, 0.22500);

  //		Ponto* p1033 = p1033; //new Vertice (-1.50000, 0.00000, 0.15000
  //);
  Ponto* p1113 = new Vertice(-1.50000, 0.84000, 0.15000);
  Ponto* p1123 = new Vertice(-0.84000, 1.50000, 0.15000);
  Ponto* p1133 = new Vertice(0.00000, 1.50000, 0.15000);

  //		Curva* patch11_c1 = new CurvParamBezier ( *p633, *p713, *p723, *p733
  //);
  Curva* patch11_c2 = new CurvParamBezier(*p733, *p1131, *p1132, *p1133);
  Curva* patch11_c3 = new CurvParamBezier(*p1033, *p1113, *p1123, *p1133);
  //		Curva* patch11_c4 = new CurvParamBezier ( *p633, *p1031, *p1032,
  //*p1033 );

  Patch* patch11 = new BezierPatch(patch7_c3, patch11_c2, patch11_c3,
                                   patch10_c2, *p1111, *p1121, *p1112, *p1122);

  geo->inserePatch(patch11);
  //		geo->insereCurva ( patch11_c1 );
  geo->insereCurva(patch11_c2);
  geo->insereCurva(patch11_c3);
  //		geo->insereCurva ( patch11_c4 );
  //======================== FIM DO PATCH 11 =================================

  //============================== PATCH 12 ==================================
  //		Ponto* p733 = p733; //new Vertice ( 0.00000, 2.00000, 0.90000 );
  //		Ponto* p813 = p813; //new Vertice ( 1.12000, 2.00000, 0.90000 );
  //		Ponto* p823 = p823; //new Vertice ( 2.00000, 1.12000, 0.90000 );
  //		Ponto* p503 = p503; // new Vertice ( 2.00000, 0.00000, 0.90000
  //);

  //		Ponto* p1131 = p1131; //new Vertice ( 0.00000, 2.00000, 0.45000
  //);
  Ponto* p1211 = new Vertice(1.12000, 2.00000, 0.45000);
  Ponto* p1221 = new Vertice(2.00000, 1.20000, 0.45000);
  //		Ponto* p901 = p901; //new Vertice ( 2.00000, 0.00000, 0.45000 );

  //		Ponto* p1132 = p1132; //new Vertice ( 0.00000, 1.50000, 0.22500
  //);
  Ponto* p1212 = new Vertice(0.84000, 1.50000, 0.22500);
  Ponto* p1222 = new Vertice(1.50000, 0.84000, 0.22500);
  //		Ponto* p902 = p902; //new Vertice ( 1.50000, 0.00000, 0.22500 );

  //		Ponto* p1133 = p1133; //new Vertice ( 0.00000, 1.50000, 0.15000
  //);
  Ponto* p1213 = new Vertice(0.84000, 1.50000, 0.15000);
  Ponto* p1223 = new Vertice(1.50000, 0.84000, 0.15000);
  //		Ponto* p903 = p903; //new Vertice ( 1.50000, 0.00000, 0.15000 );

  //		Curva* patch12_c1 = new CurvParamBezier ( *p733, *p813, *p823, *p503
  //); 		Curva* patch12_c2 = new CurvParamBezier ( *p503, *p901, *p902, *p903 );
  Curva* patch12_c3 = new CurvParamBezier(*p1133, *p1213, *p1223, *p903);
  //		Curva* patch12_c4 = new CurvParamBezier ( *p733, *p1131, *p1132,
  //*p1133 );

  Patch* patch12 = new BezierPatch(patch8_c3, patch9_c4, patch12_c3, patch11_c2,
                                   *p1211, *p1221, *p1212, *p1222);

  geo->inserePatch(patch12);
  //		geo->insereCurva ( patch12_c1 );
  //		geo->insereCurva ( patch12_c2 );
  geo->insereCurva(patch12_c3);
  //		geo->insereCurva ( patch12_c4 );
  //======================== FIM DO PATCH 12 =================================

  //============================== PATCH 13 ==================================
  Ponto* p1300 = new Vertice(-1.60000, 0.00000, 2.02500);
  Ponto* p1310 = new Vertice(-1.60000, -0.30000, 2.02500);
  Ponto* p1320 = new Vertice(-1.50000, -0.30000, 2.25000);
  Ponto* p1330 = new Vertice(-1.50000, 0.00000, 2.25000);

  Ponto* p1301 = new Vertice(-2.30000, 0.00000, 2.02500);
  Ponto* p1311 = new Vertice(-2.30000, -0.30000, 2.02500);
  Ponto* p1321 = new Vertice(-2.50000, -0.30000, 2.25000);
  Ponto* p1331 = new Vertice(-2.50000, 0.00000, 2.25000);

  Ponto* p1302 = new Vertice(-2.70000, 0.00000, 2.02500);
  Ponto* p1312 = new Vertice(-2.70000, -0.30000, 2.02500);
  Ponto* p1322 = new Vertice(-3.00000, -0.30000, 2.25000);
  Ponto* p1332 = new Vertice(-3.00000, 0.00000, 2.25000);

  Ponto* p1303 = new Vertice(-2.70000, 0.00000, 1.80000);
  Ponto* p1313 = new Vertice(-2.70000, -0.30000, 1.80000);
  Ponto* p1323 = new Vertice(-3.00000, -0.30000, 1.80000);
  Ponto* p1333 = new Vertice(-3.00000, 0.00000, 1.80000);

  Curva* patch13_c1 = new CurvParamBezier(*p1300, *p1310, *p1320, *p1330);
  Curva* patch13_c2 = new CurvParamBezier(*p1330, *p1331, *p1332, *p1333);
  Curva* patch13_c3 = new CurvParamBezier(*p1303, *p1313, *p1323, *p1333);
  Curva* patch13_c4 = new CurvParamBezier(*p1300, *p1301, *p1302, *p1303);

  Patch* patch13 = new BezierPatch(patch13_c1, patch13_c2, patch13_c3,
                                   patch13_c4, *p1311, *p1321, *p1312, *p1322);

  geo->inserePatch(patch13);
  geo->insereCurva(patch13_c1);
  geo->insereCurva(patch13_c2);
  geo->insereCurva(patch13_c3);
  geo->insereCurva(patch13_c4);
  //======================== FIM DO PATCH 13 =================================

  //============================== PATCH 14 ==================================
  //		Ponto* p1330 = p1330; //new Vertice ( -1.50000, 0.00000, 2.25000
  //);
  Ponto* p1410 = new Vertice(-1.50000, 0.30000, 2.25000);
  Ponto* p1420 = new Vertice(-1.60000, 0.30000, 2.02500);
  //		Ponto* p1300 = p1300; //new Vertice ( -1.60000, 0.00000, 2.02500
  //);

  //		Ponto* p1331 = p1331; //new Vertice ( -2.50000, 0.00000, 2.25000
  //);
  Ponto* p1411 = new Vertice(-2.50000, 0.30000, 2.25000);
  Ponto* p1421 = new Vertice(-2.30000, 0.30000, 2.02500);
  //		Ponto* p1301 = p1301; //new Vertice ( -2.30000, 0.00000, 2.02500
  //);

  //		Ponto* p1332 = p1332; //new Vertice ( -3.00000, 0.00000, 2.25000
  //);
  Ponto* p1412 = new Vertice(-3.00000, 0.30000, 2.25000);
  Ponto* p1422 = new Vertice(-2.70000, 0.30000, 2.02500);
  //		Ponto* p1302 = p1302; //new Vertice ( -2.70000, 0.00000, 2.02500
  //);

  //		Ponto* p1333 = p1333; //new Vertice ( -3.00000, 0.00000, 1.80000
  //);
  Ponto* p1413 = new Vertice(-3.00000, 0.30000, 1.80000);
  Ponto* p1423 = new Vertice(-2.70000, 0.30000, 1.80000);
  //		Ponto* p1303 = p1303; //new Vertice ( -2.70000, 0.00000, 1.80000
  //);

  Curva* patch14_c1 = new CurvParamBezier(*p1330, *p1410, *p1420, *p1300);
  //		Curva* patch14_c2 = new CurvParamBezier ( *p1300, *p1301, *p1302,
  //*p1303 );
  Curva* patch14_c3 = new CurvParamBezier(*p1333, *p1413, *p1423, *p1303);
  //		Curva* patch14_c4 = new CurvParamBezier ( *p1330, *p1331, *p1332,
  //*p1333 );

  Patch* patch14 = new BezierPatch(patch14_c1, patch13_c4, patch14_c3,
                                   patch13_c2, *p1411, *p1421, *p1412, *p1422);

  geo->inserePatch(patch14);
  geo->insereCurva(patch14_c1);
  //		geo->insereCurva ( patch14_c2 );
  geo->insereCurva(patch14_c3);
  //		geo->insereCurva ( patch14_c4 );
  //======================== FIM DO PATCH 14 =================================

  //============================== PATCH 15 ==================================
  //		Ponto* p1303 = p1303; //new Vertice ( -2.70000, 0.00000, 1.80000
  //); 		Ponto* p1313 = p1313; //new Vertice ( -2.70000,-0.30000, 1.80000 );
  //		Ponto* p1323 = p1323; //new Vertice ( -3.00000,-0.30000, 1.80000
  //); 		Ponto* p1333 = p1333; //new Vertice ( -3.00000, 0.00000, 1.80000 );

  Ponto* p1501 = new Vertice(-2.70000, 0.00000, 1.57500);
  Ponto* p1511 = new Vertice(-2.70000, -0.30000, 1.57500);
  Ponto* p1521 = new Vertice(-3.00000, -0.30000, 1.35000);
  Ponto* p1531 = new Vertice(-3.00000, 0.00000, 1.35000);

  Ponto* p1502 = new Vertice(-2.50000, 0.00000, 1.12500);
  Ponto* p1512 = new Vertice(-2.50000, -0.30000, 1.12500);
  Ponto* p1522 = new Vertice(-2.65000, -0.30000, 0.93750);
  Ponto* p1532 = new Vertice(-2.65000, 0.00000, 0.93750);

  //		Ponto* p633 = p633; //new Vertice ( -2.00000, 0.00000, 0.90000
  //);
  Ponto* p1513 = new Vertice(-2.00000, -0.30000, 0.90000);
  Ponto* p1523 = new Vertice(-1.90000, -0.30000, 0.60000);
  Ponto* p1533 = new Vertice(-1.90000, 0.00000, 0.60000);

  //		Curva* patch15_c1 = new CurvParamBezier ( *p1303, *p1313, *p1323,
  //*p1333 );
  Curva* patch15_c2 = new CurvParamBezier(*p1333, *p1531, *p1532, *p1533);
  Curva* patch15_c3 = new CurvParamBezier(*p633, *p1513, *p1523, *p1533);
  Curva* patch15_c4 = new CurvParamBezier(*p1303, *p1501, *p1502, *p633);

  Patch* patch15 = new BezierPatch(patch13_c3, patch15_c2, patch15_c3,
                                   patch15_c4, *p1511, *p1521, *p1512, *p1522);

  geo->inserePatch(patch15);
  //		geo->insereCurva ( patch15_c1 );
  geo->insereCurva(patch15_c2);
  geo->insereCurva(patch15_c3);
  geo->insereCurva(patch15_c4);
  //======================== FIM DO PATCH 15 =================================

  //============================== PATCH 16 ==================================
  //		Ponto* p1333 = p1333; //new Vertice ( -3.00000, 0.00000, 1.80000
  //); 		Ponto* p1413 = p1413; //new Vertice ( -3.00000, 0.30000, 1.80000 );
  //		Ponto* p1423 = p1423; //new Vertice ( -2.70000, 0.30000, 1.80000
  //); 		Ponto* p1303 = p1303; //new Vertice ( -2.70000, 0.00000, 1.80000 );

  //		Ponto* p1531 = p1531; //new Vertice ( -3.00000, 0.00000, 1.35000
  //);
  Ponto* p1611 = new Vertice(-3.00000, 0.30000, 1.35000);
  Ponto* p1621 = new Vertice(-2.70000, 0.30000, 1.57500);
  //		Ponto* p1501 = p1501; //new Vertice ( -2.70000, 0.00000, 1.57500
  //);

  //		Ponto* p1532 = p1532; //new Vertice ( -2.65000, 0.00000, 0.93750
  //);
  Ponto* p1612 = new Vertice(-2.65000, 0.30000, 0.93750);
  Ponto* p1622 = new Vertice(-2.50000, 0.30000, 1.12500);
  //		Ponto* p1502 = p1502; //new Vertice ( -2.50000, 0.00000, 1.12500
  //);

  //		Ponto* p1533 = p1533; //new Vertice ( -1.90000, 0.00000, 0.60000
  //);
  Ponto* p1613 = new Vertice(-1.90000, 0.30000, 0.60000);
  Ponto* p1623 = new Vertice(-2.00000, 0.30000, 0.90000);
  //		Ponto* p633 = p633; //new Vertice ( -2.00000, 0.00000, 0.90000
  //);

  //		Curva* patch16_c1 = new CurvParamBezier ( *p1333, *p1413, *p1423,
  //*p1303 ); 		Curva* patch16_c2 = new CurvParamBezier ( *p1303, *p1501, *p1502,
  //*p633 );
  Curva* patch16_c3 = new CurvParamBezier(*p1533, *p1613, *p1623, *p633);
  //		Curva* patch16_c4 = new CurvParamBezier ( *p1333, *p1531, *p1532,
  //*p1533 );

  Patch* patch16 = new BezierPatch(patch14_c3, patch15_c4, patch16_c3,
                                   patch15_c2, *p1611, *p1621, *p1612, *p1622);

  geo->inserePatch(patch16);
  //		geo->insereCurva ( patch16_c1 );
  //		geo->insereCurva ( patch16_c2 );
  geo->insereCurva(patch16_c3);
  //		geo->insereCurva ( patch16_c4 );
  //======================== FIM DO PATCH 16 =================================

  //============================== PATCH 17 ==================================
  Ponto* p1700 = new Vertice(1.70000, 0.00000, 1.42500);
  Ponto* p1710 = new Vertice(1.70000, -0.66000, 1.42500);
  Ponto* p1720 = new Vertice(1.70000, -0.66000, 0.60000);
  Ponto* p1730 = new Vertice(1.70000, 0.00000, 0.60000);

  Ponto* p1701 = new Vertice(2.60000, 0.00000, 1.42500);
  Ponto* p1711 = new Vertice(2.60000, -0.66000, 1.42500);
  Ponto* p1721 = new Vertice(3.10000, -0.66000, 0.82500);
  Ponto* p1731 = new Vertice(3.10000, 0.00000, 0.82500);

  Ponto* p1702 = new Vertice(2.30000, 0.00000, 2.10000);
  Ponto* p1712 = new Vertice(2.30000, -0.25000, 2.10000);
  Ponto* p1722 = new Vertice(2.40000, -0.25000, 2.02500);
  Ponto* p1732 = new Vertice(2.40000, 0.00000, 2.02500);

  Ponto* p1703 = new Vertice(2.70000, 0.00000, 2.40000);
  Ponto* p1713 = new Vertice(2.70000, -0.25000, 2.40000);
  Ponto* p1723 = new Vertice(3.30000, -0.25000, 2.40000);
  Ponto* p1733 = new Vertice(3.30000, 0.00000, 2.40000);

  Curva* patch17_c1 = new CurvParamBezier(*p1700, *p1710, *p1720, *p1730);
  Curva* patch17_c2 = new CurvParamBezier(*p1730, *p1731, *p1732, *p1733);
  Curva* patch17_c3 = new CurvParamBezier(*p1703, *p1713, *p1723, *p1733);
  Curva* patch17_c4 = new CurvParamBezier(*p1700, *p1701, *p1702, *p1703);

  Patch* patch17 = new BezierPatch(patch17_c1, patch17_c2, patch17_c3,
                                   patch17_c4, *p1711, *p1721, *p1712, *p1722);

  geo->inserePatch(patch17);
  geo->insereCurva(patch17_c1);
  geo->insereCurva(patch17_c2);
  geo->insereCurva(patch17_c3);
  geo->insereCurva(patch17_c4);
  //======================== FIM DO PATCH 17 =================================

  //============================== PATCH 18 ==================================
  //		Ponto* p1730 = p1730; //new Vertice ( 1.70000, 0.00000, 0.60000
  //);
  Ponto* p1810 = new Vertice(1.70000, 0.66000, 0.60000);
  Ponto* p1820 = new Vertice(1.70000, 0.66000, 1.42500);
  //		Ponto* p1700 = p1700; //new Vertice ( 1.70000, 0.00000, 1.42500
  //);

  //		Ponto* p1731 = p1731; //new Vertice ( 3.10000, 0.00000, 0.82500
  //);
  Ponto* p1811 = new Vertice(3.10000, 0.66000, 0.82500);
  Ponto* p1821 = new Vertice(2.60000, 0.66000, 1.42500);
  //		Ponto* p1701 = p1701; //new Vertice ( 2.60000, 0.00000, 1.42500
  //);

  //		Ponto* p1732 = p1732; //new Vertice ( 2.40000, 0.00000, 2.02500
  //);
  Ponto* p1812 = new Vertice(2.40000, 0.25000, 2.02500);
  Ponto* p1822 = new Vertice(2.30000, 0.25000, 2.10000);
  //		Ponto* p1702 = p1702; //new Vertice ( 2.30000, 0.00000, 2.10000
  //);

  //		Ponto* p1733 = p1733; //new Vertice ( 3.30000, 0.00000, 2.40000
  //);
  Ponto* p1813 = new Vertice(3.30000, 0.25000, 2.40000);
  Ponto* p1823 = new Vertice(2.70000, 0.25000, 2.40000);
  //		Ponto* p1703 = p1703; //new Vertice ( 2.70000, 0.00000, 2.40000
  //);

  Curva* patch18_c1 = new CurvParamBezier(*p1730, *p1810, *p1820, *p1700);
  //		Curva* patch18_c2 = new CurvParamBezier ( *p1700, *p1701, *p1702,
  //*p1703 );
  Curva* patch18_c3 = new CurvParamBezier(*p1733, *p1813, *p1823, *p1703);
  //		Curva* patch18_c4 = new CurvParamBezier ( *p1730, *p1731, *p1732,
  //*p1733 );

  Patch* patch18 = new BezierPatch(patch18_c1, patch17_c4, patch18_c3,
                                   patch17_c2, *p1811, *p1821, *p1812, *p1822);

  geo->inserePatch(patch18);
  geo->insereCurva(patch18_c1);
  //		geo->insereCurva ( patch18_c2 );
  geo->insereCurva(patch18_c3);
  //		geo->insereCurva ( patch18_c4 );
  //======================== FIM DO PATCH 18 =================================

  //============================== PATCH 19 ==================================
  //		Ponto* p1703 = p1703; //new Vertice ( 2.70000, 0.00000, 2.40000
  //); 		Ponto* p1713 = p1713; //new Vertice ( 2.70000,-0.25000, 2.40000
  //);3.30000, 0.25000, 2.40000 		Ponto* p1723 = p1723; //new Vertice
  //( 3.30000,-0.25000, 2.40000 ); 		Ponto* p1733 = p1733; //new Vertice
  //( 3.30000, 0.00000, 2.40000 );

  Ponto* p1901 = new Vertice(2.80000, 0.00000, 2.47500);
  Ponto* p1911 = new Vertice(2.80000, -0.25000, 2.47500);
  Ponto* p1921 = new Vertice(3.52500, -0.25000, 2.49375);
  Ponto* p1931 = new Vertice(3.52500, 0.00000, 2.49375);

  Ponto* p1902 = new Vertice(2.90000, 0.00000, 2.47500);
  Ponto* p1912 = new Vertice(2.90000, -0.15000, 2.47500);
  Ponto* p1922 = new Vertice(3.45000, -0.15000, 2.51250);
  Ponto* p1932 = new Vertice(3.45000, 0.00000, 2.51250);

  Ponto* p1903 = new Vertice(2.80000, 0.00000, 2.40000);
  Ponto* p1913 = new Vertice(2.80000, -0.15000, 2.40000);
  //		Ponto* p1933 = new Vertice ( 3.20000, 0.00000, 2.40000 );
  Ponto* p1933 = new Vertice(3.20000, 0.00000, 2.40000);

  //		Curva* patch19_c1 = new CurvParamBezier ( *p1703, *p1713, *p1723,
  //*p1733 );
  Curva* patch19_c2 = new CurvParamBezier(*p1733, *p1931, *p1932, *p1933);
  Curva* patch19_c3 = new CurvParamBezier(*p1903, *p1913, *p1933, *p1933);
  Curva* patch19_c4 = new CurvParamBezier(*p1703, *p1901, *p1902, *p1903);

  Patch* patch19 = new BezierPatch(patch17_c3, patch19_c2, patch19_c3,
                                   patch19_c4, *p1911, *p1921, *p1912, *p1922);

  geo->inserePatch(patch19);
  //		geo->insereCurva ( patch19_c1 );
  geo->insereCurva(patch19_c2);
  geo->insereCurva(patch19_c3);
  geo->insereCurva(patch19_c4);
  //======================== FIM DO PATCH 19 =================================

  //============================== PATCH 20 ==================================
  //		Ponto* p1733 = p1733; //new Vertice ( 3.30000, 0.00000, 2.40000
  //);
  Ponto* p2010 = new Vertice(3.30000, 0.25000, 2.40000);
  Ponto* p2020 = new Vertice(2.70000, 0.25000, 2.40000);
  //		Ponto* p1703 = p1703; //new Vertice ( 2.70000, 0.00000, 2.40000
  //);

  //		Ponto* p1931 = p1931; //new Vertice ( 3.52500, 0.00000, 2.49375
  //);
  Ponto* p2011 = new Vertice(3.52500, 0.25000, 2.49375);
  Ponto* p2021 = new Vertice(2.80000, 0.25000, 2.47500);
  //		Ponto* p1901 = p1901; //new Vertice ( 2.80000, 0.00000, 2.47500
  //);

  //		Ponto* p1932 = p1932; //new Vertice ( 3.45000, 0.00000, 2.51250
  //);
  Ponto* p2012 = new Vertice(3.45000, 0.15000, 2.51250);
  Ponto* p2022 = new Vertice(2.90000, 0.15000, 2.47500);
  //		Ponto* p1902 = p1902; //new Vertice ( 2.90000, 0.00000, 2.47500
  //);

  //		Ponto* p1933 = p1933; //new Vertice ( 3.20000, 0.00000, 2.40000
  //); 		Ponto* p2013 = new Vertice ( 3.20000, 0.15000, 2.40000 );
  Ponto* p2023 = new Vertice(2.80000, 0.15000, 2.40000);
  //		Ponto* p1903 = p1903; //new Vertice ( 2.80000, 0.00000, 2.40000
  //);

  Curva* patch20_c1 = new CurvParamBezier(*p1733, *p2010, *p2020, *p1703);
  //		Curva* patch20_c2 = new CurvParamBezier ( *p1703, *p1901, *p1902,
  //*p1903 );
  Curva* patch20_c3 = new CurvParamBezier(*p1933, *p1933, *p2023, *p1903);
  //		Curva* patch20_c4 = new CurvParamBezier ( *p1733, *p1931, *p1932,
  //*p1933 );

  Patch* patch20 = new BezierPatch(patch20_c1, patch19_c4, patch20_c3,
                                   patch19_c2, *p2011, *p2021, *p2012, *p2022);

  geo->inserePatch(patch20);
  geo->insereCurva(patch20_c1);
  //		geo->insereCurva ( patch20_c2 );
  geo->insereCurva(patch20_c3);
  //		geo->insereCurva ( patch20_c4 );
  //======================== FIM DO PATCH 20 =================================

  //============================== PATCH 21 ==================================
  Ponto* p2100 = new Vertice(0.10000, 0.00000, 3.15000);
  Ponto* p2110 = new Vertice(0.08660, -0.05000, 3.15000);
  Ponto* p2120 = new Vertice(0.05000, -0.08660, 3.15000);
  Ponto* p2130 = new Vertice(0.00000, -0.10000, 3.15000);

  Ponto* p2101 = new Vertice(0.80000, 0.00000, 3.15000);
  Ponto* p2111 = new Vertice(0.80000, -0.45000, 3.15000);
  Ponto* p2121 = new Vertice(0.45000, -0.80000, 3.15000);
  Ponto* p2131 = new Vertice(0.00000, -0.80000, 3.15000);

  Ponto* p2102 = new Vertice(0.00000, 0.00000, 2.85000);
  //		Ponto* p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000
  //); 		Ponto* p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 ); 		Ponto*
  //p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 );

  Ponto* p2103 = new Vertice(0.20000, 0.00000, 2.70000);
  Ponto* p2113 = new Vertice(0.20000, -0.11200, 2.70000);
  Ponto* p2123 = new Vertice(0.11200, -0.20000, 2.70000);
  Ponto* p2133 = new Vertice(0.00000, -0.20000, 2.70000);

  Curva* patch21_c1 = new CurvParamBezier(*p2100, *p2110, *p2120, *p2130);
  Curva* patch21_c2 = new CurvParamBezier(*p2130, *p2131, *p2102, *p2133);
  Curva* patch21_c3 = new CurvParamBezier(*p2103, *p2113, *p2123, *p2133);
  Curva* patch21_c4 = new CurvParamBezier(*p2100, *p2101, *p2102, *p2103);

  Patch* patch21 = new BezierPatch(patch21_c1, patch21_c2, patch21_c3,
                                   patch21_c4, *p2111, *p2121, *p2102, *p2102);

  geo->inserePatch(patch21);
  geo->insereCurva(patch21_c1);
  geo->insereCurva(patch21_c2);
  geo->insereCurva(patch21_c3);
  geo->insereCurva(patch21_c4);
  //======================== FIM DO PATCH 21 =================================

  //============================== PATCH 22 ==================================
  //		Ponto* p2130 = p2130; //new Vertice ( 0.00000,-0.10000, 3.15000
  //);
  Ponto* p2210 = new Vertice(-0.05000, -0.08660, 3.15000);
  Ponto* p2220 = new Vertice(-0.08660, -0.05000, 3.15000);
  Ponto* p2230 = new Vertice(-0.10000, 0.00000, 3.15000);

  //		Ponto* p2131 = p2131; //new Vertice (  0.00000,-0.80000, 3.15000
  //);
  Ponto* p2211 = new Vertice(-0.45000, -0.80000, 3.15000);
  Ponto* p2221 = new Vertice(-0.80000, -0.45000, 3.15000);
  Ponto* p2231 = new Vertice(-0.80000, 0.00000, 3.15000);

  //		Ponto* p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000
  //); 		Ponto* p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 ); 		Ponto*
  //p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 ); 		Ponto* p2102 =
  //p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 );

  //		Ponto* p2133 = p2133; //new Vertice (  0.00000,-0.20000, 2.70000
  //);
  Ponto* p2213 = new Vertice(-0.11200, -0.20000, 2.70000);
  Ponto* p2223 = new Vertice(-0.20000, -0.11200, 2.70000);
  Ponto* p2233 = new Vertice(-0.20000, 0.00000, 2.70000);

  Curva* patch22_c1 = new CurvParamBezier(*p2130, *p2210, *p2220, *p2230);
  Curva* patch22_c2 = new CurvParamBezier(*p2230, *p2231, *p2102, *p2233);
  Curva* patch22_c3 = new CurvParamBezier(*p2133, *p2213, *p2223, *p2233);
  //		Curva* patch22_c4 = new CurvParamBezier ( *p2130, *p2131, *p2102,
  //*p2133 );

  Patch* patch22 = new BezierPatch(patch22_c1, patch22_c2, patch22_c3,
                                   patch21_c2, *p2211, *p2221, *p2102, *p2102);

  geo->inserePatch(patch22);
  geo->insereCurva(patch22_c1);
  geo->insereCurva(patch22_c2);
  geo->insereCurva(patch22_c3);
  //		geo->insereCurva ( patch22_c4 );
  //======================== FIM DO PATCH 22 =================================

  //============================== PATCH 23 ==================================
  //		Ponto* p2230 = new Vertice (-0.10000, 0.00000, 3.15000 );
  Ponto* p2310 = new Vertice(-0.08660, 0.05000, 3.15000);
  Ponto* p2320 = new Vertice(-0.05000, 0.08660, 3.15000);
  Ponto* p2330 = new Vertice(0.00000, 0.10000, 3.15000);

  //		Ponto* p2231 = new Vertice ( -0.80000, 0.00000, 3.15000 );
  Ponto* p2311 = new Vertice(-0.80000, 0.45000, 3.15000);
  Ponto* p2321 = new Vertice(-0.45000, 0.80000, 3.15000);
  Ponto* p2331 = new Vertice(0.00000, 0.80000, 3.15000);

  //		Ponto* p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000
  //); 		Ponto* p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 ); 		Ponto*
  //p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 ); 		Ponto* p2102 =
  //p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 );

  //		Ponto* p2233 = new Vertice ( -0.20000, 0.00000, 2.70000 );
  Ponto* p2313 = new Vertice(-0.20000, 0.11200, 2.70000);
  Ponto* p2323 = new Vertice(-0.11200, 0.20000, 2.70000);
  Ponto* p2333 = new Vertice(0.00000, 0.20000, 2.70000);

  Curva* patch23_c1 = new CurvParamBezier(*p2230, *p2310, *p2320, *p2330);
  Curva* patch23_c2 = new CurvParamBezier(*p2330, *p2331, *p2102, *p2333);
  Curva* patch23_c3 = new CurvParamBezier(*p2233, *p2313, *p2323, *p2333);
  //		Curva* patch23_c4 = new CurvParamBezier ( *p2230, *p2231, *p2102,
  //*p2233 );

  Patch* patch23 = new BezierPatch(patch23_c1, patch23_c2, patch23_c3,
                                   patch22_c2, *p2311, *p2321, *p2102, *p2102);

  geo->inserePatch(patch23);
  geo->insereCurva(patch23_c1);
  geo->insereCurva(patch23_c2);
  geo->insereCurva(patch23_c3);
  //		geo->insereCurva ( patch23_c4 );
  //======================== FIM DO PATCH 23 =================================

  //============================== PATCH 24 ==================================
  //		Ponto* p2330 = new Vertice ( 0.00000, 0.10000, 3.15000 );
  Ponto* p2410 = new Vertice(0.05000, 0.08660, 3.15000);
  Ponto* p2420 = new Vertice(0.08660, 0.05000, 3.15000);
  //		Ponto* p2100 = new Vertice ( 0.10000, 0.00000, 3.15000 );

  //		Ponto* p2331 = new Vertice ( 0.00000, 0.80000, 3.15000 );
  Ponto* p2411 = new Vertice(0.45000, 0.80000, 3.15000);
  Ponto* p2421 = new Vertice(0.80000, 0.45000, 3.15000);
  Ponto* p2431 = p2101;  // new Vertice ( 0.80000, 0.00000, 3.15000 );

  //		Ponto* p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000
  //); 		Ponto* p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 ); 		Ponto*
  //p2102 = p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 ); 		Ponto* p2102 =
  //p2102; //new Vertice ( 0.00000, 0.00000, 2.85000 );

  //		Ponto* p2333 = new Vertice ( 0.00000, 0.20000, 2.70000 );
  Ponto* p2413 = new Vertice(0.11200, 0.20000, 2.70000);
  Ponto* p2423 = new Vertice(0.20000, 0.11200, 2.70000);
  //		Ponto* p2103 = p2103; //new Vertice ( 0.20000, 0.00000, 2.70000
  //);

  Curva* patch24_c1 = new CurvParamBezier(*p2330, *p2410, *p2420, *p2100);
  Curva* patch24_c2 = new CurvParamBezier(*p2100, *p2431, *p2102, *p2103);
  Curva* patch24_c3 = new CurvParamBezier(*p2333, *p2413, *p2423, *p2103);
  //		Curva* patch24_c4 = new CurvParamBezier ( *p2330, *p2331, *p2102,
  //*p2333 );

  Patch* patch24 = new BezierPatch(patch24_c1, patch24_c2, patch24_c3,
                                   patch23_c2, *p2411, *p2421, *p2102, *p2102);

  geo->inserePatch(patch24);
  geo->insereCurva(patch24_c1);
  geo->insereCurva(patch24_c2);
  geo->insereCurva(patch24_c3);
  //		geo->insereCurva ( patch24_c4 );
  //======================== FIM DO PATCH 24 =================================

  //============================== PATCH 25 ==================================
  //		Ponto* p2103 = p2103; //new Vertice ( 0.20000, 0.00000, 2.70000
  //); 		Ponto* p2113 = p2113; //new Vertice ( 0.20000,-0.11200, 2.70000 ); 		Ponto*
  //p2123 = p2123; //new Vertice ( 0.11200,-0.20000, 2.70000 ); 		Ponto* p2133 =
  //p2133; //new Vertice ( 0.00000,-0.20000, 2.70000 );

  Ponto* p2501 = new Vertice(0.40000, 0.00000, 2.55000);
  Ponto* p2511 = new Vertice(0.40000, -0.22400, 2.55000);
  Ponto* p2521 = new Vertice(0.22400, -0.40000, 2.55000);
  Ponto* p2531 = new Vertice(0.00000, -0.40000, 2.55000);

  Ponto* p2502 = new Vertice(1.30000, 0.00000, 2.55000);
  Ponto* p2512 = new Vertice(1.30000, -0.72800, 2.55000);
  Ponto* p2522 = new Vertice(0.72800, -1.30000, 2.55000);
  Ponto* p2532 = new Vertice(0.00000, -1.30000, 2.55000);

  Ponto* p2503 = new Vertice(1.30000, 0.00000, 2.40000);
  Ponto* p2513 = new Vertice(1.30000, -0.72800, 2.40000);
  Ponto* p2523 = new Vertice(0.72800, -1.30000, 2.40000);
  Ponto* p2533 = new Vertice(0.00000, -1.30000, 2.40000);

  //		Curva* patch25_c1 = new CurvParamBezier ( *p2103, *p2113, *p2123,
  //*p2133 );
  Curva* patch25_c2 = new CurvParamBezier(*p2133, *p2531, *p2532, *p2533);
  Curva* patch25_c3 = new CurvParamBezier(*p2503, *p2513, *p2523, *p2533);
  Curva* patch25_c4 = new CurvParamBezier(*p2103, *p2501, *p2502, *p2503);

  Patch* patch25 = new BezierPatch(patch21_c3, patch25_c2, patch25_c3,
                                   patch25_c4, *p2511, *p2521, *p2512, *p2522);

  geo->inserePatch(patch25);
  //		geo->insereCurva ( patch25_c1 );
  geo->insereCurva(patch25_c2);
  geo->insereCurva(patch25_c3);
  geo->insereCurva(patch25_c4);
  //======================== FIM DO PATCH 25 =================================

  //============================== PATCH 26 ==================================
  //		Ponto* p2133 = p2133; //new Vertice ( 0.00000,-0.20000, 2.70000
  //); 		Ponto* p2213 = new Vertice (-0.11200,-0.20000, 2.70000 ); 		Ponto* p2223 =
  //new Vertice (-0.20000,-0.11200, 2.70000 ); 		Ponto* p2233 = new Vertice
  //(-0.20000, 0.00000, 2.70000 );

  //		Ponto* p2531 = new Vertice ( 0.00000,-0.40000, 2.55000 );
  Ponto* p2611 = new Vertice(-0.22400, -0.40000, 2.55000);
  Ponto* p2621 = new Vertice(-0.40000, -0.22400, 2.55000);
  Ponto* p2631 = new Vertice(-0.40000, 0.00000, 2.55000);

  //		Ponto* p2532 = new Vertice ( 0.00000,-1.30000, 2.55000 );
  Ponto* p2612 = new Vertice(-0.72800, -1.30000, 2.55000);
  Ponto* p2622 = new Vertice(-1.30000, -0.72800, 2.55000);
  Ponto* p2632 = new Vertice(-1.30000, 0.00000, 2.55000);

  //		Ponto* p2533 = new Vertice ( 0.00000,-1.30000, 2.40000 );
  Ponto* p2613 = new Vertice(-0.72800, -1.30000, 2.40000);
  Ponto* p2623 = new Vertice(-1.30000, -0.72800, 2.40000);
  Ponto* p2633 = new Vertice(-1.30000, 0.00000, 2.40000);

  //		Curva* patch26_c1 = new CurvParamBezier ( *p2133, *p2213, *p2223,
  //*p2233 );
  Curva* patch26_c2 = new CurvParamBezier(*p2233, *p2631, *p2632, *p2633);
  Curva* patch26_c3 = new CurvParamBezier(*p2533, *p2613, *p2623, *p2633);
  //		Curva* patch26_c4 = new CurvParamBezier ( *p2133, *p2531, *p2532,
  //*p2533 );

  Patch* patch26 = new BezierPatch(patch22_c3, patch26_c2, patch26_c3,
                                   patch25_c2, *p2611, *p2621, *p2612, *p2622);

  geo->inserePatch(patch26);
  //		geo->insereCurva ( patch26_c1 );
  geo->insereCurva(patch26_c2);
  geo->insereCurva(patch26_c3);
  //		geo->insereCurva ( patch26_c4 );
  //======================== FIM DO PATCH 26 =================================

  //============================== PATCH 27 ==================================
  //		Ponto* p2233 = new Vertice ( -0.20000, 0.00000, 2.70000 );
  //		Ponto* p2313 = new Vertice ( -0.20000, 0.11200, 2.70000 );
  //		Ponto* p2323 = new Vertice ( -0.11200, 0.20000, 2.70000 );
  //		Ponto* p2333 = new Vertice (  0.00000, 0.20000, 2.70000 );

  //		Ponto* p2631 = new Vertice ( -0.40000, 0.00000, 2.55000 );
  Ponto* p2711 = new Vertice(-0.40000, 0.22400, 2.55000);
  Ponto* p2721 = new Vertice(-0.22400, 0.40000, 2.55000);
  Ponto* p2731 = new Vertice(0.00000, 0.40000, 2.55000);

  //		Ponto* p2632 = new Vertice ( -1.30000, 0.00000, 2.55000 );
  Ponto* p2712 = new Vertice(-1.30000, 0.72800, 2.55000);
  Ponto* p2722 = new Vertice(-0.72800, 1.30000, 2.55000);
  Ponto* p2732 = new Vertice(0.00000, 1.30000, 2.55000);

  //		Ponto* p2633 = new Vertice ( -1.30000, 0.00000, 2.40000 );
  Ponto* p2713 = new Vertice(-1.30000, 0.72800, 2.40000);
  Ponto* p2723 = new Vertice(-0.72800, 1.30000, 2.40000);
  Ponto* p2733 = new Vertice(0.00000, 1.30000, 2.40000);

  //		Curva* patch27_c1 = new CurvParamBezier ( *p2233, *p2313, *p2323,
  //*p2333 );
  Curva* patch27_c2 = new CurvParamBezier(*p2333, *p2731, *p2732, *p2733);
  Curva* patch27_c3 = new CurvParamBezier(*p2633, *p2713, *p2723, *p2733);
  //		Curva* patch27_c4 = new CurvParamBezier ( *p2233, *p2631, *p2632,
  //*p2633 );

  Patch* patch27 = new BezierPatch(patch23_c3, patch27_c2, patch27_c3,
                                   patch26_c2, *p2711, *p2721, *p2712, *p2722);

  geo->inserePatch(patch27);
  //		geo->insereCurva ( patch27_c1 );
  geo->insereCurva(patch27_c2);
  geo->insereCurva(patch27_c3);
  //		geo->insereCurva ( patch27_c4 );
  //======================== FIM DO PATCH 27 =================================

  //============================== PATCH 28 ==================================
  //		Ponto* p2333 = new Vertice ( 0.00000, 0.20000, 2.70000 );
  //		Ponto* p2413 = new Vertice ( 0.11200, 0.20000, 2.70000 );
  //		Ponto* p2423 = new Vertice ( 0.20000, 0.11200, 2.70000 );
  //		Ponto* p2103 = p2103; //new Vertice ( 0.20000, 0.00000, 2.70000
  //);

  //		Ponto* p2731 = new Vertice ( 0.00000, 0.40000, 2.55000 );
  Ponto* p2811 = new Vertice(0.22400, 0.40000, 2.55000);
  Ponto* p2821 = new Vertice(0.40000, 0.22400, 2.55000);
  //		Ponto* p2501 = new Vertice ( 0.40000, 0.00000, 2.55000 );

  //		Ponto* p2732 = new Vertice ( 0.00000, 1.30000, 2.55000 );
  Ponto* p2812 = new Vertice(0.72800, 1.30000, 2.55000);
  Ponto* p2822 = new Vertice(1.30000, 0.72800, 2.55000);
  //		Ponto* p2502 = new Vertice ( 1.30000, 0.00000, 2.55000 );

  //		Ponto* p2733 = new Vertice ( 0.00000, 1.30000, 2.40000 );
  Ponto* p2813 = new Vertice(0.72800, 1.30000, 2.40000);
  Ponto* p2823 = new Vertice(1.30000, 0.72800, 2.40000);
  //		Ponto* p2503 = new Vertice ( 1.30000, 0.00000, 2.40000 );

  //		Curva* patch28_c1 = new CurvParamBezier ( *p2333, *p2413, *p2423,
  //*p2103 ); 		Curva* patch28_c2 = new CurvParamBezier ( *p2103, *p2501, *p2502,
  //*p2503 );
  Curva* patch28_c3 = new CurvParamBezier(*p2733, *p2813, *p2823, *p2503);
  //		Curva* patch28_c4 = new CurvParamBezier ( *p2333, *p2731, *p2732,
  //*p2733 );

  Patch* patch28 = new BezierPatch(patch24_c3, patch25_c4, patch28_c3,
                                   patch27_c2, *p2811, *p2821, *p2812, *p2822);

  geo->inserePatch(patch28);
  //		geo->insereCurva ( patch28_c1 );
  //		geo->insereCurva ( patch28_c2 );
  geo->insereCurva(patch28_c3);
  //		geo->insereCurva ( patch28_c4 );
  //======================== FIM DO PATCH 28 =================================

  //============================== PATCH 29 ==================================
  Ponto* p2900 = new Vertice(0.10000, 0.00000, 0.00001);
  Ponto* p2910 = new Vertice(0.08660, 0.05000, 0.00001);
  Ponto* p2920 = new Vertice(0.05000, 0.08660, 0.00001);
  Ponto* p2930 = new Vertice(0.00000, 0.10000, 0.00001);

  Ponto* p2901 = new Vertice(1.42500, 0.00000, 0.00000);
  Ponto* p2911 = new Vertice(1.42500, 0.79800, 0.00000);
  Ponto* p2921 = new Vertice(0.79800, 1.42500, 0.00000);
  Ponto* p2931 = new Vertice(0.00000, 1.42500, 0.00000);

  Ponto* p2902 = new Vertice(1.50000, 0.00000, 0.07500);
  Ponto* p2912 = new Vertice(1.50000, 0.84000, 0.07500);
  Ponto* p2922 = new Vertice(0.84000, 1.50000, 0.07500);
  Ponto* p2932 = new Vertice(0.00000, 1.50000, 0.07500);

  //		Ponto* p903 = p903; //new Vertice ( 1.50000, 0.00000, 0.15000 );
  //		Ponto* p1223 = new Vertice ( 1.50000, 0.84000, 0.15000 );
  //		Ponto* p1213 = new Vertice ( 0.84000, 1.50000, 0.15000 );
  //		Ponto* p1133 = p1133; //new Vertice ( 0.00000, 1.50000, 0.15000
  //);

  Curva* patch29_c1 = new CurvParamBezier(*p2900, *p2910, *p2920, *p2930);
  Curva* patch29_c2 = new CurvParamBezier(*p2930, *p2931, *p2932, *p1133);
  Curva* patch29_c3 = new CurvParamBezier(*p903, *p1223, *p1213, *p1133);
  Curva* patch29_c4 = new CurvParamBezier(*p2900, *p2901, *p2902, *p903);

  Patch* patch29 = new BezierPatch(patch29_c1, patch29_c2, patch29_c3,
                                   patch29_c4, *p2911, *p2921, *p2912, *p2922);

  geo->inserePatch(patch29);
  geo->insereCurva(patch29_c1);
  geo->insereCurva(patch29_c2);
  geo->insereCurva(patch29_c3);
  geo->insereCurva(patch29_c4);
  //======================== FIM DO PATCH 29 =================================

  //============================== PATCH 30 ==================================
  //		Ponto* p2930 = new Vertice ( 0.00000, 0.10000, 0.00001 );
  Ponto* p3010 = new Vertice(-0.05000, 0.08660, 0.00001);
  Ponto* p3020 = new Vertice(-0.08660, 0.05000, 0.00001);
  Ponto* p3030 = new Vertice(-0.10000, 0.00000, 0.00001);

  //		Ponto* p2931 = new Vertice (  0.00000, 1.42500, 0.00000 );
  Ponto* p3011 = new Vertice(-0.79800, 1.42500, 0.00000);
  Ponto* p3021 = new Vertice(-1.42500, 0.79800, 0.00000);
  Ponto* p3031 = new Vertice(-1.42500, 0.00000, 0.00000);

  //		Ponto* p2932 = new Vertice ( 0.00000, 1.50000, 0.07500 );
  Ponto* p3012 = new Vertice(-0.84000, 1.50000, 0.07500);
  Ponto* p3022 = new Vertice(-1.50000, 0.84000, 0.07500);
  Ponto* p3032 = new Vertice(-1.50000, 0.00000, 0.07500);

  //		Ponto* p1133 = p1133; //new Vertice ( 0.00000, 1.50000, 0.15000
  //); 		Ponto* p1123 = p1123; //new Vertice (-0.84000, 1.50000, 0.15000 ); 		Ponto*
  //p1113 = p1113; //new Vertice (-1.50000, 0.84000, 0.15000 ); 		Ponto* p1033 =
  //new Vertice (-1.50000, 0.00000, 0.15000 );

  Curva* patch30_c1 = new CurvParamBezier(*p2930, *p3010, *p3020, *p3030);
  Curva* patch30_c2 = new CurvParamBezier(*p3030, *p3031, *p3032, *p1033);
  Curva* patch30_c3 = new CurvParamBezier(*p1133, *p1123, *p1113, *p1033);
  //		Curva* patch30_c4 = new CurvParamBezier ( *p2930, *p2931, *p2932,
  //*p1133 );

  Patch* patch30 = new BezierPatch(patch30_c1, patch30_c2, patch30_c3,
                                   patch29_c2, *p3011, *p3021, *p3012, *p3022);

  geo->inserePatch(patch30);
  geo->insereCurva(patch30_c1);
  geo->insereCurva(patch30_c2);
  geo->insereCurva(patch30_c3);
  //		geo->insereCurva ( patch30_c4 );
  //======================== FIM DO PATCH 30 =================================

  //============================== PATCH 31 ==================================
  //		Ponto* p3030 = new Vertice (-0.10000, 0.00000, 0.00001 );
  Ponto* p3110 = new Vertice(-0.08660, -0.05000, 0.00001);
  Ponto* p3120 = new Vertice(-0.05000, -0.08660, 0.00001);
  Ponto* p3130 = new Vertice(0.00000, -0.10000, 0.00001);

  //		Ponto* p3031 = new Vertice ( -1.42500, 0.00000, 0.00000 );
  Ponto* p3111 = new Vertice(-1.42500, -0.79800, 0.00000);
  Ponto* p3121 = new Vertice(-0.79800, -1.42500, 0.00000);
  Ponto* p3131 = new Vertice(0.00000, -1.42500, 0.00000);

  //		Ponto* p3032 = new Vertice ( -1.50000, 0.00000, 0.07500 );
  Ponto* p3112 = new Vertice(-1.50000, -0.84000, 0.07500);
  Ponto* p3122 = new Vertice(-0.84000, -1.50000, 0.07500);
  Ponto* p3132 = new Vertice(0.00000, -1.50000, 0.07500);

  //		Ponto* p1033 = new Vertice ( -1.50000, 0.00000, 0.15000 );
  //		Ponto* p1023 = new Vertice ( -1.50000,-0.84000, 0.15000 );
  //		Ponto* p1013 = new Vertice ( -0.84000,-1.50000, 0.15000 );
  //		Ponto* p933 = p933; //new Vertice (  0.00000,-1.50000, 0.15000
  //);

  Curva* patch31_c1 = new CurvParamBezier(*p3030, *p3110, *p3120, *p3130);
  Curva* patch31_c2 = new CurvParamBezier(*p3130, *p3131, *p3132, *p933);
  Curva* patch31_c3 = new CurvParamBezier(*p1033, *p1023, *p1013, *p933);
  //		Curva* patch31_c4 = new CurvParamBezier ( *p3030, *p3031, *p3032,
  //*p1033 );

  Patch* patch31 = new BezierPatch(patch31_c1, patch31_c2, patch31_c3,
                                   patch30_c2, *p3111, *p3121, *p3112, *p3122);

  geo->inserePatch(patch31);
  geo->insereCurva(patch31_c1);
  geo->insereCurva(patch31_c2);
  geo->insereCurva(patch31_c3);
  //		geo->insereCurva ( patch31_c4 );
  //======================== FIM DO PATCH 31 =================================

  //============================== PATCH 32 ==================================
  //		Ponto* p3130 = new Vertice ( 0.00000,-0.10000, 0.00001 );
  Ponto* p3210 = new Vertice(0.05000, -0.08660, 0.00001);
  Ponto* p3220 = new Vertice(0.08660, -0.05000, 0.00001);
  //		Ponto* p2900 = new Vertice ( 0.10000, 0.00000, 0.00001 );

  //		Ponto* p3131 = new Vertice ( 0.00000,-1.42500, 0.00000 );
  Ponto* p3211 = new Vertice(0.79800, -1.42500, 0.00000);
  Ponto* p3221 = new Vertice(1.42500, -0.79800, 0.00000);
  //		Ponto* p2901 = new Vertice ( 1.42500, 0.00000, 0.00000 );

  //		Ponto* p3132 = new Vertice ( 0.00000,-1.50000, 0.07500 );
  Ponto* p3212 = new Vertice(0.84000, -1.50000, 0.07500);
  Ponto* p3222 = new Vertice(1.50000, -0.84000, 0.07500);
  //		Ponto* p2902 = new Vertice ( 1.50000, 0.00000, 0.07500 );

  //		Ponto* p933 = p933; //new Vertice ( 0.00000,-1.50000, 0.15000 );
  //		Ponto* p923 = p923; //new Vertice ( 0.84000,-1.50000, 0.15000 );
  //		Ponto* p913 = p913; //new Vertice ( 1.50000,-0.84000, 0.15000 );
  //		Ponto* p903 = p903; //new Vertice ( 1.50000, 0.00000, 0.15000 );

  Curva* patch32_c1 = new CurvParamBezier(*p3130, *p3210, *p3220, *p2900);
  //		Curva* patch32_c2 = new CurvParamBezier ( *p2900, *p2901, *p2902,
  //*p903 );
  Curva* patch32_c3 = new CurvParamBezier(*p933, *p923, *p913, *p903);
  //		Curva* patch32_c4 = new CurvParamBezier ( *p3130, *p3131, *p3132,
  //*p933 );

  Patch* patch32 = new BezierPatch(patch32_c1, patch29_c4, patch32_c3,
                                   patch31_c2, *p3211, *p3221, *p3212, *p3222);

  geo->inserePatch(patch32);
  geo->insereCurva(patch32_c1);
  //		geo->insereCurva ( patch32_c2 );
  geo->insereCurva(patch32_c3);
  //		geo->insereCurva ( patch32_c4 );
  //======================== FIM DO PATCH 32 =================================
  //==============================================================================
  // Fim do exemplo do Utahteapot
  //==============================================================================
  return geo;
}
