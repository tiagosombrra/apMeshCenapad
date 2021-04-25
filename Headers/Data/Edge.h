#ifndef _EDGE_H_
#define _EDGE_H_

#include "../Data/Definitions.h"
#include "../Crabmesh/Aft/Shape.h"
#include "../Data/Curve/CurvaParametrica.h"
#include "Vertex.h"
#include "../Crabmesh/Aft/QuadtreeCell.h"
#include "../Data/Curve/CurvaParametrica.h"

using namespace Par2DJMesh;
using namespace Par2DJMesh::Basics;

namespace Par2DJMesh
{
namespace Basics
{
using namespace Par2DJMesh::AFT;

class Edge : public Shape
{
private:
    bool free;
    bool inBoundary;
    Vertex *v[2];
    Vertex *mid;
    Vertex *vector;
    double len;

    QuadtreeCell *cell;

    double xmin;
    double xmax;
    double ymin;
    double ymax;

//#if USE_OPENGL
//    double width;
//#endif //#if USE_OPENGL

    //Daniel Siqueira
    //ponteiro para a curva
    CurvaParametrica* c;

public:
    Vertex *makeMid();
    Vertex *makeVector();

public:
    Edge(Vertex *v1 = NULL, Vertex *v2 = NULL, long int id = 0);
    ~Edge();

    void setV1(Vertex *v);
    void setV2(Vertex *v);
    void setVertices(Vertex *v1, Vertex *v2);
    Vertex *getV1();
    Vertex *getV2();

    void setInBoundary(bool inBoundary);
    bool isInBoundary();

//#if USE_OPENGL
//    void setWidth(double width);
//#endif //#if USE_OPENGL

    void setFree(bool free);
    bool isFree();

    void setCell(QuadtreeCell *cell);
    QuadtreeCell *getCell();

    Vertex *getMid();

    double length();

    bool intercept(Edge *e);
    bool intercept(Vertex *v1, Vertex *v2);
    bool intercept(Vertex *v);
    bool intercept(double x, double y);

    double straightDistance(Vertex *v);
    double distance(Vertex *v);
    double distance(double x, double y);

    double dot(Vertex *v);

    bool left(Vertex *v);
    bool left(double x, double y);

    bool right(Vertex *v);
    bool right(double x, double y);

    bool accordingToNormal(Vertex *v, bool inEdgeTest = false);

    double angle(Edge *e);
    double angle(Vertex *v1, Vertex *v2);

    Vertex *normal();

    bool equals(Edge *e);
    bool equals(Vertex *v1, Vertex *v2);
    bool matches(Edge *e);
    bool matches(Vertex *v1, Vertex *v2);

    //metodos do Daniel Siqueira
    void setCurva ( CurvaParametrica*  );
    void setLen(double len);
    double getLen();
    void makeParamMid();

    string getText();

//#if USE_OPENGL
//    void highlight();
//    void highlight(bool highlightCell);
//    void unhighlight();
//    void unhighlight(bool highlightCell);

//    void draw();
//    void drawNormal();
//#endif //#if USE_OPENGL
};
}
}

#endif //#ifndef _EDGE_H_
