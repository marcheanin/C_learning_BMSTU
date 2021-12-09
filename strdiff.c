#include <stdio.h>
#include <string.h>

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

int strdiff(char *a, char *b)
{
        long count = 0;
        char q = 0;
        unsigned long n1 = strlen(a), n2 = strlen(b);
        for (int i = 0; i <= min(n1, n2); i++) {
          q = a[i] ^ b[i];
          if (q == 0) {
            count += 8;
          }
          else {
            for (int j = 0; j < 8; j++) {
              if ((q & 1) == 1) {
                return count;
              }
              else {
                count++;
                q = q >> 1;
              }
            }
          }
        }
        if ((n1 == n2) && (count == (n1 + 1) * 8)) {
          return -1;
        }
}

int main(int argc, char **argv)
{
        char s1[1000], s2[1000];
        gets(s1);
        gets(s2);
        printf("%d\n", strdiff(s1, s2));

        return 0;
}
