/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:53:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/02 20:04:01 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sort(t_stack *a, t_stack *b, int init)
{
	int		pivot;
	int		top;
	int		bottom;
	int		i;

getchar();
	if (ft_issorted(*a))
		return ;
	top = a->top;
	bottom = init;
	pivot = a->data[bottom];
	i = 0;
	while (bottom <= top)
	{
		if (a->data[top] <= pivot)
		{
			ft_exec_cmd(a, b, "pb");
			top--;
		}
		else
		{
			ft_exec_cmd(a, b, "ra");
			bottom++;
		}
	}
ft_display(*a, *b);
ft_printf("init = %d ; bot = %d\n", init, bottom);
	while (bottom > init)
	{
		ft_exec_cmd(a, b, "rra");
		bottom--;
	}
ft_display(*a, *b);
	ft_flush(a, b);
ft_display(*a, *b);
ft_printf("top = %d ; bot = %d\n", top, bottom);
	ft_sort(a, b, bottom + 1);
}
