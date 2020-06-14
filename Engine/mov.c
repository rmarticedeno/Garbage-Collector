#include <stdio.h>
#include <stdlib.h>

int max(char** board);
int randomize(char** board);
int nextone(char** board);

int** cant;
int** visited;
int a,b,m,n,maxx,maxy,maxv;
int dx[4] = { 1 , 0 , -1 , 0 }; // ayuda eje x
int dy[4] = { 0 , 1 , 0 , -1 }; //ayuda eje y

int fdm(char** board, int step)
{
    int i,j;
    for(i = 0; i < 2; ++i)
    {
        for(j = 0; j < 15; ++j)
        {
            if(board[i][j] == 'X')
            {
                a = i;
                b = j;
                break;
            }
        }
    }
    
    return nextone(board);
} 

int randomize(char** board)
{
    int result = rand()%5;
    while(a + dx[result] >= 15 || a + dx[result] < 0 || b + dy[result] >= 15 || b + dy[result] < 0)
    {
        result = rand()%5;
    }
    return result;
}

int nextone(char** board)
{
    m = -1;
    n = -1;
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 15; ++j)
        {
            int pos = abs(i-a) + abs(j-b);
            if(board[i][j] == 'o')
            {
                if (m == -1)
                {
                    m = i;
                    n = j;
                }
                if (abs(m-a)+abs(n-b) > pos)
                {
                    m = i;
                    n = j;
                }
            }
        }
    }
  //  if(m != -1 && (abs(m-a)+abs(n-b)) > 4)
    if(m != -1)
    {
        if(m < a) { return 2; }
        if(m > a) { return 0; }
        if(n < b) { return 3; }
        if(n > b) { return 1; }
    }
    else
    {
        return -1;
    }
}

int max(char** board)
{
    cant = calloc(15*sizeof(int*),sizeof(int));
    {
        for(int i = 0; i < 15; ++i)
        {
            cant[i] = calloc(15*sizeof(int),sizeof(int));
        }
    }
    
    visited = calloc(15*sizeof(int*),sizeof(int));
    {
        for(int i = 0; i < 15; ++i)
        {
            visited[i] = calloc(15*sizeof(int),sizeof(int));
        }
    }
    
    for(int i = 0; i < 15; ++i)
    {
        for(int j = 0;j < 15; ++j)
        {
            if(!visited[i][j] && board[i][j] == 'o')
            {
                ++cant[i][j];
                visited[i][j] = 1;
                for(int k = 0; k < 4; ++k)
                {
                    int p = i + dx[k];
                    int q = j + dy[k];
                    if(p < 15 && p >= 0 && q < 15 && q >= 0 && board[p][q] == 'o')
                    {
                        if(k == 1 || k ==2)
                        {
                            cant[i][j] += cant[p][q];
                        }
                        else
                        {
                            ++cant[i][j];
                        }
                    }
                }
            }
        }
    }
    
    maxx = 0;
    maxy = 0;
    maxv = -1;
    
    for(int i = 0; i < 15; ++i)
    {
        for(int j = 0; j < 15; ++j)
        {
            if(cant[i][j] > maxv)
            {
                maxv = cant[i][j];
                maxx = i;
                maxy = j;
            }
        }
    }
    
    printf("maxx%d, maxy%d, maxv%d",maxx,maxy,maxv);
    
    for(int i = 0; i < 15; ++i)
    {
        free(visited[i]);
        free(cant[i]);
    }
    free(visited);
    free(cant);
    
    if(maxy < b) { return 3; }
    if(maxy > b) { return 1; }
    if(maxx < a) { return 2; }
    if(maxx > a) { return 0; }
}
