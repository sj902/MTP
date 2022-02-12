#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"

void vector_init(vector *v)
{
    v->capacity = VECTOR_INIT_CAPACITY;
    v->total = 0;
    v->items = (int*)malloc(sizeof(int) * v->capacity);
}

int vector_total(vector *v)
{
    return v->total;
}

static void vector_resize(vector *v, int capacity)
{
    #ifdef DEBUG_ON
    printf("vector_resize: %d to %d\n", v->capacity, capacity);
    #endif

    int *items = realloc(v->items, sizeof(int) * capacity);
    if (items) {
        v->items = items;
        v->capacity = capacity;
    }
}

void vector_add(vector *v, int item)
{
    if (v->capacity == v->total)
        vector_resize(v, v->capacity * 2);
    v->items[v->total++] = item;
}

void vector_set(vector *v, int index, int item)
{
    if (index >= 0 && index < v->total)
        v->items[index] = item;
}

int vector_get(vector *v, int index)
{
    if (index >= 0 && index < v->total)
        return v->items[index];
    return -1;
}

void vector_delete(vector *v, int index)
{
    if (index < 0 || index >= v->total)
        return;

    v->items[index] = -1;

    for (int i = index; i < v->total - 1; i++) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = -1;
    }

    v->total--;

    if (v->total > 0 && v->total == v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}

void vector_free(vector *v)
{
    free(v->items);
}

int vector_isIn(vector *v, int x){
	int i;
	for (i = 0; i < v->total; i++)
		if (v->items[i] == x) return 1;
	return 0;
}

int vector_intersection(vector *u, vector *v){
	int i, j, nElems = 0;;
	for (i = 0; i < u->total; i++){
		for (j = 0; j < v->total; j++){
			if ((u->items[i] == v->items[j]) && (u->items[i] != -1))
				nElems += 1;
		}
	}
	return nElems;
}

int vector_getIndex(vector *v, int x){
	int i, index = -1;
	for (i = 0; i < v->total; i++){
		if (v->items[i] == x){
			index = i;
			break;
		}
	}
	return index;
}

void vector_remove(vector *v, int item){
	int index = vector_getIndex(v, item);
	if (index != -1) vector_delete(v, index);
}

vector vector_sample(vector *v, int numSamples){
	vector k;
	vector_init(&k);
	int i;


	for (i = 0; i < numSamples; i++){
		if (i >= v->total) return k;
		vector_add(&k, v->items[i]);
	}

	while (i < v->total){
		int j = rand()%i;
		if (j < numSamples){
			k.items[j] = v->items[i];
		}
		i += 1;
	}
	return k;
}
