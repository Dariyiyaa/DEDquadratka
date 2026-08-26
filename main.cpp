#include <stdio.h>

#include "output.cpp"
#include "input.cpp"
#include "solve.cpp"
#include "AllTests.cpp"

// #define TEST

int main()
{
    #ifdef TEST

    RunTests();

    #else

    double a = 0, b = 0, c = 0; 
    input(&a, &b, &c);
    
    double x1 = 0, x2 = 0;
    Roots root = SolveSquare(a, b, c, &x1, &x2);

    output(root, x1, x2);
    #endif
}