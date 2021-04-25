#include "../../../Headers/Crabmesh/Aft/Shape.h"

//double Shape::tolerance = 1.e-8;

//double Shape::getTolerance()
//{
//    return this->tolerance;
//}

Shape::Shape(long int id)
{
    setId(id);
//    this->tolerance = 1.e-8;
    //setTolerance(0.001);
//#if USE_OPENGL
//    setColor(1.0, 1.0, 1.0);
//#endif //#if USE_OPENGL
}

Shape::~Shape()
{

}

void Shape::setId(long int id)
{
    this->id = id;
}

long int Shape::getId()
{
    return id;
}

//void Shape::setTolerance(double tolerance)
//{
//    Shape::tolerance = tolerance;
//}

//#if USE_OPENGL
//void Shape::setColor(double r, double g, double b)
//{
//    setR(r);
//    setG(g);
//    setB(b);
//}

//void Shape::setR(double r)
//{
//    this->r = r;
//}

//void Shape::setG(double g)
//{
//    this->g = g;
//}

//void Shape::setB(double b)
//{
//    this->b = b;
//}

//double Shape::getR()
//{
//    return r;
//}

//double Shape::getG()
//{
//    return g;
//}

//double Shape::getB()
//{
//    return b;
//}

//void Shape::getColor(double *r, double *g, double *b)
//{
//    *r = this->r;
//    *g = this->g;
//    *b = this->b;
//}
//#endif //#if USE_OPENGL
