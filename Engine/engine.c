#include <stdio.h>
#include <stdlib.h>
#include "types.h"

char** board; //tablero
int x, y, score; //pos x,y del robot y la puntuación
int dx[4] = { 1 , 0 , -1 , 0 }; // ayuda eje x
int dy[4] = { 0 , 1 , 0 , -1 }; // ayuda eje y

/*
Inicializa el tablero y lo rellena
*/
void init()
{
    int i, j;
    board = calloc(2 * sizeof(char*), sizeof(char*));
    for(i = 0; i < 2; ++i)
    {
        board[i] = calloc(15 * sizeof(char), sizeof(char));
        for(j = 0; j < 15; ++j)
        {
            board[i][j] = '.';
        }
    }
    x = 0;
    y = 0;
    board[x][y] = 'X';
}


/*
limpia la memoria asignada al tablero
*/
void dispose()
{
    int i;
    for(i = 0; i < 2 ; ++i)
    {
        free(board[i]);
    }
    free(board);
}
/*
Imprime el tablero
 */
void print()
{
    system("clear");
    int i;
    printf("===================\n");
    for(i = 0; i < 2; ++i)
    {
        printf("||%s||\n", board[i]);
    }
    printf("==================== WALLE_SCORE: %d ======================\n", score);
}
/*
Actualiza la basura en el mapa 
 */
void gg()
{
    int a , b;
    a = rand()%2;
    b = rand()%16;
    if (board[a][b] == '.')
    {
        board[a][b] = 'o';
    }
    if (board[a][b] == 'X')
    {
        score += 1;
    }
}

/*
Dado un resultado de la funcion de movimiento mueve el robot, se asume que el movimiento siempre es valido
*/

void move(int mov)
{
    int a, b;
    a = dx[mov];
    b = dy[mov];
    board[x][y] = '.';
    x += a;
    y += b;
    if(board[x][y] == 'o')
    {
        score += 1;
    }
    board[x][y] = 'X';
}
