/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 12:21:32 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/08 10:41:13 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_tab2(t_stack *a, t_stack *b, int start_i)
{
	if (a->data[start_i] < a->data[a->top])
		ft_exec_cmd(a, b, "sa", 1);
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
	int	scase;

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
	ft_exec_cmd(a, b, "pb", 1);
	ft_exec_cmd(a, b, "pb", 1);
	if (min == a->data[a->top - 1])
		ft_exec_cmd(a, b, "sa", 1);
	if ((scase = b->data[b->top - 1] < b->data[b->top] && b->data[b->top] > a->data[a->top]))
		ft_exec_cmd(a, b, "ra", 1);
	else
		ft_exec_cmd(a, b, "rr", 1);
	ft_exec_cmd(a, b, "pa", 1);
	if (scase)
		ft_exec_cmd(a, b, "sa", 1);
	ft_exec_cmd(a, b, "pa", 1);
	return (ft_tab3(a, b, start_i + 1));
}

static int		ft_tab5(t_stack *a, t_stack *b, int start_i)
{
	int	min;
	int	tmp;
	
	min = ft_local_min(a, start_i);
	if (a->data[a->top] == min)
	{
		ft_exec_cmd(a, b, "ra", 1);
		return (ft_tab4(a, b, start_i + 1));
	}
	if (a->data[a->top - 1] == min)
	{
		ft_exec_cmd(a, b, "sa", 1);
		ft_exec_cmd(a, b, "ra", 1);
		return (ft_tab4(a, b, start_i + 1));
	}
	return (0);
	tmp = a->data[start_i + 1];
	ft_tab3(a, b, start_i + 2);
	while (a->data[a->top] != tmp)
		ft_exec_cmd(a, b, "ra", 1);
	return (ft_tab3(a, b, a->top - 1));
}

int		ft_sort_small_tab(t_stack *a, t_stack *b, int start_i)
{
//ft_printf("tab size = %d\n", a->top - start_i + 1);
	if (start_i == a->top - 1)
		return (ft_tab2(a, b, start_i));
	else if (start_i == a->top - 2)
		return (ft_tab3(a, b, start_i));
	else if (start_i == a->top - 3)
		return (ft_tab4(a, b, start_i));
	else if (start_i == a->top - 4)
		return (ft_tab5(a, b, start_i));
	else
		return (0);
}
