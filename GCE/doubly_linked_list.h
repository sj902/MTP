//
// Created by Shubham  Jain on 10/04/18.
//

#include <stdlib.h>

#ifndef GCE_DOUBLY_LINKED_LIST_H
#define GCE_DOUBLY_LINKED_LIST_H

typedef struct node{
    int item;
    struct  node* next;
    struct node* prev;
} node;

typedef struct array{
    int size;
    node* first;
    node* last;
}array;

//adds an item to end of the array
void add(array* arg_array,int arg_item){
    node* temp =(node*) malloc(sizeof(node));
    temp -> item = arg_item;
    temp -> next = NULL;
    temp -> prev = NULL;

    if(arg_array->size == 0)
    {
        arg_array -> first = temp;
        arg_array -> last = temp;
    }
    else
    {
        arg_array -> last -> next = temp;
        temp -> prev = arg_array -> last;
        arg_array -> last = temp;
    }

    arg_array -> size = arg_array -> size +1;

}

//Prints the entire list
void print_list(array* arg_array)
{
    if(arg_array == NULL || arg_array->size == 0)
    {
        printf("Empty");
        return;
    }

    node* n = arg_array->first;
    while(n != NULL)
    {
        printf("%d -> ", n -> item);
        n = n -> next;
    }
}


//Returns 1 if item is present in the list else 0
int contains(array* arg_array, int arg_item)
{
    if(arg_array == NULL || arg_array->size == 0)
    {
        return 0;
    }

    node* n = arg_array->first;
    while(n != NULL)
    {
        if(n-> item == arg_item)
        {
            return 1;
        }
        n = n -> next;
    }
    return 0;
}



/*
 * Working example
 * int main(int argc, char** argv) {
 * if(argc < 3) {
 * printf("Usage:\n ./GCE filename nodeId\n");
 * return 0;
 * }
 *
 * printf("Hello, World!\n");
 * print_list(get_adjacency_list(argv[1], argv[2]));
 * printf("\n");
 * }
 *
 * */

#endif //GCE_DOUBLY_LINKED_LIST_H
