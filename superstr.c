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

char* concat(char a[], char b[]){
    int n = strlen(a), m = strlen(b);
    if (n == 0) return b;
    if (m == 0) return a;
    int pos = -1;
    for (int i = n - 1, j = 0; i >= 0, j < m; i--, j++){
        if (strcmp(substring(a, i, n - i), substring(b, 0, j + 1)) == 0){
            pos = j;
        }
    }
    char* t = (char*)malloc(sizeof(char) * n);
    strcpy(t, a);
    return strcat(t, substring(b, pos + 1, m - (pos + 1)));
}

char mux[1000] = "";

void per(char **s, int used[], char res[], int k, int n){
    if (k >= n){
        //printf("%s\n", res);
        if (strcmp(mux, "") == 0 || strlen(res) < strlen(mux)){
            strcpy(mux, res);
        }
        return;
    }
    char* t;
    for (int i = 0; i < n; i++){
        if (!used[i]){
            used[i] = 1;
            per(s, used, concat(res, s[i]), k + 1, n);
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

    int used[10] = {};
    char* res = "";
    //printf("%s\n", concat(s[0], s[1]));
    per(s, used, res, 0, n);
    //printf("%s\n", mux);
    printf("%d", strlen(mux));
}

/*
3
caacccca
accaacccc
cabaccaac

5
bba
babccaab
abccaabac
aabacacab
acabaab

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
*/
