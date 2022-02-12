#include <stdio.h>
#include "bloom.h"
#include "bloomTree.c"
#include "bestLevel.c"
#include "doubly_linked_list.h"
#include "sampleMultipleFromTree.c"

extern int VECT_SIZE;
extern int levelThreshold;


int main(int argc, char** argv) {

    struct bloom *mainFilter;
    struct bloomTree *rooted;

    array* list = (array*) malloc(sizeof(array));

    int m = 40000;
    int n = 100;

    VECT_SIZE = m;

    long int M = 20000;
    int numSamples = 1;

    levelThreshold = bestLevel(m, n, M);

    seiveInitial();

    mainFilter = (struct bloom *) malloc(sizeof(struct bloom));
    mainFilter->bloom_vector = (int *) malloc(sizeof(int) * (m / NUM_BITS + 1));

    int i;
    for (i = 0; i < n; i++) {
        int v = rand() % M;
        insert(v, mainFilter);
        add(list, v);
        v = rand() % M;
    }


    rooted = getBloomTree(1, M);

    int* result2 = samplesFromTree(mainFilter, rooted, 10);
    printf("\nResult:%d", result2);
}