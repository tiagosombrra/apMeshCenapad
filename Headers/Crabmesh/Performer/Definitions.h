#ifndef _PERFORMER_DEFINITIONS_H_
#define _PERFORMER_DEFINITIONS_H_

#include "../../Data/Definitions.h"

namespace Performer {
using Data::Int;
using Data::LInt;
using Data::LReal;
using Data::Real;
using Data::Short;
using Data::UInt;
using Data::ULInt;
using Data::UShort;

// base class for Performer classes
class Builder;

// class that represents the current status of the program
class Status;
// classes to manage the ids
class IdManager;
class SequentialIdManager;
class RangedIdManager;

// classes for Performer::App library
// class that represents manages a bunch of builders
class MainDrive;

// classes for Performer::Graph library
class GraphBuilder;

// classes for Performer::Graph::Tree library
class TreeGenerator;
class TreeRefiner;
class MinTreeRefiner;
class NeighborTreeRefiner;

// classes for Performer::Geometry library
class Clipper;

// classes for Performer::ComputationalGeometry library
class PointInOnbjectDecider;
class AnglePointInObjectDecider;
class TreeCellClassifier;
class AngleTreeCellClassifier;

// classes for Performer::Mesh library
class BoundaryBuilder;
class BoundaryAdapter;
class UniformBoundaryAdapter;
class SizeBoundaryAdapter;
class EdgeBoundaryAdapter;
class EdgeSwapBoundaryAdapter;
class EdgeCollapseBoundaryAdapter;
class BoundaryNormalInverter;
class BoundaryNormalFixer;
class BoundaryCreator;
class BoundaryWaterTightnessChecker;
class AdjacenciesIdentifier;
class CracksIdentifier;
class CrackRemover;
class MissingAdjacencyRemover;
class MeshMerger;
class MeshSplitter;
class MeshTransformer;
class MeshInterceptionChecker;
class MeshTopologyChecker;
class MeshGenerator;
class TemplateMeshGenerator;
class FrontAdvancer;
class MeshRefiner;
class MeshImprover;
class MeshOptimizer;
class MeshBackTracker;
class MeshSmoother;
class LaplacianSmoother;
class VertexMerger;
class InnerSurfacesIdentifier;

#if USE_NUMERICAL
class CovarianceMatrixFinder;
class PrincipalComponentsAnalyzer;
class PrincipalComponentsBasisFinder;
class HotellingTransformer;
#endif  //#if USE_NUMERICAL

struct Crack {
  Data::FrontElement *fel1;
  Data::FrontElement *fel2;
  void *data;
};

// Elements are treated as FrontElements. Class Data::Element is being used
//   because it is Data::FrontElement's superclass, and, therefore, surface
//   meshes can be used here as well.
struct ECrack {
  Data::Element *fel1;
  Data::Element *fel2;
  void *data;
};

typedef std::list<MeshOptimizer *> MeshOptimizerList;

typedef std::vector<IdManager *> IdManagerVector;

#if USE_C__11
typedef std::unordered_map<Data::Vertex *, Data::FrontElement *> VFEHashMap;
typedef std::unordered_map<Data::FrontElement *, Data::Vertex *> FEVHashMap;

typedef std::unordered_map<Data::FrontElement *, VFEHashMap> FEVFEMapHashMap;

typedef std::unordered_map<Data::FrontElement *, Crack> FECrackHashMap;
typedef std::unordered_map<Data::FrontElement *, Data::FrontElementHash>
    FEFEHashHashMap;

typedef std::unordered_map<Data::Vertex *, Data::Element *> VEHashMap;
typedef std::unordered_map<Data::Element *, Data::Vertex *> EVHashMap;

typedef std::unordered_map<Data::Element *, VEHashMap> EVEMapHashMap;

typedef std::unordered_map<Data::Element *, ECrack> ECrackHashMap;
typedef std::unordered_map<Data::Element *, Data::ElementHash> EEHashHashMap;
#endif  //#if USE_C__11

typedef std::map<Data::Vertex *, Data::FrontElement *> VFEMap;
typedef std::map<Data::FrontElement *, Data::Vertex *> FEVMap;

typedef std::map<Data::FrontElement *, VFEMap> FEVFEMapMap;

typedef std::map<Data::FrontElement *, Crack> FECrackMap;
typedef std::map<Data::FrontElement *, Data::FrontElementSet> FEFESetMap;

typedef std::map<Data::Vertex *, Data::Element *> VEMap;
typedef std::map<Data::Element *, Data::Vertex *> EVMap;

typedef std::map<Data::Element *, VEMap> EVEMapMap;

typedef std::map<Data::Element *, ECrack> ECrackMap;
typedef std::map<Data::Element *, Data::ElementSet> EESetMap;
}  // namespace Performer

#endif  //#ifndef _PERFORMER_DEFINITIONS_H_
