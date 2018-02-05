/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:58:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/05 18:27:31 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_partition(t_stack *a, t_stack *b, int start_i)
{
	int		pivot;
	int		init;

	if (ft_issorted(*a, start_i, a->top))
		return (a->top);
//ft_printf("--> IN PARTITION : start_i = %d\n", start_i);
	init = start_i;
	pivot = ft_get_pivot(a, start_i, a->top);
//ft_printf("start_i = %d ; pivot = %d\t <-- IN PARTITION.c\n", start_i, pivot);
//getchar();
	while (start_i <= a->top)
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
