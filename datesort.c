#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date{
    int Day, Month, Year;
};

int getKey(int key, struct Date date){
    if (key == 0) return date.Day - 1;
    if (key == 1) return date.Month - 1;
    return date.Year - 1970;
}

void datesort(int key, int m, struct Date *s, int n){
    int *count = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) count[i] = 0;

    for (int j = 0; j < n; j++){
        int k = getKey(key, s[j]);
        count[k]++;
    }
    for (int i = 1; i < m; i++){
        count[i] += count[i - 1];
    }

    struct Date *sorted = malloc(sizeof(struct Date) * n);
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
    struct Date *arr = malloc(n * sizeof(struct Date));
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &arr[i].Year, &arr[i].Month, &arr[i].Day);

    datesort(0, 31, arr, n);
    datesort(1, 12, arr, n);
    datesort(2, 2030 - 1970 + 1, arr, n);

    for (int i = 0; i < n; i++)
        printf("%d %02d %02d\n", arr[i].Year, arr[i].Month, arr[i].Day);

    free(arr);
}
