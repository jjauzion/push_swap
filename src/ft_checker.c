/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:15:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/31 14:03:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*command;
	int			ret;

	a = NULL;
	if (argc <= 2)
	{
		ft_printf("Usage : At least two integer argument required\n");
		return (1);
	}
	if (ft_parser(&a, &b, argv, argc - 1))
		return (1);
	ft_display(*a, *b);
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(0, &command);
		ret = ft_exec_cmd(a, b, command);
		ft_display(*a, *b);
		if (ft_issorted(*a) && b->top < 0)
			ret = 0;
	}
	return (0);
}
