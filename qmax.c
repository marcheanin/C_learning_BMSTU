#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 150000

typedef struct {
        int x, max;
} elem_t;

typedef struct {
        elem_t* data;
        int cap,  top1, top2;
} doubleStack_t;

doubleStack_t initDoubleStack(int n)
{
        doubleStack_t s;
        s.data = (elem_t*)malloc(n * sizeof(elem_t));
        s.cap = n;
        s.top1 = 0;
        s.top2 = n - 1;
        return s;
}

char stackEmpty1(doubleStack_t s)
{
        return s.top1 == 0;
}

char stackEmpty2(doubleStack_t s)
{
        return s.top2 == s.cap - 1;
}

void push1(doubleStack_t *s, int x)
{
        elem_t p = s->data[s->top1];
        if(stackEmpty1(*s))
                p.max = x;
        else {
                int prevmax = s->data[s->top1 - 1].max;
                p.max = x > prevmax ? x : prevmax;
        }
        p.x = x;
        s->data[s->top1] = p;
        s->top1++;
}

void push2(doubleStack_t *s, int x)
{
        elem_t p = s->data[s->top2];
        if(stackEmpty2(*s))
                p.max = x;
        else {
                int prevmax = s->data[s->top2 + 1].max;
                p.max = x > prevmax ? x : prevmax;
        }
        p.x = x;
        s->data[s->top2] = p;
        s->top2--;
}

elem_t pop1(doubleStack_t *s)
{
        s->top1--;
        return s->data[s->top1];
}

elem_t pop2(doubleStack_t *s)
{
        s->top2++;
        return s->data[s->top2];
}

doubleStack_t initQueueOnStack(int n)
{
        return initDoubleStack(n);
}

char queueEmpty(doubleStack_t s)
{
        return stackEmpty1(s) && stackEmpty2(s);
}

void enqueue(doubleStack_t *s, int x)
{
        push1(s, x);
}

elem_t dequeue(doubleStack_t *s)
{
        if(stackEmpty2(*s))
                while(!stackEmpty1(*s))
                        push2(s, pop1(s).x);
        return pop2(s);
}

int max(int a, int b)
{
        return a > b ? a : b;
}

int main()
{
        int n, i, j;
        scanf("%u", &n);
        doubleStack_t q = initQueueOnStack(STACKSIZE);
        for(i = 0; i < n; i++) {
                char s[6];
                scanf("%s", s);
                if(!strcmp("ENQ", s)) {
                        int x;
                        scanf("%d", &x);
                        enqueue(&q, x);
                        continue;
                }
                if(!strcmp("DEQ", s)) {
                        printf("%d\n", dequeue(&q).x);
                        continue;
                }
                if(!strcmp("EMPTY", s)) {
                        if(queueEmpty(q)) printf("true\n");
                        else printf("false\n");
                        continue;
                }
                if(!strcmp("MAX", s)) {
                        if(stackEmpty2(q)) {
                                printf("%d\n", q.data[q.top1 - 1].max);
                                continue;
                        }
                        if(!stackEmpty1(q) && !stackEmpty2(q))
                                printf("%d\n", max(q.data[q.top1 - 1].max, q.data[q.top2 + 1].max));
                        else
                                printf("%d\n", q.data[q.top2 + 1].max);
                }
        }
        free(q.data);
}
