#include "../../Headers/Parallel/MPIMessage.h"

#if USE_MPI

#include "../../Headers/Parallel/MPICommunicator.h"

using namespace Parallel;

Parallel::MPIMessage::MPIMessage() :
	Message()
{

}

Parallel::MPIMessage::MPIMessage(Int message) :
	Message(message)
{

}

Parallel::MPIMessage::~MPIMessage()
{

}

UInt Parallel::MPIMessage::packSize(const Parallel::Communicator *comm) const
{
	UInt size = 0;

	//unsigned - type
	size += comm->packSize(1, Communicator::UINT);
	//int - message
	size += comm->packSize(1, Communicator::INT);

	return size;
}

void Parallel::MPIMessage::pack(const Communicator *comm, char *buffer, Int size, Int &position) const
{
	comm->pack(this->type, buffer, size, position);
	comm->pack(this->message, buffer, size, position);
}

Package Parallel::MPIMessage::pack(const Communicator *comm) const
{
	Int size = this->packSize(comm);
	char *buffer = NULL;
	Int position = 0;

	buffer = new char[size];

	this->pack(comm, buffer, size, position);

	Package p(size, buffer);

	return p;
}

void Parallel::MPIMessage::unpack(const Communicator *comm, const Package &p, Int &position)
{
	Int size = p.first;
	char *buffer = p.second;

	if (position == 0)
	{
		Int ignore = 0;

		comm->unpack(ignore, buffer, size, position);
	}

	comm->unpack(this->message, buffer, size, position);
}

#endif //#if USE_MPI
