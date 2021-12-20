#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char *concat(char **s, int n){
    int len = 0;
    for (int i = 0; i < n; i++) len += strlen(s[i]);
    len++;
    char *ans = (char*)malloc(len * sizeof(char));
    strcpy(ans, "");
    for (int i = 0; i < n; i++){
        strcat(ans, s[i]);
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    char **s;
    s = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++){
        s[i] = (char*)malloc(200 * sizeof(char));
        scanf("%s", s[i]);
        //scanf("%s", s[i]);
    }
    char* res = concat(s, n);
    printf("%s", res);

    free(s);
    return 0;
}
