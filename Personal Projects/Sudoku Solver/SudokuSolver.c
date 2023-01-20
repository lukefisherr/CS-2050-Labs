#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfRecursions;
int numOfBacktracks;

int ** getPuzzle();
void freePuzzle(int ** sudoku);

void printPuzzle(int ** sudoku);

int solve(int ** sudoku);

int possibleNumber(int ** sudoku, int row, int column, int num);

int checkRow(int ** sudoku, int row, int num);
int checkColumn(int ** sudoku, int column, int num);
int checkSquare(int ** sudoku, int row, int column, int num);

int main(void)
{
    int ** sudoku = getPuzzle();
    printPuzzle(sudoku);
    while(!solve(sudoku));
    printf("\n\n");
    printPuzzle(sudoku);
    printf("Number of Recursions: %d\n", numOfRecursions);
    printf("Number of Backtracks: %d", numOfBacktracks);
    freePuzzle(sudoku);
}

int ** getPuzzle()
{
    FILE * fp;
    char file[100];
    printf("Type Sudoku txt or csv file name (Ex: 'Sudoku.csv' or 'Sudoku.txt'):\n");
    scanf("%s", &file);
    printf("\n");
    fp = fopen(file, "r");
    if(!fp){printf("Error opening file"); return NULL;}

    int ** sudoku;
    sudoku = malloc(9 * sizeof(int *));
    for(int i = 0; i < 9; i++)
    {
        sudoku[i] = malloc(9 * sizeof(int));
    }
    if(!sudoku){return NULL;}

    if(strstr(file, "txt"))
    {
        for(int row = 0; row < 9; row++)
        {
            for(int column = 0; column < 9; column++)
            {
                fscanf(fp, "%d", &(sudoku[row][column]));
            }
        }
    }
    else if(strstr(file, "csv"))
    {
        for(int row = 0; row < 9; row++)
        {
            for(int column = 0; column < 9; column++)
            {
                fscanf(fp, "%d,", &(sudoku[row][column]));
            }
        }
    }
    else
    {
        printf("File not txt or csv type");
    }
    return sudoku;
}

void printPuzzle(int ** sudoku)
{
    int row = 0;
    for(int i = 1; i <= 3; i++)
    {
        for(int i = row; row < i + 3; row++)
        {
            for(int column = 0; column < 9; column++)
            {
                printf("%d ", sudoku[row][column]);
                if(column % 3 == 2 && column != 8)
                {
                    printf("| ");
                }
            }
            printf("\n");
        }
        if(i != 3)
        {
            printf("---------------------\n");
        }
    }
}

int solve(int ** sudoku)
{
    for(int row = 0; row < 9; row++)
    {
        for(int column = 0; column < 9; column++)
        {
            if(sudoku[row][column] == 0)
            {

                for(int num = 1; num < 10; num++)
                {
                    if(possibleNumber(sudoku, row, column, num))
                    {
                        //printf("[%d][%d] with %d is possible\n", row, column, num);
                        sudoku[row][column] = num;
                        numOfRecursions++;
                        if(!solve(sudoku))
                        {
                            numOfBacktracks++;
                            sudoku[row][column] = 0;
                        }
                        else if (row == 8 && column == 8 && sudoku[8][8] != 0)
                        {
                            return 1;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int possibleNumber(int ** sudoku, int row, int column, int num)
{
    if (checkColumn(sudoku, column, num) && checkRow(sudoku, row, num) && checkSquare(sudoku, row, column, num))
    {
        return 1;
    }
    return 0;
}

int checkColumn(int ** sudoku, int column, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(sudoku[i][column] == num)
        {
            return 0;
        }
    }
    return 1;
}
int checkRow(int ** sudoku, int row, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(sudoku[row][i] == num)
        {
            return 0;
        }
    }
    return 1;
}
int checkSquare(int ** sudoku, int row, int column, int num)
{
    row = row/3 * 3;
    column = column/3 * 3;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(sudoku[row+i][column+j] == num)
            {
                return 0;
            }
        }
    }
    return 1;
}

void freePuzzle(int ** sudoku)
{
    for(int i = 0; i < 9; i++)
    {
        free(sudoku[i]);
    }
    free(sudoku);
}