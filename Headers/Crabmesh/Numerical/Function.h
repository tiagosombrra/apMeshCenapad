#ifndef _DATA_NUMERICAL_FUNCTION_H_
#define _DATA_NUMERICAL_FUNCTION_H_

#include "../../Data/Definitions.h"
#include "MultiVariableFunction.h"

namespace Data {
namespace Numerical {
class Function : public Data::Numerical::MultiVariableFunction<1> {
 public:
  virtual double f(double x) = 0;

  virtual double f(const double x[1]);
};
}  // namespace Numerical
}  // namespace Data

#endif  //#ifndef _DATA_NUMERICAL_FUNCTION_H_
