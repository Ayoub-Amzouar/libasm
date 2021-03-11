/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:02:06 by aamzouar          #+#    #+#             */
/*   Updated: 2021/03/11 17:07:58 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libasm_bonus.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*new;

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

int		main()
{
	t_list	*head;
	int		len;

	initialize_linked_list(&head);
	ft_list_push_front(&head, "Z");
	ft_list_push_front(&head, "B");
	ft_list_push_front(&head, "A");
	ft_list_push_front(&head, "C");
	print_linked_list(head);
	printf("len: %d\n", ft_list_size(head));
	return (0);
}
