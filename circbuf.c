#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_buffer
{
	int		*arr;
	size_t	size;
	size_t	count_elements;
	size_t	head;
	size_t	tail;
}				t_buffer;

void init_queue(t_buffer *buffer, size_t size)
{
	buffer->arr = (int *)calloc(size + 1, sizeof(int));
	buffer->size = size;
}

void queue_empty(t_buffer *buffer)
{
	if (buffer->tail == buffer->head)
		printf("true\n");
	else
		printf("false\n");
}

void print_buffer(t_buffer *buffer)
{
	for(int i = 0; i < buffer->size; i++)
		printf("%d ", buffer->arr[i]);
	printf("\n");
}

void resize(t_buffer *buffer)
{
	//if (buffer->size == 0)
	size_t size = buffer->size * 2;
	int *new_arr = (int *)calloc(size, sizeof(int));
	int head = buffer->head;
	int i = 0;
	for(i = 0; i < buffer->size; i++)
	{
		new_arr[i] = buffer->arr[head];
		head++;
		head = head % buffer->size;
	}
	buffer->head = 0;
	buffer->tail = i;
	buffer->size = size;
	free(buffer->arr);
	buffer->arr = new_arr;
}

int dequeue(t_buffer *buffer)
{
	int elem = buffer->arr[buffer->head];
	buffer->arr[buffer->head] = 0;
	buffer->head++;
	buffer->head = buffer->head % buffer->size;
	return elem;
}

void enqueue(t_buffer *buffer, int x)
{
	buffer->arr[buffer->tail] = x;
	buffer->tail++;
	buffer->tail = buffer->tail % buffer->size;
	if (buffer->head == buffer->tail)
		resize(buffer);
	buffer->count_elements++;
}

int main(void)
{
	const int len = 10;
	t_buffer buffer;
	size_t count_operation = 0;;
	char operation[len];
	memset(&buffer, 0, sizeof(t_buffer));
	init_queue(&buffer, 4);
	scanf("%zu", &count_operation);
	for (int i = 0; i < count_operation; i++)
	{
		memset(operation, 0 , len);
		scanf("%s", operation);
		if (!strcmp(operation, "ENQ"))
		{
			int x = 0;
			scanf("%d", &x);
			enqueue(&buffer, x);
		}
		else if (!strcmp(operation, "DEQ"))
			printf("%d\n",dequeue(&buffer));
		else if (!strcmp(operation, "EMPTY"))
			queue_empty(&buffer);
		//print_buffer(&buffer);
	}
	free(buffer.arr);
	return 0;
}
