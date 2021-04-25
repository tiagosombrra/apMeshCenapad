#include "../../Headers/Parallel/ApMeshCommunicator.h"

ApMeshCommunicator::ApMeshCommunicator(bool sharedParallelismEnabled):
    Parallel::TMCommunicator::TMCommunicator(sharedParallelismEnabled)
{

}

ApMeshCommunicator::~ApMeshCommunicator()
{

}

bool ApMeshCommunicator::isMaster() const
{
   return (this->rank() == this->root());
}

Parallel::Transferable *ApMeshCommunicator::unpack(Parallel::Package &p) const
{
    return NULL;
}
