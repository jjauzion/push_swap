/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:53:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/04 20:13:49 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sort(t_stack *a, t_stack *b, int start, int end)
{
	int		pindex;
	int		cpt;

	ft_sort_b(a, b);
	if (start >= end)
		return ;
	cpt = 0;
	while (end < a->top)
	{
ft_printf("++ra\t <-- IN SORT.c\n");
		ft_exec_cmd(a, b, "ra", 1);
		end++;
		start++;
		cpt++;
	}
	pindex = ft_partition(a, b, start);
	ft_sort(a, b, start, pindex - 1);
	while (cpt > 0)
	{
ft_printf("--rra\t <-- IN SORT.c\n");
		ft_exec_cmd(a, b, "rra", 1);
		end--;
		start--;
		cpt--;
	}
}
