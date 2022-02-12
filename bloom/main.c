#include <stdio.h>
#include "bloom.h"
#include <stdlib.h>
#include "set_difference.c"
#include "best_level.c"
#include <pthread.h>

extern int K;
extern int VECT_SIZE;
extern int levelThreshold;


int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: ./sampleMultipleFromTree m n M");
        exit(0);
    }
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    VECT_SIZE = m;

    long int M = atol(argv[3]);

    levelThreshold = best_level(m, n, M);
    levelThreshold = 5;

    seiveInitial();

    struct bloom *mainFilter;
    mainFilter = (struct bloom *) malloc(sizeof(struct bloom));
    mainFilter->bloom_vector = (int *) malloc(sizeof(int) * (m / NUM_BITS + 1));
    init(mainFilter);

    struct bloom *mainFilter2;
    mainFilter2 = (struct bloom *) malloc(sizeof(struct bloom));
    mainFilter2->bloom_vector = (int *) malloc(sizeof(int) * (m / NUM_BITS + 1));
    init(mainFilter2);

    struct bloomTree *rooted;
    rooted = getBloomTree(1, M);

    int i;
    for (i = 0; i < n; i++) {
        int v = rand() % M;
        insert(v, mainFilter);
        if(i%2)
            insert(v, mainFilter2);
        v = rand() % M;
    }

    printf("n:::%d\n", n);

    printf("MF : %f\n", elemsEst(mainFilter));

    printf("MF 2 : %f\n", elemsEst(mainFilter2));

    struct bloom *diff = set_difference(mainFilter, mainFilter2, rooted);

    printf("\nDiff : %f\n", elemsEst(diff));
}