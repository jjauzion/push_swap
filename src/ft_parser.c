/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:55:57 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/31 14:19:48 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_init_stack(t_stack **a, t_stack **b, char **argv, int size)
{
	int	i;
	int	j;
	int	tmp;

	(*a)->top = 0;
	(*b)->top = -1;
	j = size;
	while (--j >= 0)
	{
		tmp = ft_atoi(argv[(*a)->top + 1]);
		i = size;
		while (--i > j)
		{
			if ((*a)->data[i] == tmp)
				return (1);
		}
		(*a)->data[j] = tmp;
		(*b)->data[j] = 0;
		(*a)->top++;
	}
	(*a)->top--;
	return (0);
}

static int	ft_check_input(char **argv, int size)
{
	while (size)
	{
		if (!ft_isnumber(argv[size]))
			return (1);
		size--;
	}
	return (0);
}

int			ft_parser(t_stack **a, t_stack **b, char **argv, int size)
{
	*a = (t_stack*)malloc(sizeof(t_stack));
	*b = (t_stack*)malloc(sizeof(t_stack));
	if (!(*b) || !(*a))
	{
		ft_putendl("Error");
		return (1);
	}
	(*a)->data = (int*)malloc(sizeof(int) * size);
	(*b)->data = (int*)malloc(sizeof(int) * size);
	if (!(*a)->data || !(*b)->data)
	{
		ft_putendl("Error");
		return (1);
	}
	if (ft_check_input(argv, size) || ft_init_stack(a, b, argv, size))
	{
		ft_free_stack(a);
		ft_free_stack(b);
		ft_putendl("Error");
		return (1);
	}
	return (0);
}
