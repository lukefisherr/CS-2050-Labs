#include "lab11.h"

//implementation for student database which holds the size, current student, the database to the right and left student
typedef struct StudentDB{
    int size;
    Student * current;
    struct StudentDB * left;
    struct StudentDB * right;
}StudentDB;

// O(1)
//initialize the database to NULL and return
StudentDB * createDatabase()
{
    StudentDB * root;
    root = malloc(sizeof(StudentDB));
    if(!root){return NULL;}
    root->current = NULL;
    root->left = NULL;
    root->right = NULL;
    root->size = 0;
    return root;
}

// O(1)
//access the size member of the data base
int getSize(StudentDB *db)
{
    printf("size %d\n", db->size);
    return db->size;
}

//this function currently segfaults
//function will go until it finds an empty or NULL node and insert
//will navigate by going left is less than or right if greater than current node
StudentDB * insertRecursively(StudentDB * db, StudentDB *s)
{
        //db->size++;
        printf("inserting student %d\n", s->current->id);
        printf("running\n");
        if(db == NULL || db->current == NULL)
        {
            printf("here1\n");
            db->current = s->current;
            db->size++;
            return db;
        }
        else if(s->current->id < db->current->id)
        {
            db->size++;
            printf("here2\n");
            db = db->left;
            insertRecursively(db, s);
        }
        else if(s->current->id >= db->current->id)
        {
            db->size++;
            printf("here3");
            db = db->right;
            insertRecursively(db, s);
        }
        return db;
}

// O(log(n))
//insert student funciton that calls the recrusive function to inser
int insertStudent(StudentDB *db, Student *s)
{
    StudentDB * temp = createDatabase();
    temp->current = s;
    if(db != NULL)
    {
        printf("new is %d\n",temp->current->id);
        db = insertRecursively(db,temp);
        printf("Done\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

// O(n)
//fucntion goes through every node starting at the left node and prints in ascending order
void printDB(StudentDB *db)
{
    if(db == NULL){return;}
    printDB(db->left);
    printf("%d\n", db->current->id);
    printDB(db->right);
}

// O(log(n))
//funciton searches the database and finds the id in o log n
Student * getStudent(StudentDB *db, int id)
{
    if(db == NULL || db->current == NULL)
    {
        printf("not found\n");
        return NULL;
    }
    else if(id == db->current->id)
    {
        printf("found\n");
        return db->current;
    }
    else if(id < db->current->id)
    {
        printf("still looking\n");
        db = db->left;
        getStudent(db,id);
    }
    else
    {
        printf("still looking\n");
        db = db->left;
        getStudent(db, id);
    }
    return NULL;
}

// O(log(n))
//function goes all the way left to find min node
Student * getMin(StudentDB *db)
{
    if(db == NULL)
    {
        return NULL;
    }
    while(db->right != NULL)
    {
        getMax(db->right);
    }
    printf("Min is %d\n", db->current->id);
    return db->current;
}

// O(log(n))
//function goes all the way right to find max node
Student * getMax(StudentDB *db)
{
    if(db == NULL)
    {
        return NULL;
    }
    while(db->left != NULL)
    {
        getMax(db->left);
    }
    printf("Max is %d\n", db->current->id);
    return db->current;
}

// O(n)
//function goes through whole database and frees
void freeDatabase(StudentDB *db)
{
    if(db->current == NULL)
    {
        free(db);
        return;
    }
    freeDatabase(db->left);
    freeDatabase(db->right);
    free(db->current);
}

/*int main(void)
{
    StudentDB * root;
    root = createDatabase();
    Student * student1;
    student1 = malloc(sizeof(Student));
    student1->id = 10;
    printf("here %d\n", student1->id);

    Student * student2;
    student2 = malloc(sizeof(Student));
    student2->id = 4;

    Student * student3;
    student3 = malloc(sizeof(Student));
    student3->id = 12;
    insertStudent(root,student1);
    insertStudent(root,student2);
    //insertStudent(root,student3);
    getSize(root);
    printDB(root);
    getMax(root);
    getMin(root);
    getStudent(root,4);
}*/