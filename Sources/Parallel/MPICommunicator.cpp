#include "../../Headers/Parallel/MPICommunicator.h"

#if USE_MPI

#include "../../Headers/Parallel/MPIMessage.h"

/*#if USE_OPENMP
#include <omp.h>
#endif //#if USE_OPENMP*/

using namespace Parallel;

UInt Parallel::MPICommunicator::count = 0;
bool Parallel::MPICommunicator::initializedHere = false;

#if USE_OLD_MPI
namespace Parallel {
namespace MPIOps {
void min(const void *in, void *inout, int size,
         const MPI::Datatype & /*type*/) {
  const unsigned long long int *rin =
      static_cast<const unsigned long long int *>(in);
  unsigned long long int *rinout = static_cast<unsigned long long int *>(inout);

  for (int i = 0; i < size; i++) {
    rinout[i] = std::min(rin[i], rinout[i]);
  }
}

void max(const void *in, void *inout, int size,
         const MPI::Datatype & /*type*/) {
  const unsigned long long int *rin =
      static_cast<const unsigned long long int *>(in);
  unsigned long long int *rinout = static_cast<unsigned long long int *>(inout);

  for (int i = 0; i < size; i++) {
    rinout[i] = std::max(rin[i], rinout[i]);
  }
}

MPI::Op minULInt;
MPI::Op maxULInt;

void init() {
  Parallel::MPIOps::minULInt.Init(&Parallel::MPIOps::min, true);
  Parallel::MPIOps::maxULInt.Init(&Parallel::MPIOps::max, true);
}

void free() {
  Parallel::MPIOps::minULInt.Free();
  Parallel::MPIOps::maxULInt.Free();
}
}  // namespace MPIOps
}  // namespace Parallel
#endif  //#if USE_OLD_MPI

Parallel::MPICommunicator::MPICommunicator() {
  this->request = 0;

  this->process = -1;
  this->rootProcess = -1;
  this->size = -1;

  // this->totalThreadCount = 0;

  // this->shParallel = false;

  this->typemap[CHAR] = MPI::Char;
  this->typemap[SCHAR] = MPI::SChar;
  this->typemap[UCHAR] = MPI::UChar;

  this->typemap[BOOL] = MPI::Boolean;

  this->typemap[BYTE] = MPI::Byte;

  this->typemap[SHORT] = MPI::Short;
  this->typemap[USHORT] = MPI::UShort;

  this->typemap[INT] = MPI::Int;
  this->typemap[UINT] = MPI::UInt;
  this->typemap[LINT] = MPI::LInt;
  this->typemap[ULINT] = MPI::ULInt;

  this->typemap[REAL] = MPI::Real;
  this->typemap[LREAL] = MPI::LReal;

  this->typemap[PACKED] = MPI::Packed;

#if (!USE_OLD_MPI)
  this->typemap[COMPLEX] = MPI::Complex;
  this->typemap[DCOMPLEX] = MPI::DComplex;
  this->typemap[LDCOMPLEX] = MPI::LDComplex;
#endif  //#if (!USE_OLD_MPI)

  this->opmap[MAXIMUM] = MPI::MAX;
  this->opmap[MINIMUM] = MPI::MIN;

  this->opmap[SUM] = MPI::SUM;
  this->opmap[PRODUCT] = MPI::PROD;

  this->opmap[LOGICAL_AND] = MPI::LAND;
  this->opmap[LOGICAL_OR] = MPI::LOR;
  this->opmap[LOGICAL_XOR] = MPI::LXOR;

  this->opmap[BITWISE_AND] = MPI::BAND;
  this->opmap[BITWISE_OR] = MPI::BOR;
  this->opmap[BITWISE_XOR] = MPI::BXOR;

  this->opmap[MAXIMUM_LOCATION] = MPI::MAXLOC;
  this->opmap[MINIMUM_LOCATION] = MPI::MINLOC;

  this->setCommunicator(&MPI::COMM_WORLD);

  this->count++;
}

Parallel::MPICommunicator::~MPICommunicator() {
  // this->typemap.clear();
  // this->opmap.clear();

  this->count--;
}

