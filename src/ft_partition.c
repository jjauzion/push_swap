/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:58:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/12 15:38:53 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_get_pivot_index(t_stack *b, int pivot)
{
	int	i;

	i = 0;
	while (b->data[i] != pivot)
	{
		i++;
	}
	return (i);
}

static void		ft_pull_pivot(t_stack *a, t_stack *b, int pivot)
{
	int	i;

	i = ft_get_pivot_index(b, pivot);
	while (b->data[b->top] != pivot)
		if (i >= b->top / 2)
			ft_exec_cmd(a, b, "rb", 1);
		else
			ft_exec_cmd(a, b, "rrb", 1);
	ft_exec_cmd(a, b, "pa", 1);
}

static int		ft_exit(t_stack *a, int pivot, int start_i)
{
	int		i;

	i = start_i;
	while (i <= a->top)
	{
		if (a->data[i] <= pivot)
			return (0);
		i++;
	}
	return (1);
}

static int		ft_push2b(t_stack *a, t_stack *b, int pivot, int start_i)
{
	while (!ft_exit(a, pivot, start_i))
	{
		if (a->data[a->top] <= pivot)
			ft_exec_cmd(a, b, "pb", 1);
		else if (b->data[b->top] != pivot)
		{
			ft_exec_cmd(a, b, "rr", 1);
			start_i++;
		}
		else
		{
			ft_exec_cmd(a, b, "ra", 1);
			start_i++;
		}
	}
	return (start_i);
}

int				ft_partition(t_stack *a, t_stack *b, int start_i)
{
	int		pivot;
	int		init;
	int		pindex;

	if (!ft_isnsorted(*a, start_i, a->top))
		return (a->top);
	if (ft_sort_small_tab(a, b, start_i))
		return (start_i + 1);
	init = start_i;
	pivot = ft_get_pivot(a, start_i, a->top);
	start_i = ft_push2b(a, b, pivot, start_i);
	pindex = ft_get_pivot_index(b, pivot);
	while (init > 0 && start_i > init)
	{
		if (((pindex + 1 - (start_i - init)) < (b->top - pindex)) &&
				(b->data[b->top] != pivot))
			ft_exec_cmd(a, b, "rrr", 1);
		else
			ft_exec_cmd(a, b, "rra", 1);
		start_i--;
		pindex--;
	}
	ft_pull_pivot(a, b, pivot);
	return (a->top);
}
