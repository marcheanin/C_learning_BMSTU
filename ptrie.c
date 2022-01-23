#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SSIZE 7
#define VSIZE 100000

typedef struct node {
        struct node *parent;
        struct node **arcs;
        char endOfStringFlag;
        unsigned short count;
} node_t;

typedef struct {
        node_t *x;
        unsigned int i;
} funcRet_t;

void freeNode(node_t *x)
{
        free(x->arcs);
        free(x);
}

void freeTrie(node_t *t, unsigned char m)
{
        unsigned int i;
        node_t *x = t;
        for(i = 0; i < m; i++) {
                if(x->arcs[i] != NULL) freeTrie(x->arcs[i], m);
        }
        freeNode(t);
}

node_t* initNode(unsigned char m)
{
        node_t* p = malloc(1 * sizeof(node_t));
        p->count = 1, p->endOfStringFlag = 1, p->parent = NULL;
        p->arcs = malloc(m * sizeof(node_t*));
        unsigned int i;
        for(i = 0; i < m; i++) {
                p->arcs[i] = NULL;
        }
        return p;
}

unsigned int alphCode(char c)
{
        return c - 'a';
}

funcRet_t descend(node_t *t, char* k)
{
        node_t *x, *y;
        unsigned int i, len = strlen(k);
        for(x = t, i = 0; i < len; i++) {
                y = x->arcs[alphCode(k[i])];
                if(y == NULL) break;
                x = y;
        }
        funcRet_t f;
        f.x = x, f.i = i;
        return f;
}

void countIncrease(node_t *t, char *k)
{
        node_t *x;
        unsigned int i, len = strlen(k);
        for(x = t, i = 0; i < len; i++) {
                node_t *y = x->arcs[alphCode(k[i])];
                if(y == NULL) break;
                y->count++, x = y;
        }
}

void insert(node_t *t, char *k, unsigned char m)
{
        funcRet_t f = descend(t, k);
        node_t *x = f.x;
        unsigned int i = f.i, len = strlen(k);
        if(x->endOfStringFlag || i < len) countIncrease(t,k);
        for(; i < len; i++) {
                node_t *y = initNode(m);
                x->arcs[alphCode(k[i])] = y, y->parent = x, x = y;
        }
        x->endOfStringFlag = 0;
}

void countDecrease(node_t *x)
{
        if(x->parent!=NULL) {
                while(x->parent!=NULL) {
                        x->count--, x = x->parent;
                }
        }
}

void delete(node_t *t, char *k, unsigned char m)
{
        funcRet_t f = descend(t, k);
        node_t *x = f.x, *y;
        unsigned int i = f.i, j;
        x->endOfStringFlag = 1;
        while(x->parent != NULL && x->endOfStringFlag) {
                for(j = 0; j < m && x->arcs[j] == NULL; j++);
                if(j < m) break;
                y = x->parent;
                --i;
                y->arcs[alphCode(k[i])] = NULL;
                freeNode(x);
                x = y;
        }
        countDecrease(x);
}

unsigned short prefix(node_t *t, char *k)
{
        node_t *x;
        unsigned int i, len = strlen(k);
        for(x = t, i = 0; i < len; i++) {
                node_t *y = x->arcs[alphCode(k[i])];
                if(y == NULL) return 0;
                x = y;
        }
        return x->count;
}

int main()
{
        unsigned int n, i;
        char s[SSIZE], *k = calloc(VSIZE, sizeof(char));
        unsigned char m = 'z' - 'a' + 1;
        scanf("%u", &n);
        node_t *t = initNode(m);
        for(i = 0; i < n; i++) {
                scanf("%s %s", s, k);
                if(!strcmp("INSERT", s)) {
                        insert(t, k, m);
                }
                if(!strcmp("PREFIX", s)) {
                        printf("%u\n", prefix(t, k));
                }
                if(!strcmp("DELETE", s)) {
                        delete(t, k, m);
                }
        }
        free(k);
        freeTrie(t, m);
        return 0;
}
