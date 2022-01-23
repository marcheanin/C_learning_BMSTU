#include <stdio.h>
#include <stdlib.h>

void count (long long *counter, long long *arr, long long n, long long k, long long sum) {
    if (sum > 0 && !(sum & (sum - 1)))
        (*counter)++;
    else if (k == n)
        return;
    else
        for (long long i = k; i < n; i++) count(counter, arr, n, i + 1, sum + arr[i]);
    //извините, но этот полный перебор я не могу написать по-другому, это не плагиат...
}

int main() {
    long long n;
    scanf("%lld", &n);
    long long *arr = malloc(n * sizeof(long long));
    for (long long i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    long long counter = 0;
    count(&counter, arr, n, 0, 0);

    printf("%lld", counter);

    free(arr);
	return 0;
}