/*void Parallel::MPICommunicator::setShParallel(bool shParallel)
{
        this->shParallel = shParallel;
}

bool Parallel::MPICommunicator::isShParallel() const
{
        return this->shParallel;
}*/

void Parallel::MPICommunicator::setCommunicator(MPI::Comm *communicator) {
  this->communicator = communicator;
}

MPI::Comm *Parallel::MPICommunicator::getCommunicator() const {
  return this->communicator;
}

Int Parallel::MPICommunicator::root() const {
  if (this->rootProcess == -1) {
    this->rootProcess = 0;
  }

  return this->rootProcess;
}

Int Parallel::MPICommunicator::rank() const {
  if (this->process == -1) {
    this->process = this->communicator->Get_rank();
  }

  return this->process;
}

Data::IntVector Parallel::MPICommunicator::ranks(Int process) const {
  return Data::IntVector(1, (process < 0) ? this->rank() : process);

  /*Int rank = (process < 0) ? this->rank() : process;

  size = this->threadCount[rank];

  Data::IntVector ranks(size);

  Int minRank = 0;

  for (Int i = 0; i < rank; i++)
  {
          minRank += this->threadCount[i];
  }

  for (Int i = 0; i < this->threadCount[rank]; i++)
  {
          ranks[i] = minRank + i;
  }

  return ranks;*/
}

/*UInt Parallel::MPICommunicator::numThreads(Int processor) const
{
        if (processor < 0)
        {
                if (!this->threadCount.empty())
                {
                        return this->threadCount[this->rank()];
                }

#if USE_OPENMP
                return this->isShParallel() ? omp_get_max_threads() : 1;
#else
                return 1;
#endif //#if USE_OPENMP
        }

        if (!this->threadCount.empty())
        {
                return this->threadCount[processor];
        }

        return 0;
}*/

Int Parallel::MPICommunicator::numProcesses() const {
  if (this->size == -1) {
    this->size = this->communicator->Get_size();
  }

  return this->size;
}

std::string Parallel::MPICommunicator::processorName() const {
  char *name = NULL;
  Int len;

  MPI::Get_processor_name(name, len);

  std::string s(name, len);

  delete[] name;

  return s;
}

bool Parallel::MPICommunicator::isMaster() const { return false; }

bool Parallel::MPICommunicator::isSlave() const { return !this->isMaster(); }

bool Parallel::MPICommunicator::isParallel() const {
  if (!this->isInitialized()) {
    return false;
  }

  if (this->isFinalized()) {
    return false;
  }

  if (this->numProcesses() == 1) {
    return false;
  }

  return true;
}

bool Parallel::MPICommunicator::isSerial() const { return !this->isParallel(); }

/*Int Parallel::MPICommunicator::numWorkers() const
{
        if (this->totalThreadCount != 0)
        {
                return this->totalThreadCount;
        }

        return this->numProcesses();
}*/

void Parallel::MPICommunicator::init() const {
  if (this->isParallel()) {
    return;
  }

  if (this->count == 1) {
    if (!this->isInitialized()) {
      this->initializedHere = true;

      MPI::Init();
    }

#if USE_OLD_MPI
    Parallel::MPIOps::init();
#endif  //#if USE_OLD_MPI
  }
}

void Parallel::MPICommunicator::init(Int &argc, char **&argv) const {
  if (this->isParallel()) {
    return;
  }

  if (this->count == 1) {
    if (!this->isInitialized()) {
      this->initializedHere = true;

      MPI::Init(argc, argv);
    }

#if USE_OLD_MPI
    Parallel::MPIOps::init();
#endif  //#if USE_OLD_MPI
  }
}

/*void Parallel::MPICommunicator::initThreadCount()
{
        Int numProcesses = this->numProcesses();

#if USE_OPENMP
        Int numThreads = this->isShParallel() ? omp_get_max_threads() : 1;
#else
        Int numThreads = 1;
#endif //#if USE_OPENMP

        this->totalThreadCount = 0;

        if (numProcesses == 1)
        {
                this->totalThreadCount = numThreads;
        }
        else
        {
                this->threadCount.clear();

                this->threadCount.resize(numProcesses);

                Int *threadCount = this->allGather(numThreads);

                for (Int i = 0; i < numProcesses; i++)
                {
                        this->threadCount[i] = threadCount[i];
                        this->totalThreadCount += this->threadCount[i];
                }

                delete [] threadCount;
        }
}*/

