#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dsort(char* str) {
    unsigned int count[26] = {0};
    char* p = str;
    while (*p != '\0') {
        count[*p - 'a']++;
        p++;
    }

    int *a = (int*)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++){
        a[i] += 4;
    }
    free(a);

    for (int i = 0; i < 26; ++i) {
        while (count[i]) {
            *str = (char)i + 'a';
            str++;
            count[i]--;
        }
    }
}

int main(){
    char* s;
    s = (char*)malloc(sizeof(char) * 2000000);
    scanf("%s", s);
    dsort(s);
    printf("%s", s);
    free(s);
}
