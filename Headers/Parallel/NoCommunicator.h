#ifndef _PARALLEL_NO_COMMUNICATOR_H_
#define _PARALLEL_NO_COMMUNICATOR_H_

#include "Communicator.h"
#include "Definitions.h"

namespace Parallel {
class NoCommunicator : public Communicator {
 public:
  NoCommunicator();
  virtual ~NoCommunicator();

  virtual Int root() const;

  virtual Int rank() const;

  virtual Int numProcesses() const;

  virtual std::string processorName() const;

  virtual bool isMaster() const;
  virtual bool isSlave() const;

  virtual bool isParallel() const;
  virtual bool isSerial() const;

  virtual Int numWorkers() const;

  virtual void init() const;
  virtual void init(Int &argc, char **&argv) const;
  virtual void finalize() const;
  virtual void abort(Int error) const;

  virtual bool isInitialized() const;
  virtual bool isFinalized() const;

  virtual void barrier() const;

  using Parallel::Communicator::packSize;
  virtual Int packSize(UInt num, enum Type type) const;

  using Parallel::Communicator::pack;
  virtual void pack(const void *val, Int size, void *buffer, Int bufferSize,
                    Int &position, enum Type type) const;

  using Parallel::Communicator::unpack;
  virtual void unpack(void *val, Int size, const void *buffer, Int bufferSize,
                      Int &position, enum Type type) const;

  virtual void deleteRequest(UInt id) const;
  virtual void removeRequest(UInt id, bool posponeDeletion = false) const;
  virtual Transferable *testRequest(UInt id) const;
  virtual Transferable *waitRequest(UInt id) const;

  using Parallel::Communicator::broadcast;
  virtual void broadcast(void *val, Int size, enum Type type, Int root) const;

  using Parallel::Communicator::scatter;
  virtual void scatter(const void *sendBuffer, Int sendCount,
                       void *receiveBuffer, Int receiveCount, enum Type type,
                       Int root) const;
  using Parallel::Communicator::scatterv;
  virtual void scatterv(const void *sendBuffer, const Int sendCounts[],
                        const Int displacements[], void *receiveBuffer,
                        Int receiveCount, enum Type type, Int root) const;

  using Parallel::Communicator::gather;
  virtual void gather(const void *sendBuffer, Int sendCount,
                      void *receiveBuffer, Int receiveCount, enum Type type,
                      Int root) const;
  using Parallel::Communicator::gatherv;
  virtual void gatherv(const void *sendBuffer, Int sendCount,
                       void *receiveBuffer, const Int receiveCounts[],
                       const Int displacements[], enum Type type,
                       Int root) const;

  using Parallel::Communicator::allGather;
  virtual void allGather(const void *sendBuffer, void *receiveBuffer, Int count,
                         enum Type type) const;
  using Parallel::Communicator::allGatherv;
  virtual void allGatherv(const void *sendBuffer, Int sendCount,
                          void *receiveBuffer, const Int receiveCounts[],
                          const Int displacements[], enum Type type) const;

  using Parallel::Communicator::allToAll;
  virtual void allToAll(const void *sendBuffer, void *receiveBuffer, Int count,
                        enum Type type) const;
  using Parallel::Communicator::allToAllv;
  virtual void allToAllv(const void *sendBuffer, const Int sendCounts[],
                         const Int sendDisplacements[], void *receiveBuffer,
                         const Int receiveCounts[],
                         const Int receiveDisplacements[],
                         enum Type type) const;

  using Parallel::Communicator::send;
  virtual void send(const void *buffer, Int size, enum Type type, Int process,
                    Int tag) const;
  using Parallel::Communicator::ssend;
  virtual void ssend(const void *buffer, Int size, enum Type type, Int process,
                     Int tag) const;
  using Parallel::Communicator::bsend;
  virtual void bsend(const void *buffer, Int size, enum Type type, Int process,
                     Int tag) const;
  using Parallel::Communicator::rsend;
  virtual void rsend(const void *buffer, Int size, enum Type type, Int process,
                     Int tag) const;

  using Parallel::Communicator::isend;
  virtual UInt isend(const void *buffer, Int size, enum Type type, Int process,
                     Int tag) const;
  using Parallel::Communicator::issend;
  virtual UInt issend(const void *buffer, Int size, enum Type type, Int process,
                      Int tag) const;
  using Parallel::Communicator::ibsend;
  virtual UInt ibsend(const void *buffer, Int size, enum Type type, Int process,
                      Int tag) const;
  using Parallel::Communicator::irsend;
  virtual UInt irsend(const void *buffer, Int size, enum Type type, Int process,
                      Int tag) const;

  using Parallel::Communicator::receive;
  virtual void receive(void *buffer, Int size, enum Type type, Int process,
                       Int tag) const;
  using Parallel::Communicator::ireceive;
  virtual UInt ireceive(void *buffer, Int size, enum Type type, Int process,
                        Int tag) const;

  using Parallel::Communicator::reduce;
  virtual void reduce(const void *sendBuffer, void *receiveBuffer, Int size,
                      enum Type type, enum Operation operation, Int root) const;

  using Parallel::Communicator::allReduce;
  virtual void allReduce(const void *sendBuffer, void *receiveBuffer, Int size,
                         enum Type type, enum Operation operation) const;

  using Parallel::Communicator::reduceScatter;
  virtual void reduceScatter(const void *sendBuffer, void *receiveBuffer,
                             Int receiveCounts[], enum Type type,
                             enum Operation operation) const;

  virtual Transferable *unpack(Package &p) const;

 protected:
};
}  // namespace Parallel

#endif  //#ifndef _PARALLEL_NO_COMMUNICATOR_H_
