#include <stdio.h>
#include <string.h> // remove strcmp, and use instead ft_strcmp
#include <stdlib.h>

typedef struct	s_list
{
	void            *data;
	struct s_list   *next;
}				t_list;

void	ft_list_push_front(t_list **head, void *data);
int		ft_list_size(t_list *head);
void	ft_list_sort(t_list **head, int (*cmp)());
int		compare(t_list **head, int (*cmp)());

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

void	list_sort(t_list **head, int (*cmp)())
{
	void	*tmp;
	t_list	*list;
	t_list	*list2;

	list = *head;
	while (list != NULL)
	{
		list2 = list->next;
		while (list2 != NULL)
		{
			if ((*cmp)(list->data, list2->data) > 0)
			{
				tmp = list->data;
				list->data = list2->data;
				list2->data = tmp;
			}
			list2 = list2->next;
		}
		list = list->next;
	}
}

int main()
{
	t_list	*head;
	int		len;

	initialize_linked_list(&head);
	ft_list_push_front(&head, "Z");
	ft_list_push_front(&head, "B");
	ft_list_push_front(&head, "C");
	ft_list_push_front(&head, "A");
	// print_linked_list(head);
	ft_list_sort(&head, &strcmp);
	printf("%d\n", compare(&head, &strcmp));
	print_linked_list(head);
	printf("len: %d\n", ft_list_size(head));
	return (0);
}
