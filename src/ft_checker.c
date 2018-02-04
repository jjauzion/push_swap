/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:15:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/04 19:52:14 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*command;
	int			ret;
	int			option;

	a = NULL;
	if (argc <= 2)
	{
		ft_printf("Usage : At least two integer argument required\n");
		return (1);
	}
	if (((option = ft_parser(&a, &b, argv, argc - 1)) < 0))
		return (1);
	ret = 1;
	while (ret == 1)
	{
		if (option == 1)
		{
			ft_display(*a, *b);
		}
		ret = (get_next_line(0, &command) && ft_exec_cmd(a, b, command, 0));
		ft_strdel(&command);
	}
	if (ft_issorted(*a) && b->top < 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
