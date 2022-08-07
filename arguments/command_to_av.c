#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

list_t *add_node_end(list_t **head, const char *str);
size_t print_list(const list_t *h);


/**
 * add_node_end - add node at the end of list
 *
 * @head: list head
 * @str: str to add
 * Return: list_t*
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t **tail;

	tail = head;
	while ((*tail) != NULL)
	{
		tail = &((*tail)->next);
	}
	(*tail) = malloc(sizeof(list_t *));
	if ((*tail) == NULL)
	{
		return (NULL);
	}
	(*tail)->str = strdup(str);
	(*tail)->next = NULL;

	return (*tail);
}

/**
 * print_list - print given list
 *
 * @h: the list
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	int len;

	len = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("(nil)\n");
		}
		else
		{
			printf("%s\n", h->str);
		}
		h = h->next;
		len++;
	}
	return (len);
}


/**
 * main - Entry : print given words as ar 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
	char * word;
	list_t *words;

	if (argc < 2)
	{
		exit(1);
	}

	words = malloc(sizeof(list_t *));

	if (words == NULL)
	{
		exit(2);
	}

	word = strtok(argv[1], " ");
	while (word != NULL)
	{
		add_node_end(&words, word);
		word = strtok(NULL, " ");
	}

	print_list(words);
	return 0;
}
