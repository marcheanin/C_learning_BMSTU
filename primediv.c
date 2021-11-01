#include <stdio.h>
#include <math.h>

int main(){
    long x;
    scanf("%ld", &x);
    long n = abs(x);
    x = abs(x);
    for (long i = 2; i <= n; i++){
        if (i == x){
            printf("%ld", x);
            return 0;
        }
        if (x % i == 0){
            x /= i;
            i--;
        }
    }
}
