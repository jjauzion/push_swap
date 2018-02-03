/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:58:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/03 19:30:45 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_min2top(t_stack *a, t_stack *b)
{
	int	min;
	int	i;

	min = ft_tab_min(a->data, a->top + 1);
	i = -1;
	while (a->data[++i] > min);
	while (a->data[a->top] > min)
	{
		if (i > a->top / 2)
			ft_exec_cmd(a, b, "ra");
		else
			ft_exec_cmd(a, b, "rra");
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	if (argc <= 2)
	{
		ft_printf("Usage : At least two integer argument required\n");
		return (1);
	}
	if (ft_parser(&a, &b, argv, argc - 1))
		return (1);
	ft_sort(a, b, 0, a->top);
ft_printf("--------- END SORT ----------\n");
ft_display(*a, *b);
	ft_min2top(a, b);
ft_display(*a, *b);
}