void Parallel::MPICommunicator::finalize() const {
  if (!this->isInitialized()) {
    return;
  }

  if (this->isFinalized()) {
    return;
  }

  if (this->count == 1) {
#if USE_OLD_MPI
    Parallel::MPIOps::free();
#endif  //#if USE_OLD_MPI

    if (this->initializedHere) {
      MPI::Finalize();
    }
  }

  this->deleteRequest();
}

void Parallel::MPICommunicator::abort(Int error) const {
  if (!this->isParallel()) {
    return;
  }

  this->communicator->Abort(error);
}

bool Parallel::MPICommunicator::isInitialized() const {
  return MPI::Is_initialized();
}

bool Parallel::MPICommunicator::isFinalized() const {
  return MPI::Is_finalized();
}

void Parallel::MPICommunicator::barrier() const {
  this->communicator->Barrier();
}

Int Parallel::MPICommunicator::packSize(UInt num, enum Type type) const {
  return this->packSize(num, this->typemap[type]);
}

Int Parallel::MPICommunicator::packSize(UInt num, MPI::Datatype &type) const {
  return type.Pack_size(num, *this->communicator);
}

void Parallel::MPICommunicator::pack(const void *val, Int size, void *buffer,
                                     Int bufferSize, Int &position,
                                     enum Type type) const {
  this->pack(val, size, buffer, bufferSize, position, this->typemap[type]);
}

void Parallel::MPICommunicator::pack(const void *val, Int size, void *buffer,
                                     Int bufferSize, Int &position,
                                     MPI::Datatype &type) const {
  type.Pack(val, size, buffer, bufferSize, position, *this->communicator);
}

void Parallel::MPICommunicator::unpack(void *val, Int size, const void *buffer,
                                       Int bufferSize, Int &position,
                                       enum Type type) const {
  this->unpack(val, size, buffer, bufferSize, position, this->typemap[type]);
}

void Parallel::MPICommunicator::unpack(void *val, Int size, const void *buffer,
                                       Int bufferSize, Int &position,
                                       MPI::Datatype &type) const {
  type.Unpack(buffer, bufferSize, val, size, position, *this->communicator);
}

void Parallel::MPICommunicator::removeRequest(UInt id,
                                              bool postponeDeletion) const {
  RequestMap::iterator it = this->requests.find(id);

  if (it == this->requests.end()) {
    return;
  }

  Request r = (*it).second;

  if (postponeDeletion) {
    this->oldRequests[(*it).first] = (*it).second;
  }

  this->requests.erase(it);

#if USE_C__11
  MPI::Request request = std::get<0>(r);
#else
  MPI::Request request = r.request;
#endif  //#if USE_C__11

  request.Free();

  /*do
  {
          request.Wait(this->status);
  }
  while (!this->status.Is_cancelled());

  Package p = std::make_pair(std::get<1>(r), (char *)std::get<2>(r));

  Transferable::free(p);*/
}

void Parallel::MPICommunicator::deleteRequest(UInt id) const {
  if (id == 0) {
    while (!this->oldRequests.empty()) {
      Request r = (*this->oldRequests.begin()).second;

      this->oldRequests.erase(this->oldRequests.begin());

#if USE_C__11
      if (std::get<1>(r) > 0)
#else
      if (r.size > 0)
#endif  //#if USE_C__11
      {
#if USE_C__11
        char *buf = static_cast<char *>(std::get<2>(r));
#else
        char *buf = static_cast<char *>(r.buffer);
#endif  //#if USE_C__11

        delete[] buf;
      }
    }

    return;
  }

  Request r;

  // search first for requests removed from the main list...
  RequestMap::iterator it = this->oldRequests.find(id);

  if (it == this->oldRequests.end()) {
    //...if not found, search for active requests
    RequestMap::iterator it = this->requests.find(id);

    if (it == this->requests.end()) {
      return;
    }

    r = (*it).second;

    this->requests.erase(it);
  } else {
    r = (*it).second;

    this->oldRequests.erase(it);
  }

#if USE_C__11
  char *buf = static_cast<char *>(std::get<2>(r));
#else
  char *buf = static_cast<char *>(r.buffer);
#endif  //#if USE_C__11

  delete[] buf;
}

