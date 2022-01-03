#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_stck {
	long *values;
	size_t p;
} stck;

void push(long value) { stck.values[stck.p++] = value; }
long pop() { return stck.values[--stck.p]; }

void add() { push(pop() + pop()); }
void sub() { push(pop() - pop()); }
void mul() { push(pop() * pop()); }
void sdiv() { push(pop() / pop()); }
void neg() { push(-pop()); }
void dup() { push(stck.values[stck.p - 1]); }

void smax()
{
	long a = pop(), b = pop();
	push(a > b ? a : b);
}

void smin()
{
	long a = pop(), b = pop();
	push(a < b ? a : b);
}

void swap()
{
	long a = pop(), b = pop();
	push(a);
	push(b);
}

int main(int argc, char **argv)
{
	size_t n = 0;
	scanf("%u", &n);

	stck.p = 0;
	stck.values = (long*)calloc(n, sizeof(long));

	char cmd[20];
	long arg;

	for (size_t i = 0; i < n; i++)
	{
		scanf("%s", cmd);

		if (strcmp(cmd, "CONST") == 0)
		{
			scanf("%li", &arg);
			push(arg);
		}
		else if (strcmp(cmd, "ADD") == 0) add();
		else if (strcmp(cmd, "SUB") == 0) sub();
		else if (strcmp(cmd, "MUL") == 0) mul();
		else if (strcmp(cmd, "DIV") == 0) sdiv();
		else if (strcmp(cmd, "MAX") == 0) smax();
		else if (strcmp(cmd, "MIN") == 0) smin();
		else if (strcmp(cmd, "NEG") == 0) neg();
		else if (strcmp(cmd, "DUP") == 0) dup();
		else if (strcmp(cmd, "SWAP") == 0) swap();
	}

	printf("%li", pop());
	free(stck.values);

	return 0;
}
