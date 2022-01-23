#include <stdio.h>
#include <stdlib.h>

typedef struct List list;

struct List{
    int k;
    int v;
    list* next;
};

void printlist(list* t){
    printf("%d %d\n", t->k, t->v);
}

list* initlist(int k, int v){
    list* elem = malloc(sizeof(list));
    elem->k=k;
    elem->v=v;
    elem->next=NULL;
}




int checkempty(list* t){
    if (t->next==NULL)
        return 1;
    else
        return 0;
}

list* listsearch(list* t,int k){
    list* x =t->next;
    while (x!=NULL && x->k!=k){
        x=x->next;
    }

    return x;
}

void insertbeforehead(list* t, int y,int x){
    list* elem = malloc(sizeof(list));
    elem->k=y;
    elem->v=x;
    elem->next=t->next;

    t->next=elem;

}

int h(int x, int n){
    int result;
    result = abs(x)%n;
    return result;
}

void inithash(int n, list **t){
    int i;
    for (i=0;i<n;i++)
    {
        t[i] = initlist(0, 0);
    }
}

list* mapsearch(list** t, int k, int n){
    list* result;
    result = listsearch(t[h(k,n)],k);

    return result;
}

void freelist(list* t){
    list* b;
    b=t;
    while (b!=NULL){
        t = t->next;
        free(b);
        b = t;
    }
}


int main() {
    int i,n,m,firstdigit,seconddigit;
    char cmd[20];

    scanf("%d\n%d", &n, &m);

    list *ex[m],*buf;
    inithash(m,ex);

    for (i=0;i<n;i++){
        scanf("%s", cmd);


        switch(cmd[1]) {
            case 'T':
                scanf("%d", &firstdigit);
                buf = mapsearch(ex,firstdigit,m);
                if (buf==NULL)
                    printf("0\n");
                else
                    printf("%d\n",buf->v);
                break;
            case 'S':
                scanf("%d %d", &firstdigit, &seconddigit);
                if ((buf = mapsearch(ex,firstdigit,m))!=NULL)
                    buf->v=seconddigit;
                else
                    insertbeforehead(ex[h(firstdigit,m)], firstdigit,seconddigit);
                break;
        }
    }

    for(i=0;i<m;i++)
        freelist(ex[i]);



}
