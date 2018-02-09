/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fulltab5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:49:19 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/09 21:13:20 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_next_i(t_stack *s, int i, int option)
{
	if (option == -1)
	{
		if (i - 1 < 0)
			return (s->top);
		return (i - 1);
	}
	else
	{
		if (i + 1 > s->top)
			return (0);
		return (i + 1);
	}
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
		tmp = ft_next_i(s, i, -1);
		if (s->data[i] > s->data[tmp] &&
				!(s->data[i] == max && s->data[tmp] == min))
			return (i);
		tmp = ft_next_i(s, i, 1);
		if (s->data[i] < s->data[tmp]
				&& !(s->data[i] == min && s->data[tmp] == max))
			return (i);
	}
	return (-1);
}

static int		ft_check_swap(t_stack *s)
{
	int	i;
	int	min;
	int	max;

	min = ft_local_min(s, 0);
	max = ft_local_max(s, 0);
	i = s->top;
	if (s->data[i - 1] < s->data[i] ||
			(s->data[i - 1] == max && s->data[i] == min))
		if (s->data[i - 1] > s->data[0] ||
				(s->data[i - 1] == min && s->data[0] == max))
			if (s->data[i] < s->data[i - 2] ||
					(s->data[i] == max && s->data[i - 2] == min))
				return (1);
	return (0);
}

static void		ft_loop(t_stack *a, t_stack *b, int count)
{
	int	max;
	int	min;
	int	i;
	int	outlier_i;

	while (count)
	{
		min = ft_local_min(a, 0);
		max = ft_local_max(a, 0);
		i = 0;
		outlier_i = -1;
		while (i <= a->top && outlier_i < 0)
		{
			if ((b->data[b->top] < a->data[i] &&
						b->data[b->top] > a->data[ft_next_i(a, i, 1)]) ||
					(b->data[b->top] > max && a->data[i] == min) ||
					(b->data[b->top] < min &&
					a->data[ft_next_i(a, i, 1)] == max))
				outlier_i = i;
			i++;
		}
		ft_rotate_stack(a, b, outlier_i);
		ft_exec_cmd(a, b, "pa", 1);
		count--;
	}
}

int				ft_fulltab5(t_stack *a, t_stack *b)
{
	int	outlier_i;
	int	count;

	count = 0;
	while ((outlier_i = ft_outlier(a)) >= 0)
	{
		ft_rotate_stack(a, b, outlier_i);
		if (ft_check_swap(a))
			ft_exec_cmd(a, b, "sa", 1);
		else
		{
			ft_exec_cmd(a, b, "pb", 1);
			count++;
		}
	}
	ft_loop(a, b, count);
	return (0);
}
