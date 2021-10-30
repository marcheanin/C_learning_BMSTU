#include <stdio.h>

int main(int argc, char ** argv) {
    long a, b, m;
    scanf("%ld%ld%ld", &a, &b, &m);
    long x = b;
    int s[100];
    int k = 0;
    while(x){
        s[k] = x % 2;
        x /= 2;
        k++;
    }
    long res = a * s[k - 1];
    //printf("%ld ", k);
    for (int i = 0; i <= k - 2; i++){
        res *= 2;
        res = (res % m) + ((a * s[k - i - 2]) % m);
    }
    printf("%ld", res % m);
    return 0;
}
