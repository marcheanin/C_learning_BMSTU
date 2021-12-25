#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dsort(char *s){
    for (int i = strlen(s) - 1; i >= 1; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (s[j] > s[j + 1])
            {
                char c = s[j];
                s[j] = s[j + 1];
                s[j + 1] = c;
            }
        }
    }
}

int main(){
    char* s;
    s = (char*)malloc(sizeof(char) * 1000000);
    scanf("%s", s);
    dsort(s);
    printf(s);
}
