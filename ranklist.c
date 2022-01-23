#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define SSIZE 7
#define VSIZE 10
#define ELEM struct elem

ELEM {
        int k;
        char *v;
        unsigned short *span;
        ELEM **next;
};

ELEM* initSkipList(int m)
{
        ELEM *l = calloc(1, sizeof(ELEM));
        l->next = malloc(m * sizeof(ELEM*));
        l->span = calloc(m, sizeof(unsigned short));
        unsigned int i;
        for (i = 0; i < m; i++)
                l->next[i] = NULL;
        return l;
}

ELEM* succ(ELEM* x)
{
        return x->next[0];
}

ELEM** skip(ELEM *l, int m, int k, ELEM **p)
{
        ELEM *x = l;
        int i;
        for (i = m - 1; i >= 0; i--) {
                while(x->next[i] != NULL && x->next[i]->k < k) {
                        x = x->next[i];
                }
                p[i] = x;
        }
        return p;
}

char* lookup(ELEM *l, int m, int k, ELEM **p)
{
        skip(l, m, k, p);
        ELEM *x = succ(p[0]);
        return x->v;
}

void insert(ELEM *l, int m, int k, ELEM *x, ELEM **p, unsigned short *rankarray)
{
        ELEM *f = l;
        int i;
        for (i = m - 1; i >= 0; i--) {
                rankarray[i] = i == m - 1 ? 0 : rankarray[i+1];
                while(f->next[i] != NULL && f->next[i]->k < k) {
                        rankarray[i] += f->span[i];
                        f = f->next[i];
                }
        }
        p = skip(l, m, k, p);

        x->next = malloc(m * sizeof(ELEM*));
        x->span = calloc(m, sizeof(unsigned short));
        int r = rand() << 1;
        for(i = 0; i < m && !(r & 1); i++) {
                x->next[i] = p[i]->next[i];
                p[i]->next[i] = x;
                unsigned short temp = rankarray[0] - rankarray[i];
                x->span[i] = p[i]->span[i] - temp;
                p[i]->span[i] = temp + 1;
                r >>= 1;
        }
        while(i < m) {
                ++p[i]->span[i];
                x->next[i++] = NULL;
        }
}

void delete(ELEM *l, int m, int k, ELEM **p) {
        p = skip(l, m, k, p);
        ELEM *x = succ(p[0]);
        unsigned int i;
        for(i = 0; i < m && p[i]->next[i] == x; i++) {
                p[i]->span[i] += x->span[i] - 1;
                p[i]->next[i] = x->next[i];
        }
        while(i < m)
                --p[i]->span[i++];
}

int rank(ELEM *l, int m, int k)
{
        ELEM *x = l;
        int i, result = 0;
        for (i = m - 1; i >= 0; i--)
                while(x->next[i] != NULL && x->next[i]->k < k) {
                        result += x->span[i];
                        x = x->next[i];
                }
        return result;
}

int main() {
        unsigned int n;
        scanf("%d", &n);
        int m = log2(n);
        ELEM *l = initSkipList(m);
        ELEM *a = malloc(n * sizeof(ELEM));
        unsigned short* rankarray = malloc(m * sizeof(unsigned short));
        ELEM **p = malloc(m * sizeof(ELEM*));

        char s[SSIZE];
        srand(time(NULL));
        int k;
        unsigned int i, j;
        for(i = 0, j = 0; i < n; i++) {
                scanf("%s", s);
                if(!strcmp("INSERT", s)) {
                        char v[VSIZE];
                        scanf("%d %s", &k, v);
                        a[j].v = malloc((strlen(v) + 1) * sizeof(char));
                        strcpy(a[j].v, v);
                        a[j].k = k;
                        insert(l, m, k, &a[j++], p, rankarray);
                        continue;
                }
                if(!strcmp("LOOKUP", s)) {
                        scanf("%d", &k);
                        printf("%s\n", lookup(l, m, k, p));
                        continue;
                }
                if(!strcmp("DELETE", s)) {
                        scanf("%d", &k);
                        delete(l, m, k, p);
                        continue;
                }
                if(!strcmp("RANK", s)) {
                        scanf("%d", &k);
                        printf("%d\n", rank(l, m, k));
                }
        }

        for(i = 0; i < j; i++) {
                free(a[i].v);
                free(a[i].next);
                free(a[i].span);
        }
        free(rankarray);
        free(p);
        free(l->next);
        free(l->span);
        free(l);
        free(a);
        return 0;
}
