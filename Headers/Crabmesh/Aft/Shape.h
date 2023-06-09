#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "../../Data/Definitions.h"

using namespace Par2DJMesh;
using namespace Par2DJMesh::Basics;

namespace Par2DJMesh {
namespace Basics {
class Shape {
 protected:
  long int id;
  // static double tolerance;

  //#if USE_OPENGL
  //    double r;
  //    double g;
  //    double b;
  //#endif //#if USE_OPENGL

 public:
  Shape(long int id = 0);
  virtual ~Shape();

  void setId(long int id);
  long int getId();

  // static void setTolerance(double tolerance);

  virtual string getText() = 0;

  //#if USE_OPENGL
  //    void setColor(double r, double g, double b);
  //    void setR(double r);
  //    void setG(double g);
  //    void setB(double b);
  //    double getR();
  //    double getG();
  //    double getB();
  //    void getColor(double *r, double *g, double *b);

  //    virtual void highlight() = 0;
  //    virtual void unhighlight() = 0;

  //    virtual void draw() = 0;
  //#endif //#if USE_OPENGL
  // static double getTolerance();
};
}  // namespace Basics
}  // namespace Par2DJMesh

#endif  //#ifndef _SHAPE_H_
