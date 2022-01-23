#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long KMP_Subst(char *s, char *t, long *P, long len_S, long len_T){
	long q = 0, k = 0;
	while (k < len_T) {
		while ( (q > 0) && (s[q] != t[k]) )
			q = P[q - 1];
		if (s[q] == t[k])
			q++;
		if (q == 0){
			k = k - len_S + 3;
			return k;
		}
		k++;
	}
	return 0;
}

void Prefix(char *s, long *P, long length){
	P[0] = 0;
	long t = 0, i = 1;
	while (i < length){
		while( (t > 0) && (s[t] != s[i]) )
			t = P[t-1];
		if (s[t] == s[i])
			t++;
		P[i] = t;
		i++;
	}
}

int main(int argc, char **argv){
	long length_1 = strlen(argv[1]);
	long length_2 = strlen(argv[2]);
	long P[length_1];
	Prefix(argv[1], P, length_1);
	if (KMP_Subst(argv[1], argv[2], P, length_1, length_2) == 0)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
