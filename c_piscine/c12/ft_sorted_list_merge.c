#include "ft_list.h"

static void	ft_sorted_list_merge2(t_list **begin_list1, t_list *lptr, \
					t_list *begin_list2, int (*cmp)());

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*lptr;

	lptr = *begin_list1;
	if (!begin_list2)
		return;
	else if (!lptr)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	else if (cmp(lptr->data, begin_list2->data) > 0)
	{
		*begin_list1 = begin_list2;
		begin_list2 = begin_list2->next;
	}
	else
	{
		*begin_list1 = lptr;
		lptr = lptr->next;
	}
	ft_sorted_list_merge2(begin_list1, lptr, begin_list2, cmp);
}

static void	ft_sorted_list_merge2(t_list **begin_list1, t_list *lptr, \
					t_list *begin_list2, int (*cmp)())
{

	while (lptr || begin_list2)
	{
		if (lptr && (!begin_list2 || \
			cmp(lptr->data, begin_list2->data) <= 0))
		{
			(*begin_list1)->next = lptr;
			lptr = lptr->next;
		}
		else
		{
			(*begin_list1)->next = begin_list2;
			begin_list2 = begin_list2->next;
		}
		begin_list1 = &(*begin_list1)->next;
	}
}
