#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *s;

void swap(unsigned long i, unsigned long j){
    long t = s[i];
    s[i] = s[j];
    s[j] = t;
}

int compare(unsigned long i, unsigned long j){
    if (s[i] < s[j]){
        return -1;
    }
    else if (s[i] == s[j]) return 0;
    return 1;
}

void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    if (nel == 1) return;
    int a = 1, b = 1, size_d = 0;
    for (;b < nel; size_d++){
        int c = b;
        b += a;
        a = c;
    }
    int *d = (int*)malloc(sizeof(int) * size_d);
    a = 1, b = 1;
    for (int i = 0; b < nel; i++) {
        int c = b;
        b = a + b;
        a = c;
        d[i] = a;
    }
    for (int k = size_d - 1; k >= 0; k--) {
        //printf("%d\n", d);
        for (int i = 0; i < nel; i++)
            for (int j = i - d[k]; j >= 0 && compare(j, j + d[k]) == 1; j -= d[k])
                swap(j, j + d[k]);
    }
    free(d);
}

int main(){
    int n;
    scanf("%d", &n);
    if (n == 0) return 0;
    s = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    shellsort(n, compare, swap);
    for (int i = 0; i < n; i++){
        printf("%d ", s[i]);
    }
    free(s);
}

/*
30
2
3
5
32
23
3
33
3
2
3
32
34
3
2
3
32
32
2
2
2
24
2
3
434
53
2
2
34
33
3
*/
