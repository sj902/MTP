#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "vector.h"


//This fn print a vector to a file
void print_to_file(int node, vector *edges, char *path) {
    FILE *out_file;
    out_file = fopen(path, "a+");
    if (out_file == NULL)
    {
        printf("Can't open file for writing.\n");
    }

    fprintf(out_file,"%d", node);

    for(int i = 0; i< vector_total(edges); ++i){
        fprintf(out_file,"%s", " ");
        fprintf(out_file,"%d", vector_get(edges, i));
    }

    fprintf(out_file,"%s", "\n");
    fclose(out_file);
}


//This fn populates a vector with adjacency list of a node read from file
void get_adjacency_list(int node, char *path, vector* result) {

    FILE *in_file;
    int number1, ch, flag = 0;
    ch = 0;
    char str[2000];

    in_file = fopen(path, "r");

    if (in_file == NULL)
    {
        printf("Can't open file for reading.\n");
    }

    while(ch !=  EOF)
    {

        fscanf(in_file, "%d", &number1);

        if(node == number1)
        {
            flag = 1;
            char buffer[10000];
            char *pbuff;
            int value;

            while (1) {
                if (!fgets(buffer, sizeof buffer, in_file)) break;
                pbuff = buffer;
                while (1) {
                    if (*pbuff == '\n') break;
                    printf("%s\n", pbuff);
                    value = strtol(pbuff, &pbuff, 10);
                    vector_add(result, value);
                }
                return;
            }
        }

        else{
            fscanf(in_file,"%[^\n]", str);
        }
        ch = getc(in_file); //to check for eof
    }

    if(!flag) printf("\nNode not found.\n");
}







int main(int argc, char *argv[]) {

    if (argc < 1) {
        printf("Usage: ./ajd_list file");
        exit(0);
    }

    FILE *in_file;
    int number1, ch, node = -1, edge;
    vector vec;
    ch = 0;

    in_file = fopen(argv[1], "r");

    if (in_file == NULL)
    {
        printf("Can't open file 1 for reading.\n");
    }

    while(ch !=  EOF)
    {

        fscanf(in_file, "%d", &number1);

        fscanf(in_file, "%d", &edge);

        if(node == -1){
            node = number1;
            vector_init(&vec);
        }

        // If new node is encountered
        // Print vector to file
        // Create new vector
        if(number1 != node)
        {
            print_to_file(node, &vec, argv[2]);
            vector_init(&vec);
            node = number1;
        }

        // put edge in vector here
        vector_add(&vec, edge);

        ch = getc(in_file); //to check for eof
    }

    //to print last node
    print_to_file(node, &vec, argv[2]);

    fclose(in_file);

    printf("\nEnter node for which you need adjacency list:");
    scanf("%d", &node);

    vector result;
    vector_init(&result);
    get_adjacency_list(node, argv[2], &result);

    printf("res:::::\n");


    return 0;
}
