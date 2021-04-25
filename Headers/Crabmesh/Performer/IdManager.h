#ifndef _PERFORMER_ID_MANAGER_H_
#define _PERFORMER_ID_MANAGER_H_

#include "Definitions.h"

namespace Performer
{
	class IdManager
	{
	public:

		IdManager(ULInt id = 1, UInt size = 1);
		virtual ~IdManager();

		virtual void setId(UInt i, ULInt id);
		virtual void setId(ULInt id);
		virtual ULInt getId(UInt i) const;
		virtual ULInt getId() const;

		virtual ULInt current(UInt i) const;
		virtual ULInt current() const;
		virtual ULInt next(UInt i) = 0;
		virtual ULInt next() = 0;

	protected:

		ULInt *ids;
		UInt size;
	};
}

#endif //#ifndef _PERFORMER_ID_MANAGER_H_
