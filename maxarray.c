#include <stdio.h>

int compare(void* a, void* b) {
    int* x = (int*) a;
    int* y = (int*) b;
    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    return 0;
}

int maxarray(void *base, size_t nel, size_t width, int (*compare)(void *a, void *b)){
    void* mux = base;
    int pos;
    for (int i = 0; i < nel; i++){
        if (compare(base + i * width, base + pos * width) == 1){
            pos = i;
        }
    }
    return pos;
}

int main(){
    int s[10] = {1, 4, 7, 2, 11, 5, 5, 8, 3, 10};
    double a[10] =  { 7.7, 5.8, 3.2, 6.9, 1.1, 2.5, 9.3, 4.6, 8.4 };
    printf("%d\n", maxarray(s, 10, sizeof(int), compare));
    printf("%d", maxarray(a, 9, sizeof(double), compare));

}
