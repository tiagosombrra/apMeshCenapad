#ifndef _PARALLEL_OMP_THREAD_MANAGER_H_
#define _PARALLEL_OMP_THREAD_MANAGER_H_

#include "Definitions.h"

#if USE_OPENMP

#include "ThreadManager.h"

namespace Parallel
{
	class OMPThreadManager : public Parallel::ThreadManager
	{
	public:

		OMPThreadManager(bool sharedParallelismEnabled = true);
		virtual ~OMPThreadManager();

		virtual void setMaxThreads(Int maxThreads);
		virtual Int getMaxThreads() const;

		virtual bool isInParallel() const;

		virtual Int numThreads() const;

		virtual Int threadId() const;
	};
}

#endif //#if USE_OPENMP

#endif //#ifndef _PARALLEL_OMP_THREAD_MANAGER_H_
