/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:58:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/02 19:06:32 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	ft_display(*a, *b);
	ft_sort(a, b, 0);
}
