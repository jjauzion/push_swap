/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:53:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/03 20:30:46 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sort(t_stack *a, t_stack *b, int start, int end)
{
	int		pindex;
	int		cpt;

/*ft_printf("> > > > > > BEGIN SORT > > > > > >\n");
ft_printf("start = %d ; end = %d\n", start, end);
ft_display(*a, *b);
getchar();*/

	if (start >= end)
		return ;
	cpt = 0;
	while (end < a->top)
	{
//ft_putendl("--------------------> ra ++ <-----------------------");
		ft_exec_cmd(a, b, "ra", 1);
		end++;
		start++;
		cpt++;
	}
//ft_putendl("1");
	pindex = ft_partition(a, b, start, end);
//ft_putendl("2");
	ft_flush_b(a, b);
//ft_putendl("3");
	ft_sort(a, b, pindex + 1, end);
//ft_putendl("4");
	ft_sort(a, b, start, pindex - 1);
//ft_putendl("5");
	while (cpt > 0)
	{
//ft_putendl("--------------------> -- rra <-----------------------");
		ft_exec_cmd(a, b, "rra", 1);
		end--;
		start--;
		cpt--;
	}
//ft_printf("< < < < < < OUT OFSORT < < < < < <\n");
}
