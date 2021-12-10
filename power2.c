#include <stdio.h>
#include <stdlib.h>

int res = 0;

void count (int *arr, int n, int k, int sum) {
    if (sum > 0 && !(sum & (sum - 1)))
        res++;
    if (k >= n)
        return;
    for (int i = k; i < n; i++) {
        count(arr, n, i + 1, sum + arr[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    count(arr, n, 0, 0);

    printf("%d", res);

    free(arr);
	return 0;
}
