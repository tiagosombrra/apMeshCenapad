#ifndef _PERFORMER_RANGED_ID_MANAGER_H_
#define _PERFORMER_RANGED_ID_MANAGER_H_

#include "Definitions.h"
#include "IdManager.h"

namespace Performer
{
	class RangedIdManager : public Performer::IdManager
	{
	public:

		RangedIdManager(ULInt id = 1, ULInt min = 1, ULInt offset = 1, ULInt range = 1, UInt size = 1);
		virtual ~RangedIdManager();

		using Performer::IdManager::setId;
		virtual void setId(UInt i, ULInt id);

		virtual void setMin(UInt i, ULInt min);
		virtual void setMin(ULInt min);
		virtual ULInt getMin(UInt i) const;
		virtual ULInt getMin() const;

		virtual void setOffset(ULInt offset);
		virtual ULInt getOffset() const;

		virtual void setRange(ULInt range);
		virtual ULInt getRange() const;

		virtual ULInt next(UInt i);
		virtual ULInt next();

	protected:

		virtual void adjust(UInt i);
		virtual void adjustAll();

	protected:

		ULInt *mins;
		ULInt offset;
		ULInt range;

	};
}

#endif //#ifndef _PERFORMER_RANGED_ID_MANAGER_H_
