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
    int* mux = (int*)base;
    for (int i = 0; i < nel; i++){
        if (compare(base + i * width, mux) == 1) mux = base + i * width;
    }
    return *mux;
}

int main(){
    int s[10] = {1, 4, 7, 2, 5, 11, 5, 8, 3, 10};
    printf("%d", maxarray(s, 10, sizeof(int), compare));

}
