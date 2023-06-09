#ifndef _PARALLEL_MPI_MESSAGE_H_
#define _PARALLEL_MPI_MESSAGE_H_

#include "Definitions.h"

#if USE_MPI

#include "Message.h"

namespace Parallel {
class MPIMessage : public Parallel::Message {
 public:
  MPIMessage();
  MPIMessage(Int message);
  virtual ~MPIMessage();

  virtual UInt packSize(const Communicator *comm) const;
  virtual void pack(const Communicator *comm, char *buffer, Int size,
                    Int &position) const;
  virtual Package pack(const Communicator *comm) const;
  virtual void unpack(const Communicator *comm, const Package &p,
                      Int &position);
};
}  // namespace Parallel

#endif  //#if USE_MPI

#endif  //#ifndef _PARALLEL_MPI_MESSAGE_H_
