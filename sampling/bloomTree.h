#include "bloom.h"
int levelThreshold;
struct bloomNode{
	struct bloom filter;
	int start;		/*starting vertex for this node*/
	int end;		/*ending vertex for this node*/
	struct bloomNode *lchild;
	struct bloomNode *rchild;
	int trueValue;	//TO BE DELETED
	int flag;
	int leafID;
        int sample;
        double prevEstimate;
	int level;
	int nOnes;
};

struct bloomTree{		/*The root level*/
	struct bloomNode* left;
	struct bloomNode* right;
};

struct bloomTree *getBloomTree(int startVertex, int endVertex);
void sampleFromTree();