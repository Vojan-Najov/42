#include "push_swap.h"

static void	stacks_init(t_stacks **stacks, char **args, int flag);

static void	stacks_free(t_stacks *stacks, char **args, int flag);

static void	instructions_print(t_stacks *stacks);

//static void	print_stack(t_list *a);

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**args;
	int			free_args;

	stacks = NULL;
	free_args = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		free_args = 1;
	}
	else
		args = argv + 1;
	if (!check_args(args))
	{
		write(STDERR_FILENO, ERRMES, ERRMESLEN);
		stacks_free(stacks, args, free_args);
		return (1);
	}
	stacks_init(&stacks, args, free_args);
	if (!ft_list_issorted(stacks->a_top))
		stack_sort(stacks);
	instructions_print(stacks);
	stacks_free(stacks, args, free_args);
	return (0);
}

static void	stacks_init(t_stacks **stacks, char **args, int flag)
{
	int	num;

	*stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!*stacks || !args)
		exit(EXIT_FAILURE);
	(*stacks)->instructions = (char *) ft_calloc(1, 1);
	if (!(*stacks)->instructions)
	{
		stacks_free(*stacks, args, flag);
		exit(EXIT_FAILURE);
	}
	while (*args)
	{
		num = ft_atoi(*args);
		ft_list_push_back(&(*stacks)->a_top, num);
		++args;
	}
	(*stacks)->a_end = ft_list_last((*stacks)->a_top);
}

static void	instructions_print(t_stacks *stacks)
{
	int	len;
	int	ret;

	len = ft_strlen(stacks->instructions);
	ret = write(STDOUT_FILENO, stacks->instructions, len);
	if (ret != len)
		exit(EXIT_FAILURE);
}

static void	stacks_free(t_stacks *stacks, char **args, int flag)
{
	int	i;

	if (stacks)
	{
		ft_list_clear(stacks->a_top);
		ft_list_clear(stacks->b_top);
		ft_list_clear(stacks->frame);
		free(stacks->instructions);
		free(stacks);
	}
	if (flag)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
			++i;
		}
		free(args);
	}
}

/*
int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**args;

	args = NULL;
	stacks = (t_stacks *) malloc(sizeof(t_stacks));
	if (!stacks)
		exit(EXIT_FAILURE);
	if (check_args(argv + 1) == -1)
		write(STDOUT_FILENO, "Error\n", 6);
	else if (check_args(argv + 1) == 0)
	{
		free(stacks);
		return (0);
	}
	else
	{
		if (argc == 2)
		{
			args = ft_split(argv[1], ' ');
			init_stacks(stacks, args);
		}
		else
			init_stacks(stacks, argv + 1);
	}
	stack_sort(stacks);
	printf("%s", stacks->instructions);
	free_stacks(stacks);
	char **tmp = args;
	if (tmp)
	{
		while (*tmp)
		{
			free(*tmp);
			++tmp;
		}
		free(args);
	}
}

static void	init_stacks(t_stacks *stacks, char **args)
{
	int	num;

	stacks->a_top = NULL;
	stacks->a_end = NULL;
	stacks->b_top = NULL;
	stacks->b_end = NULL;
	stacks->frame = NULL;
	stacks->instructions = (char *) malloc(1);
	if (!stacks->instructions)
	{
		free_stacks(stacks);
		exit(EXIT_FAILURE);
	}
	*stacks->instructions = '\0';
	while (*args)
	{
		num = ft_atoi(*args);
		ft_list_push_back(&stacks->a_top, num);
		++args;
	}
	stacks->a_end = ft_list_last(stacks->a_top);
}
//	printf("before\n");
//	printf("stack_a:\n");
//	print_stack(stacks->a_top);
//	printf("stack_b:\n");
//	print_stack(stacks->b_top);

//	printf("\nafter\n");
//	printf("stack_a:\n");
//	print_stack(stacks->a_top);
//	printf("stack_b:\n");
//	print_stack(stacks->b_top);

static void	print_stack(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

	printf("before\n");
	print_stack(stacks->a_top);
	stack_rotate(stacks, STACK_A);
	printf("after\n");
	print_stack(stacks->a_top);

	printf("before\n");
	print_stack(stacks->a_top);
	stack_rev_rotate(stacks, STACK_A);
	printf("after\n");
	print_stack(stacks->a_top);

	stack_swap(stacks, STACK_A);
	print_stack(stacks->a_top);

	stack_push(stacks, STACK_B);
	printf("stack a:\n");
	print_stack(stacks->a_top);
	printf("stack b:\n");
	print_stack(stacks->b_top);

	stack_push(stacks, STACK_B);
	printf("stack a:\n");
	print_stack(stacks->a_top);
	printf("stack b:\n");
	print_stack(stacks->b_top);

	stack_swap(stacks, STACKS_AB);
	printf("stack a:\n");
	print_stack(stacks->a_top);
	printf("stack b:\n");
	print_stack(stacks->b_top);

	stack_push(stacks, STACK_A);
	printf("stack a:\n");
	print_stack(stacks->a_top);
	printf("stack b:\n");
	print_stack(stacks->b_top);

	stack_push(stacks, STACK_A);
	printf("stack a:\n");
	print_stack(stacks->a_top);
	printf("stack b:\n");
	print_stack(stacks->b_top);

	printf("\n\n%s\n", stacks->instructions);
	(ft_list_issorted(stacks->a_top)) ? printf("YES\n") : printf("NO\n");
*/
