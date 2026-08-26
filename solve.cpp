#include <math.h>

#ifndef OPEN
#define OPEN

enum Roots 
{
    INFINITE, 
    ZERO, 
    ONE, 
    TWO
};

Roots SolveSquare(double a, double b, double c, double* x1_ptr, double* x2_ptr);

int double_equal(double a, double b);

int double_equal(const double a, const double b)
{
    const double EPS = 1e-6;
    
    if (fabs(a - b) <= EPS)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



static Roots SolveTrivial(const double c)
{
    if (double_equal(c, 0))
    {   
        return INFINITE;
    }

    return ZERO;
}


static Roots SolveLine(const double b, const double c, double* const x1_ptr, double* const x2_ptr)
{
    if (double_equal(b, 0))
    {
        return SolveTrivial(c);
    }
    /* b != 0*/
    *x1_ptr = -c / b;
    *x2_ptr = NAN;
    return ONE;
}



Roots SolveSquare(const double a, const double b, const double c, double* const x1_ptr, double* const x2_ptr)
{
    if (double_equal(a, 0))
    {
        return SolveLine(b, c, x1_ptr, x2_ptr);
    }
    /* a != 0 */

    double d = 0;
    d = b*b - 4*a*c;
    if (double_equal(d, 0))
    {
        *x1_ptr = -b / (2*a);
        *x2_ptr = NAN;
        return ONE;
    }
    else if (d > 0)
    {
        *x1_ptr = (-b + sqrt(d)) / (2*a);
        *x2_ptr = (-b - sqrt(d)) / (2*a);
        
        if (*x1_ptr > *x2_ptr)
        {
            double x1_dubl = *x1_ptr;
            *x1_ptr = *x2_ptr;
            *x2_ptr = x1_dubl;
        }

        return TWO;
    }
    else /* d < 0 */
    {
        return ZERO;
    }
}
#endif 