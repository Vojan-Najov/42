#include "push_swap.h"

////////////////////////////////////////////////////////////////////////////////

static int	stack_a_split(t_stacks *stacks, int size, int middle, int count);

static void	frame_sort(t_stacks *stacks);

void	stack_sort(t_stacks *stacks)
{
	int		middle;
	size_t	count;
	size_t	size;

	size = ft_list_size(stacks->a_top);
	while (size > 3)
	{
		middle = list_middle_data(stacks->a_top, size);
		count = list_count_lessmid(stacks->a_top, size, middle);
		ft_list_push_front(&stacks->frame, count);
		size = stack_a_split(stacks, size, middle, count);
		/*ft_strjoin_and_free_src(&stacks->instructions, "__________\n");*/
	}
	//ft_strjoin_and_free_src(&stacks->instructions, "sort stack_a\n"); //
	if (size == 3)
		stack_a3only_sort(stacks);
	else if (size == 2)
		stack_2elem_sort(stacks, STACK_A);
	frame_sort(stacks);
}

static int	stack_a_split(t_stacks *stacks, int size, int middle, int count)
{
	while (count)
	{
		if (stacks->a_top->data < middle)
		{
			stack_push(stacks, STACK_B);
			--count;
			--size;
		}
		else if (stacks->a_end->data < middle)
			stack_rev_rotate(stacks, STACK_A);
		else if (count == 1 && size > 1 && stacks->a_top->next->data < middle)
		{
			if (ft_list_size(stacks->b_top) > 1 && \
			stacks->b_top->data < stacks->b_top->next->data)
				stack_swap(stacks, STACKS_AB);
			else
				stack_swap(stacks, STACK_A);
		}
		else
			stack_rotate(stacks, STACK_A);
	}
	return (size);
}

static void	frame_sort(t_stacks *stacks)
{
	while (stacks->frame)
	{
/*
		ft_strjoin_and_free_src(&stacks->instructions, "__________\n");
		char fs[100];
		sprintf(fs, "frame = %d\n", stacks->frame->data);
		ft_strjoin_and_free_src(&stacks->instructions, fs);
	t_list *a = stacks->frame; //
		printf("frames: ");
		while (a)
		{
			printf("%d ", a->data);
			a = a->next;
		}
		printf("\n");

	a = stacks->a_top; //
	printf("\na:\n");
	while (a)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
	printf("\n");
	t_list *b = stacks->b_top; //
	printf("\nb:\n");
	while (b)
	{
		printf("%d\n", b->data);
		b = b->next;
	}
	printf("\n");
*/
		if (stacks->frame->data == 1)
			stack_push(stacks, STACK_A);
		else if (stacks->frame->data == 2)
		{
			stack_2elem_sort(stacks, STACK_B);
			stack_push(stacks, STACK_A);
			stack_push(stacks, STACK_A);
		}
		else if (stacks->frame->data == 3)
			stack_b3_sort(stacks);
		else
		{
			frame_split(stacks);
			continue ;
		}
		ft_list_remove(&stacks->frame, 0);
	}
}
