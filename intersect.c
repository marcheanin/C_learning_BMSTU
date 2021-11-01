#include <stdio.h>
#include <math.h>

int main(){
    long a = 0, b = 0;
    int n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        a += pow(2, x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d", &x);
        b += pow(2, x);
    }
    int s[32];
    for (int i = 0; i < 32; i++) s[i] = 0;
    for (int i = 31; i >= 0; i--){
        if (a >= pow(2, i) && b >= pow(2, i)){
            s[i] = 1;
            a -= pow(2, i);
            b -= pow(2, i);
        }
        else if (a >= pow(2, i)) a -= pow(2, i);
        else if (b >= pow(2, i)) b -= pow(2, i);
    }
    for (int i = 0; i < 32; i++){
        if (s[i] == 1){
            printf("%d ", i);
        }
    }
}
