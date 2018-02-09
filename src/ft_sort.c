/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:53:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/09 20:29:36 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sort(t_stack *a, t_stack *b, int start_v, int end_v)
{
	int		pindex;
	int		start_i;
	int		end_i;

	if (a->top <= 20 && b->top < 0)
	{
		ft_fulltab5(a, b);
		return ;
	}
	ft_sort_b(a, b);
	start_i = ft_get_index(a, start_v);
	end_i = ft_get_index(a, end_v);
	if (start_i >= end_i || !ft_isnsorted(*a, start_i, end_i))
		return ;
	while (end_v != a->data[a->top])
	{
		if (end_i > a->top / 2)
			ft_exec_cmd(a, b, "ra", 1);
		else
			ft_exec_cmd(a, b, "rra", 1);
	}
	start_i = ft_get_index(a, start_v);
	pindex = ft_partition(a, b, start_i);
	ft_sort(a, b, a->data[start_i], a->data[pindex - 1]);
}
