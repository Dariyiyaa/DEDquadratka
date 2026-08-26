#include <stdio.h>
#include <math.h>


int main()
{
    int a = 0, b = 0, c = 0;
    int mx = 0;

    scanf("%d, %d. %d", &a, &b, &c);
    
    if (a > b && a > c)
        mx = a;
    else if (b > c && b > a)
        mx = b;
    else if (c > a && c > b)
        mx = c;

    printf("%d", mx);
}