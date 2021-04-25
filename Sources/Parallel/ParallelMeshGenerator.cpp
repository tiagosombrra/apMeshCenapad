#include "../../Headers/Parallel/ParallelMeshGenerator.h"

ParallelMeshGenerator::ParallelMeshGenerator()
{
    this->idManager = NULL;
    this->idoffset = 0;
    this->idrange = 1024;
}

Performer::IdManager *ParallelMeshGenerator::makeIdManager(const Parallel::TMCommunicator *comm, Int id) const
{
    UInt numProcs = comm->numProcesses();
    UInt rank = comm->rank();

    ULInt procOffset = rank*this->idrange;

    this->idoffset = numProcs*this->idrange;
    ULInt tidrange = this->idrange/comm->getMaxThreads();

    Performer::RangedIdManager *manager = new Performer::RangedIdManager(1, 1, 1, 1, 3);

    ULInt threadOffset = id*tidrange;

    manager->setRange(tidrange);
    manager->setOffset(this->idoffset);

    manager->setMin(0, this->idManager->getId(0) + procOffset + threadOffset);
    manager->setMin(1, this->idManager->getId(1) + procOffset + threadOffset);
    manager->setMin(2, this->idManager->getId(2) + procOffset + threadOffset);

    return manager;
}
