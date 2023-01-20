#include "lab7.h"

Node * makeList()
{
    //allocate memory for dummy node
    Node * head;
    head = malloc(sizeof(Node));

    //if there is memory return the pointer if not return NULL
    if (head)
    {
        head->data = NULL;
        head->next = NULL;
        return head;
    }
    else
    {
        return NULL;
    }
}

int getSize(Node *head)
{
    //temp node so we dont change head on accident
    Node * temp = head->next;

    //traverse through list while temp isn't NULL and add to length, when temp is NULL that means we are at the end and we can return the lenght
    int length;
    for(length = 0; temp != NULL; length++)
    {
        temp = temp->next;
    }
    return length;
}

int insertAtIndex(Node *head, void *data, int index)
{
    //allocate memory for the node we are inserting
    Node * insert;
    insert = malloc(sizeof(Node));
    if(!insert){return 1;}//NULL check

    //initialize the varibales in new node
    insert->data = data;
    insert->next = NULL;

    //go through list until we reach our index and then insert our new node we made
    int count = 0;
    while(head != NULL)
    {
        if(count == index)
        {
            insert->next = head->next;
            head->next = insert;
            return 0;
        }
        count++;
        head = head->next;
    }
    return 1;
}

void * removeFromHead(Node *head)
{
    //temp node to hold the first node in our list
    Node * temp = head->next;
    if(!temp){return NULL;}//if there is no node return NULL

    //remove the node and free it, return the data from that node
    head->next = temp->next;
    void * tempData = temp->data;
    free(temp);
    return tempData;
}

void * getAtIndex(Node *head, int index)
{
    //temp node for the first element (which is 0)
    Node * temp = head->next;

    //go through list until we reach our index and return the data, if index is too large it'll return NULL
    int count = 0;
    while(temp != NULL)
    {
        if(count == index)
        {
            return temp->data;
        }
        if(temp->next == NULL){return NULL;}
        count++;
        temp = temp->next;
    }
    return NULL;
}

void freeList(Node *head)
{
    //temp node so we can free after we change next pointers
    Node * temp;

    //go through list freeing each element
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}