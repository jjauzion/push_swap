/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:58:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/13 15:39:21 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			option;

	a = NULL;
	if (argc < 2)
		return (1);
	if (((option = ft_parser(&a, &b, argv, argc - 1)) < 0))
		return (1);
	ft_sort(a, b, a->data[0], a->data[a->top]);
	ft_min2top_a(a, b);
	ft_free_stack(&a);
	ft_free_stack(&b);
}
