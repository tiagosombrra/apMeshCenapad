#include "../../../Headers/Crabmesh/Numerical/BisectionEquationRoot.h"

using namespace Data;
using namespace Data::Numerical;

double Data::Numerical::BisectionEquationRoot::execute(EquationRootFunction *function,
                                                       int maxSteps, double tolerance, bool testFunction, bool testStepSize, bool &ok)
{
    ok = true;

    if ((!testFunction) && (!testStepSize))
    {
        testFunction = testStepSize = true;
    }

    double a = function->min();
    double b = function->max();

    double min = std::min(a, b);
    double fmin = function->f(min);

    if ((testFunction) && (std::fabs(fmin) <= tolerance))
    {
        return min;
    }

    double max = std::max(a, b);
    double fmax = function->f(max);

    if ((testFunction) && (std::fabs(fmax) <= tolerance))
    {
        return max;
    }

    if (fmin*fmax >= 0.0)
    {
        ok = false;

        return 0.5*(min + max);
    }

    double mid = 0.0, fmid = 0.0;

    for (int i = 0; i < maxSteps; i++)
    {
        mid = 0.5*(min + max);

        if ((testStepSize) && ((max - min) <= tolerance))
        {
            return mid;
        }

        fmid = function->f(mid);

        if ((testFunction) && (std::fabs(fmid) <= tolerance))
        {
            return mid;
        }

        if (fmin*fmid < 0.0)
        {
            max = mid;
            fmax = fmid;
        }
        else
        {
            min = mid;
            fmin = fmid;
        }
    }

    ok = false;

    return mid;
}

double Data::Numerical::BisectionEquationRoot::execute(EquationRootFunction *function, int maxSteps, double tolerance, bool &ok)
{
    return this->execute(function, maxSteps, tolerance, true, true, ok);
}

double Data::Numerical::BisectionEquationRoot::execute(EquationRootFunction *function, bool &ok)
{
    return this->execute(function, 1000, 0.0001, ok);
}

double Data::Numerical::BisectionEquationRoot::execute(EquationRootFunction *function)
{
    bool ok;

    return this->execute(function, ok);
}

double Data::Numerical::ClosestBisectionEquationRoot::recursiveExecute(EquationRootFunction *function,
                                                                       double min, double max, double fmin, double fmax,
                                                                       int maxSteps, double tolerance, bool testFunction, bool testStepSize, bool &ok, double &fval)
{
    ok = true;

    double mid = 0.5*(min + max);

    if (maxSteps == 0)
    {
        ok = false;

        fval = 0.0;

        return mid;
    }

    double fmid = function->f(mid);

    if ((testStepSize) && ((max - min) <= tolerance))
    {
        fval = fmid;

        return mid;
    }

    if ((testFunction) && (std::fabs(fmid) <= tolerance))
    {
        fval = fmid;

        return mid;
    }

    bool tested1 = false, ok1 = false;
    double val1 = 0.0, fval1 = 0.0;

    if (std::fabs(fmin) <= std::fabs(fmax) + tolerance)
    {
        tested1 = true;

        val1 = this->recursiveExecute(function, min, mid, fmin, fmid, maxSteps - 1, tolerance, testFunction, testStepSize, ok1, fval1);
    }

    bool tested2 = false, ok2 = false;
    double val2 = 0.0, fval2 = 0.0;

    if (std::fabs(fmin) + tolerance >= std::fabs(fmax))
    {
        tested2 = true;

        val2 = this->recursiveExecute(function, mid, max, fmid, fmax, maxSteps - 1, tolerance, testFunction, testStepSize, ok2, fval2);
    }

    if ((!tested1) && (std::fabs(val2 - mid) < tolerance))
    {
        tested1 = true;

        val1 = this->recursiveExecute(function, min, mid, fmin, fmid, maxSteps - 1, tolerance, testFunction, testStepSize, ok1, fval1);
    }

    if ((!tested2) && (std::fabs(val1 - mid) < tolerance))
    {
        tested2 = true;

        val2 = this->recursiveExecute(function, mid, max, fmid, fmax, maxSteps - 1, tolerance, testFunction, testStepSize, ok2, fval2);
    }

    if (ok2)
    {
        if (((ok1) && (std::fabs(fval2) < std::fabs(fval1))) ||
                (!ok1))
        {
            fval1 = fval2;

            val1 = val2;

            ok1 = true;
        }
    }

    if (ok1)
    {
        if (std::fabs(fmid) < std::fabs(fval1))
        {
            fval = fmid;

            return mid;
        }

        fval = fval1;

        return val1;
    }

    ok = false;

    fval = fmid;

    return mid;
}

