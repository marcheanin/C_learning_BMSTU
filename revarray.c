#include <stdio.h>


void revarray(void *base, size_t nel, size_t width){
    for (void *i = base, *j =  base + (nel - 1) * width; i < j; i += width, j -= width){
        int x = *(int*)i;
        *(int*)i = *(int*)j;
        *(int*)j = x;
    }
}
int main(){
    int s[] = {1, 2, 3, 17, 4, 5, 6};
    int *a = s, n = 7;
    revarray(a, n, sizeof(int));
    for (int i = 0; i < 7; i++){
        printf("%d ", s[i]);
    }

}
