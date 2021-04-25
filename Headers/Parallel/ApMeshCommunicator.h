#ifndef APMESHCOMMUNICATOR_H
#define APMESHCOMMUNICATOR_H

#include "TMCommunicator.h"

class ApMeshCommunicator:public Parallel::TMCommunicator
{
public:
    ApMeshCommunicator(bool sharedParallelismEnabled);
    virtual ~ApMeshCommunicator();
    virtual bool isMaster() const;
    using Parallel::TMCommunicator::unpack;
    virtual Parallel::Transferable *unpack(Parallel::Package &p) const;
};

#endif // APMESHCOMMUNICATOR_H
