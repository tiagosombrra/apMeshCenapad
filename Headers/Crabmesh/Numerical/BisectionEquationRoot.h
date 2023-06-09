#ifndef _DATA_NUMERICAL_BISECTION_EQUATION_ROOT_H_
#define _DATA_NUMERICAL_BISECTION_EQUATION_ROOT_H_

#include "../../Data/Definitions.h"
#include "EquationRoot.h"

namespace Data {
namespace Numerical {
class BisectionEquationRoot : public Data::Numerical::EquationRoot {
 public:
  /// by default, max = 1000, tolerance = 0.0001, testFunction = true,
  /// testStepSize = true
  ///   if both testFunction and testStepSize are false, then they are converted
  ///   to true
  virtual double execute(EquationRootFunction *function, int maxSteps,
                         double tolerance, bool testFunction, bool testStepSize,
                         bool &ok);
  virtual double execute(EquationRootFunction *function, int maxSteps,
                         double tolerance, bool &ok);
  virtual double execute(EquationRootFunction *function, bool &ok);
  virtual double execute(EquationRootFunction *function);
};

class ClosestBisectionEquationRoot
    : public Data::Numerical::BisectionEquationRoot {
 public:
  using Data::Numerical::BisectionEquationRoot::execute;
  virtual double execute(EquationRootFunction *function, int maxSteps,
                         double tolerance, bool testFunction, bool testStepSize,
                         bool &ok);

 protected:
  virtual double recursiveExecute(EquationRootFunction *function, double min,
                                  double max, double fmin, double fmax,
                                  int maxSteps, double tolerance,
                                  bool testFunction, bool testStepSize,
                                  bool &ok, double &fval);
};

class MaxBisectionEquationRoot : public Data::Numerical::BisectionEquationRoot {
 public:
  using Data::Numerical::BisectionEquationRoot::execute;
  virtual double execute(EquationRootFunction *function, int maxSteps,
                         double tolerance, bool testFunction, bool testStepSize,
                         bool &ok);

 protected:
  virtual double recursiveExecute(EquationRootFunction *function, double min,
                                  double max, double fmin, double fmax,
                                  int maxSteps, double tolerance,
                                  bool testFunction, bool testStepSize,
                                  bool &ok, double &fval);
};

class MinBisectionEquationRoot : public Data::Numerical::BisectionEquationRoot {
 public:
  using Data::Numerical::BisectionEquationRoot::execute;
  virtual double execute(EquationRootFunction *function, int maxSteps,
                         double tolerance, bool testFunction, bool testStepSize,
                         bool &ok);

 protected:
  virtual double recursiveExecute(EquationRootFunction *function, double min,
                                  double max, double fmin, double fmax,
                                  int maxSteps, double tolerance,
                                  bool testFunction, bool testStepSize,
                                  bool &ok, double &fval);
};
}  // namespace Numerical
}  // namespace Data

#endif  //#ifndef _DATA_NUMERICAL_BISECTION_EQUATION_ROOT_H_