double Data::Numerical::ClosestBisectionEquationRoot::execute(EquationRootFunction *function,
                                                              int maxSteps, double tolerance, bool testFunction, bool testStepSize, bool &ok)
{
    ok = true;

    if ((!testFunction) && (!testStepSize))
    {
        testFunction = testStepSize = true;
    }

    double a = function->min();
    double b = function->max();

    double min = std::min(a, b);
    double fmin = function->f(min);

    if ((testFunction) && (std::fabs(fmin) <= tolerance))
    {
        return min;
    }

    double max = std::max(a, b);
    double fmax = function->f(max);

    if ((testFunction) && (std::fabs(fmax) <= tolerance))
    {
        return max;
    }

    double fval = 0.0;

    double val = this->recursiveExecute(function, min, max, fmin, fmax, maxSteps, tolerance, testFunction, testStepSize, ok, fval);
    //double val = this->recursiveExecute(function, min, max, fmin, fmax, maxSteps, tolerance, true, false, ok, fval);

    if (std::fabs(fmax) < std::fabs(fmin))
    {
        fmin = fmax;

        min = max;
    }

    if (ok)
    {
        if (std::fabs(fmin) < std::fabs(fval))
        {
            return min;
        }

        return val;
    }

    return min;
}

double Data::Numerical::MaxBisectionEquationRoot::recursiveExecute(EquationRootFunction *function,
                                                                   double min, double max, double fmin, double fmax,
                                                                   int maxSteps, double tolerance, bool testFunction, bool testStepSize, bool &ok, double &fval)
{
    ok = true;

    double mid = 0.5*(min + max);

    double fmid = function->f(mid);

    if ((testFunction) && (std::fabs(fmax - fmin) <= 2.0*tolerance) &&
            (std::fabs(fmax - fmid) <= tolerance) && (std::fabs(fmin - fmid) <= tolerance))
    {
        fval = fmid;

        return mid;
    }

    if (maxSteps == 0)
    {
        ok = false;

        fval = fmid;

        return mid;
    }

    if ((testStepSize) && ((max - min) <= tolerance))
    {
        fval = fmid;

        return mid;
    }

    bool tested1 = false, ok1 = false;
    double val1 = 0.0, fval1 = 0.0;

    if (fmin + tolerance >= fmax)
    {
        tested1 = true;

        val1 = this->recursiveExecute(function, min, mid, fmin, fmid, maxSteps - 1, tolerance, testFunction, testStepSize, ok1, fval1);
    }

    bool tested2 = false, ok2 = false;
    double val2 = 0.0, fval2 = 0.0;

    if (fmin <= fmax + tolerance)
    {
        tested2 = true;

        val2 = this->recursiveExecute(function, mid, max, fmid, fmax, maxSteps - 1, tolerance, testFunction, testStepSize, ok2, fval2);
    }

    if ((!tested1) && (std::fabs(val2 - mid) < tolerance))
    {
        tested1 = true;

        val1 = this->recursiveExecute(function, min, mid, fmin, fmid, maxSteps - 1, tolerance, testFunction, testStepSize, ok1, fval1);
    }

    if ((!tested2) && (std::fabs(val1 - mid) < tolerance))
    {
        tested2 = true;

        val2 = this->recursiveExecute(function, mid, max, fmid, fmax, maxSteps - 1, tolerance, testFunction, testStepSize, ok2, fval2);
    }

    if (ok2)
    {
        if (((ok1) && (fval2 > fval1)) ||
                (!ok1))
        {
            fval1 = fval2;

            val1 = val2;

            ok1 = true;
        }
    }

    if (ok1)
    {
        if (fmid > fval1)
        {
            fval = fmid;

            return mid;
        }

        fval = fval1;

        return val1;
    }

    ok = false;

    fval = fmid;

    return mid;
}

