#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

int getKey(int key, union Int32 num) {
    if (key == 3)
        if (num.x < 0)
            return (int)num.bytes[key] - 128;
        else
            return 128 + (int)num.bytes[key];
    return num.bytes[key];
}

void radixsort(int key, int m, union Int32 *s, int n){
    int *count = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) count[i] = 0;

    for (int j = 0; j < n; j++){
        int k = getKey(key, s[j]);
        count[k]++;
    }
    for (int i = 1; i < m; i++){
        count[i] += count[i - 1];
    }

    union Int32 *sorted = malloc(sizeof(union Int32) * n);
    for (int j = n - 1; j >= 0; j--){
        int k = getKey(key, s[j]);
        int i = count[k] - 1;
        count[k] = i;
        sorted[i] = s[j];
    }
    for (int i = 0; i < n; i++){
        s[i] = sorted[i];
    }

    free(count), free(sorted);
}


int main(){
    int n;
    scanf("%d", &n);
    union Int32 *arr = malloc(n * sizeof(union Int32));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].x);
        memmove(arr[i].bytes, &arr[i].x, sizeof(int));
    }

    for (int i = 0; i < 4; i++)
        radixsort(i, 256, arr, n);

     for (int i = 0; i < n; i++)
        printf("%d ", arr[i].x);

    free(arr);
}
