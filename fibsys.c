#include <stdio.h>

void fib_sys(long long x, long long s[], long long fib[]){
    for (int i = 89; i >= 0; i--){
        if (fib[i] <= x && s[i + 1] != 1 && s[i - 1] != 1){
            s[i] = 1;
            fib_sys(x - fib[i], s, fib);
            //printf("%lld\n", fib[i]);
            return;
        }
    }
}

int main(){
    long long x;
    scanf("%lld", &x);
    long long fib[1000];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 90; i++){
        fib[i] = fib[i - 2] + fib[i - 1];
    }
//    for (int i = 0; i < 90; i++){
//        printf("%lld ", fib[i]);
//    }
    //printf("\n");
    long long s[100];
    for (int i = 0; i < 100; i++){
        s[i] = 0;
    }
    fib_sys(x, s, fib);
    for (int i = 0; i < 90; i++){
        printf("%lld", s[i]);
    }
    return 0;
}
