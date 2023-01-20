#include <stdio.h>
#include <stdlib.h>


int sudoku[9][9] = {5,3,0,0,7,0,0,0,0,
                    6,0,0,1,9,5,0,0,0,
                    0,9,8,0,0,0,0,6,0,
                    8,0,0,0,6,0,0,0,3,
                    4,0,0,8,0,3,0,0,1,
                    7,0,0,0,2,0,0,0,6,
                    0,6,0,0,0,0,2,8,0,
                    0,0,0,4,1,9,0,0,5,
                    0,0,0,0,8,0,0,7,9};

int possibleNumber(int row, int column);

int isNumInRow(int row, int column, int num);
int isNumInColumn(int row, int column, int num);
int isNumInSquare(int row, int column, int num);
