#include <stdio.h>
#include <stdlib.h>

void generate(const char* file, int lines, int seed)
{
    int i, j=lines;
    FILE* fp = fopen(file, "w");
    srand(seed);
    while(j--)
    {
        for(i = 0; i < 5 ; ++i)
        {
            fprintf(fp, "%d", rand()%2);
            fprintf(fp, "%s", ",");
            fprintf(fp, "%d", rand()%15);
            if (i != 4)
            {
                fprintf(fp, "%s", " ");
            }
        }
        fprintf(fp , "%s" , "\n");
    }
    fclose (fp);
}
