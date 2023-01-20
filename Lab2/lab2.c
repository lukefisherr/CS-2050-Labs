#include "lab2.h"

int * makeArray(int size)
{
    int * array; //declare array
    array = malloc(size * sizeof(int)); //allocate memory for the array with given size
    if (array == NULL) //NULL check
    {
        return NULL;
    }
    else //initialize each element of array to 0 and return the array if it isn't NULL
    {
        for(int i = 0; i < size; i++)
        {
            *(array+i)=0;
        }
        return array;
    }
}

void fillThrees(int *array, int size)
{
    int threes = 0;
    //Initialize each part of the array with increments of 3
    for(int i = 0; i < size; i++)
    {
        *(array+i) = threes;
        threes = threes + 3;
    }
}

void freeArray(int **array)
{
    //free the array and assign the pointer to NULL to make sure
    free(*array);
    *array = NULL;
}
