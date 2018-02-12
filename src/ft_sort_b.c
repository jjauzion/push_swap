/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:47:22 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/11 12:14:27 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_push_pivot(t_stack *a, t_stack *b, int pivot)
{
	int	i;

	i = -1;
	while (b->data[++i] != pivot)
	{
	}
	while (b->data[b->top] != pivot)
		if (i >= b->top / 2)
			ft_exec_cmd(a, b, "rb", 1);
		else
			ft_exec_cmd(a, b, "rrb", 1);
	ft_exec_cmd(a, b, "pa", 1);
}

static int		ft_exit(t_stack *b, int pivot)
{
	int		i;

	i = -1;
	while (++i <= b->top)
	{
		if (b->data[i] > pivot)
			return (0);
	}
	return (1);
}

void			ft_sort_b(t_stack *a, t_stack *b)
{
	int		pivot;
	int		init;

	if (b->top < 0)
		return ;
	init = a->top + 1;
	pivot = ft_get_pivot(b, 0, b->top);
	while (!ft_exit(b, pivot))
	{
		if (b->data[b->top] > pivot)
			ft_exec_cmd(a, b, "pa", 1);
		else
			ft_exec_cmd(a, b, "rb", 1);
	}
	ft_push_pivot(a, b, pivot);
	ft_sort(a, b, a->data[init], a->data[a->top - 1]);
}
