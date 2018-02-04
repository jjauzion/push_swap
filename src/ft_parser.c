/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:55:57 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/04 19:59:11 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_init_stack(t_stack **a, char **argv, int size, char *option)
{
	int	i;
	int	j;
	int	tmp;

	(*a)->top = -1;
	if (*option == 'v')
		j = 1;
	else
		j = 0;
	while (++j <= size)
	{
		tmp = ft_atoi(argv[j]);
		i = (*a)->top;
		while (i >= 0)
		{
			if ((*a)->data[i] == tmp)
				return (1);
			i--;
		}
		(*a)->top++;
		(*a)->data[(*a)->top] = tmp;
	}
	return (0);
}

static int	ft_check_input(char **argv, int size, char *option)
{
	int	i;

	i = 0;
	if (ft_strequ(argv[1], "-v"))
	{
		*option = 'v';
		i = 1;
	}
	else
		*option = '\0';
	if (*option == 'v' && size <= 2)
	{
		ft_printf("Usage : At least two integer argument required\n");
		return (1);
	}
	while (++i <= size)
	{
		if (!ft_isnumber(argv[i]))
			return (1);
	}
	return (0);
}

int			ft_parser(t_stack **a, t_stack **b, char **argv, int size)
{
	char	option;

	*a = (t_stack*)malloc(sizeof(t_stack));
	*b = (t_stack*)malloc(sizeof(t_stack));
	if (!(*b) || !(*a))
	{
		ft_putendl("Error");
		return (-1);
	}
	(*a)->data = (int*)malloc(sizeof(int) * size);
	(*b)->data = (int*)ft_memalloc(sizeof(int) * size);
	if (!(*a)->data || !(*b)->data)
	{
		ft_putendl("Error");
		return (-1);
	}
	(*b)->top = -1;
	if (ft_check_input(argv, size, &option) || ft_init_stack(a, argv, size, &option))
	{
		ft_free_stack(a);
		ft_free_stack(b);
		ft_putendl("Error");
		return (-1);
	}
	return ((option == 'v') ? 1 : 0);
}
