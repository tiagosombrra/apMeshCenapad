#ifndef _QUADTREE_CELL_H_
#define _QUADTREE_CELL_H_

#include "../../Data/Definitions.h"
#include "../../Data/Edge.h"
#include "../../Data/Face.h"
#include "../../Data/Vertex.h"
#include "Boundary.h"
#include "Quadtree.h"
#include "Shape.h"

using namespace Par2DJMesh;
using namespace Par2DJMesh::AFT;
using namespace Par2DJMesh::Basics;

extern double TOLERANCIA_AFT;

namespace Par2DJMesh {
namespace AFT {
class QuadtreeCell : public Shape {
 private:
  unsigned long int level;
  double size;
  bool highlighted;
  bool highlightedAsNeighbor;

  // para a geracao baseada em templates
  Vertex *v[8];
  Edge *e[8];

  Vertex *min;
  Vertex *max;
  Vertex **mids;

  QuadtreeCell *children[4];
  QuadtreeCell *parent;

  Quadtree *tree;

  QuadtreeCellList neighbors[4];

  EdgeList edges;

 private:
  Vertex **makeMids();

  void subdivide(bool setChildrenEdges = true);

  void setChildrenNeighbors();

  void setChildrenEdges();

  // para a geracao baseada em templates
  Edge *makeE(int i);
  Edge *makeE(int i, int j);
  Edge *makeE(Vertex *v1, Vertex *v2);

  void makeMeshType1();
  void makeMeshType2(int c);
  void makeMeshType3(int c);
  void makeMeshType4(int c);
  void makeMeshType5(int c);
  void makeMeshType6();

 public:
  QuadtreeCell(long int id,
               // MainDrive *mainDrive,
               Quadtree *tree = NULL, Vertex *min = NULL, Vertex *max = NULL,
               QuadtreeCell *parent = NULL, long int level = 0);
  ~QuadtreeCell();

  void setQuadtree(Quadtree *tree);

  void setLevel(long int level);
  long int getLevel();

  double getSize();

  void setParent(QuadtreeCell *parent);
  QuadtreeCell *getParent();

  void setChild(int position, QuadtreeCell *child);
  QuadtreeCell *getChild(int position);

  void setBox(Vertex *min, Vertex *max);
  Vertex *getMin();
  Vertex *getMax();

  void setNeighbors(int direction, QuadtreeCellList neighbors);
  QuadtreeCellList getNeighbors(int direction);

  // retorna o numero de celulas da subarvore que tem this como raiz
  int getNumCells();

  // retorna os vertices das arestas internas à essa celula
  VertexList getVertices();
  EdgeList getEdges();

  bool shouldSubdivide(Edge *e);
  bool shouldSubdivide(Face *f);

  void addEdge(Edge *e);
  void removeEdge(Edge *e);
  void clearEdges();
  QuadtreeCell *findCell(Edge *e);
  QuadtreeCell *findCell(Face *f);

  bool in(Vertex *v);
  bool on(Vertex *v);
  bool out(Vertex *v);

  double height();
  double surface();

  bool subdivide(Edge *e);
  bool subdivide(Face *f);
  void subdivideToLevel(unsigned long int level);
  bool subdivideAccordingToNeighbors();

  bool subdivided();

  // para a geracao baseada em templates
  void sortNeighbors();
  bool inBoundary();

  void makeOuterVertices();
  void makeOuterEdges();
  void makeTemplateBasedMesh();

  string getText();

  //#if USE_OPENGL
  //    void highlight();
  //    void highlight(bool highlightEdges, /*debug*/bool dontHighlightNeighbors
  //    = false/*endebug*/); void highlightAsNeighbor(); void unhighlight();
  //    void unhighlight(bool highlightEdges, /*debug*/bool
  //    dontHighlightNeighbors = false/*endebug*/); void
  //    unhighlightAsNeighbor();

  //    void draw();
  //#endif //#if USE_OPENGL
};
}  // namespace AFT
}  // namespace Par2DJMesh

#endif  //#ifndef _QUADTREE_CELL_H_
