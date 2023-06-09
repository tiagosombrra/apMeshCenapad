#ifndef _PARALLEL_TM_COMMUNICATOR_H_
#define _PARALLEL_TM_COMMUNICATOR_H_

#include "Definitions.h"
#include "MPICommunicator.h"
#include "NoCommunicator.h"
#include "NoThreadManager.h"
#include "OMPThreadManager.h"

namespace Parallel {
class TMCommunicator :
#if USE_MPI
    public Parallel::MPICommunicator
#else
    public Parallel::NoCommunicator
#endif  //#if USE_MPI
    ,
#if USE_OPENMP
    public OMPThreadManager
#else
    public NoThreadManager
#endif  //#if USE_OPENMP
{
 public:
  TMCommunicator(bool sharedParallelismEnabled = true);
  virtual ~TMCommunicator();

  virtual Data::IntVector ranks(Int process = -1) const;

#if USE_OPENMP
  using OMPThreadManager::numThreads;
#else
  using NoThreadManager::numThreads;
#endif  //#if USE_OPENMP

  /// Unlike OMPThreadManager::numThreads(), this method actually returns
  ///   the maxThreads() of the given process.
  virtual Int numThreads(Int process) const;

  virtual Int numWorkers() const;

  virtual void initThreadCount();

 protected:
  Int totalThreadCount;
  Data::IntVector threadCount;
};
}  // namespace Parallel

#endif  //#ifndef _PARALLEL_TM_COMMUNICATOR_H_
