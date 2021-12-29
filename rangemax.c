#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long n, t[4000000];

long long min(long long a, long long b){
    if (a < b) return a;
    return b;
}

long long max(long long a, long long b){
    if (a > b) return a;
    return b;
}

void build (long long a[], long long v, long long tl, long long tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		long long tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}

long long get_max(long long v, long long tl, long long tr, long long l, long long r) {
	if (l > r)
		return -1e9;
	if (l == tl && r == tr)
		return t[v];
	long long tm = (tl + tr) / 2;
	return max(get_max(v*2, tl, tm, l, min(r,tm)), get_max(v*2+1, tm+1, tr, max(l,tm+1), r));
}

void update (long long v, long long tl, long long tr, long long pos, long long new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		long long tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v * 2, tl, tm, pos, new_val);
		else
			update (v * 2 + 1, tm + 1, tr, pos, new_val);
		t[v] = max(t[v * 2], t[v * 2 + 1]);
	}
}


int main(){
    scanf("%lld", &n);
    long long* s = (long long*)malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &s[i]);
    }
    build(s, 1, 0, n - 1);
    long long m;
    scanf("%lld", &m);
    char a[5];
    long long x, y;
    for (int j = 0; j < m; j++){
        scanf("%s%lld%lld", &a, &x, &y);
        //prlong longf("%s %d %d\n", a, x, y);
        if (strcmp(a, "m") == 0){
            printf("%lld ", get_max(1, 0, n - 1, x - 1, y - 1));
        }
        else{
            update(1, 0, n - 1, x - 1, y);
        }
    }
    free(s);
    return 0;
}
