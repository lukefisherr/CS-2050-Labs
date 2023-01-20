#include "lab6.h"

Student * createArray(int size)//create of array of structs or students
{
    //allocate memory for the students in the array and the size of the array so we can hide it
    int * array;//int array to make hiding the size easier
    array = malloc(size * sizeof(Student) + sizeof(int));
    if (!array) return NULL;//NULL check

    //hide the size of the array so it's now at -1
    array[0] = size; array++;

    //return the array but change it to struct array
    return (Student *)array;
}

int getSize(Student *array)
{
    //temp int array to make it slight easier to access -1, return the int stored in -1
    int * temp = (int *)array;
    return temp[-1];
}

Student * getStudent(Student *array, int index)
{
    //temp student ppinter
    Student * temp;

    //get size of array
    int size = getSize(array);

    //if the index given is bigger than the size then return NULL to let user know given index runs off array
    if(index > size - 1)
    {
        printf("Index not found in array, returning null\n");
        return NULL;
    }

    //return the student pointer at given index
    temp = (array+index);
    return temp;
}

float getGPA(Student *s)
{
    //return given student gpa
    return s->gpa;
}
int getID(Student *s)
{
    //return given student id
    return s->id;
}

Student * getMinGPA(Student *array)
{
    //get size
    int size = getSize(array);

    //temp varibales for our loop
    float comparison = 100;//value to compare gpa's to, purposely higher than max gpa
    int temp;//varibale to hold index

    //loop through the array to find min gpa
    for(int i = 0; i < size; i++)
    {
        //when gpa is less than comparison, change the comparison to new min and change temp to current index
        if((array+i)->gpa < comparison)
        {
            comparison = (array+i)->gpa;
            temp = i;
        }
    }

    //return student pointer with the min gpa using temp index
    Student * min = (array + temp);
    return min;
}

void freeArray(Student *array)
{
    //cahnge student array to int array to get back to -1 element and free from there
    free(((int *)array) - 1);
}