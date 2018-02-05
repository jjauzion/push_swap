/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:53:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/05 18:38:18 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sort(t_stack *a, t_stack *b, int start_v, int end_v)
{
	int		pindex;
	int		cpt;
	int		start_i;
	int		end_i;

//ft_printf("--> IN SORT : start_v = %d ; end_v = %d\n", start_v, end_v);
	ft_sort_b(a, b);
//ft_printf("\t\t<-- OUT OF SORT_B : start_v = %d ; end_v = %d\n", start_v, end_v);
//getchar();
	start_i = ft_get_index(a, start_v);
	end_i = ft_get_index(a, end_v);
	if (start_i < 0 || end_i < 0)
	{
		ft_printf("value not found\n");
		return ;
	}
	if (start_i >= end_i)
		return ;
	cpt = 0;
	while (end_i < a->top)
	{
//ft_printf("++ra\t +++++\n");
		ft_exec_cmd(a, b, "ra", 1);
		end_i++;
		start_i++;
		cpt++;
	}
	pindex = ft_partition(a, b, start_i);
//ft_printf("\t\t<-- OUT OF PARTITION\n");
	ft_sort(a, b, a->data[start_i], a->data[pindex - 1]);
}
