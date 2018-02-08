/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fulltab5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:49:19 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/08 15:44:29 by jjauzion         ###   ########.fr       */
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
		if (s->data[i] > s->data[tmp] && !(s->data[i] == max && s->data[tmp] == min))
			return (i);
		tmp = ft_above(s, i);
		if (s->data[i] < s->data[tmp] && !(s->data[i] == min && s->data[tmp] == max))
			return (i);
	}
	return (-1);
}

static void		ft_rotate(t_stack *a, t_stack *b, int index)
{
	int	target;
	
	target = a->data[index];
	while (a->data[a->top] != target)
		if (index >= a->top / 2)
			ft_exec_cmd(a, b, "ra", 1);
		else
			ft_exec_cmd(a, b, "rra", 1);
}

static int		ft_check_swap(t_stack *s)
{
	int	i;
	int	min;
	int	max;

	min = ft_local_min(s, 0);
	max = ft_local_max(s, 0);
	i = s->top;
	if (s->data[i - 1] < s->data[i] || (s->data[i - 1] == max && s->data[i] == min))
		if (s->data[i - 1] > s->data[0] || (s->data[i - 1] == min && s->data[0] == max))
			if (s->data[i] < s->data[i - 2] || (s->data[i] == max && s->data[i - 2] == min))
				return (1);
	return (0);
}

int				ft_fulltab5(t_stack *a, t_stack *b)
{
	int	outlier_i;
	int	i;
	int	min;
	int	max;
	int	count;

	count = 0;
	while ((outlier_i = ft_outlier(a)) >= 0)
	{
		ft_rotate(a, b, outlier_i);
		if (ft_check_swap(a))
			ft_exec_cmd(a, b, "sa", 1);
		else
		{
			ft_exec_cmd(a, b, "pb", 1);
			count++;
		}
	}
	while (count)
	{
		min = ft_local_min(a, 0);
		max = ft_local_max(a, 0);
		i = 0;
		outlier_i = -1;
		while (i <= a->top && outlier_i < 0)
		{
			if (b->data[b->top] < a->data[i] && b->data[b->top] > a->data[ft_above(a, i)])
				outlier_i = i;
			else if (b->data[b->top] > max && a->data[i] == min)
				outlier_i = i;
			else if (b->data[b->top] < min && a->data[ft_above(a, i)] == max)
				outlier_i = i;
			i++;
		}
		ft_rotate(a, b, outlier_i);
		ft_exec_cmd(a, b, "pa", 1);
		count--;
	}
	return (0);
}
