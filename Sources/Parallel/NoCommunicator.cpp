#include "../../Headers/Parallel/NoCommunicator.h"

using namespace Parallel;

Parallel::NoCommunicator::NoCommunicator() :
	Parallel::Communicator::Communicator()
{

}

Parallel::NoCommunicator::~NoCommunicator()
{

}

Int Parallel::NoCommunicator::root() const
{
	return 0;
}

Int Parallel::NoCommunicator::rank() const
{
	return 0;
}

Int Parallel::NoCommunicator::numProcesses() const
{
	return 1;
}

std::string Parallel::NoCommunicator::processorName() const
{
	return std::string();
}

bool Parallel::NoCommunicator::isMaster() const
{
	return false;
}

bool Parallel::NoCommunicator::isSlave() const
{
	return (!this->isMaster());
}

bool Parallel::NoCommunicator::isParallel() const
{
	return false;
}

bool Parallel::NoCommunicator::isSerial() const
{
	return (!this->isParallel());
}

Int Parallel::NoCommunicator::numWorkers() const
{
	return 1;
}

void Parallel::NoCommunicator::init() const
{

}

void Parallel::NoCommunicator::init(Int &/*argc*/, char **&/*argv*/) const
{

}

void Parallel::NoCommunicator::finalize() const
{

}

void Parallel::NoCommunicator::abort(Int /*error*/) const
{

}

bool Parallel::NoCommunicator::isInitialized() const
{
	return true;
}

bool Parallel::NoCommunicator::isFinalized() const
{
	return true;
}

void Parallel::NoCommunicator::barrier() const
{

}

Int Parallel::NoCommunicator::packSize(UInt /*num*/, enum Type /*type*/) const
{
	return 0;
}

void Parallel::NoCommunicator::pack(const void */*val*/, Int /*size*/, void */*buffer*/, Int /*bufferSize*/, Int &position, enum Type /*type*/) const
{
	position = 0;
}

void Parallel::NoCommunicator::unpack(void */*val*/, Int /*size*/, const void */*buffer*/, Int /*bufferSize*/, Int &position, enum Type /*type*/) const
{
	position = 0;
}

void Parallel::NoCommunicator::deleteRequest(UInt /*id*/) const
{

}

void Parallel::NoCommunicator::removeRequest(UInt /*id*/, bool /*posponeDeletion*/) const
{

}

Transferable *Parallel::NoCommunicator::testRequest(UInt /*id*/) const
{
	return NULL;
}

Transferable *Parallel::NoCommunicator::waitRequest(UInt /*id*/) const
{
	return NULL;
}

void Parallel::NoCommunicator::broadcast(void */*val*/, Int /*size*/, enum Type /*type*/, Int /*root*/) const
{

}

void Parallel::NoCommunicator::scatter(const void */*sendBuffer*/, Int /*sendCount*/, void */*receiveBuffer*/, Int /*receiveCount*/, enum Type /*type*/, Int /*root*/) const
{

}

void Parallel::NoCommunicator::scatterv(const void */*sendBuffer*/, const Int /*sendCounts*/[], const Int /*displacements*/[], void */*receiveBuffer*/, Int /*receiveCount*/, enum Type /*type*/, Int /*root*/) const
{

}

void Parallel::NoCommunicator::gather(const void */*sendBuffer*/, Int /*sendCount*/, void */*receiveBuffer*/, Int /*receiveCount*/, enum Type /*type*/, Int /*root*/) const
{

}

void Parallel::NoCommunicator::gatherv(const void */*sendBuffer*/, Int /*sendCount*/, void */*receiveBuffer*/, const Int /*receiveCounts*/[], const Int /*displacements*/[], enum Type /*type*/, Int /*root*/) const
{

}

void Parallel::NoCommunicator::allGather(const void */*sendBuffer*/, void */*receiveBuffer*/, Int /*count*/, enum Type /*type*/) const
{

}

void Parallel::NoCommunicator::allGatherv(const void */*sendBuffer*/, Int /*sendCount*/, void */*receiveBuffer*/, const Int /*receiveCounts*/[], const Int /*displacements*/[], enum Type /*type*/) const
{

}

void Parallel::NoCommunicator::allToAll(const void */*sendBuffer*/, void */*receiveBuffer*/, Int /*count*/, enum Type /*type*/) const
{

}

void Parallel::NoCommunicator::allToAllv(const void */*sendBuffer*/, const Int /*sendCounts*/[], const Int /*sendDisplacements*/[], void */*receiveBuffer*/, const Int /*receiveCounts*/[], const Int /*receiveDisplacements*/[], enum Type /*type*/) const
{

}

void Parallel::NoCommunicator::send(const void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{

}

void Parallel::NoCommunicator::ssend(const void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{

}

void Parallel::NoCommunicator::bsend(const void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{

}

void Parallel::NoCommunicator::rsend(const void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{

}

UInt Parallel::NoCommunicator::isend(const void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{
	return 0;
}

UInt Parallel::NoCommunicator::issend(const void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{
	return 0;
}

UInt Parallel::NoCommunicator::ibsend(const void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{
	return 0;
}

UInt Parallel::NoCommunicator::irsend(const void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{
	return 0;
}

void Parallel::NoCommunicator::receive(void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{

}

UInt Parallel::NoCommunicator::ireceive(void */*buffer*/, Int /*size*/, enum Type /*type*/, Int /*process*/, Int /*tag*/) const
{
	return 0;
}

void Parallel::NoCommunicator::reduce(const void */*sendBuffer*/, void */*receiveBuffer*/, Int /*size*/, enum Type /*type*/, enum Operation /*operation*/, Int /*root*/) const
{

}

void Parallel::NoCommunicator::allReduce(const void */*sendBuffer*/, void */*receiveBuffer*/, Int /*size*/, enum Type /*type*/, enum Operation /*operation*/) const
{

}

void Parallel::NoCommunicator::reduceScatter(const void */*sendBuffer*/, void */*receiveBuffer*/, Int /*receiveCounts*/[], enum Type /*type*/, enum Operation /*operation*/) const
{

}

Transferable *Parallel::NoCommunicator::unpack(Package &/*p*/) const
{
	return NULL;
}
