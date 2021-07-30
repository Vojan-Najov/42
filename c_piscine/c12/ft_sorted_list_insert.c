#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	*lptr;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (!*begin_list || cmp((*begin_list)->data, data) >= 0)
	{
		elem->next = *begin_list;
		*begin_list = elem;
		return ;
	}
	while ((*begin_list)->next)
		if (cmp((*begin_list)->data, data) >= 0)
		{
			lptr = *begin_list;
			*begin_list = elem;
			elem->next = lptr;
			return ;
		}
		else
			begin_list = &(*begin_list)->next;
	(*begin_list)->next = elem;	
}
