// #include <stdio.h>


// int main()
// {   
//     // char a = 0;

//     FILE *ptr = fopen("Tests.txt", "r");
//     // fscanf(ptr, "%c", &a);
//     int ch;

//     while ((ch = getc(ptr)) != EOF)
//     {
//         putchar(ch);
//     }

//     fclose(ptr);
// }




// #include <stdio.h>

// int main()
// {
//     long last, count;
//     char ch;

//     FILE *ptr = fopen("Tests.txt", "r");
    
//     fseek(ptr, 0L, SEEK_END); // переходит в конец фвйла
//     last = ftell(ptr); // возвращает текущую позицию в фвйле

//     for (count = 1L; count <= last; count++)
//     {
//         fseek(ptr, -count, SEEK_END);
//         ch = (char)getc(ptr);
//         putchar(ch);
//     }

// }


// #include <stdio.h>
// #include <stdlib.h>

// // загрузка из файла структуры

// enum roots 
// {
//     INFINITE, 
//     ZERO, 
//     ONE, 
//     TWO
// };

// struct Tests
// {
//     double     a;
//     double     b;
//     double     c;
//     enum roots nRoots;
//     double     x1;
//     double     x2;
// };

// int main()
// {
//     struct Tests cases[8];
//     FILE *fp;
//     fp = fopen("Tests.txt", "rb");

//     for(int i = 0; i < 8; i++)
//     {
//         fread(&cases[i], sizeof(struct Tests), 1, fp);
//     }
//     fclose(fp);
 
// }