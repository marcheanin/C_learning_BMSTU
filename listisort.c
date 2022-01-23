#include <stdio.h>
#include <stdlib.h>

typedef struct Elem {
    struct Elem *prev, *next;
    int v;
} elem_t;

elem_t* initDoubleLinkedList()
{
        elem_t* l = calloc(1, sizeof(elem_t));
	l->prev = l;
	l->next = l;
	return l;
}

void insertAfter(elem_t* x, elem_t* y)
{
	elem_t* z = x->next;
	x->next = y;
	y->prev = x;
	y->next = z;
	z->prev = y;
}

void delete(elem_t* x)
{
	elem_t *y, *z;
	y = x->prev;
	z = x->next;
	y->next = z;
	z->prev = y;
	x->prev = NULL;
	x->next = NULL;
}

void insertSort(elem_t* list)
{
	elem_t* el = list->next, *loc = el->prev;
        while(el != list) {
		while(loc!=list && el->v < loc->v)
			loc = loc->prev;
		delete(el);
		insertAfter(loc, el);
		el = el->next;
		loc = el->prev;
	}
}

int main()
{
	int i, n;
	scanf("%d", &n);
	elem_t* list = initDoubleLinkedList();
	elem_t* a = malloc(n * sizeof(elem_t));
	for(i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		a[i].v = v;
		insertAfter(list->prev, &a[i]);
	}
	insertSort(list);
	elem_t* el = list->next;
	while(el != list) {
		printf("%d ", el->v);
		el = el->next;
	}
	free(a);
	free(list);
	return 0;
}
