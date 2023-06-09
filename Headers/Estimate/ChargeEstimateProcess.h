#ifndef CHARGEESTIMATEPROCESS_H
#define CHARGEESTIMATEPROCESS_H

#include <algorithm>
#include <map>

#include "../Adapter/AdaptadorPorCurvatura.h"
#include "../Data/Curve/CurvParamBezier.h"
#include "../Data/Curve/Curva.h"
#include "../Data/Mesh/Malha.h"
#include "../Data/Patch/BezierPatch.h"
#include "../Data/Ponto.h"
#include "../Data/Vertice.h"
#include "../Generator/GeradorAdaptativoPorCurvatura.h"
#include "../IO/PatchBezierReader.h"
#include "../IO/WriteOBJFIle.h"
#include "../Timer/Timer.h"
#include "../Data/Geometria.h"

extern double TOLERANCIA_ESTIMATIVE;
extern double TRIANGLE_MEDIO;
extern std::string WRITE_MESH;
class ChargeEstimateProcess {
 public:
  ChargeEstimateProcess();
  std::list<BezierPatch *> chargeEstimateProcess(Geometria *, Timer *timer,
                                                 string entrada);
  std::vector<Ponto> interpolateControlPointsCurve(Ponto p0, Ponto p1, Ponto p2,
                                                   Ponto p3, double u,
                                                   double v);
  double calculateKaMedioPatch(BezierPatch *patch, int points);
  double calculateAreaPatch(BezierPatch *patch, int pointesGauusLegandre);
  double calculateAreaTriangleMedioRad(BezierPatch *patch);
  double calculateAreaTriangleMedio(BezierPatch *patch, Timer *timer, int grau);
  long int calculateNumbersTriangle(BezierPatch *patch, int grau);
  SubMalha *malhaInicialEstimativa(CoonsPatch *patch, int grau);
  bool calculateErroEstimative(Malha *malha, Timer *timer, int grau);
  // double calculateAreaPatchSegmets(BezierPatch *patch, int segments);
  // double calculateSegmentMedio(BezierPatch *patch);
  ~ChargeEstimateProcess();
  double menor_erro;
  int menor_grau;
  WriteOBJFIle write;
  std::vector<double> vecCurvature;
};

#endif  // CHARGEESTIMATEPROCESS_H
