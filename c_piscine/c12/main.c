#include "ft_list.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void	free_const(void *ptr);

void	f(void *ptr);

int	main(int argc, char **argv)
{
	if (argc == 1)
		printf("\n\tuse with arguments\n\n");
	t_list	*begin_list;
	t_list	*begin_list2;
	t_list	*begin_list3;
	t_list	*begin_list4;
	t_list	*tmp;
	int	list_size;
	int	count;
	int	nbr;
	char	**args;
	char	*str;
	char	*strd;
	char *strs[3];
	char *strs2[3];
	char *strs4[4];

	strs[0] = strdup("abc");
	strs[1] = strdup("def");
	strs[2] = strdup("ghk");
	begin_list = NULL;
	begin_list2 = NULL;
	begin_list3 = NULL;
	begin_list4 = NULL;
	/*	test ft_create_elem ft_list_push_front ft_list_size	*/
	args = argv + 1;
	while (*args)
	{
		ft_list_push_front(&begin_list, *args);
		++args;
	}
	count = 0;
	args = argv + argc - 1;
	tmp = begin_list;
	while (tmp)
	{
		if (args == argv)
		{
			printf("Error, when compare list data with original data\n");
			break ;
		}
		if (strcmp(tmp->data, *args) == 0)
			++count;
		tmp = tmp->next;
		args--;
	}
	list_size = ft_list_size(begin_list);
	printf("ft_create_elem: ");
	(list_size == argc - 1) ? printf("Ok\n") : printf("Error\n");
	printf("ft_list_push_front: ");
	(list_size == argc - 1) ? printf("Ok\n") : printf("Error\n");
	printf("ft_list_size: ");
	(list_size == argc - 1 && count == argc - 1) ? printf("Ok\n") : printf("Error\n");
	/*	test ft_list_last	*/
	tmp = ft_list_last(begin_list);
	printf("ft_list_last: ");
	if (argc == 1)
	{
		(tmp == NULL) ? printf("Ok\n") : printf("Error\n");
	}
	else
	{
		(strcmp(tmp->data, argv[1]) == 0) ? printf("Ok\n") : printf("Error\n");
	}
	/*	test ft_list_push_back		*/
	args = argv + 1;
	while (*args)
	{
		ft_list_push_back(&begin_list2, *args);
		++args;
	}
	list_size = ft_list_size(begin_list2);
	printf("ft_list_push_back: ");
	(list_size == argc - 1) ? printf("Ok\n") : printf("Error\n");
	/*	test ft_list_push_strs		*/
	begin_list3 = ft_list_push_strs(sizeof(strs) / sizeof(*strs), strs);
	list_size = ft_list_size(begin_list3);
	printf("ft_list_push_strs: ");
	(list_size == sizeof(strs) / sizeof(*strs)) ? printf("Ok\n") : printf("Error\n");
	begin_list4 = ft_list_push_strs(0, strs);
	list_size = ft_list_size(begin_list4);
	printf("ft_list_push_strs: ");
	(list_size == 0) ? printf("Ok\n") : printf("Error\n");
	/*	test ft_list_clear		*/
	ft_list_clear(begin_list, free_const);
	ft_list_clear(begin_list2, free_const);
	ft_list_clear(begin_list3, free);
	ft_list_clear(begin_list4, free);
	printf("ft_list_clear: ");
	printf("check with valgrind --leak-check=full\n");
	/* 	test ft_list_at			*/
	printf("ft_list_at: ");
	args = argv + 1;
	begin_list = NULL;
	tmp = ft_list_at(begin_list, 100);
	(tmp == NULL) ? printf("Ok ") : printf("Error ");
	while (*args)
	{
		ft_list_push_back(&begin_list, *args);
		++args;
	}
	count = 0;
	nbr = 0;
	while (nbr < argc - 1)
	{
		tmp = ft_list_at(begin_list, nbr);
		if (strcmp(tmp->data, argv[1 + nbr]) == 0)
			++count;
		++nbr;
	}
	tmp = ft_list_at(begin_list, argc + 100);
	(count == argc - 1 && tmp == NULL) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free_const);
	/*	test ft_list_reverse		*/
	printf("ft_list_reverse: ");
	args = argv + 1;
	begin_list = NULL;
	ft_list_reverse(&begin_list);
	(begin_list == NULL) ? printf("Ok ") : printf("Error ");
	while (*args)
	{
		ft_list_push_front(&begin_list, *args);
		++args;
	}
	ft_list_reverse(&begin_list);
	count = 0;
	tmp = begin_list;
	args = argv + 1;
	while (tmp)
	{
		if (strcmp(tmp->data, *args) == 0)
			++count;
		tmp = tmp->next;
		++args;
	}
	(count == argc - 1) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free_const);
	/*	test ft_list_foreach		*/
	printf("ft_list_foreach: ");
	args = argv + 1;
	begin_list = NULL;
	ft_list_foreach(begin_list, f);
	(begin_list == NULL) ? printf("Ok ") : printf("Error ");
	while (*args)
	{
		ft_list_push_back(&begin_list, *args);
		++args;
	}
	ft_list_foreach(begin_list, f);
	count = 0;
	tmp = begin_list;
	args = argv + 1;
	while (tmp)
	{
		str = *args;
		strd = (char *) tmp->data;
		while (*strd)
		{
			if (*strd != toupper(*str))
				printf("Error ");
			++strd;
			++str;
		}
		++count;
		tmp = tmp->next;
		++args;
	}
	(count == argc - 1) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free_const);
	/*	test ft_list_foreach_if		*/
	printf("ft_list_foreach_if: ");
	begin_list = NULL;
	strs[0] = strdup("abc");
	strs[1] = strdup("def");
	strs[2] = strdup("ghk");
	ft_list_foreach_if(begin_list, f, "0", strcmp);
	(begin_list == NULL) ? printf("Ok ") : printf("Error ");
	ft_list_push_back(&begin_list, strs[0]);
	ft_list_push_back(&begin_list, strs[1]);
	ft_list_push_back(&begin_list, strs[2]);
	ft_list_foreach_if(begin_list, f, strs[1], strcmp);
	tmp = begin_list;
	count = 0;
	if (strcmp(tmp->data, strs[0]) == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "DEF") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, strs[2]) == 0)
		++count;
	tmp = tmp->next;
	(count == 3 && tmp == NULL) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free);
	/*	test ft_list_find		*/
	printf("ft_list_find: ");
	begin_list = NULL;
	tmp = ft_list_find(begin_list, "0", strcmp);
	(tmp == NULL) ? printf("Ok ") : printf("Error ");
	args = argv + 1;
	while (*args)
	{
		ft_list_push_back(&begin_list, *args);
		++args;
	}
	if (argc > 1)
	{
		tmp = ft_list_find(begin_list, argv[argc - 1], strcmp);
		(strcmp(tmp->data, argv[argc - 1]) == 0) ? printf("Ok ") : printf("Error ");
	}
	tmp = ft_list_find(begin_list, "abyrvalg", strcmp);
	(tmp == NULL) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free_const);
	/*	test ft_list_remove_if		*/
	printf("ft_list_remove_if :");
	begin_list = NULL;
	ft_list_remove_if(&begin_list, "0", strcmp, free);
	(begin_list == NULL) ? printf("Ok ") : printf("Error ");
	strs[0] = strdup("abc");
	strs[1] = strdup("def");
	strs[2] = strdup("ghk");
	ft_list_push_back(&begin_list, strs[0]);
	ft_list_push_back(&begin_list, strs[1]);
	ft_list_push_back(&begin_list, strs[2]);
	ft_list_remove_if(&begin_list, "0", strcmp, free);
	ft_list_remove_if(&begin_list, "def", strcmp, free);
	ft_list_remove_if(&begin_list, "def", strcmp, free);
	tmp = begin_list;
	count = 0;
	if (strcmp(tmp->data, "abc") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "ghk") == 0)
		++count;
	tmp = tmp->next;
	(count == 2 && tmp == NULL) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free);
	/*	test ft_list_merge		*/
	printf("ft_list_merge: ");
	begin_list = NULL;
	begin_list2 = NULL;
	ft_list_merge(&begin_list, begin_list2);
	(begin_list == NULL) ? printf("Ok ") : printf("Error ");
	strs[0] = strdup("abc");
	strs[1] = strdup("def");
	strs[2] = strdup("ghk");
	ft_list_push_back(&begin_list, strs[0]);
	ft_list_push_back(&begin_list, strs[1]);
	ft_list_push_back(&begin_list, strs[2]);
	ft_list_merge(&begin_list, begin_list2);
	tmp = begin_list;
	count = 0;
	if (strcmp(tmp->data, "abc") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "def") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "ghk") == 0)
		++count;
	tmp = tmp->next;
	(count == 3 && tmp == NULL) ? printf("Ok ") : printf("Error ");
	strs2[0] = strdup("abc");
	strs2[1] = strdup("def");
	strs2[2] = strdup("ghk");
	ft_list_push_back(&begin_list2, strs2[0]);
	ft_list_push_back(&begin_list2, strs2[1]);
	ft_list_push_back(&begin_list2, strs2[2]);
	ft_list_merge(&begin_list, begin_list2);
	tmp = begin_list;
	count = 0;
	if (strcmp(tmp->data, "abc") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "def") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "ghk") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "abc") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "def") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "ghk") == 0)
		++count;
	tmp = tmp->next;
	(count == 6 && tmp == NULL) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free);
	/*	test ft_list_sort		*/
	printf("ft_list_sort: ");
	begin_list = NULL;
	strs[0] = strdup("abc");
	strs[1] = strdup("def");
	strs[2] = strdup("ghk");
	ft_list_sort(&begin_list, strcmp);
	ft_list_push_front(&begin_list, strs[0]);
	ft_list_push_front(&begin_list, strs[1]);
	ft_list_push_front(&begin_list, strs[2]);
	ft_list_sort(&begin_list, strcmp);
	tmp = begin_list;
	count = 0;
	if (strcmp(tmp->data, "abc") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "def") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "ghk") == 0)
		++count;
	tmp = tmp->next;
	(count == 3 && tmp == NULL) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free);
	/*	test ft_sorted_list_insert	*/
	printf("ft_sorted_list_insert: ");
	begin_list = NULL;
	strs4[0] = strdup("abc");
	strs4[1] = strdup("def");
	strs4[2] = strdup("def");
	strs4[3] = strdup("ghk");
	ft_sorted_list_insert(&begin_list, strs4[0], strcmp);
	ft_sorted_list_insert(&begin_list, strs4[1], strcmp);
	ft_sorted_list_insert(&begin_list, strs4[3], strcmp);
	ft_sorted_list_insert(&begin_list, strs4[2], strcmp);
	tmp = begin_list;
	count = 0;
	if (strcmp(tmp->data, "abc") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "def") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "def") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "ghk") == 0)
		++count;
	tmp = tmp->next;
	(count == 4 && tmp == NULL) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free);
	/*	test ft_sorted_list_merge	*/
	printf("ft_sorted_list_merge: ");
	strs[0] = strdup("1abc");
	strs[1] = strdup("4def");
	strs[2] = strdup("5ghk");
	strs4[0] = strdup("0abc");
	strs4[1] = strdup("3def");
	strs4[2] = strdup("8ghk");
	strs4[3] = strdup("9ghk");
	begin_list = NULL;
	begin_list2 = NULL;
	ft_list_push_back(&begin_list, strs[0]);
	ft_list_push_back(&begin_list, strs[1]);
	ft_list_push_back(&begin_list, strs[2]);
	ft_list_push_back(&begin_list2, strs4[0]);
	ft_list_push_back(&begin_list2, strs4[1]);
	ft_list_push_back(&begin_list2, strs4[2]);
	ft_list_push_back(&begin_list2, strs4[3]);
	ft_sorted_list_merge(&begin_list, begin_list2, strcmp);
	tmp = begin_list;
	count = 0;
	if (strcmp(tmp->data, "0abc") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "1abc") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "3def") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "4def") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "5ghk") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "8ghk") == 0)
		++count;
	tmp = tmp->next;
	if (strcmp(tmp->data, "9ghk") == 0)
		++count;
	tmp = tmp->next;
	(count == 7 && tmp == NULL) ? printf("Ok\n") : printf("Error\n");
	ft_list_clear(begin_list, free);

	return (0);
}

void	free_const(void *ptr)
{
	(void) ptr;
}

void	f(void *ptr)
{
	char	*str;

	str = (char *) ptr;
	while (*str)
	{
		*str = toupper(*str);
		++str;
	}
}
