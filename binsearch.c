#include <stdio.h>

int s[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int elem = 11;

int compare(unsigned long i){
    if (s[i] < elem){
        return -1;
    }
    else if (s[i] == elem){
        return 0;
    }
    return 1;
}

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)){
    int left = -1;
    int right = nel - 1, middle;
    while (right - left > 1){
        middle = (left + right) / 2;
        if (compare(middle) != -1)
            right = middle;
        else
            left = middle;
    }
    if (compare(right) == 0)
        return right;
    return nel;
}

int main(){
    printf("%d", binsearch(10, compare));
}
