#ifndef READERPATCHES_H
#define READERPATCHES_H

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>

#include "../Data/Modelo.h"
#include "../Data/Patch/BezierPatch.h"
#include "../Data/Patch/HermitePatch.h"
#include "../Data/Ponto.h"

extern std::string entrada;

class ReaderPatches {
 public:
  std::list<BezierPatch *> patches;
  std::list<HermitePatch *> patchesHermite;
  BezierPatch *patch;
  HermitePatch *patchHermite;

  ReaderPatches();

  std::list<BezierPatch *> loaderBezierPatchFile(string fileName);
  Ponto getPointVectorControlPoints(std::vector<Ponto>, unsigned long);

  Geometria *readerPatches(Geometria *geo, string fileName);
};

#endif  // READERPATCHES_H