double Data::Numerical::MaxBisectionEquationRoot::execute(EquationRootFunction *function,
                                                          int maxSteps, double tolerance, bool testFunction, bool testStepSize, bool &ok)
{
    ok = true;

    if ((!testFunction) && (!testStepSize))
    {
        testFunction = testStepSize = true;
    }

    double a = function->min();
    double b = function->max();

    double min = std::min(a, b);
    double fmin = function->f(min);

    double max = std::max(a, b);
    double fmax = function->f(max);

    double fval = 0.0;

    double val = this->recursiveExecute(function, min, max, fmin, fmax, maxSteps, tolerance, testFunction, testStepSize, ok, fval);

    if (fmin > fmax)
    {
        fmax = fmin;

        max = min;
    }

    if (ok)
    {
        if (fmax > fval)
        {
            return max;
        }

        return val;
    }

    return max;
}

double Data::Numerical::MinBisectionEquationRoot::recursiveExecute(EquationRootFunction *function,
                                                                   double min, double max, double fmin, double fmax,
                                                                   int maxSteps, double tolerance, bool testFunction, bool testStepSize, bool &ok, double &fval)
{
    ok = true;

    double mid = 0.5*(min + max);

    double fmid = function->f(mid);

    if ((testFunction) && (std::fabs(fmax - fmin) <= tolerance) &&
            (std::fabs(fmax - fmid) <= tolerance) && (std::fabs(fmin - fmid) <= tolerance))
    {
        fval = fmid;

        return mid;
    }

    if (maxSteps == 0)
    {
        ok = false;

        fval = fmid;

        return mid;
    }

    if ((testStepSize) && ((max - min) <= tolerance))
    {
        fval = fmid;

        return mid;
    }

    bool tested1 = false, ok1 = false;
    double val1 = 0.0, fval1 = 0.0;

    if (fmin <= fmax + tolerance)
    {
        tested1 = true;

        val1 = this->recursiveExecute(function, min, mid, fmin, fmid, maxSteps - 1, tolerance, testFunction, testStepSize, ok1, fval1);
    }

    bool tested2 = false, ok2 = false;
    double val2 = 0.0, fval2 = 0.0;

    if (fmin + tolerance >= fmax)
    {
        tested2 = true;

        val2 = this->recursiveExecute(function, mid, max, fmid, fmax, maxSteps - 1, tolerance, testFunction, testStepSize, ok2, fval2);
    }

    if ((!tested1) && (std::fabs(val2 - mid) < tolerance))
    {
        tested1 = true;

        val1 = this->recursiveExecute(function, min, mid, fmin, fmid, maxSteps - 1, tolerance, testFunction, testStepSize, ok1, fval1);
    }

    if ((!tested2) && (std::fabs(val1 - mid) < tolerance))
    {
        tested2 = true;

        val2 = this->recursiveExecute(function, mid, max, fmid, fmax, maxSteps - 1, tolerance, testFunction, testStepSize, ok2, fval2);
    }

    if (ok2)
    {
        if (((ok1) && (fval2 < fval1)) ||
                (!ok1))
        {
            fval1 = fval2;

            val1 = val2;

            ok1 = true;
        }
    }

    if (ok1)
    {
        if (fmid < fval1)
        {
            fval = fmid;

            return mid;
        }

        fval = fval1;

        return val1;
    }

    ok = false;

    fval = fmid;

    return mid;
}

double Data::Numerical::MinBisectionEquationRoot::execute(EquationRootFunction *function,
                                                          int maxSteps, double tolerance, bool testFunction, bool testStepSize, bool &ok)
{
    ok = true;

    if ((!testFunction) && (!testStepSize))
    {
        testFunction = testStepSize = true;
    }

    double a = function->min();
    double b = function->max();

    double min = std::min(a, b);
    double fmin = function->f(min);

    double max = std::max(a, b);
    double fmax = function->f(max);

    double fval = 0.0;

    double val = this->recursiveExecute(function, min, max, fmin, fmax, maxSteps, tolerance, testFunction, testStepSize, ok, fval);

    if (fmax < fmin)
    {
        fmin = fmax;

        min = max;
    }

    if (ok)
    {
        if (fmin < fval)
        {
            return min;
        }

        return val;
    }

    return min;
}
