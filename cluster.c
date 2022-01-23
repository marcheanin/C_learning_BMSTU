#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int* heap;
	int cap, count;
} queue_t;

queue_t initPriorityQueue(int n)
{
	queue_t q;
	q.heap = (int*)malloc(n * sizeof(int));
	q.cap = n;
	q.count = 0;
	return q;
}
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int compare(int a, int b)
{
        return a > b;
}

void insert(queue_t *q, int x)
{
	int i = q->count;
	q->count = i + 1;
	q->heap[i] = x;
	while(i > 0 && compare(q->heap[(i - 1)/2],q->heap[i])) {
		swap(&(q->heap[(i - 1)/2]), &(q->heap[i]));
		i = (i - 1)/2;
	}
}

void heapify(int *base, int nel, int i,
        int (*compare)(int a, int b))
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

int extraxtMax(queue_t *q)
{
	int x = q->heap[0];
	q->count--;
	if(q->count > 0) {
		q->heap[0] = q->heap[q->count];
		heapify(q->heap, q->count, 0, compare);
	}
	return x;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	queue_t q = initPriorityQueue(N);
	int i, res = 0;
	for(i = 0; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		int p = t1 + t2;
		res = p > res ? p : res;
		insert(&q, p);
	}
	for(i = N; i < M; i++) {
		int p = extraxtMax(&q);
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		p = p < t1 ? t1 + t2 : p + t2;
		res = p > res ? p : res;
		insert(&q, p);
	}
	printf("%d\n", res);
	free(q.heap);
}
