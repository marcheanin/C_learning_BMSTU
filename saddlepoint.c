#include <stdio.h>

long inf = 1e5;

int main(){
    int n, m, s[10][10], strokmax[10], stolbmin[10], strokkord[10], stolbkord[10];
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) stolbmin[i] = inf;
    for (int i = 0; i < n; i++) strokmax[i] = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &s[i][j]);
            if (s[i][j] < stolbmin[j]){
                stolbmin[j] = s[i][j];
                stolbkord[j] = j;
            }
            if (s[i][j] > strokmax[i]){
                strokmax[i] = s[i][j];
                strokkord[i] = i;
            }
        }
    }
//    for (int i = 0; i < n; i++){
//        printf("%d ", strokmax[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < m; i++){
//        printf("%d ", stolbmin[i]);
//    }
//    printf("\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (strokmax[i] == stolbmin[j]){
                printf("%d %d", strokkord[i], stolbkord[j]);
                return 0;
            }
        }
    }
    printf("none");
    return 0;
}


/*
3 4
10 11 7 13
1 2 5 3
14 15 8 16
*/