Transferable *Parallel::MPICommunicator::testRequest(UInt id) const {
  RequestMap::iterator it = this->requests.find(id);

  if (it == this->requests.end()) {
    return NULL;
  }

  Request r = (*it).second;

#if USE_C__11
  MPI::Request request = std::get<0>(r);
#else
  MPI::Request request = r.request;
#endif  //#if USE_C__11

  if (request.Test()) {
#if USE_C__11
    Package p =
        std::make_pair(std::get<1>(r), static_cast<char *>(std::get<2>(r)));
#else
    Package p = std::make_pair(r.size, static_cast<char *>(r.buffer));
#endif  //#if USE_C__11

    return this->unpack(p, true);
  }

  return NULL;
}

Transferable *Parallel::MPICommunicator::waitRequest(UInt id) const {
  RequestMap::iterator it = this->requests.find(id);

  if (it == this->requests.end()) {
    return NULL;
  }

  Request r = (*it).second;

  this->requests.erase(it);

#if USE_C__11
  MPI::Request request = std::get<0>(r);
#else
  MPI::Request request = r.request;
#endif  //#if USE_C__11

  request.Wait();

#if USE_C__11
  Package p =
      std::make_pair(std::get<1>(r), static_cast<char *>(std::get<2>(r)));
#else
  Package p = std::make_pair(r.size, static_cast<char *>(r.buffer));
#endif  //#if USE_C__11

  return this->unpack(p, true);
}

void Parallel::MPICommunicator::broadcast(void *val, Int size, enum Type type,
                                          Int root) const {
  this->broadcast(val, size, this->typemap[type], root);
}

void Parallel::MPICommunicator::broadcast(void *val, Int size,
                                          MPI::Datatype &type, Int root) const {
  this->communicator->Bcast(val, size, type, root);
}

void Parallel::MPICommunicator::scatter(const void *sendBuffer, Int sendCount,
                                        void *receiveBuffer, Int receiveCount,
                                        enum Type type, Int root) const {
  this->scatter(sendBuffer, sendCount, receiveBuffer, receiveCount,
                this->typemap[type], root);
}

void Parallel::MPICommunicator::scatter(const void *sendBuffer, Int sendCount,
                                        void *receiveBuffer, Int receiveCount,
                                        MPI::Datatype &type, Int root) const {
  this->communicator->Scatter(sendBuffer, sendCount, type, receiveBuffer,
                              receiveCount, type, root);
}

void Parallel::MPICommunicator::scatterv(const void *sendBuffer,
                                         const Int sendCounts[],
                                         const Int displacements[],
                                         void *receiveBuffer, Int receiveCount,
                                         enum Type type, Int root) const {
  this->scatterv(sendBuffer, sendCounts, displacements, receiveBuffer,
                 receiveCount, this->typemap[type], root);
}

void Parallel::MPICommunicator::scatterv(const void *sendBuffer,
                                         const Int sendCounts[],
                                         const Int displacements[],
                                         void *receiveBuffer, Int receiveCount,
                                         MPI::Datatype &type, Int root) const {
  this->communicator->Scatterv(sendBuffer, sendCounts, displacements, type,
                               receiveBuffer, receiveCount, type, root);
}

void Parallel::MPICommunicator::gather(const void *sendBuffer, Int sendCount,
                                       void *receiveBuffer, Int receiveCount,
                                       enum Type type, Int root) const {
  this->gather(sendBuffer, sendCount, receiveBuffer, receiveCount,
               this->typemap[type], root);
}

void Parallel::MPICommunicator::gather(const void *sendBuffer, Int sendCount,
                                       void *receiveBuffer, Int receiveCount,
                                       MPI::Datatype &type, Int root) const {
  this->communicator->Gather(sendBuffer, sendCount, type, receiveBuffer,
                             receiveCount, type, root);
}

