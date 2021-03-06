#include <stdio.h>
#include "bloom.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "bloomTree.c"

extern int K;
extern int VECT_SIZE;

int main(int argc, char *argv[]) {


    if (argc < 4) {
        printf("Usage: ./bestLevel m n M");
        exit(0);
    }
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    int numSamples = atoi(argv[4]);

    K = 3;
    VECT_SIZE = m;

    long int M = atol(argv[3]);
    seiveInitial();

    struct bloom *k = (struct bloom *) malloc(sizeof(struct bloom));
    k->bloom_vector = (int *) malloc(sizeof(int) * (m / NUM_BITS + 1));

    struct bloom *l = (struct bloom *) malloc(sizeof(struct bloom));
    l->bloom_vector = (int *) malloc(sizeof(int) * (m / NUM_BITS + 1));


    srand(time(NULL));
    int val = rand() % M;

    int i;
    for (i = 0; i < n; i++) {
        int v = rand() % M;
        insert(v, k);
        v = rand() % M;
        insert(v, l);
    }

    double m_cost = 0, i_cost = 0;
    struct timespec start, finish;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < 1000; i++) {
        val = rand() % M;
        is_in(val, k);
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    m_cost += finish.tv_sec - start.tv_sec;
    m_cost += (finish.tv_nsec - start.tv_nsec) / pow(10, 9);
    m_cost /= 1000;

    int nk = num_ones(k), nl = num_ones(l);
    clock_gettime(CLOCK_MONOTONIC, &start);
    elemsIntersection(k, l, nk, nl);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    i_cost += finish.tv_sec - start.tv_sec;
    i_cost += (finish.tv_nsec - start.tv_nsec) / pow(10, 9);

    int totalLevels = 1;
    double nElems = M / 2;
    while (nElems > 0) {
        totalLevels += 1;
        nElems /= 2;
    }
    //printf("M = %ld, m_cost = %lf,i_cost = %lf, totalLevels = %d\n", M, m_cost, i_cost, totalLevels);
    struct bloomTree *rooted;

    nElems = M;
    int d = 1;
    while (nElems > 0) {
        double mem_cost = 0;
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (i = 0; i < nElems; i++) {
            val = rand() % M;
            is_in(val, k);
        }
        clock_gettime(CLOCK_MONOTONIC, &finish);
        nElems = M / pow(2, d);
        mem_cost += finish.tv_sec - start.tv_sec;
        mem_cost += (finish.tv_nsec - start.tv_nsec) / pow(10, 9);

        double int_cost = i_cost * 2 + (mem_cost / 2);
        if (mem_cost < int_cost) break;
        d = d + 1;
    }
    //printf("BEST LEVEL IS %d\n", d);
    levelThreshold = d;
    rooted = getBloomTree(1, M);

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < numSamples; ++i) {
        int r = sampleFromTree(l, rooted, numSamples);
        //printf("\n%d",r);
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    printf("\n%ld,%lf",
           numSamples, (((finish.tv_sec - start.tv_sec) * 1.0e3) + ((finish.tv_nsec - start.tv_nsec) / 1.0e6)));

}
