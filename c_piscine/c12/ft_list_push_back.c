#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*tmp;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (!*begin_list)
		*begin_list = elem;
	else
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}
