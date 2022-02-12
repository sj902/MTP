//
// Created by Shubham  Jain on 12/04/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

#ifndef GCE_ADJACENCY_H
#define GCE_ADJACENCY_H


/*
This function returns an array containing the adjacent nodes of list
Param0 - File which contains adjacency list
Param1 - Node whose adjacent nodes have to be returned
 */
array* get_adjacency_list(char* arg_file_name, const char* arg_node_id)
{
    array* list = (array*) malloc(sizeof(array));
    FILE * file_pointer;
    char *word;
    char* nodes;

    //Initialise file pointer
    file_pointer = fopen (arg_file_name, "r");

    //While we reach end of file
    while(!feof(file_pointer)) {

        //Read first word of the line
        fscanf(file_pointer, "%s", word);

        //if the word is equal to the node Id provided, read word by word and add that to the list
        if(strcmp(word, arg_node_id) == 0)
        {
            fscanf(file_pointer, "%[^\n]", word);
            nodes = strtok (word," ,.-");
            while (nodes != NULL)
            {
                add(list, atoi(nodes));
                nodes = strtok (NULL, " ,.-");
            }
        }

            //else skip to next line
        else
        {
            fscanf(file_pointer, "%[^\n]\n", word);
        }
    }

    fclose(file_pointer);

    return list;
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

#endif //GCE_ADJACENCY_H
