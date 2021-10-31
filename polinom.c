#include <stdio.h>

long long gorner_count(long long s[], long long x0, long long n){
    long long res = s[0];
    for (int i = 0; i < n; i++){
        res *= x0;
        res += s[i + 1];
    }
    return res;
}

int main(int argc, char ** argv) {
    long long x0, s[10000], n;
    scanf("%lld%lld", &n, &x0);
    for (int i = 0; i < n + 1; i++){
        scanf("%lld", &s[i]);
    }
    long long res1 = gorner_count(s, x0, n);
    printf("%lld\n", res1);

    long long s1[10000];
    for(int i = 0; i < n + 1; i++){
        s1[i] = s[i] * (n - i);
    }
    long long res2 = gorner_count(s1, x0, n - 1);
    printf("%lld\n", res2);
    return 0;
}
