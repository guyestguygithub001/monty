#include "monty.h"
/**
 * f_pop - prints for top of stack..
 * @head: head of the stack..
 * @counter: line_number..
 * Return: void..
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't show empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
