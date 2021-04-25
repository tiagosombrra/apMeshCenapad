#ifndef _PARALLEL_MPI_COMMUNICATOR_H_
#define _PARALLEL_MPI_COMMUNICATOR_H_

#include "Definitions.h"
#include "Communicator.h"

#if USE_MPI
#include <mpi.h>

namespace MPI
{
	//these constants were redefined because they can change in some other
	// implementation

	const Datatype Char = CHAR;
	const Datatype SChar = SIGNED_CHAR;
	const Datatype UChar = UNSIGNED_CHAR;

#if USE_OLD_MPI
    const Datatype Boolean = CHAR;
#else
    const Datatype Boolean = BOOL;
#endif //#if USE_OLD_MPI

	const Datatype Byte = BYTE;

	const Datatype Short = SHORT;
	const Datatype UShort = UNSIGNED_SHORT;

	const Datatype Int = INT;
	const Datatype UInt = UNSIGNED;

#if USE_LONG_LONG_INT
	const Datatype LInt = LONG_LONG;
	const Datatype ULInt = UNSIGNED_LONG_LONG;
#else //#if USE_LONG_LONG_INT
	const Datatype LInt = LONG;
	const Datatype ULInt = UNSIGNED_LONG;
#endif //#if USE_LONG_LONG_INT

#if USE_DOUBLE
	const Datatype Real = DOUBLE;
	const Datatype LReal = LONG_DOUBLE;
#else //#if USE_DOUBLE
	const Datatype Real = FLOAT;
	const Datatype LReal = DOUBLE;
#endif //#if USE_DOUBLE

	const Datatype Packed = PACKED;

#if (!USE_OLD_MPI)
	const Datatype Complex = COMPLEX;
	const Datatype DComplex = DOUBLE_COMPLEX;
	const Datatype LDComplex = LONG_DOUBLE_COMPLEX;
#endif //#if (!USE_OLD_MPI)
}

namespace Parallel
{
	class MPICommunicator : public Parallel::Communicator
	{
	public:

		enum SendMode
		{
			NORMAL = 1,
			BLOCKING,
			BUFFERED,
			READY
		};

	public:

		MPICommunicator();
		virtual ~MPICommunicator();

		//virtual void setShParallel(bool shParallel);
		//virtual bool isShParallel() const;

		virtual void setCommunicator(MPI::Comm *communicator);
		virtual MPI::Comm *getCommunicator() const;

		virtual Int root() const;

		virtual Int rank() const;

		virtual Data::IntVector ranks(Int process = -1) const;
		//virtual UInt numThreads(Int process = -1) const;

		virtual Int numProcesses() const;

		virtual std::string processorName() const;

		virtual bool isMaster() const;
		virtual bool isSlave() const;

		virtual bool isParallel() const;
		virtual bool isSerial() const;

		//virtual Int numWorkers() const;

		virtual void init() const;
		virtual void init(Int &argc, char **&argv) const;

		//virtual void initThreadCount();

		virtual void finalize() const;

		virtual void abort(Int error = 0) const;

		virtual bool isInitialized() const;
		virtual bool isFinalized() const;

		virtual void barrier() const;

		virtual Int packSize(UInt num, enum Type type) const;
		virtual Int packSize(UInt num, MPI::Datatype &type) const;

		using Parallel::Communicator::pack;

		virtual void pack(const void *val, Int size, void *buffer, Int bufferSize, Int &position, enum Type type) const;
		virtual void pack(const void *val, Int size, void *buffer, Int bufferSize, Int &position, MPI::Datatype &type) const;

		using Parallel::Communicator::unpack;

		virtual void unpack(void *val, Int size, const void *buffer, Int bufferSize, Int &position, enum Type type) const;
		virtual void unpack(void *val, Int size, const void *buffer, Int bufferSize, Int &position, MPI::Datatype &type) const;

		virtual void removeRequest(UInt id, bool posponeDeletion = false) const;
		virtual void deleteRequest(UInt id = 0) const;
		virtual Transferable *testRequest(UInt id) const;
		virtual Transferable *waitRequest(UInt id) const;

