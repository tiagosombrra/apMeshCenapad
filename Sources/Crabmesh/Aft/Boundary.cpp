#include "../../../Headers/Crabmesh/Aft/Boundary.h"


Boundary::Boundary() : Shape()
{
    lastVertexId = lastEdgeId = 0;

    first = NULL;
}

Boundary::~Boundary()
{
    while (!edges.empty())
    {
        Edge *e = edges.front();
        edges.pop_front();

        e->setVertices(NULL, NULL);

        delete e;
    }

    while (!boundary.empty())
    {
        Vertex *v = boundary.front();
        boundary.pop_front();

        delete v;
    }
}

Edge *Boundary::makeEdge(Vertex *v)
{
    Edge *e = NULL;

    e = new Edge(boundary.back(), v, ++lastEdgeId);

    boundary.back()->addAdjacentEdge(e);
    v->addAdjacentEdge(e);

    return e;
}

void Boundary::setBoundary(VertexList boundary)
{
    this->boundary = boundary;
}

VertexList Boundary::getBoundary()
{
    return boundary;
}

void Boundary::setEdges(EdgeList edges)
{
    for (EdgeList::iterator iter = edges.begin();
         iter != edges.end(); iter++)
    {
        (*iter)->setInBoundary(false);
    }

    this->edges = edges;

    for (EdgeList::iterator iter = edges.begin();
         iter != edges.end(); iter++)
    {
        (*iter)->setInBoundary(true);
    }
}

EdgeList Boundary::getEdges()
{
    return edges;
}

long int Boundary::getLastVertexId()
{
    return lastVertexId;
}

long int Boundary::getLastEdgeId()
{
    return lastEdgeId;
}

Vertex *Boundary::addVertex(double x, double y, CurvaParametrica *c)
{
    Vertex *v = NULL;

    v = new Vertex(x, y, ++lastVertexId);

//#if USE_OPENGL
//    //figura
//    //v->setSize(3.0);
//    //v->setSize(1.0);
//    v->setColor(0.0, 0.0, 0.0);
//    //endfigura
//#endif //#if USE_OPENGL

    if (!first)
    {
        first = v;
    }
    else if (!boundary.empty())
    {
        Edge *e = makeEdge(v);
        
        e->setCurva(c);
        
        e->makeParamMid();

        ////figura
        //#if USE_OPENGL
        //e->setColor(0.0, 0.0, 0.0);
        //#endif //#if USE_OPENGL
        ////endfigura

        edges.push_back(e);

        e->setInBoundary(true);

        //figura
        //e->setWidth(2.0);
        //endfigura
    }

    boundary.push_back(v);

    return v;
}

Vertex *Boundary::addVertex(long int id, double x, double y)
{
    Vertex *v = addVertex(x, y, NULL);

    if (v)
    {
        v->setId(id);

        if (id > lastVertexId)
        {
            lastVertexId = id;
        }
    }

    return v;
}

bool Boundary::close(CurvaParametrica *c)
{
    Edge *e = new Edge(boundary.back(), first, ++lastEdgeId);
    
    e->setCurva(c);

    e->makeParamMid();

    boundary.back()->addAdjacentEdge(e);
    first->addAdjacentEdge(e);

    first = NULL;

    ////figura
    //#if USE_OPENGL
    //e->setColor(0.0, 0.0, 0.0);
    //#endif //#if USE_OPENGL
    ////endfigura

    e->setInBoundary(true);

    edges.push_back(e);

    return true;
}

Edge *Boundary::getEdge(long int id)
{
    for (EdgeList::iterator iter = edges.begin();
         iter != edges.end(); iter++)
    {
        if ((*iter)->getId() == id)
        {
            return (*iter);
        }
    }

    return NULL;
}

Vertex *Boundary::getVertex(long int id)
{
    for (VertexList::iterator iter = boundary.begin();
         iter != boundary.end(); iter++)
    {
        if ((*iter)->getId() == id)
        {
            return (*iter);
        }
    }

    return NULL;
}

void Boundary::getBox(double *minX, double *minY, double *maxX, double *maxY)
{
    *minX = boundary.front()->getX();
    *maxX = boundary.front()->getX();

    *minY = boundary.front()->getY();
    *maxY = boundary.front()->getY();

    for (VertexList::iterator iter = ++boundary.begin();
         iter != boundary.end(); iter++)
    {
        if ((*iter)->getX() < *minX)
        {
            *minX = (*iter)->getX();
        }

        if ((*iter)->getY() < *minY)
        {
            *minY = (*iter)->getY();
        }

        if ((*iter)->getX() > *maxX)
        {
            *maxX = (*iter)->getX();
        }

        if ((*iter)->getY() > *maxY)
        {
            *maxY = (*iter)->getY();
        }
    }
}

bool Boundary::belongs(Edge *e)
{
    for (EdgeList::iterator iter = edges.begin();
         iter != edges.end(); iter++)
    {
        if ((*iter) == e)
        {
            return true;
        }
    }

    return false;
}

bool Boundary::belongs(Vertex *v1, Vertex *v2)
{
    for (EdgeList::iterator iter = edges.begin();
         iter != edges.end(); iter++)
    {
        if ((*iter)->equals(v1, v2))
        {
            return true;
        }
    }

    return false;
}

string Boundary::getText()
{
    string s;

    return s;
}

//#if USE_OPENGL
//void Boundary::highlight()
//{

//}

//void Boundary::unhighlight()
//{

//}

//void Boundary::draw()
//{
//    for (EdgeList::iterator iter = edges.begin();
//         iter != edges.end(); iter++)
//    {
//        (*iter)->draw();
//    }

//    for (VertexList::iterator iter = boundary.begin();
//         iter != boundary.end(); iter++)
//    {
//        (*iter)->draw();
//    }
//}

//void Boundary::drawNormals()
//{
//    for (EdgeList::iterator iter = edges.begin();
//         iter != edges.end(); iter++)
//    {
//        (*iter)->drawNormal();
//    }
//}
//#endif //#if USE_OPENGL
