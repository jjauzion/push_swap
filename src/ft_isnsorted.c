/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnsorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:48:21 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/06 15:48:27 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return the nb of cells preceded by a greater value then itself
*/

#include "header.h"

int		ft_isnsorted(t_stack s, int start_i, int end_i)
{
	int		i;
	int		cpt;

	cpt = 0;
	i = end_i;
	while (i > start_i)
	{
		if (s.data[i - 1] < s.data[i])
			cpt++;
		i--;
	}
	return (cpt);
}
