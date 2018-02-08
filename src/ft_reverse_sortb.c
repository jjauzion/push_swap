/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_sortb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:28:49 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/08 16:57:50 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_bellow(t_stack *s, int i)
{
	if (i - 1 < 0)
		return (s->top);
	return (i - 1);
}

static int		ft_above(t_stack *s, int i)
{
	if (i + 1 > s->top)
		return (0);
	return (i + 1);
}

static int		ft_outlier(t_stack *s)
{
	int	i;
	int tmp;
	int	min;
	int	max;

	min = ft_local_min(s, 0);
	max = ft_local_max(s, 0);
	i = s->top + 1;
	while (--i >= 0)
	{	
		tmp = ft_bellow(s, i);
		if (s->data[i] < s->data[tmp] && !(s->data[i] == min && s->data[tmp] == max))
			return (i);
		tmp = ft_above(s, i);
		if (s->data[i] > s->data[tmp] && !(s->data[i] == max && s->data[tmp] == min))
			return (i);
	}
	return (-1);
}

static void		ft_rotate(t_stack *a, t_stack *b, int index)
{
	int	target;

	target = b->data[index];
	while (b->data[b->top] != target)
		if (index >= b->top / 2)
			ft_exec_cmd(a, b, "rb", 1);
		else
			ft_exec_cmd(a, b, "rrb", 1);
}

static int		ft_check_swap(t_stack *s)
{
	int	i;
	int	min;
	int	max;

	min = ft_local_min(s, 0);
	max = ft_local_max(s, 0);
	i = s->top;
	if (s->data[i - 1] > s->data[i] || (s->data[i - 1] == min && s->data[i] == max))
		if (s->data[i - 1] < s->data[0] || (s->data[i - 1] == max && s->data[0] == min))
			if (s->data[i] > s->data[i - 2] || (s->data[i] == min && s->data[i - 2] == max))
				return (1);
	return (0);
}

void				ft_reverse_sortb(t_stack *a, t_stack *b)
{
	int	outlier_i;
	int	i;
	int	min;
	int	max;
	int	count;

	count = 0;
	while ((outlier_i = ft_outlier(b)) >= 0)
	{
		ft_rotate(a, b, outlier_i);
		if (ft_check_swap(b))
			ft_exec_cmd(a, b, "sb", 1);
		else
		{
			ft_exec_cmd(a, b, "pa", 1);
			count++;
		}
	}
	while (count)
	{
		min = ft_local_min(b, 0);
		max = ft_local_max(b, 0);
		i = 0;
		outlier_i = -1;
		while (i <= b->top && outlier_i < 0)
		{
			if (a->data[a->top] > b->data[i] && a->data[a->top] < b->data[ft_above(b, i)])
				outlier_i = i;
			else if (a->data[a->top] < min && b->data[i] == max)
				outlier_i = i;
			else if (a->data[a->top] > max && b->data[ft_above(b, i)] == min)
				outlier_i = i;
			i++;
		}
		ft_rotate(a, b, outlier_i);
		ft_exec_cmd(a, b, "pb", 1);
		count--;
	}
	ft_max2top_b(a, b);
	while (b->top >= 0)
		ft_exec_cmd(a, b, "pa", 1);
}
