#ifndef _PARALLEL_TRANSFERABLE_H_
#define _PARALLEL_TRANSFERABLE_H_

#include "Definitions.h"

namespace Parallel
{
	class Transferable
	{
	public:

		Transferable(UInt type);
		virtual ~Transferable();

		virtual void setType(UInt type);
		virtual UInt getType();

		//this method returns the size of the pack created when calling the
		// mehtod pack()
		virtual UInt packSize(const Communicator *comm) const = 0;
		//this method creates a package with the contents of the object, along
		// with the type as the first content item
		virtual Package pack(const Communicator *comm) const = 0;
		virtual void pack(const Communicator *comm, char *buffer, Int size, Int &position) const = 0;
		//this method unpacks the contents of the package. the given position
		// is passed because the type of the object has already been extracted,
		// and does not need to be extracted again
		virtual void unpack(const Communicator *comm, const Package &p, Int &position) = 0;

		static void free(Package &p);

	protected:

		UInt type;
	};
}

#endif //#ifndef _PARALLEL_TRANSFERABLE_H_
