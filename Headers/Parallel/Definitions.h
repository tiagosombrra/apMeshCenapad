#ifndef _PARALLEL_DEFINITIONS_H_
#define _PARALLEL_DEFINITIONS_H_

#include "../Crabmesh/Performer/Definitions.h"

namespace Parallel {
using Data::Int;
using Data::LInt;
using Data::LReal;
using Data::Real;
using Data::Short;
using Data::UInt;
using Data::ULInt;
using Data::UShort;

// Parallel::Data
class Communicator;
class NoCommunicator;

class Transferable;
// Messages must have type 0
class Message;

class ThreadManager;
class NoThreadManager;
class Lock;

#if USE_MPI
class MPICommunicator;
class MPIMessage;
#endif  //#if USE_MPI

#if USE_OPENMP
class OMPThreadManager;
class OMPLock;
#endif  //#if USE_OPENMP

/// ThreadManager and Communicator
class TMCommunicator;

class Partition;

// Parallel::Performer
class Builder;

class Task;

class Partitioner;

class LoadBalancer;
class StaticLoadBalancer;
class DynamicLoadBalancer;
class SyncDynamicLoadBalancer;
class AsyncDynamicLoadBalancer;

class GreedySerialStaticLoadBalancer;
class WeightedGreedySerialStaticLoadBalancer;
class SpringSerialStaticLoadBalancer;
class DemandParallelDynamicLoadBalancer;

class MainDrive;

enum AvailableLoadBalancers {
  UNDEFINED = 0,
  GREEDY_SERIAL_STATIC,
  WEIGHTED_GREEDY_SERIAL_STATIC,
  SPRING_SERIAL_STATIC,
  DEMAND_PARALLEL_DYNAMIC
};

// package size and package contents
typedef std::pair<Int, char *> Package;

typedef std::list<Partition *> PartitionList;
typedef std::list<Task *> TaskList;

typedef std::vector<Partition *> PartitionVector;
typedef std::vector<Task *> TaskVector;

#if USE_C__11
typedef std::unordered_map<Int, TaskVector> TaskVectorHashMap;
#endif  //#if USE_C__11

typedef std::map<Int, TaskVector> TaskVectorMap;
}  // namespace Parallel

#endif  //#ifndef _PARALLEL_DEFINITIONS_H_