		using Parallel::Communicator::broadcast;

		virtual void broadcast(void *val, Int size, enum Type type, Int root) const;
		virtual void broadcast(void *val, Int size, MPI::Datatype &type, Int root) const;

		using Parallel::Communicator::scatter;

		virtual void scatter(const void *sendBuffer, Int sendCount, void *receiveBuffer, Int receiveCount, enum Type type, Int root) const;
		virtual void scatter(const void *sendBuffer, Int sendCount, void *receiveBuffer, Int receiveCount, MPI::Datatype &type, Int root) const;

		using Parallel::Communicator::scatterv;

		virtual void scatterv(const void *sendBuffer, const Int sendCounts[], const Int displacements[], void *receiveBuffer, Int receiveCount, enum Type type, Int root) const;
		virtual void scatterv(const void *sendBuffer, const Int sendCounts[], const Int displacements[], void *receiveBuffer, Int receiveCount, MPI::Datatype &type, Int root) const;

		using Parallel::Communicator::gather;

		virtual void gather(const void *sendBuffer, Int sendCount, void *receiveBuffer, Int receiveCount, enum Type type, Int root) const;
		virtual void gather(const void *sendBuffer, Int sendCount, void *receiveBuffer, Int receiveCount, MPI::Datatype &type, Int root) const;

		using Parallel::Communicator::gatherv;

		virtual void gatherv(const void *sendBuffer, Int sendCount, void *receiveBuffer, const Int receiveCounts[], const Int displacements[], enum Type type, Int root) const;
		virtual void gatherv(const void *sendBuffer, Int sendCount, void *receiveBuffer, const Int receiveCounts[], const Int displacements[], MPI::Datatype &type, Int root) const;

		using Parallel::Communicator::allGather;

		virtual void allGather(const void *sendBuffer, void *receiveBuffer, Int count, enum Type type) const;
		virtual void allGather(const void *sendBuffer, void *receiveBuffer, Int count, MPI::Datatype &type) const;

		using Parallel::Communicator::allGatherv;

		virtual void allGatherv(const void *sendBuffer, Int sendCount, void *receiveBuffer, const Int receiveCounts[], const Int displacements[], enum Type type) const;
		virtual void allGatherv(const void *sendBuffer, Int sendCount, void *receiveBuffer, const Int receiveCounts[], const Int displacements[], MPI::Datatype &type) const;

		using Parallel::Communicator::allToAll;

		virtual void allToAll(const void *sendBuffer, void *receiveBuffer, Int count, enum Type type) const;
		virtual void allToAll(const void *sendBuffer, void *receiveBuffer, Int count, MPI::Datatype &type) const;

		using Parallel::Communicator::allToAllv;

		virtual void allToAllv(const void *sendBuffer, const Int sendCounts[], const Int sendDisplacements[], void *receiveBuffer, const Int receiveCounts[], const Int receiveDisplacements[], enum Type type) const;
		virtual void allToAllv(const void *sendBuffer, const Int sendCounts[], const Int sendDisplacements[], void *receiveBuffer, const Int receiveCounts[], const Int receiveDisplacements[], MPI::Datatype &type) const;

		using Communicator::send;

		virtual void send(const void *buffer, Int size, enum Type type, Int process, Int tag) const;
		virtual void send(const void *buffer, Int size, MPI::Datatype &type, Int process, Int tag) const;

		using Communicator::ssend;

		virtual void ssend(const void *buffer, Int size, enum Type type, Int process, Int tag) const;
		virtual void ssend(const void *buffer, Int size, MPI::Datatype &type, Int process, Int tag) const;

		using Communicator::bsend;

		virtual void bsend(const void *buffer, Int size, enum Type type, Int process, Int tag) const;
		virtual void bsend(const void *buffer, Int size, MPI::Datatype &type, Int process, Int tag) const;

		using Communicator::rsend;

		virtual void rsend(const void *buffer, Int size, enum Type type, Int process, Int tag) const;
		virtual void rsend(const void *buffer, Int size, MPI::Datatype &type, Int process, Int tag) const;

		using Communicator::isend;

