#include <stdio.h>

int main(int argc, char ** argv) {
    unsigned long long a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);
    unsigned long long x = b;
    unsigned long long s[200];
    unsigned long long k = 0;
    while(x){
        s[k] = x % 2;
        x /= 2;
        k++;
    }

    unsigned long long res = a * s[k - 1];
    //printf("%ld ", k);
    for (int i = 0; i <= k - 2; i++){
        res  = (res % m) * 2;
        res = (res % m) + ((a * s[k - i - 2]) % m);
    }
    printf("%lld", res % m);
    return 0;
}
