#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_list
{
	void            *data;
	struct s_list   *next;
}				t_list;

t_list	*ft_list_push_front(t_list **head, void *data);

t_list	*ft_create_elem(void *data)
{
	t_list		*new;

	new = (t_list*)malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}

void    initialize_linked_list(t_list **head)
{
	t_list  *tmp;

	*head = (t_list*)malloc(sizeof(t_list));
	(*head)->data = "One";
	(*head)->next = NULL;
	
	tmp = *head;
	
	for (int i = 0; i < 3; i++)
	{
		tmp->next = (t_list*)malloc(sizeof(t_list));
		tmp = tmp->next;
		tmp->data = "One";
		tmp->next = NULL;
	}
}

void    print_linked_list(t_list *head)
{
	while (head != NULL)
	{
		printf("data: %s\n", head->data);
		head = head->next;
	}
}

int main()
{
	t_list	*head;
	
	initialize_linked_list(&head);
	ft_list_push_front(&head, "Hello");
	ft_list_push_front(&head, "Ayoub");
	print_linked_list(head);
	return (0);
}
