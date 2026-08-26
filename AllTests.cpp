#include <stdio.h>
#include "solve.cpp"
#include <string.h>

#define STR_INFINITE "INFINITE"
#define STR_ZERO "ZERO"
#define STR_ONE "ONE"
#define STR_TWO "TWO"

struct Tests
{
    double     a;
    double     b;
    double     c;
    enum Roots nRoots;
    double     x1;
    double     x2;
};

int RunOneTest(struct Tests test);
void RunTests();

int RunOneTest(const struct Tests test)
{
    double x1 = 0, x2 = 0;
    enum Roots nRoots = SolveSquare(test.a, test.b, test.c, &x1, &x2);

	switch (nRoots)
	{
		case INFINITE:
			return (nRoots == test.nRoots);
			break;
		case ZERO:
			return (nRoots == test.nRoots);
			break;
		case ONE:
			return (nRoots == test.nRoots && double_equal(x1, test.x1));
            break;
		case TWO:
		    return (nRoots == test.nRoots && double_equal(x1, test.x1) && double_equal(x2, test.x2));
			break;
		default:
			printf("ERROR");
            return -1;
    }
}

void RunTests()
{
    // struct Tests test_arr[8] = 
    // {
    //     (struct Tests){ 0,    0,    0,    INFINITE,    NAN,    NAN }, 
    //     (struct Tests){ 0,    0,    1,    ZERO,        NAN,    NAN }, 
    //     (struct Tests){ 0,    1,    0,    ONE,         0,      NAN },
    //     (struct Tests){ 0,    1,    1,    ONE,         -1,     NAN },
    //     (struct Tests){ 1,    0,    0,    ONE,         0,      NAN },
    //     (struct Tests){ 1,    0,    1,    ZERO,        NAN,    NAN },
    //     (struct Tests){ 1,    0,    -25,  TWO,         -5,     5   },
    //     (struct Tests){ 1,    3,    0,    TWO,         -3,     0   }
    // };

    struct Tests test_arr[8];
    FILE *ptr = 0;
    ptr = fopen("Tests.txt", "rb");


    for(int i = 0; i < 8; i++)
    {
        char str[100] = "";

        if (fscanf(ptr, "%lg %lg %lg %s %lg %lg", &test_arr[i].a, &test_arr[i].b, &test_arr[i].c, str, &test_arr[i].x1, &test_arr[i].x2) == 6)
        {
            if (strcmp(str, STR_INFINITE) == 0) 
                test_arr[i].nRoots = INFINITE; 
            
            else if (strcmp(str, STR_ZERO) == 0)
                test_arr[i].nRoots = ZERO;
            
            else if (strcmp(str, STR_ONE) == 0)
                test_arr[i].nRoots = ONE;

            else if (strcmp(str, STR_TWO) == 0)
                test_arr[i].nRoots = TWO;
            
            else  
            {
                printf("Wrong test data\n");
                return;  
            }
        }
        else 
        {
            printf("Wrong test data\n");
            return;
        }

    }
    fclose(ptr);
 

    int CorrectTest = 0;

    for (int i = 0; i < 8; i++)
    {
        CorrectTest += RunOneTest(test_arr[i]);
        printf("%d\n", CorrectTest);
    }
    

    printf("%d out of 8 tests has succeeded \n", CorrectTest);
}