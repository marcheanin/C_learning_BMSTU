#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define STACK_LEN 1024

void swap(int *a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

struct Task
{
	int low, high;
};

void sort(int *arr, int n)
{
	struct Task tasks[STACK_LEN];
	int l = 0, r = 0, point_mid = 0, p = 0;
	int i = 0, j = 0;

	int stack_pos = 1;
	tasks[stack_pos].low = 0;
	tasks[stack_pos].high = n - 1;

	do
	{
		l = tasks[stack_pos].low;
		r = tasks[stack_pos].high;
		stack_pos--;

		do
		{
			point_mid = (l + r) >> 1;
			i = l;
			j = r;
			p = arr[point_mid];

			do
			{
				while (arr[i] < p)
					i++;

				while (p < arr[j])
					j--;

				if (i <= j)
				{
					swap(arr, i, j);
					i++;
					j--;
				}

			} while (i <= j);

			if (i < point_mid)
			{
				if (i < r)
				{
					stack_pos++;
					tasks[stack_pos].low = i;
					tasks[stack_pos].high = r;
				}

				r = j;
			}
			else
			{
				if (j > l)
				{
					stack_pos++;
					tasks[stack_pos].low = l;
					tasks[stack_pos].high = j;
				}

				l = i;
			}
		}
		while (l < r);
	}
	while (stack_pos > 0);
}

int main(int argc, char **argv)
{
	int n = 0, i = 0;
	scanf("%d", &n);

	int *arr = (int*)calloc(n, sizeof(int));

	for (i = 0; i < n; i++)
		scanf("%d", &(arr[i]));

	sort(arr, n);
	sort(arr, n);

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	free(arr);
	return 0;
}
