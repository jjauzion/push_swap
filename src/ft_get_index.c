/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:10:17 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/05 11:12:19 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_index(t_stack *s, int val)
{
	int	i;

	i = -1;
	while (++i <= s->top)
	{
		if (s->data[i] == val)
			return (i);
	}
	return (-1);
}