		virtual UInt isend(const void *buffer, Int size, enum Type type, Int process, Int tag) const;
		virtual MPI::Request isend(const void *buffer, Int size, MPI::Datatype &type, Int process, Int tag) const;

		using Communicator::issend;

		virtual UInt issend(const void *buffer, Int size, enum Type type, Int process, Int tag) const;
		virtual MPI::Request issend(const void *buffer, Int size, MPI::Datatype &type, Int process, Int tag) const;

		using Communicator::ibsend;

		virtual UInt ibsend(const void *buffer, Int size, enum Type type, Int process, Int tag) const;
		virtual MPI::Request ibsend(const void *buffer, Int size, MPI::Datatype &type, Int process, Int tag) const;

		using Communicator::irsend;

		virtual UInt irsend(const void *buffer, Int size, enum Type type, Int process, Int tag) const;
		virtual MPI::Request irsend(const void *buffer, Int size, MPI::Datatype &type, Int process, Int tag) const;

		using Communicator::receive;

		virtual void receive(void *buffer, Int size, enum Type type, Int proces, Int tag) const;
		virtual void receive(void *buffer, Int size, MPI::Datatype &type, Int proces, Int tag) const;

		using Communicator::ireceive;

		virtual UInt ireceive(void *buffer, Int size, enum Type type, Int proces, Int tag) const;
		virtual MPI::Request ireceive(void *buffer, Int size, MPI::Datatype &type, Int proces, Int tag) const;

		using Communicator::reduce;

		virtual void reduce(const void *sendBuffer, void *receiveBuffer, Int size, enum Type type, enum Operation operation, Int root) const;
		virtual void reduce(const void *sendBuffer, void *receiveBuffer, Int size, MPI::Datatype &type, MPI::Op &operation, Int root) const;

		using Communicator::allReduce;

		virtual void allReduce(const void *sendBuffer, void *receiveBuffer, Int size, enum Type type, enum Operation operation) const;
		virtual void allReduce(const void *sendBuffer, void *receiveBuffer, Int size, MPI::Datatype &type, MPI::Op &operation) const;

		using Communicator::reduceScatter;

		virtual void reduceScatter(const void *sendBuffer, void *receiveBuffer, Int receiveCounts[], enum Type type, enum Operation operation) const;
		virtual void reduceScatter(const void *sendBuffer, void *receiveBuffer, Int receiveCounts[], MPI::Datatype &type, MPI::Op &operation) const;

	protected:

#if USE_C__11
		typedef std::tuple<MPI::Request, Int, void *> Request;
#else
		struct Request {MPI::Request request; Int size; void *buffer;};
#endif //#if USE_C__11

#if USE_C__11
		struct TypeHash
		{
			size_t operator()(const enum Communicator::Type &type) const
			{
				return static_cast<size_t>(type);
			};
		};

		struct OpHash
		{
			size_t operator()(const enum Communicator::Operation &op) const
			{
				return static_cast<size_t>(op);
			};
		};

		typedef std::unordered_map<UInt, Request> RequestHashMap;
		typedef std::unordered_map<enum Communicator::Type, MPI::Datatype, TypeHash> TypeHashMap;
		typedef std::unordered_map<enum Communicator::Operation, MPI::Op, OpHash> OpHashMap;
#endif //#if USE_C__11

		typedef std::map<UInt, Request> RequestMap;
		typedef std::map<enum Communicator::Type, MPI::Datatype> TypeMap;
		typedef std::map<enum Communicator::Operation, MPI::Op> OpMap;

		mutable TypeMap typemap;
		mutable OpMap opmap;

		MPI::Comm *communicator;
		MPI::Status status;

		mutable UInt request;
		mutable RequestMap requests;
		mutable RequestMap oldRequests;

		mutable Int process;
		mutable Int rootProcess;
		mutable Int size;

		//Int totalThreadCount;
		//Data::IntVector threadCount;

		//bool shParallel;

		static UInt count;
		static bool initializedHere;
	};
}

#endif //#if USE_MPI

#endif //#ifndef _PARALLEL_MPI_COMMUNICATOR_H_
