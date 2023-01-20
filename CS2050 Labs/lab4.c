#include "lab4.h"

short * createArray(int size)//create short array with int size
{
    int *array; //create an int array to make it easier to store our size
    array = malloc(size * sizeof(short) + sizeof(int));//allocate memory for shorts and our int sizez
    if (!array) return NULL;//NULL check
    array[0] = size; array = array + 1;//store the size in 0 and shift the pointer
    return (short *)array;//return the array as a short pointer instead of int
}

int getSize(short *array)//get size of array
{
    return array[-sizeof(short)];//shift back through array to get size. Go back a size of short instead of an int because int is bigger. array[-1] does not return size
}

int countLesser(short *array, int query)//function 
{
    int count = 0;//varibale to store amount of elements less than query given
    int size = array[-sizeof(short)];//get the size of array
    for(int i = 0; i < size; i++)//loop through array
    {
        if(array[i] < query)//if element is less than query add 1 to counter
        {
            count++;
        }
    }
    return count;//return int count
}

void freeArray(short *array)//free array
{
    free(array-(sizeof(short)));//shift pointer back the size of short because shifting back an int is too much and will not free thr pointer
}