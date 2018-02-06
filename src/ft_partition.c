/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:58:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/06 20:34:23 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_early_exit(t_stack *a, int pivot, int start_i, int init)
{
	int		i;

	if (start_i == init)
	{
		i = start_i;
		while (i < a->top)
		{
			if (a->data[i] < pivot)
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = -1;
		while (++i < a->top)
		{
			if (a->data[i] < pivot)
				return (0);
		}
		return (1);
	}
}

int			ft_partition(t_stack *a, t_stack *b, int start_i)
{
	int		pivot;
	int		init;
	int		exit;

	if (!ft_isnsorted(*a, start_i, a->top))
		return (a->top);
//ft_printf("--> IN PARTITION : BEFORE start_i = %d\n", start_i);
//ft_display(*a, *b);
//getchar();
	if (ft_sort_small_tab(a, b, start_i))
		return (a->top);
//ft_display(*a, *b);
//ft_printf("--> IN PARTITION : start_i = %d\n", start_i);
	init = start_i;
	pivot = ft_get_pivot(a, start_i, a->top);
//ft_printf("start_i = %d ; pivot = %d\t <-- IN PARTITION.c\n", start_i, pivot);
//getchar();
	exit = 0;
	while (start_i <= a->top && !exit)
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
		if (a->data[a->top] == pivot)
			exit = ft_early_exit(a, pivot, start_i, init);
	}
	if (exit)
		return (a->top);
	while (init > 0 && start_i > init)
	{
		ft_exec_cmd(a, b, "rra", 1);
		start_i--;
	}
	while (b->data[b->top] != pivot)
		ft_exec_cmd(a, b, "rb", 1);
	ft_exec_cmd(a, b, "pa", 1);
	return (a->top);
}
