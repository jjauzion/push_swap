/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:40:32 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/31 13:41:40 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_display(t_stack a, t_stack b)
{
	int		i;

	ft_printf("      %5s \t %5s \n", "a", "b");
	i = ft_max(a.top, b.top);
	while (i >= 0)
	{
		if (i > a.top)
			ft_printf("%3d: |%5s|\t|%5d|\n", i, " ", b.data[i]);
		else if (i > b.top)
			ft_printf("%3d: |%5d|\t|%5s|\n", i, a.data[i], " ");
		else
			ft_printf("%3d: |%5d|\t|%5d|\n", i, a.data[i], b.data[i]);
		i--;
	}
}
