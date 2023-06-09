#include "../../Headers/Parallel/OMPThreadManager.h"

#if USE_OPENMP

#include <omp.h>

using namespace Parallel;

Parallel::OMPThreadManager::OMPThreadManager(bool sharedParallelismEnabled)
    : Parallel::ThreadManager::ThreadManager(sharedParallelismEnabled) {}

Parallel::OMPThreadManager::~OMPThreadManager() {}

void Parallel::OMPThreadManager::setMaxThreads(Int maxThreads) {
  if (this->isSharedParallelismEnabled()) {
    omp_set_num_threads(maxThreads);
  }
}

Int Parallel::OMPThreadManager::getMaxThreads() const {
  return this->isSharedParallelismEnabled() ? omp_get_max_threads() : 1;
}

bool Parallel::OMPThreadManager::isInParallel() const {
  return static_cast<bool>(omp_in_parallel());
}

Int Parallel::OMPThreadManager::numThreads() const {
  return omp_get_num_threads();
}

Int Parallel::OMPThreadManager::threadId() const {
  return omp_get_thread_num();
}

#endif  //#if USE_OPENMP
