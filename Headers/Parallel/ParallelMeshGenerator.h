#ifndef PARALLELMESHGENERATOR_H
#define PARALLELMESHGENERATOR_H

#include "../Crabmesh/Performer/RangedIdManager.h"
#include "TMCommunicator.h"

using namespace Data;

class ParallelMeshGenerator {
 public:
  ParallelMeshGenerator();

  Performer::IdManager *makeIdManager(const Parallel::TMCommunicator *comm,
                                      Int id) const;

 protected:
  Performer::IdManager *idManager;
  mutable ULInt idoffset;
  ULInt idrange;
};

#endif  // PARALLELMESHGENERATOR_H
