#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmpbeg;
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*begin_list)
		return ;
	tmpbeg = *begin_list;
	tmp1 = tmpbeg;
	tmp2 = tmpbeg;
	while (tmp1->next)
		tmp1 = tmp1->next;
	*begin_list = tmp1;
	while (tmp1 != tmpbeg)
	{
		while (tmp2->next != tmp1)
			tmp2 = tmp2->next;
		tmp1->next = tmp2;
		tmp1 = tmp1->next;
		tmp2 = tmpbeg;
	}
	tmp1->next = NULL;
}
