#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	long val;
	long arr_num;
} pair;

struct Queue
{
	pair *heap;
	size_t cnt, cap;
} q;

int Compare(size_t a, size_t b)
{
	if (q.heap[a].val == q.heap[b].val)
		return 0;

	return (q.heap[a].val > q.heap[b].val) ? 1 : -1;
}

void Swap(size_t a, size_t b)
{
	pair tmp = q.heap[a];
	q.heap[a] = q.heap[b];
	q.heap[b] = tmp;
}

void QueueInit(size_t n)
{
	q.heap = (pair *)malloc(n * sizeof(pair));
	q.cap = n;
	q.cnt = 0;
}

size_t Parent(size_t idx)
{
	return (idx - 1) >> 1;
}

size_t ChildLeft(size_t idx)
{
	return (idx << 1) + 1;
}

size_t ChildRight(size_t idx)
{
	return (idx << 1) + 2;
}

void ShiftUp(size_t idx)
{
	while (idx && Compare(Parent(idx), idx) == 1)
	{
		Swap(Parent(idx), idx);
		idx = Parent(idx);
	}
}

void ShiftDown()
{
	size_t idx = 0, idx_min = 0, left = 0, right = 0;

	while (1)
	{
		idx = idx_min;
		left = ChildLeft(idx);
		right = ChildRight(idx);

		if (left <= q.cnt && Compare(idx_min, left) == 1)
			idx_min = left;

		if (right <= q.cnt && Compare(idx_min, right) == 1)
			idx_min = right;

		if (idx_min == idx)
			break;

		Swap(idx, idx_min);
	}
}

void QueueInsert(pair element)
{
	q.heap[q.cnt] = element;
	ShiftUp(q.cnt);
	q.cnt++;
}

void ExtractMin(pair *element)
{
	element->arr_num = q.heap[0].arr_num;
	element->val = q.heap[0].val;
	q.cnt--;

	if (q.cnt)
	{
		q.heap[0] = q.heap[q.cnt];
		ShiftDown();
	}
}

void QueueProcess(size_t *arrs_len, long **arrs)
{
	size_t i = 0, count = 0;
	pair element;

	for (i = 0; i < q.cap; i++)
	{
		element.val = arrs[i][0];
		element.arr_num = i;
		QueueInsert(element);
		count += arrs_len[i];
	}

	for (i = 0; i < count; i++)
	{
		ExtractMin(&element);
		printf("%li ", element.val);

		arrs_len[element.arr_num]--;
		if (arrs_len[element.arr_num])
		{
			++arrs[element.arr_num];
			element.val = *arrs[element.arr_num];
			QueueInsert(element);
		}
	}
}

int main()
{
	size_t kt = 0, k = 0, i = 0, j = 0, arr_len = 0, summ = 0;
	scanf("%u", &kt);

	size_t *arrs_len = malloc(kt * sizeof(size_t));

	for (i = 0; i < kt; i++)
	{
		scanf("%u", &arr_len);

		if (arr_len)
		{
			summ += arr_len;
			arrs_len[k++] = arr_len;
		}
	}

	long **arrs = (long **)malloc(k * sizeof(long *) + summ * sizeof(long));

	for (i = 0; i < k; i++)
	{
		arr_len = arrs_len[i];

		if (i == 0)
			arrs[i] = (long *)(arrs + k);
		else
			arrs[i] = (long *)(arrs[i - 1] + arrs_len[i - 1]);

		for (j = 0; j < arrs_len[i]; j++)
			scanf("%li", arrs[i] + j);
	}

	QueueInit(k);
	QueueProcess(arrs_len, arrs);

	free(arrs_len);
	free(arrs);
	free(q.heap);

	return 0;
}
