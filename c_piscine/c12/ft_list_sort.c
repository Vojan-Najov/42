#include "ft_list.h"

static void	ft_list_split(t_list *begin_list, t_list **low, t_list **high);

static void	ft_sortlist_merge(t_list *a, t_list *b, t_list **c, int (*cmp)());

static void	ft_sortlist_merge2(t_list *a, t_list *b, t_list **c, int (*cmp)());

void		ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*low;
	t_list	*high;

	if (!*begin_list || !(*begin_list)->next)
		return ;
	ft_list_split(*begin_list, &low, &high);
	ft_list_sort(&low, cmp);
	ft_list_sort(&high, cmp);
	ft_sortlist_merge(low, high, begin_list, cmp);
}

static void	ft_list_split(t_list *begin_list, t_list **low, t_list **high)
{
	t_list	*fast;
	t_list	*slow;

	if (begin_list == NULL || begin_list->next == NULL)
	{
		*low = begin_list;
		*high = NULL;
		return ;
	}
	slow = begin_list;
	fast = begin_list->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*low = begin_list;
	*high = slow->next;
	slow->next = NULL;
}

static void	ft_sortlist_merge(t_list *a, t_list *b, t_list **c, int (*cmp)())
{
	if (a == NULL)
	{
		*c = b;
		return ;
	}
	else if (b == NULL)
	{
		*c = a;
		return ;
	}
	if (cmp(a->data, b->data) < 0)
	{
		*c = a;
		a = a->next;
	}
	else
	{
		*c = b;
		b = b->next;
	}
	ft_sortlist_merge2(a, b, c, cmp);
}

static void	ft_sortlist_merge2(t_list *a, t_list *b, t_list **c, int (*cmp)())
{
	t_list	*tmp;

	tmp = *c;
	while (a || b)
	{
		if (a && (!b || cmp(a->data, b->data) < 0))
		{
			tmp->next = a;
			a = a->next;
		}
		else
		{
			tmp->next = b;
			b = b->next;
		}
		tmp = tmp->next;
	}
}
