/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:58:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/04 20:22:26 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_partition(t_stack *a, t_stack *b, int start)
{
	int		pivot;
	int		init;

	init = start;
	pivot = a->data[start];
ft_display(*a, *b);
ft_printf("pivot = %d\t <-- IN PARTITION.c\n", pivot);
	while (start <= a->top)
	{
		if (a->data[a->top] <= pivot)
			ft_exec_cmd(a, b, "pb", 1);
		else
		{
			ft_exec_cmd(a, b, "ra", 1);
			start++;
		}
	}
	while (init > 0 && start > init)
	{
		ft_exec_cmd(a, b, "rra", 1);
		start--;
	}
	ft_exec_cmd(a, b, "pa", 1);
	return (a->top);
}
