#ifndef _DATA_NUMERICAL_EQUATION_ROOT_FUNCTION_H_
#define _DATA_NUMERICAL_EQUATION_ROOT_FUNCTION_H_

#include "../../Data/Definitions.h"
#include "Function.h"
#include "../../Data/Curve/CurvaParametrica.h"

namespace Data
{
namespace Numerical
{
class EquationRootFunction : public Data::Numerical::Function
{
public:

    virtual double min() = 0;
    virtual double max() = 0;
};

template <int n>
class EquationRootMultiVariableFunction : public Data::Numerical::MultiVariableFunction<n>
{
public:

    virtual double min(int i) = 0;
    virtual double max(int i) = 0;
};
}
}

#endif //#ifndef _DATA_NUMERICAL_EQUATION_ROOT_FUNCTION_H_
