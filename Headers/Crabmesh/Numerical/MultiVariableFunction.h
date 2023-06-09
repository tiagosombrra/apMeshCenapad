#ifndef _DATA_NUMERICAL_MULTI_VARIABLE_FUNCTION_H_
#define _DATA_NUMERICAL_MULTI_VARIABLE_FUNCTION_H_

#include "../../Data/Definitions.h"

namespace Data {
namespace Numerical {
template <int n>
class MultiVariableFunction {
 public:
  virtual double f(const double x[n]) = 0;
};
}  // namespace Numerical
}  // namespace Data

#endif  //#ifndef _DATA_NUMERICAL_MULTI_VARIABLE_FUNCTION_H_
