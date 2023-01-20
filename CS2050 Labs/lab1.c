#include "lab1.h"

/*getAvg function takes int size and int array and finds the average of the array
and puts the average in double result. We error check to see if size is greater than 1
and if array is NULL*/
int getAvg(int size, int *array, double *result)
{
    *result = 0; //set result back to 0 so it resets the pointer when we call the function a second time
    //error checking the function and returning -1
    if(size < 1 || array == NULL)
    {
        return -1;
    }
    double total;
    //loop through the array and add each element into a total int
    for(int i = 0; i < size; i++)
    {
        total = total + array[i];
    }
    //find average
    *result = total/(double)size;
    return 0;
}