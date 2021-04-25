#ifndef _PARALLEL_COMMUNICATOR_H_
#define _PARALLEL_COMMUNICATOR_H_

#include "Definitions.h"

namespace Parallel
{
	class Communicator
	{
	public:

		enum Type
		{
			CHAR = 1,
			SCHAR,
			UCHAR,

			BOOL,

			BYTE,

			SHORT,
			USHORT,

			INT,
			UINT,
			LINT,
			ULINT,

			REAL,
			LREAL,

			PACKED,

#if (!USE_OLD_MPI)
			COMPLEX,
			DCOMPLEX,
			LDCOMPLEX,
#endif //#if (!USE_OLD_MPI)

			NUM_TYPES
		};

		enum Operation
		{
			MAXIMUM = 1,
			MINIMUM,

			SUM,
			PRODUCT,

			LOGICAL_AND,
			LOGICAL_OR,
			LOGICAL_XOR,

			BITWISE_AND,
			BITWISE_OR,
			BITWISE_XOR,

			MAXIMUM_LOCATION,
			MINIMUM_LOCATION,

			NUM_OPERATIONS
		};

	public:

		virtual ~Communicator();

		virtual Int root() const = 0;

		virtual Int rank() const = 0;

		//virtual Int *ranks(UInt &size, Int process = -1) const = 0;
		virtual Data::IntVector ranks(Int process = -1) const = 0;
		//virtual Int numThreads(Int process = -1) const = 0;

		virtual Int numProcesses() const = 0;

		virtual std::string processorName() const = 0;

		virtual bool isMaster() const = 0;
		virtual bool isSlave() const = 0;

		virtual bool isParallel() const = 0;
		virtual bool isSerial() const = 0;

		virtual Int numWorkers() const = 0;

		virtual void init() const = 0;
		virtual void init(Int &argc, char **&argv) const = 0;
		virtual void finalize() const = 0;
		virtual void abort(Int error = 0) const = 0;

		virtual bool isInitialized() const = 0;
		virtual bool isFinalized() const = 0;

		virtual void barrier() const = 0;

		virtual Int packSize(UInt num, enum Type type) const = 0;

		virtual void pack(const void *val, Int size, void *buffer, Int bufferSize, Int &position, enum Type type) const = 0;

