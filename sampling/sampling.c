#include <stdio.h>
#include "bloom.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "thpool.h"
#include "bloomTree.h"
#include <pthread.h>

extern int VECT_SIZE;


struct bloom *mainFilter;
struct bloomTree * rooted;

int main(int argc, char *argv[]){


    pthread_attr_t attr;
    // Initialize and set thread joinable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    if (argc < 5){
		printf("Usage: ./bestLevel m n M numberOfSamples");
		exit(0);
	}
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);


	VECT_SIZE = m;

	long int M = atol(argv[3]);
	seiveInitial();

	mainFilter = (struct bloom *)malloc(sizeof(struct bloom));
	mainFilter->bloom_vector = (int*)malloc(sizeof(int)*(m/NUM_BITS + 1));

	struct bloom *l = (struct bloom *)malloc(sizeof(struct bloom));
	l->bloom_vector = (int*)malloc(sizeof(int)*(m/NUM_BITS + 1));


	srand(time(NULL));
	int val = rand()%M;

	int i;
	for (i=0;i<n;i++){
		int v = rand()%M;
//printf("%d\n",v);
		insert(v,mainFilter);
		v = rand()%M;
		insert(v,l);
	}

	double m_cost = 0, i_cost=0;
	struct timespec start,finish;

	clock_gettime(CLOCK_MONOTONIC,&start);
	for (i=0;i<1000;i++){
		val = rand()%M;
		is_in(val,mainFilter);
	}
	clock_gettime(CLOCK_MONOTONIC,&finish);
	m_cost += finish.tv_sec - start.tv_sec;
	m_cost += (finish.tv_nsec - start.tv_nsec)/pow(10,9);
	m_cost /= 1000;

	int nk = num_ones(mainFilter), nl = num_ones(l);
	clock_gettime(CLOCK_MONOTONIC,&start);
	elemsIntersection(mainFilter,l,nk,nl);
	clock_gettime(CLOCK_MONOTONIC,&finish);
	i_cost += finish.tv_sec - start.tv_sec;
	i_cost += (finish.tv_nsec - start.tv_nsec)/pow(10,9);

	int totalLevels = 1;
	double nElems = M/2;
	while (nElems>0){
		totalLevels +=1;
		nElems /= 2;
	}
	//printf("M = %ld, m_cost = %lf,i_cost = %lf, totalLevels = %d\n",M,m_cost,i_cost,totalLevels);

	nElems = M;
	int d = 1;
	while (nElems > 0){
		nElems = M/pow(2,d);
		double mem_cost = m_cost*nElems;
		double int_cost = i_cost*(totalLevels - d) + m_cost;
		if (mem_cost < int_cost) break;
		d = d+1;
	}
	//printf("BEST LEVEL IS %d\n",d);
        levelThreshold=d;
        rooted=getBloomTree(1,M);         
        
        threadpool thpool = thpool_init(100);// 100 number of threads in a pool
        int numSamples=atoi(argv[4]);
	for (i=0; i<numSamples; i++){
		thpool_add_work(thpool, (void*)sampleFromTree, NULL);                		
	};
   sleep(50);
       thpool_destroy(thpool);
}