void Parallel::MPICommunicator::gatherv(const void *sendBuffer, Int sendCount,
                                        void *receiveBuffer,
                                        const Int receiveCounts[],
                                        const Int displacements[],
                                        enum Type type, Int root) const {
  this->gatherv(sendBuffer, sendCount, receiveBuffer, receiveCounts,
                displacements, this->typemap[type], root);
}

void Parallel::MPICommunicator::gatherv(const void *sendBuffer, Int sendCount,
                                        void *receiveBuffer,
                                        const Int receiveCounts[],
                                        const Int displacements[],
                                        MPI::Datatype &type, Int root) const {
  this->communicator->Gatherv(sendBuffer, sendCount, type, receiveBuffer,
                              receiveCounts, displacements, type, root);
}

void Parallel::MPICommunicator::allGather(const void *sendBuffer,
                                          void *receiveBuffer, Int count,
                                          enum Type type) const {
  this->allGather(sendBuffer, receiveBuffer, count, this->typemap[type]);
}

void Parallel::MPICommunicator::allGather(const void *sendBuffer,
                                          void *receiveBuffer, Int count,
                                          MPI::Datatype &type) const {
  this->communicator->Allgather(sendBuffer, count, type, receiveBuffer, count,
                                type);
}

void Parallel::MPICommunicator::allGatherv(const void *sendBuffer,
                                           Int sendCount, void *receiveBuffer,
                                           const Int receiveCounts[],
                                           const Int displacements[],
                                           enum Type type) const {
  this->allGatherv(sendBuffer, sendCount, receiveBuffer, receiveCounts,
                   displacements, this->typemap[type]);
}

void Parallel::MPICommunicator::allGatherv(const void *sendBuffer,
                                           Int sendCount, void *receiveBuffer,
                                           const Int receiveCounts[],
                                           const Int displacements[],
                                           MPI::Datatype &type) const {
  this->communicator->Allgatherv(sendBuffer, sendCount, type, receiveBuffer,
                                 receiveCounts, displacements, type);
}

void Parallel::MPICommunicator::allToAll(const void *sendBuffer,
                                         void *receiveBuffer, Int count,
                                         enum Type type) const {
  this->allToAll(sendBuffer, receiveBuffer, count, this->typemap[type]);
}

void Parallel::MPICommunicator::allToAll(const void *sendBuffer,
                                         void *receiveBuffer, Int count,
                                         MPI::Datatype &type) const {
  this->communicator->Alltoall(sendBuffer, count, type, receiveBuffer, count,
                               type);
}

void Parallel::MPICommunicator::allToAllv(const void *sendBuffer,
                                          const Int sendCounts[],
                                          const Int sendDisplacements[],
                                          void *receiveBuffer,
                                          const Int receiveCounts[],
                                          const Int receiveDisplacements[],
                                          enum Type type) const {
  this->allToAllv(sendBuffer, sendCounts, sendDisplacements, receiveBuffer,
                  receiveCounts, receiveDisplacements, this->typemap[type]);
}

void Parallel::MPICommunicator::allToAllv(const void *sendBuffer,
                                          const Int sendCounts[],
                                          const Int sendDisplacements[],
                                          void *receiveBuffer,
                                          const Int receiveCounts[],
                                          const Int receiveDisplacements[],
                                          MPI::Datatype &type) const {
  this->communicator->Alltoallv(sendBuffer, sendCounts, sendDisplacements, type,
                                receiveBuffer, receiveCounts,
                                receiveDisplacements, type);
}

void Parallel::MPICommunicator::send(const void *buffer, Int size,
                                     enum Type type, Int process,
                                     Int tag) const {
  this->send(buffer, size, this->typemap[type], process, tag);
}

void Parallel::MPICommunicator::send(const void *buffer, Int size,
                                     MPI::Datatype &type, Int process,
                                     Int tag) const {
  this->communicator->Send(buffer, size, type, process, tag);
}

void Parallel::MPICommunicator::ssend(const void *buffer, Int size,
                                      enum Type type, Int process,
                                      Int tag) const {
  this->ssend(buffer, size, this->typemap[type], process, tag);
}

