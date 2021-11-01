#include <stdio.h>
#include <math.h>

long long s[1000000];

int main(){
    long long n, k;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &s[i]);
    }
    scanf("%lld", &k);
    long long maxs = 0, t = 0;
    for (int i = 0; i < k; i++){
        maxs += s[i];
    }
    t = maxs;
    for (int i = 1; i <= n - k; i++){
        t -= s[i - 1];
        t += s[i + k - 1];
        //printf("%lld ", t);
        if (t > maxs) maxs = t;
    }
    printf("%lld", maxs);
}

/*
8
2 3 5 2 1 5 6 7
3
*/
