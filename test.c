#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_list
{
	void            *data;
	struct s_list   *next;
}				t_list;

void	ft_list_push_front(t_list **head, void *data);
int		ft_list_size(t_list *head);

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
	t_list *tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("data: %s\n", tmp->data);
		tmp = tmp->next;
	}
}

void	test_size(t_list *head)
{
	int		i = 0;

	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	printf("%d\n", i);
}

int main()
{
	t_list	*head;
	int		len;

	initialize_linked_list(&head);
	ft_list_push_front(&head, "Hello");
	ft_list_push_front(&head, "Ayoub");
	print_linked_list(head);
	printf("len: %d\n", ft_list_size(head));
	// test_size(head);
	return (0);
}
