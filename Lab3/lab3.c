#include "lab3.h"

int * makeArray(int size)
{
    int * array;
    array = malloc(size * sizeof(int) + sizeof(int));//allocate memory for the array
    if (!array) return NULL;//NULL check
    array[0] = size; array++;//Set the size of the array to 0 and shift the pointer so size is in -1
    for(int i = 0; i < size; i++)//initialzie array with random number 0-9
    {
        *(array + i) = rand() % 10;
    }
    return array;
}

int * offsetArray(int *array, int offset)
{
    int temp = offset;//temporary variable to hold offset value so we can change it
    int size = array[-1];//grab our size that was hiding
    for (int i = 0; i < size; i++, temp++)//for loop that takes the original array element and puts it in the offset location
    {
        array[temp] = array[i];
        array[i] = 0;
    }
    array = array + offset;//offset the array pointer
    return array;
}

void printThrees(int *array, int size, int offset)
{
    int i = offset;//another temporary varibale to hold offset
    for(;i < size + offset; i++)//loop that finds a 3 and prints the location its in in the array
    {
        if(*(array + i) == 3)
        printf("%d, ", i);
    }
}

void freeArray(int *array, int offset)
{
    free(array - offset - 1);//move the pointer back to its original location by subtracting the offset and the single int for the size
    array = NULL;
}
