#include "../../Headers/Parallel/ThreadManager.h"

Parallel::ThreadManager::ThreadManager(bool sharedParallelismEnabled)
{
	this->setSharedParallelismEnabled(sharedParallelismEnabled);
}

Parallel::ThreadManager::~ThreadManager()
{

}

void Parallel::ThreadManager::setSharedParallelismEnabled(bool sharedParallelismEnabled)
{
	this->sharedParallelismEnabled = sharedParallelismEnabled;
}

bool Parallel::ThreadManager::isSharedParallelismEnabled() const
{
	return this->sharedParallelismEnabled;
}