void Parallel::MPICommunicator::ssend(const void *buffer, Int size,
                                      MPI::Datatype &type, Int process,
                                      Int tag) const {
  this->communicator->Ssend(buffer, size, type, process, tag);
}

void Parallel::MPICommunicator::bsend(const void *buffer, Int size,
                                      enum Type type, Int process,
                                      Int tag) const {
  this->bsend(buffer, size, this->typemap[type], process, tag);
}

void Parallel::MPICommunicator::bsend(const void *buffer, Int size,
                                      MPI::Datatype &type, Int process,
                                      Int tag) const {
  this->communicator->Bsend(buffer, size, type, process, tag);
}

void Parallel::MPICommunicator::rsend(const void *buffer, Int size,
                                      enum Type type, Int process,
                                      Int tag) const {
  this->rsend(buffer, size, this->typemap[type], process, tag);
}

void Parallel::MPICommunicator::rsend(const void *buffer, Int size,
                                      MPI::Datatype &type, Int process,
                                      Int tag) const {
  this->communicator->Rsend(buffer, size, type, process, tag);
}

UInt Parallel::MPICommunicator::isend(const void *buffer, Int size,
                                      enum Type type, Int process,
                                      Int tag) const {
  MPI::Request r = this->isend(buffer, size, this->typemap[type], process, tag);

#if USE_C__11
  this->requests[++this->request] =
      std::make_tuple(r, size, const_cast<void *>(buffer));
#else
  Request req;

  req.request = r;
  req.size = size;
  req.buffer = const_cast<void *>(buffer);

  this->requests[++this->request] = req;
#endif  //#if USE_C__11

  return this->request;
}

MPI::Request Parallel::MPICommunicator::isend(const void *buffer, Int size,
                                              MPI::Datatype &type, Int process,
                                              Int tag) const {
  return this->communicator->Isend(buffer, size, type, process, tag);
}

UInt Parallel::MPICommunicator::issend(const void *buffer, Int size,
                                       enum Type type, Int process,
                                       Int tag) const {
  MPI::Request r =
      this->issend(buffer, size, this->typemap[type], process, tag);

#if USE_C__11
  this->requests[++this->request] =
      std::make_tuple(r, size, const_cast<void *>(buffer));
#else
  Request req;

  req.request = r;
  req.size = size;
  req.buffer = const_cast<void *>(buffer);

  this->requests[++this->request] = req;
#endif  //#if USE_C__11

  return this->request;
}

MPI::Request Parallel::MPICommunicator::issend(const void *buffer, Int size,
                                               MPI::Datatype &type, Int process,
                                               Int tag) const {
  return this->communicator->Issend(buffer, size, type, process, tag);
}

UInt Parallel::MPICommunicator::ibsend(const void *buffer, Int size,
                                       enum Type type, Int process,
                                       Int tag) const {
  MPI::Request r =
      this->ibsend(buffer, size, this->typemap[type], process, tag);

#if USE_C__11
  this->requests[++this->request] =
      std::make_tuple(r, size, const_cast<void *>(buffer));
#else
  Request req;

  req.request = r;
  req.size = size;
  req.buffer = const_cast<void *>(buffer);

  this->requests[++this->request] = req;
#endif  //#if USE_C__11

  return this->request;
}

MPI::Request Parallel::MPICommunicator::ibsend(const void *buffer, Int size,
                                               MPI::Datatype &type, Int process,
                                               Int tag) const {
  return this->communicator->Ibsend(buffer, size, type, process, tag);
}

UInt Parallel::MPICommunicator::irsend(const void *buffer, Int size,
                                       enum Type type, Int process,
                                       Int tag) const {
  MPI::Request r =
      this->irsend(buffer, size, this->typemap[type], process, tag);

#if USE_C__11
  this->requests[++this->request] =
      std::make_tuple(r, size, const_cast<void *>(buffer));
#else
  Request req;

  req.request = r;
  req.size = size;
  req.buffer = const_cast<void *>(buffer);

  this->requests[++this->request] = req;
#endif  //#if USE_C__11

  return this->request;
}

