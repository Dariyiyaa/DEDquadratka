#include <stdio.h>

struct Coefficient
{
	char s;
	double* p;
};


void input(double* a, double* b, double* c);
void EraseLine();
void ReadLine(struct Coefficient cof);

void EraseLine()
{   
    while (getchar() != '\n') {}    
    return;
}


void ReadLine(const struct Coefficient cof)
{
    printf("Enter coefficient %c: \n", cof.s);

    while (scanf("%lg", cof.p) <= 1)
    {
        if (getchar() != '\n')
        {
            EraseLine();
            printf("Enter coefficient %c: \n", cof.s);
        }
        else
        {
            break;
        }
    }
    return;
}



void input(double* const a, double* const b, double* const c)
{
    struct Coefficient coeffic_arr[3] = 
    {
		{'a', a},
		{'b', b},
		{'c', c}	
    };

    for (unsigned int i = 0; i < 3; i++)
    {
	    ReadLine(coeffic_arr[i]);
    }


    return;
}