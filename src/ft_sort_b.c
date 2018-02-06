/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 12:47:22 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/06 18:24:01 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_push_pivot(t_stack *a, t_stack *b, int pivot)
{
	int	i;

	i = -1;
	while (b->data[++i] != pivot);
	while (b->data[b->top] != pivot)
		if (i > b->top / 2)
			ft_exec_cmd(a, b, "rb", 1);
		else
			ft_exec_cmd(a, b, "rrb", 1);
	ft_exec_cmd(a, b, "pa", 1);
}

void			ft_sort_b(t_stack *a, t_stack *b)
{
	int		pivot;
	int		init;
	int		start_i;

//ft_printf("--> IN SORT_B\n");
	if (b->top < 0)
		return ;
	init = a->top + 1;
	start_i = 0;
	pivot = ft_get_pivot(b, 0, b->top);
//ft_printf("pivot = %d\t <-- IN SORT_B.c\n", pivot);
//getchar();
	while (start_i < b->top)
	{
		if (b->data[b->top] > pivot)
			ft_exec_cmd(a, b, "pa", 1);
		else
		{
			ft_exec_cmd(a, b, "rb", 1);
			start_i++;
		}
	}
	if (b->data[b->top] > pivot)
		ft_exec_cmd(a, b, "pa", 1);
	ft_push_pivot(a, b, pivot);
	ft_sort(a, b, a->data[init], a->data[a->top - 1]);
}
