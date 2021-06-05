/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str_by_percentage.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:41:02 by ccartman          #+#    #+#             */
/*   Updated: 2021/06/05 14:58:50 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_list	*ft_split_str_by_percentage(const char *fmt)
{
	const char	*ptr;
	t_list		*lst;

	lst = NULL;
	ptr = fmt;
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
			++fmt;
		if (fmt > ptr)
			ft_lstadd_back(&lst, ft_lstnew(ft_strndup(ptr, fmt - ptr)));
		if (*fmt == 0)
			break ;
		ptr = fmt;
		++fmt;
		while (!ft_is_conversion_type(*fmt))
			++fmt;
		++fmt;
		ft_lstadd_back(&lst, ft_lstnew(ft_strndup(ptr, fmt - ptr)));
		ptr = fmt;
	}
	return (lst);
}

/* test split

void ft_lstitte(t_list *lst)
{
	while (lst)
	{
		printf("%p\n", lst);
		printf("%s\n", (char *) lst->content);
		lst = lst->next;
	}
printf("%p\n", lst);
}

int	main(int argc, char** argv)
{
	t_list	*lst;

	if (argc == 2)
	{
		lst = ft_split_str_by_percentage(argv[1]);
		ft_lstitte(lst);
	}

	return (0);
}
*/
