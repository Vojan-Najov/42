#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*lst;
	t_list	*elem;

	lst = NULL;
	if (size <= 0)
		return (NULL);
	while (size--)
	{
		elem = ft_create_elem(*strs);
		if (!elem)
			return (lst);
		elem->next = lst;
		lst = elem;
		++strs;
	}
	return (lst);
}
