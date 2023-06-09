#ifndef _PARALLEL_NO_THREAD_MANAGER_H_
#define _PARALLEL_NO_THREAD_MANAGER_H_

#include "Definitions.h"
#include "ThreadManager.h"

namespace Parallel {
class NoThreadManager : public ThreadManager {
 public:
  NoThreadManager(bool sharedParallelismEnabled = true);
  virtual ~NoThreadManager();

  virtual bool isSharedParallelismEnabled() const;

  virtual void setMaxThreads(Int maxThreads);
  virtual Int getMaxThreads() const;

  virtual bool isInParallel() const;

  virtual Int numThreads() const;

  virtual Int threadId() const;

 protected:
};
}  // namespace Parallel

#endif  //#ifndef _PARALLEL_NO_THREAD_MANAGER_H_
