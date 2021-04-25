#ifndef _BOUNDARY_H_
#define _BOUNDARY_H_

#include "../../Data/Definitions.h"
#include "Shape.h"
#include "../../Data/Curve/CurvaParametrica.h"
#include "../../Data/Edge.h"
#include "../../Data/Vertex.h"
#include "QuadtreeCell.h"
#include "Quadtree.h"

using namespace Par2DJMesh;
using namespace Par2DJMesh::AFT;
using namespace Par2DJMesh::Basics;

namespace Par2DJMesh
{
namespace AFT
{
class Boundary : public Shape
{
private:
    VertexList boundary;
    EdgeList edges;

    long int lastVertexId;
    long int lastEdgeId;

    Vertex *first;

private:
    Edge *makeEdge(Vertex *v);

public:
    Boundary();
    ~Boundary();

    void setBoundary(VertexList boundary);
    VertexList getBoundary();

    void setEdges(EdgeList edges);
    EdgeList getEdges();

    long int getLastVertexId();
    long int getLastEdgeId();

    Vertex *addVertex(double x, double y, CurvaParametrica *c);
    Vertex *addVertex(long int id, double x, double y);
    bool close(CurvaParametrica *c);

    Edge *getEdge(long int id);
    Vertex *getVertex(long int id);

    void getBox(double *minX, double *minY, double *maxX, double *maxY);

    bool belongs(Edge *e);
    bool belongs(Vertex *v1, Vertex *v2);

    string getText();

//#if USE_OPENGL
//    void highlight();
//    void unhighlight();

//    void draw();
//    void drawNormals();
//#endif //#if USE_OPENGL
};
}
}

#endif //#ifndef _BOUNDARY_H_
