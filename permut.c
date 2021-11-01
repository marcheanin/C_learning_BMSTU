#include <stdio.h>

int main(){
    long long a[8], b[8], check[8];
    for (int i = 0; i < 8; i++) check[i] = 0;
    for (int i = 0; i < 8; i++){
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < 8; i++){
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < 8; i++){
        int f = 0;
        for (int j = 0; j < 8; j++){
            if (a[i] == b[j] && check[j] != 1){
                check[i] == 1;
                f = 1;
                break;
            }
        }
        if (f == 0){
            printf("no");
            return 0;
        }
    }
    printf("yes");
    return 0;
}
