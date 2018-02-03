/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:58:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/03 19:18:25 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_partition(t_stack *a, t_stack *b, int start, int end)
{
	int		pivot;
	int		init;

	(void) end;
	init = start;
	pivot = a->data[start];
	while (start <= a->top)
	{
		if (a->data[a->top] <= pivot)
			ft_exec_cmd(a, b, "pb");
		else
		{
			ft_exec_cmd(a, b, "ra");
			start++;
		}
	}
	while (start > init)
	{
		ft_exec_cmd(a, b, "rra");
		start--;
	}
	ft_exec_cmd(a, b, "pa");
	return (a->top);
}
