#ifndef _VERTEX_H_
#define _VERTEX_H_

#include "../Crabmesh/Aft/Shape.h"
#include "../Data/Definitions.h"
#include "Edge.h"

using namespace Par2DJMesh;
using namespace Par2DJMesh::Basics;

namespace Par2DJMesh {
namespace Basics {
class Vertex : public Shape {
 private:
  double x;
  double y;

  EdgeSet adjacentEdges;

  //#if USE_OPENGL
  //    double size;
  //#endif //#if USE_OPENGL

  //#if DEBUG_MODE
  // public:
  //    double h;
  //#endif //#if DEBUG_MODE

 public:
  Vertex(double x = 0.0, double y = 0.0, long int id = 0);
  ~Vertex();

  void setX(double x);
  void setY(double y);
  void setPosition(double x, double y);
  double getX();
  double getY();
  void getPosition(double *x, double *y);

  //#if USE_OPENGL
  //    void setSize(double size);
  //#endif //#if USE_OPENGL

  void addAdjacentEdge(Edge *e);
  void removeAdjacentEdge(Edge *e);
  EdgeSet getAdjacentEdges();

  void sum(Vertex *v);
  void scalarMultiplication(double d);

  double dot(Vertex *v);
  double cross(Vertex *v);

  double norm();

  double distance(Vertex *v);

  double angle(Vertex *v);
  double pseudoAngle();
  double pseudoAngle(Vertex *v);
  double squarePseudoAngle();

  double orientedAngle();
  double orientedAngle(Vertex *v);

  bool left(Vertex *v);
  bool right(Vertex *v);

  double surface(Vertex *v1, Vertex *v2);
  double orientedSurface(Vertex *v1, Vertex *v2);

  bool counterClockWise(Vertex *v1, Vertex *v2);
  bool clockWise(Vertex *v1, Vertex *v2);

  bool equals(double x, double y);
  bool matches(Vertex *v);

  string getText();

  //#if USE_OPENGL
  //    void highlight();
  //    void unhighlight();

  //    void draw();
  //#if DEBUG_MODE
  //    void drawCircle();
  //#endif //#if DEBUG_MODE
  //#endif //#if USE_OPENGL
};
}  // namespace Basics
}  // namespace Par2DJMesh

#endif  //#ifndef _VERTEX_H_
