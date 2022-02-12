/**This file returns multiple elements sampled from the tree**/

#include <stdio.h>
#include <pthread.h>
#include "bloom.h"
#include <stdlib.h>
#include "bloomTree.c"
extern int K;
extern int VECT_SIZE;


struct bloom *mainFilter;
struct bloomTree * rooted;
#define HEADS 0
#define TAILS 1

/**This returns Heads or tails
 * Parameter:
 * probability - probability of getting a HEADS**/
int coinToss(float probability) {

    double random = rand() % 1000000 + 1; //Generate a random number

    if (probability * 1000000 < random) return TAILS;
    else return HEADS;
}


/**This function will return samples from the Bloom Tree**/
int *sampleValues(struct bloom *k, struct bloomNode *r, int noOfSampledElements) {
    /**if both the left and right children are empty,
     * then calculate **/
    if ((!r->lchild) && (!r->rchild)) {
        int i = 0, j;
        int numValues = r->end - r->start + 1;
        int *values = (int *) malloc(sizeof(int) * numValues);
        for (j = r->start; j <= r->end; j++) {
            if (is_in(j, k)) {
                values[i] = j;
                i++;
            }
        }

        /**if intersection is empty return -1**/
        if (i == 0) {
            free(values);
            int res = -1;
            return &res;
        }


        /**else find required random numbers and return them**/
        int *result = (int *) malloc(sizeof(int) * noOfSampledElements);

        for (int k = 0; k < noOfSampledElements; ++k) {
            int index = rand() % i;
            result[i + 1] = values[index];
        }
        free(values);

        return result;
    }


        /**if any of the children is non-empty,
         * then choose the next leaf according to probability as stated in paper (Pt.3 of algo)**/
    else {
        double lElems = elemsIntersection(&(r->lchild->filter), k, r->lchild->nOnes, noOfSampledElements);
        double rElems = elemsIntersection(&(r->rchild->filter), k, r->rchild->nOnes, noOfSampledElements);

        int flagL = (lElems > 0) ? 1 : 0;
        int flagR = (rElems > 0) ? 1 : 0;

        if ((flagL) && (!flagR))
            return sampleValues(k, r->lchild, noOfSampledElements); //if only left node has non-zero intersection
        if ((!flagL) && (flagR))
            return sampleValues(k, r->rchild, noOfSampledElements); //if only right node has non-zero intersection
        //if both have 0 intersection then return -1
        if ((!flagL) && (!flagR)) {
            int res = -1;
            return &res;
        }

        //refer to "Sampling multiple items" in 5.3 in paper
        double probability = lElems / (lElems + rElems);
        int noOfTails = 0;
        int *result;

        for (int i = 0; i < noOfSampledElements; ++i) {
            noOfTails += coinToss(probability);
        }


        int *lSample = sampleValues(k, r->lchild, noOfSampledElements - noOfTails);

        int *rSample = sampleValues(k, r->rchild, noOfTails);

        //if both return -1 then return -1
        if (*(lSample) == -1 && *rSample == -1) {
            int res = -1;
            return &res;
        } else if (*rSample == -1) return sampleValues(k, r->lchild, noOfTails);
        else if (*(lSample) == -1) return sampleValues(k, r->rchild, noOfSampledElements - noOfTails);
            //if both return some values, then concatenate and return the list of numbers
        else {
            result = (int *) malloc(noOfSampledElements * sizeof(int));
            for (int i = 0; i < noOfSampledElements - noOfTails; ++i)
                *(result + i) = *(lSample + i);
            for (int j = 0; j < noOfTails; ++j)
                *(result + j + noOfSampledElements - noOfTails) = *(rSample + j);
        }
        return result;
    }
}


int main(int argc, char *argv[]) {
    printf("inside main");
}
