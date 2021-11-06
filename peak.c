#include <stdio.h>

long s[10] = {1, 2, 3, 4, 5, 4, 7, 8, 9, 10};
int elem = 7;

int less(unsigned long i, unsigned long j){
    if (s[i] < s[j])
        return 1;
    return 0;
}

unsigned long peak(unsigned long nel, int (*less)(unsigned long i, unsigned long j)){
    for (unsigned long i = 0; i < nel; i++){
        if ((i == 0 || (i > 0 && !less(i, i - 1))) && (i == nel - 1 || (i < nel - 1 && !less(i, i + 1))))
            return i;
    }
}

int main(){
    printf("%d", s[peak(10, less)]);
}
