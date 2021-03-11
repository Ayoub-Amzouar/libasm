/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:02:06 by aamzouar          #+#    #+#             */
/*   Updated: 2021/03/10 18:02:07 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libasm_bonus.h"

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
	ft_list_push_front(&head, "A");
	ft_list_push_front(&head, "C");
	// print_linked_list(head);
	//ft_list_sort(&head, &ft_strcmp);
	print_linked_list(head);
	printf("len: %d\n", ft_list_size(head));
	return (0);
}
