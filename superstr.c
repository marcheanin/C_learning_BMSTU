#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substring(char *string, int position, int length){
   char *p;
   int c;
   p = malloc(length+1);
   for (c = 0; c < length; c++){
      *(p + c) = *(string + position);
      string++;
   }
   *(p + c) = '\0';
   return p;
}

int count_diff(char *a, char *b){
    int n = strlen(a), m = strlen(b);
    if (m == 0 || n == 0) return m;
    int len = 0;
    for (int i = n - 1, j = 0; i >= 0, j < m; i--, j++){
        if(strcmp(substring(a, i, n - i), substring(b, 0, j + 1)) == 0){
            len = j + 1;
        }
    }
    return m - len;
}

long res = 0;

void per(int diffs[10][10], int used[], long cur, int k, int n, int last){
    if (k >= n){
        //printf("%s\n", res);
        if (res == 0 || res > cur){
            res = cur;
        }
        return;
    }
    char* t;
    for (int i = 0; i < n; i++){
        if (!used[i]){
            used[i] = 1;
            if (last == -1) per(diffs, used, diffs[i][i], k + 1, n, i);
            else per(diffs, used, cur + diffs[last][i], k + 1, n, i);
            //printf("%s\n", res);
            used[i] = 0;
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    char **s;
    s = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++){
        s[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", s[i]);
    }
    int diffs[10][10];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j){
                diffs[i][j] = count_diff(s[i], s[j]);
            }
            else diffs[i][j] = strlen(s[i]);
            printf("%d ", diffs[i][j]);
        }
        printf("\n");
    }

    int used[10] = {};
    per(diffs, used, 0, 0, n, -1);
    printf("%ld", res);
    free(s);
}

/*
3
caacccca
accaacccc
cabaccaac

13

5
bba
babccaab
abccaabac
aabacacab
acabaab

18

10
acbabcaac
cbca
bbaa
bcacaab
acbcccab
bcbcbab
bbbccbabca
accccabba
cbaca
accaabaaab

60
*/
