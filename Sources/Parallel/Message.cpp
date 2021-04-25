#include "../../Headers/Parallel/Message.h"

using namespace Parallel;

Parallel::Message::Message() :
	Transferable(0)
{
	this->setMessage(0);
}

Parallel::Message::Message(Int message) :
	Transferable(0)
{
	this->setMessage(message);
}

Parallel::Message::~Message()
{

}

void Parallel::Message::setMessage(Int message)
{
	this->message = message;
}

Int Parallel::Message::getMessage() const
{
	return this->message;
}
