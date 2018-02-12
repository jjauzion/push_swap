/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:15:29 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/12 10:56:53 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_checker(t_stack *a, t_stack *b, int option)
{
	char		*command;
	int			ret;

	ret = 1;
	while (ret == 1)
	{
		ret = (get_next_line(0, &command) && ft_exec_cmd(a, b, command, 0));
		if (ret == 1 && (option == 2 || option == 3))
			ft_printf("{blue}command : %s{eoc}\n", command);
		if (ret == 1 && (option == 1 || option == 3))
			ft_display(*a, *b);
		ft_strdel(&command);
	}
}

int			main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			option;

	a = NULL;
	if (argc < 2)
	{
		ft_printf("Usage : At least one integer argument required\n");
		return (1);
	}
	if (((option = ft_parser(&a, &b, argv, argc - 1)) < 0))
		return (1);
	if ((option == 1 || option == 3))
		ft_display(*a, *b);
	ft_checker(a, b, option);
	if (!ft_isnsorted(*a, 0, a->top) && b->top < 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
