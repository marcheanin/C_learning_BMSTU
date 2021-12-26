#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long n, t[4000000];

int min(int a, int b){
    if (a < b) return a;
    return b;
}

int max(int a, int b){
    if (a > b) return a;
    return b;
}

void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}

int get_max(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return max(get_max(v*2, tl, tm, l, min(r,tm)), get_max(v*2+1, tm+1, tr, max(l,tm+1), r));
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v * 2, tl, tm, pos, new_val);
		else
			update (v * 2 + 1, tm + 1, tr, pos, new_val);
		t[v] = max(t[v * 2], t[v * 2 + 1]);
	}
}


int main(){
    scanf("%lld", &n);
    int* s = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    build(s, 1, 0, n - 1);
    int m;
    scanf("%d", &m);
    char a[5];
    int x, y;
    for (int j = 0; j < m; j++){
        scanf("%s%d%d", &a, &x, &y);
        //printf("%s %d %d\n", a, x, y);
        if (strcmp(a, "MAX") == 0){
            printf("%d\n", get_max(1, 0, n - 1, x, y));
        }
        else{
            update(1, 0, n - 1, x, y);
        }
    }
    return 0;
}
