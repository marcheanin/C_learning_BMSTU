#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int nel, ind;
	int* value;
} elem_t;

typedef struct {
        elem_t* heap;
	int cap, count;
} queue_t;

queue_t initPriorityQueue(int n)
{
	queue_t q;
	q.heap = (elem_t*)malloc(n * sizeof(elem_t));
	q.cap = n;
	q.count = 0;
	return q;
}

void swap(elem_t *a, elem_t *b)
{
	elem_t c = *a;
	*a = *b;
	*b = c;
}

int compare(elem_t a, elem_t b)
{
        return a.value[a.ind] > b.value[b.ind];
}

void insert(queue_t *q, elem_t x)
{
	int i = q->count;
	q->count = i + 1;
	q->heap[i] = x;
	while(i > 0 && compare(q->heap[(i - 1)/2],q->heap[i])) {
		swap(&(q->heap[(i - 1)/2]), &(q->heap[i]));
		i = (i - 1)/2;
	}
}

void heapify(elem_t *base, int nel, int i,
        int (*compare)(elem_t a, elem_t b))
{
        int l, r, j;
        for(;;) {
                l = 2 * i + 1, r = l + 1, j = i;
                if(l < nel && compare(base[i], base[l])) i = l;
                if(r < nel && compare(base[i], base[r])) i = r;
                if (i == j) break;
                swap(&base[i], &base[j]);
        }
}

elem_t extraxtMax(queue_t *q)
{
	elem_t x = q->heap[0];
	q->count--;
	if(q->count > 0) {
		q->heap[0] = q->heap[q->count];
		heapify(q->heap, q->count, 0, compare);
	}
	return x;
}

char queueEmpty(queue_t q)
{
	return q.count == 0;
}

int main()
{
	unsigned int k, i, j, n = 0;
	scanf("%d", &k);
	int** arr = (int**)malloc(k * sizeof(int*));
	unsigned int* lens = (unsigned int*)malloc(k * sizeof(unsigned int));
	for(i = 0; i < k; i++) {
		scanf("%d", &lens[i]);
		n += lens[i];
	}
	for(i = 0; i < k; i++) {
		if(!lens[i])
			continue;
		arr[i] = (int*)malloc(lens[i] * sizeof(int));
		for(j = 0; j < lens[i]; j++)
			scanf("%d", &(arr[i][j]));
	}
	queue_t q = initPriorityQueue(k);
	for(i = 0; i < k; i++) {
		if(!lens[i])
			continue;
		elem_t x;
		x.nel = lens[i];
		x.value = arr[i];
		x.ind = 0;
		insert(&q, x);
	}
	while(!queueEmpty(q)) {
		elem_t temp = extraxtMax(&q);
		printf("%d ", temp.value[temp.ind]);
		int ind = ++temp.ind;
		if(ind < temp.nel) {
			temp.value[temp.ind] = temp.value[ind];
			insert(&q, temp);
		}
	}
	printf("\n");
	free(q.heap);
	for(i = 0; i < k; i++)
        	if(lens[i]) free(arr[i]);
	free(arr);
	free(lens);
	return 0;
}
