/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:47:22 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/04 16:58:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_sort_b(t_stack *a, t_stack *b)
{
	int		pivot;
	int		init;
	int		start;

	if (b->top < 0)
		return ;
	init = a->top + 1;
	start = 0;
	ft_set_pivot(a, b, 'b');
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
