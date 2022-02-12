//#include<bits/stdc++.h>
//#include <iostream>
//#include <fstream>
//#include <sstream>
#define _POSIX_C_SOURCE 199309L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include<string>
#include "bloomTree.c"
#include "bloom.h"
#include "bestLevel.h"
#include <time.h>

#define MAXCHAR 1000
//using namespace std;
int VECT_SIZE=1600;
int K=3;
int levelThreshold;
struct bloom * community;
struct bloom * shell;
int averageDegree;
int edge_in=0;
int edge_out;
char* fileName;
struct bloomTree* tree;

/*void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);

}*/


struct bloom * getBloomFilterNode(int nodeId,char *fileName){

FILE *file = fopen(fileName, "r");


    
    size_t n = 0;
    int c;

    if (file == NULL) return NULL; //could not open file
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    struct bloom * bloomFilter=(struct bloom *) calloc(1,sizeof(struct bloom));			  
    bloomFilter->bloom_vector = (int *) calloc((VECT_SIZE / NUM_BITS + 1),sizeof(int) );

	
    while ((c = fgetc(file)) != EOF) {
        	
		
		int curr_int=c-(int)'0';
                while((c = fgetc(file))!=32){
                    curr_int=10*curr_int+(c-(int)'0');

                }                
                

                
                
                if(nodeId==curr_int){
			
			int index=0;
			int sub_int=0;
			int negative=1; 
                	while((c = fgetc(file))!=10){
				
                             if(c==45){
				negative=-1;	
			     }else if(c!=32){
				sub_int=sub_int*10+(c-(int)'0');
			     }else{
					bloomFilter->bloom_vector[index]=sub_int*negative;
					//printf("%d ",(sub_int*negative) );
					sub_int=0;
					negative=1;
					
					index++;
				}
				if(c==EOF){
	                        break;
				}

                	}
                	
			return bloomFilter;
                	//init(bloomFilter);
		}else{
			while((c = fgetc(file))!=10){
                    	

                	}

		}
	

    }
return bloomFilter;
}


struct bloom * findShell(){
struct bloom * shellNew=(struct bloom *) calloc(1,sizeof(struct bloom));			  
shellNew->bloom_vector = (int *) calloc((VECT_SIZE / NUM_BITS + 1),sizeof(int) );
int k=(3*averageDegree)/2;

for(int i=0;i<k;i++){
int communityNode=sampleFromTree(community,tree,1);
struct  bloom *communityNodeFilter=getBloomFilterNode(communityNode,fileName);
  for (int j=0;j<k;j++){
int adjacentNode=sampleFromTree(communityNodeFilter,tree,1);
int shell=is_in(adjacentNode,community);


      if(shell==0){
	//elemsIntersection(shellBloomFilter,community,1,1);
	//struct  bloom *shellBloomFilter=getBloomFilterNode(adjacentNode,fileName);
	insert(adjacentNode,shellNew);
		
	}
   }
return shellNew;
}



return shellNew;
}


struct bloom * addToCommunity(int addNode){

	insert(addNode,community);
int k=(3*averageDegree)/2;
struct bloom * nodeFilter=getBloomFilterNode(addNode,fileName);
for(int i=0;i<k;i++){
int sample=sampleFromTree(nodeFilter,tree,1);
	if(is_in(sample,community)){

	}else{
	insert(sample,shell);
	printf("%d\n",sample);
	}
}

} 


void getCommunity(int seed){

insert(seed,community);
shell=findShell();
addToCommunity(77);


}



int main(int argc, char** argv){

int totalNodes=atoi(argv[1]);//total nodes in graph

VECT_SIZE=atoi(argv[2]);//bloom filter size

int elementsInOneFilter=atoi(argv[3]); //Maximum number of elements allowed to be inserted in one bloom filter

fileName=argv[4]; //file from which bloom filter is to be read to find bloom filter from corresponding node id
averageDegree=atoi(argv[5]);
edge_out=averageDegree;
srand(time(NULL));

seiveInitial();
levelThreshold=5;

tree=getBloomTree(1,totalNodes);//create bloom Tree
struct bloom * temp=getBloomFilterNode(1,fileName);//first argument is the nodeId of which bloomFilter is to be returned


community=(struct bloom *) calloc(1,sizeof(struct bloom));			  
community->bloom_vector = (int *) calloc((VECT_SIZE / NUM_BITS + 1),sizeof(int) );
/*
struct bloom * nodeFilter=getBloomFilterNode(2,fileName);
for (int i=0;i<((VECT_SIZE/NUM_BITS)+1);i++){
printf("%d ",count_ones(nodeFilter->bloom_vector[i]) );
}
printf("\n");
printf("%d\n",sampleFromTree(nodeFilter,tree,1));
*/
//getCommunity(1);


return 0;
}
