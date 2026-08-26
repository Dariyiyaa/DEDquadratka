#include <stdio.h>
#include "solve.cpp"

void output(int count_x, double x1, double x2);

void output(const int count_x, const double x1, const double x2)
{
    switch (count_x)
    {
        case INFINITE:
            printf("Infinite number of roots");
            break;
        case ZERO:
            printf("No roots");
            break;
        case ONE:
            printf("Only one root equals %lg", x1);
            break;
        case TWO:
            printf("Two roots equal:\n");
            printf("x1 = %lg, x2 = %lg", x1, x2);
            break;
        default:
            printf("ERROR");
    }
}