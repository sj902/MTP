#include <stdio.h>
#include <pthread.h>
#include "bloom.h"
#include "bloom.c"
#include <stdlib.h>
#include "bloomTree.c"
#include <math.h>

struct bloom *mainFilter;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

struct arguments {
    struct bloom *shell;
    struct bloom *community;
    struct bloomNode *node;
};


/**This function will return samples from the Bloom Tree**/
void* set_diff(void *arguments) {

    struct arguments *arg = arguments;

    struct bloom *shell = arg->shell;
    struct bloom *community = arg->community;
    struct bloomNode *node = arg->node;

    /**if leaf **/
    if ((!node->lchild) && (!node->rchild)) {
        double shell_elems = elemsIntersection(&(node->filter), shell, node->nOnes, 1);
        double community_elems = elemsIntersection(&(node->filter), community, node->nOnes, 1);
        int flag_shell = (shell_elems > 0) ? 1 : 0;
        int flag_community = (community_elems > 0) ? 1 : 0;

        if(!flag_shell)
        {
            return NULL;
        }

        else if (!flag_community) {
            int left = node->start;
            int right = node->end;
            struct bloom* temp;
            temp = (struct bloom *) malloc(sizeof(struct bloom));
            temp->bloom_vector = (int *) malloc(sizeof(int) * (VECT_SIZE / NUM_BITS + 1));
            init(temp);

            for(int i = left; i<= right; ++i){
                if(is_in(i, shell)) {
                    insert(i, temp);
                }
            }
            pthread_mutex_lock( &mutex1 );
            union_bloom(mainFilter, temp);
            pthread_mutex_unlock( &mutex1 );
        }

        else {
            int left = node->start;
            int right = node->end;
            struct bloom* temp;
            temp = (struct bloom *) malloc(sizeof(struct bloom));
            temp->bloom_vector = (int *) malloc(sizeof(int) * (VECT_SIZE / NUM_BITS + 1));
            init(temp);

            for(int i = left; i<= right; ++i){
                if(is_in(i, shell) && !(is_in(i, community))) {
                    insert(i, temp);
                }
            }
            pthread_mutex_lock( &mutex1 );
            union_bloom(mainFilter, temp);
            pthread_mutex_unlock( &mutex1 );

        }

    }

    else {

        double shell_elems = elemsIntersection(&(node->filter), shell, node->nOnes, 1);
        double community_elems = elemsIntersection(&(node->filter), community, node->nOnes, 1);

        int flag_shell = (shell_elems > 0) ? 1 : 0;
        int flag_community = (community_elems > 0) ? 1 : 0;

        if(!flag_shell)
        {
            return NULL;
        }

        else if (!flag_community) {
            int left = node->start;
            int right = node->end;
            struct bloom* temp;
            temp = (struct bloom *) malloc(sizeof(struct bloom));
            temp->bloom_vector = (int *) malloc(sizeof(int) * (VECT_SIZE / NUM_BITS + 1));
            init(temp);

            for(int i = left; i<= right; ++i){
                if(is_in(i, shell)) {
                    insert(i, temp);
                }
            }
            pthread_mutex_lock( &mutex1 );
            union_bloom(mainFilter, temp);
            pthread_mutex_unlock( &mutex1 );
        }

        else{
            struct arguments args;
            args.shell = shell;
            args.community = community;
            args.node = node->rchild;
            pthread_t tid;
            pthread_create(&tid, NULL, set_diff, (void *) &args);
            pthread_join(tid, NULL);

            struct arguments args1;
            args1.shell = shell;
            args1.community = community;
            args1.node = node->lchild;
            pthread_t tid1;
            pthread_create(&tid1, NULL, set_diff, (void *) &args1);
            pthread_join(tid1, NULL);

        }

    }
}


struct bloom *set_difference(struct bloom *shell,struct bloom *community, struct bloomTree *r) {

    mainFilter = (struct bloom *) malloc(sizeof(struct bloom));
    mainFilter->bloom_vector = (int *) malloc(sizeof(int) * (VECT_SIZE / NUM_BITS + 1));
    init(mainFilter);

    double lElems_shell = elemsIntersection(shell, &(r->left->filter),  r->left->nOnes, 1);
    double rElems_shell = elemsIntersection(shell, &(r->right->filter),  r->right->nOnes, 1);

    int flagL_shell = (lElems_shell > 0) ? 1 : 0;
    int flagR_shell = (rElems_shell > 0) ? 1 : 0;

    if(!flagL_shell && !flagR_shell)
        return NULL;

    else
    {

        struct arguments args;
        args.shell = shell;
        args.community = community;
        args.node = r->right;
        pthread_t tid;
        pthread_create(&tid, NULL, set_diff, (void *) &args);
        pthread_join(tid, NULL);



        struct arguments args1;
        args1.shell = shell;
        args1.community = community;
        args1.node = r->left;
        pthread_t tid1;
        pthread_create(&tid1, NULL, set_diff, (void *) &args1);
        pthread_join(tid1, NULL);
    }

    return mainFilter;
}


