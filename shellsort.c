#include <stdio.h>
#include <stdlib.h>

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
    int *d = (int*)malloc(sizeof(int) * nel);
    d[0] = 1, d[1] = 1;
    int k = 2;
    while(d[k - 1] + d[k - 2] < nel){
        d[k] = d[k - 1] + d[k - 2];
        k++;
    }
    for (int i = k - 1; i >= 0; i--){
        for (int j = 0; j < nel - d[i]; j++){
            int pos = j;
            while(pos >= 0 && compare(j, j + d[i]) == 1){
                swap(j, j + d[i]);
                pos--;
            }
        }
    }
//    for (int i = 1; i < nel; i++){
//        for (int j = i; j >= 1 && compare(j - 1, j) == 1; j--){
//            swap(j - 1, j);
//        }
//    }
    free(d);
}

int main(){
    int n;
    scanf("%d", &n);
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
