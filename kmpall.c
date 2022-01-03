#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *prefix_function (char *s) {
	int n = strlen(s);
	int *pi = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        pi[i] = 0;
	for (int i = 1; i < n; i++) {
		int j = pi[i -1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  j++;
		pi[i] = j;
	}
	return pi;
}

int main(int argc, char **argv){
    //char *str = argv[1];
    //char *str = (char*)malloc(sizeof(char) * 10000);
    //char *a = (char*)malloc(sizeof(char) * 10000);
    char *a = argv[1], *str = argv[2];
    //scanf("%s", a);
    //scanf("%s", str);
    char *s = (char*)malloc(sizeof(char) * 20000);
    strcpy(s, a);
    strcat(s, "#");
    strcat(s, str);
    int* prefix = prefix_function(s);
    for (int i = 0; i < strlen(s); i++){
        if (prefix[i] == strlen(a)){
            printf("%d ", (int)(i - 2 * strlen(a)));
        }
    }

    free(s), free(prefix);
    return 0;
}
