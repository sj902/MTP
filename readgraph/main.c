#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

typedef struct node{
    int nodeId;
    vector edges;
} node;

node *readGraph(char *filename, int nVertices){
    node *g = (node*)malloc(sizeof(node)*nVertices);
    int i;
    for (i = 0; i < nVertices; i++){
        g[i].nodeId = i;
        vector_init(&(g[i].edges));
    }
    FILE *fp = fopen(filename,"r");
    char str[500];
    while (fgets(str,500,fp)){
        if (str[0]=='#') continue;
        char *tok = strtok(str,"\t");
        int u = atoi(tok);
        tok = strtok(NULL,"\t");
        int v = atoi(tok);
        if (u < nVertices && v < nVertices){
            vector_add(&(g[u].edges), v);
            vector_add(&(g[v].edges), u);
        }
    }
    fclose(fp);
    return g;
}


//This fn print a vector to a file
void print_to_file(node* list, char *path, int numVertices) {
    FILE *out_file;
    out_file = fopen(path, "w");
    if (out_file == NULL)
    {
        printf("Can't open file for writing.\n");
    }

    for(int i = 0; i< numVertices; ++i){
        fprintf(out_file,"%d", list[i].nodeId);
        for(int j = 0; j< list[i].edges.total; ++j){
            fprintf(out_file,"%s", " ");
            fprintf(out_file,"%d", list[i].edges.items[j]);
        }
        fprintf(out_file,"%s", "\n");
    }
    fclose(out_file);
}

//This fn populates a vector with adjacency list of a node read from file
void get_adjacency_list(int node, char *path, vector* result) {

    vector_init(result);

    FILE *in_file;
    int number1, ch, flag = 0;
    ch = 0;
    char str[4000];

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

            if (!fgets(buffer, sizeof buffer, in_file)) break;
                pbuff = buffer;
                while (1) {
                    if (*pbuff == '\n') break;
                    value = strtol(pbuff, &pbuff, 10);
                    vector_add(result, value);
                }
                return;
        }

        else{

            ch = getc(in_file);
            while((ch = fgetc(in_file))!=10)
            {
                printf("%c", ch);
            }
        }
        //ch = getc(in_file); //to check for eof
    }

    if(!flag) printf("\nNode not found.\n");
}



int main(int argc, char *argv[]) {

    int numVertices = 2391;

    int **mat = (int **)malloc(numVertices * sizeof(int *));
    for (int i=0; i<numVertices; i++)
        mat[i] = (int *)malloc(numVertices * sizeof(int));

    //int mat[numVertices][numVertices];


    for(int i = 0; i< numVertices; ++i){
        for(int j = 0; j< numVertices; ++j){
            mat[i][j] = 0;
        }
    }

    node* list = readGraph(argv[1], numVertices);

    for(int i = 0; i< numVertices; ++i){
        printf("\n%d - ", list[i].nodeId);
        for(int j = 0; j< list[i].edges.total; ++j){
            printf("%d  ", list[i].edges.items[j]);
        }
    }

    for(int i = 0; i< numVertices; ++i){
        for(int j = 0; j< list[i].edges.total; ++j){
            mat[list[i].nodeId][list[i].edges.items[j]]=1;
        }
    }


    //To print entire matrix
    /*for(int i = 0; i< numVertices; ++i){
        printf("\n");
        for(int j = 0; j< numVertices; ++j){
            printf("%d ",  mat[i][j]);
        }
    }*/

    printf("\n");

    for(int j = 0; j< numVertices; ++j)
        printf(" %d ",  mat[0][j]);

    return 0;
}