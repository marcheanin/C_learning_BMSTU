#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix(char* s, int n, int* p) {
        p[0] = 0;
        int t = 0;
        for (int i = 1; i < n; i++){
                while ((t > 0) && (s[t] != s[i])) t = p[t - 1];
                if (s[t] == s[i]) t++;
                p[i] = t;
        }
}

int main(int argc, char** argv) {
        char *s = argv[1];
//        char s[123];
//        scanf("%s", s);
        int len = strlen(s);
        int p[len];
        prefix(s, len, p);
        prefix(s, len, p);
        for (int i = 1; i < len; i++) {
          int n = i + 1, k = (n / (n - p[i]));
          if ((n % (n - p[i])) == 0) {
            if (k >= 2) printf("%d %d\n", n, k);
          }
        }
    return 0;
}
