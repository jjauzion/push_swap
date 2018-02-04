/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:43:20 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/04 16:56:16 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			ft_get_pivot(t_stack *s)
{
	int		mean;
	int		i;
	int		delta;
	int		index;

	mean = ft_tab_mean(s->data, s->top + 1);
	delta = ABS((s->data[0] - mean));
	index = 0;
	i = 0;
	while (++i <= s->top)
	{
		if (delta > (ABS((s->data[i] - mean))))
		{
			delta = ABS((s->data[i] - mean));
			index = i;
		}
	}
	return (index);
}

void	ft_set_pivot(t_stack *a, t_stack *b, char option)
{
	int	p_index;

	if (option == 'a')
	{
		p_index = ft_get_pivot(a);
		if (p_index > (a->top + 1) / 2)
			while (p_index++ <= a->top)
				ft_exec_cmd(a, b, "ra", 1);
		else
			while (--p_index >= 0)
				ft_exec_cmd(a, b, "rra", 1);
	}
	if (option == 'b')
	{
		p_index = ft_get_pivot(b);
		if (p_index > (b->top + 1) / 2)
			while (p_index++ <= b->top)
				ft_exec_cmd(a, b, "rb", 1);
		else
			while (--p_index >= 0)
				ft_exec_cmd(a, b, "rrb", 1);
	}
}

/*
   static void	ft_set_pivot(t_stack *a, t_stack *b, int start)
   {
   int		i;
   int		mean;
   int		delta;
   int		pivot;

   mean = 0;
   i = start;
   while (i <= a->top)
   {
   mean += a->data[i];
   i++;
   }
   mean = mean / (a->top - start + 1);
   delta = ABS((a->data[start] - mean));
   pivot = a->data[start];
   i = start;
   while (++i <= a->top)
   {
   if (delta > (ABS((a->data[i] - mean))))
   {
   delta = ABS((a->data[i] - mean));
   pivot = a->data[i];
   }
   }
   if (a->data[start] == pivot)
   return ;
   i = start;
   while (i <= a->top)
   {
   if (a->data[a->top] == pivot)
   ft_exec_cmd(a, b, "pb", 1);
   else
   {
   ft_exec_cmd(a, b, "ra", 1);
   i++;
   }
   }
   ft_exec_cmd(a, b, "pa", 1);
   while ((--i - start) >= 0)
   ft_exec_cmd(a, b, "rra", 1);
   }
*/
