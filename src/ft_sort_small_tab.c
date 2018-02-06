/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:21:32 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/06 20:56:00 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_local_min(t_stack *s, int start_i)
{
	int	min;

	min = s->data[start_i];
	while (++start_i <= s->top)
		if (s->data[start_i] < min)
			min = s->data[start_i];
	return (min);
}

static int		ft_tab2(t_stack *a, t_stack *b, int start_i)
{
	if (a->data[start_i] < a->data[a->top])
		ft_exec_cmd(a, b, "sa", 1);
	ft_exec_cmd(a, b, "ra", 1);
	return (1);
}

static int		ft_tab3(t_stack *a, t_stack *b, int start_i)
{ 
	int	min;
	
	min = ft_local_min(a, start_i);
	if (a->data[a->top] == min)
	{
		ft_exec_cmd(a, b, "ra", 1);
		return (ft_tab2(a, b, start_i + 1));
	}
	if (a->data[a->top - 1] == min)
	{
		ft_exec_cmd(a, b, "sa", 1);
		ft_exec_cmd(a, b, "ra", 1);
		return (ft_tab2(a, b, start_i + 1));
	}
	ft_exec_cmd(a, b, "pb", 1);
	ft_exec_cmd(a, b, "sa", 1);
	ft_exec_cmd(a, b, "ra", 1);
	if (a->data[a->top] > b->data[b->top])
		ft_exec_cmd(a, b, "pa", 1);
	ft_exec_cmd(a, b, "ra", 1);
	if (b->top >= 0)
		ft_exec_cmd(a, b, "pa", 1);
	return (1);
}

static int		ft_tab4(t_stack *a, t_stack *b, int start_i)
{
	int	min;
	
	min = ft_local_min(a, start_i);
	if (a->data[a->top] == min)
	{
		ft_exec_cmd(a, b, "ra", 1);
		return (ft_tab3(a, b, start_i + 1));
	}
	if (a->data[a->top - 1] == min)
	{
		ft_exec_cmd(a, b, "sa", 1);
		ft_exec_cmd(a, b, "ra", 1);
		return (ft_tab3(a, b, start_i + 1));
	}
	return (0);
}

int		ft_sort_small_tab(t_stack *a, t_stack *b, int start_i)
{
	if (start_i == a->top - 1)
		return (ft_tab2(a, b, start_i));
	else if (start_i == a->top - 2)
		return (ft_tab3(a, b, start_i));
	else if (start_i == a->top - 3)
		return (ft_tab4(a, b, start_i));
	else
		return (0);
}
