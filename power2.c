#include <stdio.h>
#include <stdlib.h>

long long res = 0;

void count (long long *arr, long long n, long long k, long long sum) {
    if (sum > 0 && !(sum & (sum - 1)))
        res++;
    if (k >= n)
        return;
    for (long long i = k; i < n; i++) {
        count(arr, n, i + 1, sum + arr[i]);
    }
}

int main() {
    long long n;
    scanf("%d", &n);
    long long *arr = malloc(n * sizeof(long long));
    for (long long i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    count(arr, n, 0, 0);

    printf("%d", res);

    free(arr);
	return 0;
}
