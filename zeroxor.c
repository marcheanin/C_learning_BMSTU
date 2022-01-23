#include <stdio.h>
#include <stdlib.h>
#define ELEM struct elem

ELEM {
        long xor;
        char count;
};

unsigned int zeroXorCount(long* a, unsigned int n)
{
        unsigned int i, j, result = 0;
        long hash, temp = 0;
        ELEM *arrxor = malloc(n * sizeof(ELEM));
        for(i = 0; i < n; i++) {
                arrxor[i].xor = -1, arrxor[i].count = 1;
        }
        for (i = 0; i < n; i++) {
                temp ^= a[i];
                hash = temp % n;
                for(j = hash;; j++) {
                        if(arrxor[j].xor == -1) {
                                arrxor[j].xor = temp;
                                if(!temp) {
                                        result += arrxor[j].count++;
                                }
                                break;
                        }
                        if(arrxor[j].xor == temp) {
                                result += arrxor[j].count++;
                                break;
                        }
                        if(j == n - 1) {
                                j = -1;
                        }
                }
        }
        free(arrxor);
        return result;
}

int main()
{
        unsigned int n, i;
        scanf("%u\n", &n);
        long *a = malloc(n * sizeof(long));
        for (i = 0; i < n; i++) {
                scanf("%ld", a + i);
        }
        printf("%u\n", zeroXorCount(a, n));
        free(a);
        return 0;
}
