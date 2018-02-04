/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:47:22 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/04 14:30:40 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			ft_pivot(t_stack *s)
{
	int		mean;
	int		i;
	int		delta;
	int		index;

	mean = ft_tab_mean(s->data, s->top + 1);
	delta = ABS((s->data[0] - mean));
	index = 0;
	i = 0;
	while (++i <= s->top)
	{
		if (delta > (ABS((s->data[i] - mean))))
		{
			delta = ABS((s->data[i] - mean));
			index = i;
		}
	}
	return (index);
}

void		ft_sort_b(t_stack *a, t_stack *b)
{
	int		pivot;
	int		p_index;
	int		init;
	int		start;

	if (b->top < 0)
		return ;
	init = a->top + 1;
	start = 0;
	p_index = ft_pivot(b);
	if (p_index > (b->top + 1) / 2)
		while (p_index++ <= b->top)
			ft_exec_cmd(a, b, "rb", 1);
	else
		while (--p_index >= 0)
			ft_exec_cmd(a, b, "rrb", 1);
	pivot = b->data[start];
	while (start <= b->top)
	{
		if (b->data[b->top] >= pivot)
			ft_exec_cmd(a, b, "pa", 1);
		else
		{
			ft_exec_cmd(a, b, "rb", 1);
			start++;
		}
	}
	ft_sort(a, b, init, a->top - 1);
}
