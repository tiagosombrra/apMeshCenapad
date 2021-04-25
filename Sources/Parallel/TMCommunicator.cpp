#include "../../Headers/Parallel/TMCommunicator.h"

using namespace Parallel;

Parallel::TMCommunicator::TMCommunicator(bool sharedParallelismEnabled) :
#if USE_MPI
		Parallel::MPICommunicator::MPICommunicator()
#else
		Parallel::NoCommunicator::NoCommunicator()
#endif //#if USE_MPI
		,
#if USE_OPENMP
		Parallel::OMPThreadManager::OMPThreadManager(sharedParallelismEnabled)
#else
		Parallel::NoThreadManager::NoThreadManager(sharedParallelismEnabled)
#endif //#if USE_OPENMP
{
	this->totalThreadCount = 0;
}

Parallel::TMCommunicator::~TMCommunicator()
{

}

Data::IntVector Parallel::TMCommunicator::ranks(Int process) const
{
	Int rank = (process < 0) ? this->rank() : process;

	Int size = this->threadCount[rank];

	Data::IntVector ranks(size);

	Int minRank = 0;

	for (Int i = 0; i < rank; i++)
	{
		minRank += this->threadCount[i];
	}

	for (Int i = 0; i < this->threadCount[rank]; i++)
	{
		ranks[i] = minRank + i;
	}

	return ranks;
}

Int Parallel::TMCommunicator::numThreads(Int process) const
{
	if (process < 0)
	{
		if (!this->threadCount.empty())
		{
			return this->threadCount[this->rank()];
		}

		return this->getMaxThreads();
	}

	if (!this->threadCount.empty())
	{
		return this->threadCount[process];
	}

	return 0;
}

Int Parallel::TMCommunicator::numWorkers() const
{
	if (this->totalThreadCount != 0)
	{
		return this->totalThreadCount;
	}

#if USE_MPI
	return this->numProcesses();
#else
	return this->getMaxThreads();
#endif //#if USE_MPI
}

void Parallel::TMCommunicator::initThreadCount()
{
	Int numProcesses = this->numProcesses();

	Int numThreads = this->getMaxThreads();

	this->totalThreadCount = 0;

	if (numProcesses == 1)
	{
		this->totalThreadCount = numThreads;
	}
	else
	{
		this->threadCount.clear();

		this->threadCount.resize(numProcesses);

		Int *threadCount = this->allGather(numThreads);

		for (Int i = 0; i < numProcesses; i++)
		{
			this->threadCount[i] = threadCount[i];
			this->totalThreadCount += this->threadCount[i];
		}

		delete [] threadCount;
	}
}
