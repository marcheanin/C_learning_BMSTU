#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

struct Elem {
	struct Elem *next;
	char *word;
};
struct Elem *bsort(struct Elem *list)
{
	if (list == NULL) goto done;
	struct Elem * alist = list;
	while(1)
	{
		long i = 0;
		struct Elem *palist = alist;
		while(palist->next != NULL)
		{
			if (strlen(palist->word) > strlen(palist->next->word))
			{
				char *c = palist->word;
				palist->word = palist->next->word;
				palist->next->word = c;
				i++;
			}
			palist = palist->next;
		}
		if (i == 0) goto done;
	}
done:;
	return list;
}
int main()
{
	char str[1000];
	gets(str);
	struct Elem * pl = NULL;
	char del[1000] = " ";
	char *word = strtok(str, del);
	struct Elem * fl;
	while (word != NULL)
	{
		struct Elem * list = malloc(sizeof(struct Elem));
		list->word = word;
		if (pl != NULL)
		{
			pl->next = list;
		}
		else fl = list;
		pl = list;
		word = strtok(NULL, del);
	}
	if (pl != NULL) pl->next = NULL;
	fl = bsort(fl);
	struct Elem * list = fl;
	while(list != NULL)
	{
		puts(list->word);
		struct Elem * c = list;
		list = list->next;
		free(c);
	}
	return 0;
}
