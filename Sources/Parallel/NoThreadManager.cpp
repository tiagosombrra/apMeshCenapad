#include "../../Headers/Parallel/NoThreadManager.h"

using namespace Parallel;

Parallel::NoThreadManager::NoThreadManager(bool /*sharedParallelismEnabled*/)
    : Parallel::ThreadManager::ThreadManager(false) {}

Parallel::NoThreadManager::~NoThreadManager() {}

bool Parallel::NoThreadManager::isSharedParallelismEnabled() const {
  return false;
}

void Parallel::NoThreadManager::setMaxThreads(Int /*maxThreads*/) {}

Int Parallel::NoThreadManager::getMaxThreads() const { return 1; }

bool Parallel::NoThreadManager::isInParallel() const { return false; }

Int Parallel::NoThreadManager::numThreads() const { return 1; }

Int Parallel::NoThreadManager::threadId() const { return 0; }
