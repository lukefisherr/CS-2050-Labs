#include "lab5.h"

int * createArray(int size);
int getSize(int *array);
ArrayInfo * getInfo(int *array);
void printLastCalculation(int *array);

void sumFives(int *array);

void freeArray(int *array);

int * createArray(int size)
{
    //Initialize a struct array so we can store a struct in front
    ArrayInfo * array;

    //allocate memory for the struct and all the integers using the size given
    array = malloc(sizeof(ArrayInfo) + size*sizeof(int));

    //NULL check
    if (!array) return NULL;

    //create the struct and store it at element 0. Assign size to the size member and shift array to the right
    ArrayInfo hidden;
    hidden.size = size;
    array[0] = hidden; array++;

    //return the array as an integer array but with struct at -1
    return (int *)array;
}

int getSize(int *array)
{
    //create a temporay struct array so we dont have to concatenate as much. Store it with array values
    ArrayInfo * temp = (ArrayInfo *)array;

    //return the hidden struct size member
    return (temp[-1].size);
}

ArrayInfo * getInfo(int * array)
{
    //return a pointer to the hidden struct
    return (ArrayInfo *)(array - 1);
}

void printLastCalculation(int * array)
{
    //temp struct array to make it easier
    ArrayInfo * temp = (ArrayInfo *)array;

    //assume if there was no calculation that the value is -1 and print it
    if (temp[-1].lastCalculation == -1)
    {
        printf("Last Calculation = -1");
    }

    //print the last calculation stored in the field
    else
    {
        printf("Last Calulation = %d", temp[-1].lastCalculation);
    }
}

void sumFives(int * array)
{
    //counter variable
    int counter = 0;

    //if an element is 5 then add it to the counter
    for(int i = 0; i < getSize(array); i++)
    {
        if (array[i] == 5)
        {
            counter = counter + 5;
        }
    }

    //temp struct array and assign the sum counter to the last calculation
    ArrayInfo * temp = (ArrayInfo *)array;
    temp[-1].lastCalculation = counter;
}

void freeArray(int * array)
{
    //change int array back to struct array so we can shift it by one to the hidden struct and free everything
    free(((ArrayInfo *)array) - 1);
}