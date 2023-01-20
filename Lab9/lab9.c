#include "lab9.h"

//initialize an array with given size and null check
//randomly initialzie the members
Runner * initArray(int size)
{
    Runner * array;
    array = malloc(sizeof(Runner)*size);
    if(!array){return NULL;}
    for(int i = 0; i < size; i ++)
    {
        array[i].height = rand()%100;
        array[i].age = rand()%100;
        array[i].kilometers = rand()%10;
    }
    return array;
}

//print the array and look at heights
void printArray(Runner * array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Runner at index %d is %f inches tall\n", i, array[i].height);
    }
}

// O(n^2)
//this function sorts the array by height in ascending order. The algorithm chose to sort
//is bubble sort which is O(n^2) efficiency. The function loops through the array N times
//and swaps adjacent indexes if the element to the right is less than the element on the left
void sortByHeight(Runner *array, int size)
{
    Runner temp;

    for(int j = 0; j < size; j++)
    {
        for(int i = 0; i < size-1; i++)
        {
            if(array[i+1].height < array[i].height)
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}

// O(log(n))
//this function takes a query height and searches the array and returns the index where the query was found
//It efficiently searches using binary search. Function checks the middle of the sorted array each time
//and checks to see if the query matches the middle. If the query is larger, binary search checks the right side
//of the array (middle + 1 to the last index) and vice versa. It continually reduces the array sample until the middle
//equals the query. This is O(log(n)) efficency
int getByHeight(Runner *array, int size, float height)
{
    int last = size;
    int first = 0;
    int middle = (first+last)/2;

    while(first <= last)
    {
        if(array[middle].height < height)
        {
            first = middle + 1;
        }
        else if(array[middle].height > height)
        {
            last = middle - 1;
        }
        else if(array[middle].height == height)
        {
            return middle;
        }
        middle = (first+last)/2;
    }
    return -1;
}

//free the given array of runners
void freeArray(Runner * array)
{
    free(array);
}