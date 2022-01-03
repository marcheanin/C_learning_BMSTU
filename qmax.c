#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Queue
{
	long *data;
	size_t cnt, cap, head, tail;
} q;

void InitQueue(size_t n)
{
	q.data = (long *)calloc(n, sizeof(long));
	q.cnt = 0;
	q.cap = n;
	q.head = 0;
	q.tail = 0;
}

size_t QueueEmpty()
{
	return q.cnt == 0 ? 1 : 0;
}

long Dequeue()
{
	long ret = q.data[q.head++];
	q.cnt--;

	if (q.head == q.cap)
		q.head = 0;

	return ret;
}

void Enqueue(long value)
{
	size_t j = 0;

	if (q.cnt == q.cap)
	{
		q.data = (long *)realloc(q.data, 2 * q.cap * sizeof(long));

		for (j = 0; j < q.tail; j++)
			q.data[q.cap + j] = q.data[j];

		q.tail = q.cap + j;
		q.cap *= 2;
	}

	q.data[q.tail++] = value;
	q.cnt++;

	if (q.tail == q.cap)
		q.tail = 0;
}

int main()
{
	InitQueue(4);

	char cmd[6] = { 0 };
	long arg = 0;

	size_t n = 0, i = 0, ti = 0;
	scanf("%u", &n);

	long *result = (long*)calloc(n, sizeof(long));

	for (i = 0; i < n; i++)
	{
		scanf("%s", cmd);

		if (strcmp(cmd, "ENQ") == 0)
		{
			scanf("%li", &arg);
			Enqueue(arg);
		}
		else if (strcmp(cmd, "DEQ") == 0) result[ti++] = Dequeue();
		else if (strcmp(cmd, "EMPTY") == 0) result[ti++] = QueueEmpty() ? 2000000000 : 2000000001;
		else return 1;
	}

	for (i = 0; i < ti; i++)
		if (result[i] >= 2000000000)
			printf("%s\n", result[i] == 2000000000 ? "true" : "false");
		else
			printf("%li\n", result[i]);

	free(q.data);
	free(result);
	return 0;
}
