#include <stdio.h>
#include <math.h>

int main(){
    long long x;
    scanf("%lld", &x);
    if (x < 0) x *= -1;
    long n = x;
    for (long long i = 2; i <= sqrt(n); i++){
        //printf("%lld %lld\n", i, x);
        if (i == x){
            printf("%lld", x);
            return 0;
        }
        if (x % i == 0){
            x /= i;
            i--;
        }
    }
}
