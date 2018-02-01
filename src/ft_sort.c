/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:53:50 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/01 19:02:06 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	int		mean;
	int		i;
	int		nb_elm;

	mean = ft_tab_mean(a->data, a->top + 1);
	nb_elm = a->top;
	i = -1;
	while (++i <= nb_elm)
	{
		if (a->data[a->top] < mean)
			ft_exec_cmd(a, b, "pb");
		else
			ft_exec_cmd(a, b, "ra");
		ft_printf("mean = %d ; top = %d\n", mean, a->top);
		ft_printf("min = %d\n", ft_tab_min(a->data, a->top + 1));
		ft_display(*a, *b);
	}
}
