/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:55:57 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/12 10:10:23 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_init_stack(t_stack **a, char **argv, int size, int *option)
{
	int	i;
	int	j;
	int	tmp;

	(*a)->top = -1;
	if (*option == 1 || *option == 2)
		j = 2;
	else if (*option == 3)
		j = 3;
	else
		j = 1;
	while (size >= j)
	{
		tmp = ft_atoi(argv[size]);
		i = (*a)->top + 1;
		while (--i >= 0)
			if ((*a)->data[i] == tmp)
				return (1);
		(*a)->top++;
		(*a)->data[(*a)->top] = tmp;
		size--;
	}
	return (0);
}

static int	ft_get_option(char **argv, int *option)
{
	int	i;

	i = 1;
	*option = 0;
	while (*option >= 0 && argv[i][0] == '-' && ft_isalpha((int)argv[i][1]))
	{
		if (ft_strequ(argv[i], "-v"))
			*option += 1;
		else if (ft_strequ(argv[i], "-c"))
			*option += 2;
		else
			*option = -1;
		i++;
	}
	return (i);
}

static int	ft_check_input(char **argv, int size, int *option)
{
	int	i;

	i = ft_get_option(argv, option);
	if (*option < 0 || *option > 3)
	{
		ft_printf("Usage : -v for verbose mode ; -c to display last command\n");
		return (1);
	}
	if (*option >= 0 && size <= 2)
	{
		ft_printf("Usage : At least two integer argument required\n");
		return (1);
	}
	while (i <= size)
	{
		if (!ft_isnumber(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int			ft_parser(t_stack **a, t_stack **b, char **argv, int size)
{
	int		option;

	*a = (t_stack*)malloc(sizeof(t_stack));
	*b = (t_stack*)malloc(sizeof(t_stack));
	if (!(*b) || !(*a))
		return (-1);
	(*a)->data = (int*)malloc(sizeof(int) * size);
	(*b)->data = (int*)ft_memalloc(sizeof(int) * size);
	if (!(*a)->data || !(*b)->data)
		return (-1);
	(*b)->top = -1;
	if (ft_check_input(argv, size, &option) ||
			ft_init_stack(a, argv, size, &option))
	{
		ft_free_stack(a);
		ft_free_stack(b);
		ft_putendl("Error");
		return (-1);
	}
	return (option);
}
