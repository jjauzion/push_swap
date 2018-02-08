#include "header.h"

void	ft_min2top_a(t_stack *a, t_stack *b, char option)
{
	int	min;
	int	i;

	min = ft_tab_min(a->data, a->top + 1);
	i = -1;
	while (a->data[++i] > min);
	while (a->data[a->top] > min)
	{
		if (i >= a->top / 2)
			ft_exec_cmd(a, b, "ra", 1);
		else
			ft_exec_cmd(a, b, "rra", 1);
	}
}

void	ft_max2top_b(t_stack *a, t_stack *b, char option)
{
	int	min;
	int	i;
////////////////////
	min = ft_tab_min(b->data, b->top + 1);
	i = -1;
	while (b->data[++i] > min);
	while (b->data[b->top] > min)
	{
		if (i >= b->top / 2)
			ft_exec_cmd(a, b, "rb", 1);
		else
			ft_exec_cmd(a, b, "rrb", 1);
	}
}
