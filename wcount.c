#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s){
    int ans = 0;
    for (int i = 0; i < strlen(s); i++){
        if (i == 0 && s[i] != ' ' || (s[i] != ' ' && s[i - 1] == ' ')){
            ans++;
        }
    }
    return ans;
}

int main(){
    char s[100];
    gets(s);
    //printf("%s\n", s);
    printf("%d", wcount(s));
