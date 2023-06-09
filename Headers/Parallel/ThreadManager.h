#ifndef _PARALLEL_THREAD_MANAGER_H_
#define _PARALLEL_THREAD_MANAGER_H_

#include "Definitions.h"

namespace Parallel {
class ThreadManager {
 public:
  ThreadManager(bool sharedParallelismEnabled = true);
  virtual ~ThreadManager();

  virtual void setSharedParallelismEnabled(bool sharedParallelismEnabled);
  virtual bool isSharedParallelismEnabled() const;

  virtual void setMaxThreads(Int maxThreads) = 0;
  virtual Int getMaxThreads() const = 0;

  virtual bool isInParallel() const = 0;

  virtual Int numThreads() const = 0;

  virtual Int threadId() const = 0;

 protected:
  bool sharedParallelismEnabled;
};
}  // namespace Parallel

#endif  //#ifndef _PARALLEL_THREAD_MANAGER_H_
