#include "ft_list.h"

void	ft_list_merge(t_list **begin_list, t_list *begin_list2)
{
	if (!*begin_list)
		return ;
	while ((*begin_list)->next)
	{
		begin_list = &(*begin_list)->next;
	}
	(*begin_list)->next = begin_list2;
}