MPI::Request Parallel::MPICommunicator::irsend(const void *buffer, Int size,
                                               MPI::Datatype &type, Int process,
                                               Int tag) const {
  return this->communicator->Irsend(buffer, size, type, process, tag);
}

void Parallel::MPICommunicator::receive(void *buffer, Int size, enum Type type,
                                        Int process, Int tag) const {
  this->receive(buffer, size, this->typemap[type],
                (process < 0) ? MPI::ANY_SOURCE : process,
                (tag < 0) ? MPI::ANY_TAG : tag);
}

void Parallel::MPICommunicator::receive(void *buffer, Int size,
                                        MPI::Datatype &type, Int process,
                                        Int tag) const {
  this->communicator->Recv(buffer, size, type, process, tag);
}

UInt Parallel::MPICommunicator::ireceive(void *buffer, Int size, enum Type type,
                                         Int process, Int tag) const {
  MPI::Request r = this->ireceive(buffer, size, this->typemap[type],
                                  (process < 0) ? MPI::ANY_SOURCE : process,
                                  (tag < 0) ? MPI::ANY_TAG : tag);

#if USE_C__11
  this->requests[++this->request] =
      std::make_tuple(r, size, static_cast<char *>(buffer));
#else
  Request req;

  req.request = r;
  req.size = size;
  req.buffer = const_cast<void *>(buffer);

  this->requests[++this->request] = req;
#endif  //#if USE_C__11

  return this->request;
}

MPI::Request Parallel::MPICommunicator::ireceive(void *buffer, Int size,
                                                 MPI::Datatype &type,
                                                 Int process, Int tag) const {
  return this->communicator->Irecv(buffer, size, type, process, tag);
}

void Parallel::MPICommunicator::reduce(const void *sendBuffer,
                                       void *receiveBuffer, Int size,
                                       enum Type type, enum Operation operation,
                                       Int root) const {
#if USE_OLD_MPI
  if ((type == ULINT) && (operation == MAXIMUM)) {
    this->reduce(sendBuffer, receiveBuffer, size, this->typemap[type],
                 Parallel::MPIOps::maxULInt, root);
  } else if ((type == ULINT) && (operation == MINIMUM)) {
    this->reduce(sendBuffer, receiveBuffer, size, this->typemap[type],
                 Parallel::MPIOps::minULInt, root);
  } else
#endif  //#if USE_OLD_MPI
  {
    this->reduce(sendBuffer, receiveBuffer, size, this->typemap[type],
                 this->opmap[operation], root);
  }
}

void Parallel::MPICommunicator::reduce(const void *sendBuffer,
                                       void *receiveBuffer, Int size,
                                       MPI::Datatype &type, MPI::Op &operation,
                                       Int root) const {
  this->communicator->Reduce(sendBuffer, receiveBuffer, size, type, operation,
                             root);
}

void Parallel::MPICommunicator::allReduce(const void *sendBuffer,
                                          void *receiveBuffer, Int size,
                                          enum Type type,
                                          enum Operation operation) const {
  this->allReduce(sendBuffer, receiveBuffer, size, this->typemap[type],
                  this->opmap[operation]);
}

void Parallel::MPICommunicator::allReduce(const void *sendBuffer,
                                          void *receiveBuffer, Int size,
                                          MPI::Datatype &type,
                                          MPI::Op &operation) const {
  this->communicator->Allreduce(sendBuffer, receiveBuffer, size, type,
                                operation);
}

void Parallel::MPICommunicator::reduceScatter(const void *sendBuffer,
                                              void *receiveBuffer,
                                              Int receiveCounts[],
                                              enum Type type,
                                              enum Operation operation) const {
  this->reduceScatter(sendBuffer, receiveBuffer, receiveCounts,
                      this->typemap[type], this->opmap[operation]);
}

void Parallel::MPICommunicator::reduceScatter(const void *sendBuffer,
                                              void *receiveBuffer,
                                              Int receiveCounts[],
                                              MPI::Datatype &type,
                                              MPI::Op &operation) const {
  this->communicator->Reduce_scatter(sendBuffer, receiveBuffer, receiveCounts,
                                     type, operation);
}

#endif  //#if USE_MPI
