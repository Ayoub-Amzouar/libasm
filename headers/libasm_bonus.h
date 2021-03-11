#ifndef LIBASM_BONUS_H
#define LIBASM_BONUS_H

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

#endif