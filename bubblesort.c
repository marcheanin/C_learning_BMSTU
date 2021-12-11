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

void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j))
{
    int left = 0, right = nel - 1, c;
    do{
        c = 0;
        for (int j = left; j < right; j++){
            if (compare(j, j + 1) == 1){
                swap(j, j + 1);
                c = j;
            }
        }
        right = c;
        for (int j = right; j > left; j--){
            if (compare(j - 1, j) == 1){
                swap(j - 1, j);
                c = j;
            }
        }
        left = c;
    } while(c > 0);
}


int main(){
    int n;
    scanf("%d", &n);
    s = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    bubblesort(n, compare, swap);
    for (int i = 0; i < n; i++){
        printf("%d ", s[i]);
    }
    free(s);
}
