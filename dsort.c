#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//код презентации, ничего более придумать не могу

void dsort(char* str) {
    unsigned int count[26] = {0};
    int j = 0;
    while (str[j] != '\0') {
        count[str[j] - 'a']++;
        j++;
    }
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
