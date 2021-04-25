#ifndef _FACE_H_
#define _FACE_H_

#include "../Data/Definitions.h"
#include "../Crabmesh/Aft/Shape.h"
#include "Vertex.h"
#include "Edge.h"

using namespace Par2DJMesh;
using namespace Par2DJMesh::Basics;

namespace Par2DJMesh
{
namespace Basics
{
class Face : public Shape
{
private:
//#if USE_OPENGL
//    bool highlighted;
//#endif //#if USE_OPENGL

    Vertex *v[3];
    Vertex *mid;

private:
    Vertex *makeMid();

public:
    double h;

    Face(Vertex *v1 = NULL, Vertex *v2 = NULL, Vertex *v3 = NULL, long int id = 0);
    Face(Vertex *v1, Vertex *v2, Vertex *v3, Vertex *mid, long int id);
    ~Face();

    void setV1(Vertex *v);
    void setV2(Vertex *v);
    void setV3(Vertex *v);
    void setVertices(Vertex *v1, Vertex *v2, Vertex *v3);
    Vertex *getV1();
    Vertex *getV2();
    Vertex *getV3();

    Vertex *getMid();
    Vertex *circumcenter();
    Vertex *incenter();

    double surface();
    double orientedSurface();

    bool in(double x, double y);
    bool in(Vertex *v);
    bool on(Vertex *v);
    bool out(double x, double y);
    bool out(Vertex *v);

    void barycentricCoordinates(Vertex *v, double &l1, double &l2, double &l3);

    double gama();
    double quality();
    bool isBad();

    bool hasEdge(Vertex *v1, Vertex *v2);
    bool hasEdge(Edge *e);
    bool isAdjacent(Face *f);

    //testa se uma face intercepta outra
    bool hits(Face *f);
    bool hits(Edge *e);

    string getText();

//#if USE_OPENGL
//    void highlight();
//    void unhighlight();

//    void draw();
//#endif //#if USE_OPENGL
};
}
}

#endif //#ifndef _FACE_H_