		virtual void pack(char val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(unsigned char val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(bool val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(short val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(unsigned short val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(Int val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(UInt val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(LInt val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(ULInt val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(Real val, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(LReal val, void *buffer, Int bufferSize, Int &position) const;

		virtual void pack(const char *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const unsigned char *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const bool *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const short *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const unsigned short *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const Int *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const UInt *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const LInt *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const ULInt *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const Real *val, Int size, void *buffer, Int bufferSize, Int &position) const;
		virtual void pack(const LReal *val, Int size, void *buffer, Int bufferSize, Int &position) const;

		virtual void unpack(void *val, Int size, const void *buffer, Int bufferSize, Int &position, enum Type type) const = 0;

		virtual void unpack(char &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(unsigned char &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(bool &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(short &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(unsigned short &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(Int &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(UInt &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(LInt &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(ULInt &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(Real &val, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(LReal &val, const void *buffer, Int bufferSize, Int &position) const;

		virtual void unpack(char *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(unsigned char *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(bool *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(short *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(unsigned short *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(Int *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(UInt *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(LInt *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(ULInt *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(Real *val, Int size, const void *buffer, Int bufferSize, Int &position) const;
		virtual void unpack(LReal *val, Int size, const void *buffer, Int bufferSize, Int &position) const;

		virtual void deleteRequest(UInt id = 0) const = 0;
		virtual void removeRequest(UInt id, bool posponeDeletion = false) const = 0;
		virtual Transferable *testRequest(UInt id) const = 0;
		virtual Transferable *waitRequest(UInt id) const = 0;

		virtual void broadcast(void *val, Int size, enum Type type, Int root) const = 0;

		//use root = -1 for the root, and root != -1 when the process is not the root
		virtual void broadcast(char &val, Int root) const;
		virtual void broadcast(unsigned char &val, Int root) const;
		virtual void broadcast(bool &val, Int root) const;
		virtual void broadcast(short &val, Int root) const;
		virtual void broadcast(unsigned short &val, Int root) const;
		virtual void broadcast(Int &val, Int root) const;
		virtual void broadcast(UInt &val, Int root) const;
		virtual void broadcast(LInt &val, Int root) const;
		virtual void broadcast(ULInt &val, Int root) const;
		virtual void broadcast(Real &val, Int root) const;
		virtual void broadcast(LReal &val, Int root) const;

		virtual void broadcast(char *val, Int size, Int root) const;
		virtual void broadcast(unsigned char *val, Int size, Int root) const;
		virtual void broadcast(bool *val, Int size, Int root) const;
		virtual void broadcast(short *val, Int size, Int root) const;
		virtual void broadcast(unsigned short *val, Int size, Int root) const;
		virtual void broadcast(Int *val, Int size, Int root) const;
		virtual void broadcast(UInt *val, Int size, Int root) const;
		virtual void broadcast(LInt *val, Int size, Int root) const;
		virtual void broadcast(ULInt *val, Int size, Int root) const;
		virtual void broadcast(Real *val, Int size, Int root) const;
		virtual void broadcast(LReal *val, Int size, Int root) const;

		//these two methods must be used together, the first one for the root
		// and the second one for the receiver
		virtual void broadcast(const Transferable *t) const;
		virtual Transferable *broadcast(Int root) const;

		virtual void broadcastv(Transferable **const t, Int size) const;
		virtual Transferable **broadcastv(Int &size, Int root) const;

		virtual void scatter(const void *sendBuffer, Int sendCount, void *receiveBuffer, Int receiveCount, enum Type type, Int root) const = 0;

		//every two of these methods syncronize with each other
		virtual void scatter(const char *val) const; //for the sender (root)
		virtual void scatter(char &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const unsigned char *val) const; //for the sender (root)
		virtual void scatter(unsigned char &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const bool *val) const; //for the sender (root)
		virtual void scatter(bool &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const short *val) const; //for the sender (root)
		virtual void scatter(short &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const unsigned short *val) const; //for the sender (root)
		virtual void scatter(unsigned short &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const Int *val) const; //for the sender (root)
		virtual void scatter(Int &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const UInt *val) const; //for the sender (root)
		virtual void scatter(UInt &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const LInt *val) const; //for the sender (root)
		virtual void scatter(LInt &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const ULInt *val) const; //for the sender (root)
		virtual void scatter(ULInt &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const Real *val) const; //for the sender (root)
		virtual void scatter(Real &val, Int root) const; //for the receiver (not root)
		virtual void scatter(const LReal *val) const; //for the sender (root)
		virtual void scatter(LReal &val, Int root) const; //for the receiver (not root)

		//every two of these methods syncronize with each other
		//the size of val must be size*this->numProcesses()
		virtual void scatter(const char *val, Int size) const; //for the sender (root)
		//the size of val must be size
		virtual void scatter(char *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const unsigned char *val, Int size) const; //for the sender (root)
		virtual void scatter(unsigned char *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const bool *val, Int size) const; //for the sender (root)
		virtual void scatter(bool *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const short *val, Int size) const; //for the sender (root)
		virtual void scatter(short *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const unsigned short *val, Int size) const; //for the sender (root)
		virtual void scatter(unsigned short *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const Int *val, Int size) const; //for the sender (root)
		virtual void scatter(Int *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const UInt *val, Int size) const; //for the sender (root)
		virtual void scatter(UInt *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const LInt *val, Int size) const; //for the sender (root)
		virtual void scatter(LInt *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const ULInt *val, Int size) const; //for the sender (root)
		virtual void scatter(ULInt *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const Real *val, Int size) const; //for the sender (root)
		virtual void scatter(Real *val, Int size, Int root) const; //for the receiver (not root)
		virtual void scatter(const LReal *val, Int size) const; //for the sender (root)
		virtual void scatter(LReal *val, Int size, Int root) const; //for the receiver (not root)

		virtual void scatterv(const void *sendBuffer, const Int sendCounts[], const Int displacements[], void *receiveBuffer, Int receiveCount, enum Type type, Int root) const = 0;

		//these two methods must be used together, the first one for the root
		// and the second one for the receiver
		virtual void scatter(Transferable **const t) const;
		virtual Transferable *scatter(Int root) const;

		//sizes should have size == this->numProcesses() - 1 (excludes this->rank())
		//  and the total size of the array should be the sum of the elements in sizes[]
		virtual void scatterv(Transferable **const t, Int sizes[]) const;
		virtual Transferable **scatterv(Int &size, Int root) const;

		virtual void gather(const void *sendBuffer, Int sendCount, void *receiveBuffer, Int receiveCount, enum Type type, Int root) const = 0;

		//every two of these methods syncronize with each other
		virtual void gather(char val, Int root) const; //for the sender (not root)
		//the size of buffer must be this->numProcesses()
		virtual void gather(char val, char *buffer) const; //for the receiver (root)
		virtual void gather(unsigned char val, Int root) const; //for the sender (not root)
		virtual void gather(unsigned char val, unsigned char *buffer) const; //for the receiver (root)
		virtual void gather(bool val, Int root) const; //for the sender (not root)
		virtual void gather(bool val, bool *buffer) const; //for the receiver (root)
		virtual void gather(short val, Int root) const; //for the sender (not root)
		virtual void gather(short val, short *buffer) const; //for the receiver (root)
		virtual void gather(unsigned short val, Int root) const; //for the sender (not root)
		virtual void gather(unsigned short val, unsigned short *buffer) const; //for the receiver (root)
		virtual void gather(Int val, Int root) const; //for the sender (not root)
		virtual void gather(Int val, Int *buffer) const; //for the receiver (root)
		virtual void gather(UInt val, Int root) const; //for the sender (not root)
		virtual void gather(UInt val, UInt *buffer) const; //for the receiver (root)
		virtual void gather(LInt val, Int root) const; //for the sender (not root)
		virtual void gather(LInt val, LInt *buffer) const; //for the receiver (root)
		virtual void gather(ULInt val, Int root) const; //for the sender (not root)
		virtual void gather(ULInt val, ULInt *buffer) const; //for the receiver (root)
		virtual void gather(Real val, Int root) const; //for the sender (not root)
		virtual void gather(Real val, Real *buffer) const; //for the receiver (root)
		virtual void gather(LReal val, Int root) const; //for the sender (not root)
		virtual void gather(LReal val, LReal *buffer) const; //for the receiver (root)

		//every two of these methods syncronize with each other
		//the size of val must be size
		virtual void gather(const char *val, Int size, Int root) const; //for the sender (not root)
		//the size of val must be size and the size of buffer must be size*this->numProcesses()
		virtual void gather(const char *val, Int size, char *buffer) const; //for the receiver (root)
		virtual void gather(const unsigned char *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const unsigned char *val, Int size, unsigned char *buffer) const; //for the receiver (root)
		virtual void gather(const bool *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const bool *val, Int size, bool *buffer) const; //for the receiver (root)
		virtual void gather(const short *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const short *val, Int size, short *buffer) const; //for the receiver (root)
		virtual void gather(const unsigned short *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const unsigned short *val, Int size, unsigned short *buffer) const; //for the receiver (root)
		virtual void gather(const Int *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const Int *val, Int size, Int *buffer) const; //for the receiver (root)
		virtual void gather(const UInt *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const UInt *val, Int size, UInt *buffer) const; //for the receiver (root)
		virtual void gather(const LInt *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const LInt *val, Int size, LInt *buffer) const; //for the receiver (root)
		virtual void gather(const ULInt *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const ULInt *val, Int size, ULInt *buffer) const; //for the receiver (root)
		virtual void gather(const Real *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const Real *val, Int size, Real *buffer) const; //for the receiver (root)
		virtual void gather(const LReal *val, Int size, Int root) const; //for the sender (not root)
		virtual void gather(const LReal *val, Int size, LReal *buffer) const; //for the receiver (root)

		virtual void gatherv(const void *sendBuffer, Int sendCount, void *receiveBuffer, const Int receiveCounts[], const Int displacements[], enum Type type, Int root) const = 0;

		//these two methods must be used together, the first one for the root
		// and the second one for the receiver
		virtual Transferable **gather() const;
		virtual void gather(const Transferable *t, Int root) const;

		//sizes should have size == this->numProcesses() - 1 (excludes this->rank())
		//  and the total size of the array should be the sum of the elements in sizes[]
		virtual Transferable **gatherv(Int sizes[]) const;
		virtual void gatherv(Transferable **const t, Int size, Int root) const;

		virtual void allGather(const void *sendBuffer, void *receiveBuffer, Int count, enum Type type) const = 0;

		virtual char *allGather(char val) const;
		virtual unsigned char *allGather(unsigned char val) const;
		virtual bool *allGather(bool val) const;
		virtual short *allGather(short val) const;
		virtual unsigned short *allGather(unsigned short val) const;
		virtual Int *allGather(Int val) const;
		virtual UInt *allGather(UInt val) const;
		virtual LInt *allGather(LInt val) const;
		virtual ULInt *allGather(ULInt val) const;
		virtual Real *allGather(Real val) const;
		virtual LReal *allGather(LReal val) const;

		virtual char *allGather(const char *val, Int size) const;
		virtual unsigned char *allGather(const unsigned char *val, Int size) const;
		virtual bool *allGather(const bool *val, Int size) const;
		virtual short *allGather(const short *val, Int size) const;
		virtual unsigned short *allGather(const unsigned short *val, Int size) const;
		virtual Int *allGather(const Int *val, Int size) const;
		virtual UInt *allGather(const UInt *val, Int size) const;
		virtual LInt *allGather(const LInt *val, Int size) const;
		virtual ULInt *allGather(const ULInt *val, Int size) const;
		virtual Real *allGather(const Real *val, Int size) const;
		virtual LReal *allGather(const LReal *val, Int size) const;

		virtual void allGatherv(const void *sendBuffer, Int sendCount, void *receiveBuffer, const Int receiveCounts[], const Int displacements[], enum Type type) const = 0;

		virtual Transferable **allGather(const Transferable *t) const;

		virtual void allToAll(const void *sendBuffer, void *receiveBuffer, Int count, enum Type type) const = 0;

		virtual char *allToAll(char val) const;
		virtual unsigned char *allToAll(unsigned char val) const;
		virtual bool *allToAll(bool val) const;
		virtual short *allToAll(short val) const;
		virtual unsigned short *allToAll(unsigned short val) const;
		virtual Int *allToAll(Int val) const;
		virtual UInt *allToAll(UInt val) const;
		virtual LInt *allToAll(LInt val) const;
		virtual ULInt *allToAll(ULInt val) const;
		virtual Real *allToAll(Real val) const;
		virtual LReal *allToAll(LReal val) const;

		virtual char *allToAll(const char *val, Int size) const;
		virtual unsigned char *allToAll(const unsigned char *val, Int size) const;
		virtual bool *allToAll(const bool *val, Int size) const;
		virtual short *allToAll(const short *val, Int size) const;
		virtual unsigned short *allToAll(const unsigned short *val, Int size) const;
		virtual Int *allToAll(const Int *val, Int size) const;
		virtual UInt *allToAll(const UInt *val, Int size) const;
		virtual LInt *allToAll(const LInt *val, Int size) const;
		virtual ULInt *allToAll(const ULInt *val, Int size) const;
		virtual Real *allToAll(const Real *val, Int size) const;
		virtual LReal *allToAll(const LReal *val, Int size) const;

		virtual void allToAllv(const void *sendBuffer, const Int sendCounts[], const Int sendDisplacements[], void *receiveBuffer, const Int receiveCounts[], const Int receiveDisplacements[], enum Type type) const = 0;

		virtual Transferable **allToAll(Transferable **const t) const;

		virtual void send(const void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual void send(char val, Int process, Int tag) const;
		virtual void send(unsigned char val, Int process, Int tag) const;
		virtual void send(bool val, Int process, Int tag) const;
		virtual void send(short val, Int process, Int tag) const;
		virtual void send(unsigned short val, Int process, Int tag) const;
		virtual void send(Int val, Int process, Int tag) const;
		virtual void send(UInt val, Int process, Int tag) const;
		virtual void send(LInt val, Int process, Int tag) const;
		virtual void send(ULInt val, Int process, Int tag) const;
		virtual void send(Real val, Int process, Int tag) const;
		virtual void send(LReal val, Int process, Int tag) const;

		virtual void send(const char *val, Int size, Int process, Int tag) const;
		virtual void send(const unsigned char *val, Int size, Int process, Int tag) const;
		virtual void send(const bool *val, Int size, Int process, Int tag) const;
		virtual void send(const short *val, Int size, Int process, Int tag) const;
		virtual void send(const unsigned short *val, Int size, Int process, Int tag) const;
		virtual void send(const Int *val, Int size, Int process, Int tag) const;
		virtual void send(const UInt *val, Int size, Int process, Int tag) const;
		virtual void send(const LInt *val, Int size, Int process, Int tag) const;
		virtual void send(const ULInt *val, Int size, Int process, Int tag) const;
		virtual void send(const Real *val, Int size, Int process, Int tag) const;
		virtual void send(const LReal *val, Int size, Int process, Int tag) const;

		virtual void send(const Transferable *t, Int process, Int tag) const;

		virtual void ssend(const void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual void ssend(char val, Int process, Int tag) const;
		virtual void ssend(unsigned char val, Int process, Int tag) const;
		virtual void ssend(bool val, Int process, Int tag) const;
		virtual void ssend(short val, Int process, Int tag) const;
		virtual void ssend(unsigned short val, Int process, Int tag) const;
		virtual void ssend(Int val, Int process, Int tag) const;
		virtual void ssend(UInt val, Int process, Int tag) const;
		virtual void ssend(LInt val, Int process, Int tag) const;
		virtual void ssend(ULInt val, Int process, Int tag) const;
		virtual void ssend(Real val, Int process, Int tag) const;
		virtual void ssend(LReal val, Int process, Int tag) const;

		virtual void ssend(const char *val, Int size, Int process, Int tag) const;
		virtual void ssend(const unsigned char *val, Int size, Int process, Int tag) const;
		virtual void ssend(const bool *val, Int size, Int process, Int tag) const;
		virtual void ssend(const short *val, Int size, Int process, Int tag) const;
		virtual void ssend(const unsigned short *val, Int size, Int process, Int tag) const;
		virtual void ssend(const Int *val, Int size, Int process, Int tag) const;
		virtual void ssend(const UInt *val, Int size, Int process, Int tag) const;
		virtual void ssend(const LInt *val, Int size, Int process, Int tag) const;
		virtual void ssend(const ULInt *val, Int size, Int process, Int tag) const;
		virtual void ssend(const Real *val, Int size, Int process, Int tag) const;
		virtual void ssend(const LReal *val, Int size, Int process, Int tag) const;

		virtual void ssend(const Transferable *t, Int process, Int tag) const;

		virtual void bsend(const void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual void bsend(char val, Int process, Int tag) const;
		virtual void bsend(unsigned char val, Int process, Int tag) const;
		virtual void bsend(bool val, Int process, Int tag) const;
		virtual void bsend(short val, Int process, Int tag) const;
		virtual void bsend(unsigned short val, Int process, Int tag) const;
		virtual void bsend(Int val, Int process, Int tag) const;
		virtual void bsend(UInt val, Int process, Int tag) const;
		virtual void bsend(LInt val, Int process, Int tag) const;
		virtual void bsend(ULInt val, Int process, Int tag) const;
		virtual void bsend(Real val, Int process, Int tag) const;
		virtual void bsend(LReal val, Int process, Int tag) const;

		virtual void bsend(const char *val, Int size, Int process, Int tag) const;
		virtual void bsend(const unsigned char *val, Int size, Int process, Int tag) const;
		virtual void bsend(const bool *val, Int size, Int process, Int tag) const;
		virtual void bsend(const short *val, Int size, Int process, Int tag) const;
		virtual void bsend(const unsigned short *val, Int size, Int process, Int tag) const;
		virtual void bsend(const Int *val, Int size, Int process, Int tag) const;
		virtual void bsend(const UInt *val, Int size, Int process, Int tag) const;
		virtual void bsend(const LInt *val, Int size, Int process, Int tag) const;
		virtual void bsend(const ULInt *val, Int size, Int process, Int tag) const;
		virtual void bsend(const Real *val, Int size, Int process, Int tag) const;
		virtual void bsend(const LReal *val, Int size, Int process, Int tag) const;

		virtual void bsend(const Transferable *t, Int process, Int tag) const;

		virtual void rsend(const void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual void rsend(char val, Int process, Int tag) const;
		virtual void rsend(unsigned char val, Int process, Int tag) const;
		virtual void rsend(bool val, Int process, Int tag) const;
		virtual void rsend(short val, Int process, Int tag) const;
		virtual void rsend(unsigned short val, Int process, Int tag) const;
		virtual void rsend(Int val, Int process, Int tag) const;
		virtual void rsend(UInt val, Int process, Int tag) const;
		virtual void rsend(LInt val, Int process, Int tag) const;
		virtual void rsend(ULInt val, Int process, Int tag) const;
		virtual void rsend(Real val, Int process, Int tag) const;
		virtual void rsend(LReal val, Int process, Int tag) const;

		virtual void rsend(const char *val, Int size, Int process, Int tag) const;
		virtual void rsend(const unsigned char *val, Int size, Int process, Int tag) const;
		virtual void rsend(const bool *val, Int size, Int process, Int tag) const;
		virtual void rsend(const short *val, Int size, Int process, Int tag) const;
		virtual void rsend(const unsigned short *val, Int size, Int process, Int tag) const;
		virtual void rsend(const Int *val, Int size, Int process, Int tag) const;
		virtual void rsend(const UInt *val, Int size, Int process, Int tag) const;
		virtual void rsend(const LInt *val, Int size, Int process, Int tag) const;
		virtual void rsend(const ULInt *val, Int size, Int process, Int tag) const;
		virtual void rsend(const Real *val, Int size, Int process, Int tag) const;
		virtual void rsend(const LReal *val, Int size, Int process, Int tag) const;

		virtual void rsend(const Transferable *t, Int process, Int tag) const;

		virtual UInt isend(const void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual UInt isend(char val, Int process, Int tag) const;
		virtual UInt isend(unsigned char val, Int process, Int tag) const;
		virtual UInt isend(bool val, Int process, Int tag) const;
		virtual UInt isend(short val, Int process, Int tag) const;
		virtual UInt isend(unsigned short val, Int process, Int tag) const;
		virtual UInt isend(Int val, Int process, Int tag) const;
		virtual UInt isend(UInt val, Int process, Int tag) const;
		virtual UInt isend(LInt val, Int process, Int tag) const;
		virtual UInt isend(ULInt val, Int process, Int tag) const;
		virtual UInt isend(Real val, Int process, Int tag) const;
		virtual UInt isend(LReal val, Int process, Int tag) const;

		virtual UInt isend(const char *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const unsigned char *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const bool *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const short *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const unsigned short *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const Int *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const UInt *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const LInt *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const ULInt *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const Real *val, Int size, Int process, Int tag) const;
		virtual UInt isend(const LReal *val, Int size, Int process, Int tag) const;

		virtual UInt isend(const Transferable *t, Int process, Int tag) const;

		virtual UInt issend(const void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual UInt issend(char val, Int process, Int tag) const;
		virtual UInt issend(unsigned char val, Int process, Int tag) const;
		virtual UInt issend(bool val, Int process, Int tag) const;
		virtual UInt issend(short val, Int process, Int tag) const;
		virtual UInt issend(unsigned short val, Int process, Int tag) const;
		virtual UInt issend(Int val, Int process, Int tag) const;
		virtual UInt issend(UInt val, Int process, Int tag) const;
		virtual UInt issend(LInt val, Int process, Int tag) const;
		virtual UInt issend(ULInt val, Int process, Int tag) const;
		virtual UInt issend(Real val, Int process, Int tag) const;
		virtual UInt issend(LReal val, Int process, Int tag) const;

		virtual UInt issend(const char *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const unsigned char *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const bool *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const short *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const unsigned short *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const Int *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const UInt *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const LInt *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const ULInt *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const Real *val, Int size, Int process, Int tag) const;
		virtual UInt issend(const LReal *val, Int size, Int process, Int tag) const;

		virtual UInt issend(const Transferable *t, Int process, Int tag) const;

		virtual UInt ibsend(const void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual UInt ibsend(char val, Int process, Int tag) const;
		virtual UInt ibsend(unsigned char val, Int process, Int tag) const;
		virtual UInt ibsend(bool val, Int process, Int tag) const;
		virtual UInt ibsend(short val, Int process, Int tag) const;
		virtual UInt ibsend(unsigned short val, Int process, Int tag) const;
		virtual UInt ibsend(Int val, Int process, Int tag) const;
		virtual UInt ibsend(UInt val, Int process, Int tag) const;
		virtual UInt ibsend(LInt val, Int process, Int tag) const;
		virtual UInt ibsend(ULInt val, Int process, Int tag) const;
		virtual UInt ibsend(Real val, Int process, Int tag) const;
		virtual UInt ibsend(LReal val, Int process, Int tag) const;

		virtual UInt ibsend(const char *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const unsigned char *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const bool *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const short *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const unsigned short *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const Int *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const UInt *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const LInt *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const ULInt *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const Real *val, Int size, Int process, Int tag) const;
		virtual UInt ibsend(const LReal *val, Int size, Int process, Int tag) const;

		virtual UInt ibsend(const Transferable *t, Int process, Int tag) const;

		virtual UInt irsend(const void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual UInt irsend(char val, Int process, Int tag) const;
		virtual UInt irsend(unsigned char val, Int process, Int tag) const;
		virtual UInt irsend(bool val, Int process, Int tag) const;
		virtual UInt irsend(short val, Int process, Int tag) const;
		virtual UInt irsend(unsigned short val, Int process, Int tag) const;
		virtual UInt irsend(Int val, Int process, Int tag) const;
		virtual UInt irsend(UInt val, Int process, Int tag) const;
		virtual UInt irsend(LInt val, Int process, Int tag) const;
		virtual UInt irsend(ULInt val, Int process, Int tag) const;
		virtual UInt irsend(Real val, Int process, Int tag) const;
		virtual UInt irsend(LReal val, Int process, Int tag) const;

		virtual UInt irsend(const char *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const unsigned char *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const bool *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const short *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const unsigned short *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const Int *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const UInt *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const LInt *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const ULInt *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const Real *val, Int size, Int process, Int tag) const;
		virtual UInt irsend(const LReal *val, Int size, Int process, Int tag) const;

		virtual UInt irsend(const Transferable *t, Int process, Int tag) const;

		virtual void receive(void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual void receive(char &val, Int process, Int tag) const;
		virtual void receive(unsigned char &val, Int process, Int tag) const;
		virtual void receive(bool &val, Int process, Int tag) const;
		virtual void receive(short &val, Int process, Int tag) const;
		virtual void receive(unsigned short &val, Int process, Int tag) const;
		virtual void receive(Int &val, Int process, Int tag) const;
		virtual void receive(UInt &val, Int process, Int tag) const;
		virtual void receive(LInt &val, Int process, Int tag) const;
		virtual void receive(ULInt &val, Int process, Int tag) const;
		virtual void receive(Real &val, Int process, Int tag) const;
		virtual void receive(LReal &val, Int process, Int tag) const;

		virtual void receive(char *val, Int size, Int process, Int tag) const;
		virtual void receive(unsigned char *val, Int size, Int process, Int tag) const;
		virtual void receive(bool *val, Int size, Int process, Int tag) const;
		virtual void receive(short *val, Int size, Int process, Int tag) const;
		virtual void receive(unsigned short *val, Int size, Int process, Int tag) const;
		virtual void receive(Int *val, Int size, Int process, Int tag) const;
		virtual void receive(UInt *val, Int size, Int process, Int tag) const;
		virtual void receive(LInt *val, Int size, Int process, Int tag) const;
		virtual void receive(ULInt *val, Int size, Int process, Int tag) const;
		virtual void receive(Real *val, Int size, Int process, Int tag) const;
		virtual void receive(LReal *val, Int size, Int process, Int tag) const;

		virtual Transferable *receive(Int process, Int tag) const;

		virtual UInt ireceive(void *buffer, Int size, enum Type type, Int process, Int tag) const = 0;

		virtual UInt ireceive(char &val, Int process, Int tag) const;
		virtual UInt ireceive(unsigned char &val, Int process, Int tag) const;
		virtual UInt ireceive(bool &val, Int process, Int tag) const;
		virtual UInt ireceive(short &val, Int process, Int tag) const;
		virtual UInt ireceive(unsigned short &val, Int process, Int tag) const;
		virtual UInt ireceive(Int &val, Int process, Int tag) const;
		virtual UInt ireceive(UInt &val, Int process, Int tag) const;
		virtual UInt ireceive(LInt &val, Int process, Int tag) const;
		virtual UInt ireceive(ULInt &val, Int process, Int tag) const;
		virtual UInt ireceive(Real &val, Int process, Int tag) const;
		virtual UInt ireceive(LReal &val, Int process, Int tag) const;

		virtual UInt ireceive(char *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(unsigned char *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(bool *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(short *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(unsigned short *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(Int *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(UInt *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(LInt *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(ULInt *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(Real *val, Int size, Int process, Int tag) const;
		virtual UInt ireceive(LReal *val, Int size, Int process, Int tag) const;

		virtual UInt ireceive(Int process, Int tag) const;

		virtual void reduce(const void *sendBuffer, void *receiveBuffer, Int size, enum Type type, enum Operation operation, Int root) const = 0;

		//root = -1 means that this processor is the root (root = this->rank()).
		// the non root processes should ignore the returned value.
		virtual char reduce(char val, enum Operation operation, Int root = -1) const;
		virtual unsigned char reduce(unsigned char val, enum Operation operation, Int root = -1) const;
		virtual bool reduce(bool val, enum Operation operation, Int root = -1) const;
		virtual short reduce(short val, enum Operation operation, Int root = -1) const;
		virtual unsigned short reduce(unsigned short val, enum Operation operation, Int root = -1) const;
		virtual Int reduce(Int val, enum Operation operation, Int root = -1) const;
		virtual UInt reduce(UInt val, enum Operation operation, Int root = -1) const;
		virtual LInt reduce(LInt val, enum Operation operation, Int root = -1) const;
		virtual ULInt reduce(ULInt val, enum Operation operation, Int root = -1) const;
		virtual Real reduce(Real val, enum Operation operation, Int root = -1) const;
		virtual LReal reduce(LReal val, enum Operation operation, Int root = -1) const;

		virtual char *reduce(const char *val, Int size, enum Operation operation, Int root = -1) const;
		virtual unsigned char *reduce(const unsigned char *val, Int size, enum Operation operation, Int root = -1) const;
		virtual bool *reduce(const bool *val, Int size, enum Operation operation, Int root = -1) const;
		virtual short *reduce(const short *val, Int size, enum Operation operation, Int root = -1) const;
		virtual unsigned short *reduce(const unsigned short *val, Int size, enum Operation operation, Int root = -1) const;
		virtual Int *reduce(const Int *val, Int size, enum Operation operation, Int root = -1) const;
		virtual UInt *reduce(const UInt *val, Int size, enum Operation operation, Int root = -1) const;
		virtual LInt *reduce(const LInt *val, Int size, enum Operation operation, Int root = -1) const;
		virtual ULInt *reduce(const ULInt *val, Int size, enum Operation operation, Int root = -1) const;
		virtual Real *reduce(const Real *val, Int size, enum Operation operation, Int root = -1) const;
		virtual LReal *reduce(const LReal *val, Int size, enum Operation operation, Int root = -1) const;

		virtual void allReduce(const void *sendBuffer, void *receiveBuffer, Int size, enum Type type, enum Operation operation) const = 0;

		virtual char allReduce(char val, enum Operation operation) const;
		virtual unsigned char allReduce(unsigned char val, enum Operation operation) const;
		virtual bool allReduce(bool val, enum Operation operation) const;
		virtual short allReduce(short val, enum Operation operation) const;
		virtual unsigned short allReduce(unsigned short val, enum Operation operation) const;
		virtual Int allReduce(Int val, enum Operation operation) const;
		virtual UInt allReduce(UInt val, enum Operation operation) const;
		virtual LInt allReduce(LInt val, enum Operation operation) const;
		virtual ULInt allReduce(ULInt val, enum Operation operation) const;
		virtual Real allReduce(Real val, enum Operation operation) const;
		virtual LReal allReduce(LReal val, enum Operation operation) const;

		virtual char *allReduce(const char *val, Int size, enum Operation operation) const;
		virtual unsigned char *allReduce(const unsigned char *val, Int size, enum Operation operation) const;
		virtual bool *allReduce(const bool *val, Int size, enum Operation operation) const;
		virtual short *allReduce(const short *val, Int size, enum Operation operation) const;
		virtual unsigned short *allReduce(const unsigned short *val, Int size, enum Operation operation) const;
		virtual Int *allReduce(const Int *val, Int size, enum Operation operation) const;
		virtual UInt *allReduce(const UInt *val, Int size, enum Operation operation) const;
		virtual LInt *allReduce(const LInt *val, Int size, enum Operation operation) const;
		virtual ULInt *allReduce(const ULInt *val, Int size, enum Operation operation) const;
		virtual Real *allReduce(const Real *val, Int size, enum Operation operation) const;
		virtual LReal *allReduce(const LReal *val, Int size, enum Operation operation) const;

		virtual void reduceScatter(const void *sendBuffer, void *receiveBuffer, Int receiveCounts[], enum Type type, enum Operation operation) const = 0;

		//one reduce operation per processor
		virtual char *reduceScatter(const char *val, enum Operation operation) const;
		virtual unsigned char *reduceScatter(const unsigned char *val, enum Operation operation) const;
		virtual bool *reduceScatter(const bool *val, enum Operation operation) const;
		virtual short *reduceScatter(const short *val, enum Operation operation) const;
		virtual unsigned short *reduceScatter(const unsigned short *val, enum Operation operation) const;
		virtual Int *reduceScatter(const Int *val, enum Operation operation) const;
		virtual UInt *reduceScatter(const UInt *val, enum Operation operation) const;
		virtual LInt *reduceScatter(const LInt *val, enum Operation operation) const;
		virtual ULInt *reduceScatter(const ULInt *val, enum Operation operation) const;
		virtual Real *reduceScatter(const Real *val, enum Operation operation) const;
		virtual LReal *reduceScatter(const LReal *val, enum Operation operation) const;

		//size reduce oprations per processor
		virtual char *reduceScatter(const char *val, Int size, enum Operation operation) const;
		virtual unsigned char *reduceScatter(const unsigned char *val, Int size, enum Operation operation) const;
		virtual bool *reduceScatter(const bool *val, Int size, enum Operation operation) const;
		virtual short *reduceScatter(const short *val, Int size, enum Operation operation) const;
		virtual unsigned short *reduceScatter(const unsigned short *val, Int size, enum Operation operation) const;
		virtual Int *reduceScatter(const Int *val, Int size, enum Operation operation) const;
		virtual UInt *reduceScatter(const UInt *val, Int size, enum Operation operation) const;
		virtual LInt *reduceScatter(const LInt *val, Int size, enum Operation operation) const;
		virtual ULInt *reduceScatter(const ULInt *val, Int size, enum Operation operation) const;
		virtual Real *reduceScatter(const Real *val, Int size, enum Operation operation) const;
		virtual LReal *reduceScatter(const LReal *val, Int size, enum Operation operation) const;

		virtual Transferable *unpack(Package &p, bool freeUponSuccess) const;
		virtual Transferable *unpack(Package &p) const = 0;
	};
}

#endif //#ifndef _PARALLEL_COMMUNICATOR_H_
