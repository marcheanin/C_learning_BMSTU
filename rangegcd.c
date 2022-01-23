#include <stdio.h>
#include <stdlib.h>

//2 в степени j === 1 и j штук 0 :   2 в 10 == 10000000000 в 2 с/с
//Поэтому в 2 какой степени j === (1 << j)

int Gcd(int a, int b){
	a = (int)labs(a);
	b = (int)labs(b);
	if (b == 0)
		return (int)labs(a);
	return Gcd(b, a % b);
}

void Sparse_Table_build(int *arr, int *lg, int n, int **ST){
	int m = lg[n] + 1;
	int i = 0;
	while (i < n){
		ST[i][0] = arr[i];
		i++;
	}
	int j = 1;
	while (j < m){
		i = 0;
		while(i <= n - (1 << j)){
			ST[i][j] = Gcd (ST[i][j-1], ST[i + (1 << (j-1))][j-1]);
			i++;
		}
		j++;
	}
}

void Computer_Logarithms(int m, int* lg){
	int i = 1, j = 0;
	while (i < m){
		while(j < (1 << i)){
			lg[j] = i - 1;
			j++;
		}
		i++;
	}
}

int Sparce_Table_Query(int l, int r,int *lg, int **ST){
	int j = lg[r - l + 1];
	return Gcd (ST[l][j], ST[r - (1 << j) + 1][j]);
}

int main(int argc, const char * argv[]) {
	int length, m, l = 0 , r = 0;

	scanf("%d", &length);
	int *arr=(int*)malloc(length*sizeof(int));
	for (int i = 0; i < length; i++)
		scanf("%d", &arr[i]);

	int *lg=(int*)malloc(2000000*sizeof(int));
	Computer_Logarithms(20, lg);
	int mm = lg[length] + 1;

	int **ST = (int**)malloc(length * sizeof(int*));
	for (int i = 0; i < length; i++){
		ST[i] = (int*)malloc(mm * sizeof(int));
	}

	Sparse_Table_build(arr, lg, length, ST);
	free(arr);

	scanf("%d", &m);
		int *answer=(int*)malloc(m * sizeof(int));
	for(int i = 0; i < m; i++){
		scanf("%d %d", &l, &r);
		answer[i] = Sparce_Table_Query(l, r, lg, ST);
	}
	for(int i = 0; i < m; i++)
		printf("%d\n", answer[i]);

	free(answer);
	for (int i = 0; i < length; i++)
		free(ST[i]);
	free(ST);
	free(lg);
    return 0;
}
