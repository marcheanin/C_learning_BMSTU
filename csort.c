#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *a, char *b){
    int n = strlen(a), m = strlen(b);
    if (n != m){
        if (n > m) return -1;
        return 1;
    }
    int pos = 0;
    while(a[pos] == b[pos] && pos < n){
        pos++;
    }
    if (pos == n) return 0;
    else {
        if (a[pos] > b[pos]) return -1;
        else return 1;
    }
}

void csort(char *src, char *dest){
    char **s;
    s = (char**)malloc(400 * sizeof(char*));
    char *sp;
    sp = strtok(src, " ");
    int pos = 0;
    while(sp){
        s[pos] = (char*)malloc(400 * sizeof(char));
        s[pos] = sp;
        sp = strtok(NULL, " ");
        pos++;
    }

    char** sorted = (char**)malloc(pos * sizeof(char*));
    int size_dest = 0;
    int k;
    for (int i = 0; i < pos; i++){
        size_dest += strlen(s[i]) + 1;
        k = 0;
        for (int j = 0; j < pos; j++){
            if (compare(s[i], s[j]) == -1){
                k++;
            }
        }
        sorted[k] = (char*)malloc(sizeof(char) * strlen(s[i]));
        sorted[k] = s[i];
        //printf("%d\n", k);
    }
    dest = (char*)malloc((size_dest + 1) * sizeof(char));
    strcpy(dest, "");
    for (int i = 0; i < pos; i++){
        strcat(dest, sorted[i]);
        if (i != pos - 1)
            strcat(dest, " ");
        //printf("%s ", sorted[i]);
    }
    printf("%s", dest);
    //dest[size_dest] = '\0';
    free(sorted);
}

int main(){
    char *str;
    str = (char*)malloc(sizeof(char) * 1000);
    gets(str);
    char *res;
    csort(str, res);
    //printf("%s", res);
}
