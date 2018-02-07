/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:39:44 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/07 18:39:50 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_local_min(t_stack *s, int start_i)
{
	int	min;

	min = s->data[start_i];
	while (++start_i <= s->top)
		if (s->data[start_i] < min)
			min = s->data[start_i];
	return (min);
}

int		ft_local_max(t_stack *s, int start_i)
{
	int	max;

	max = s->data[start_i];
	while (++start_i <= s->top)
		if (s->data[start_i] > max)
			max = s->data[start_i];
	return (max);
}
