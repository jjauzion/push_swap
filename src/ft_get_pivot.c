/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:43:20 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/11 12:13:31 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_mean(int *tab, int start, int end)
{
	int		i;
	int		sum;

	if (!tab || start >= end)
		return (0);
	sum = 0;
	i = start - 1;
	while (++i <= end)
		sum += tab[i];
	return (sum / (i - start));
}

int		ft_get_pivot(t_stack *s, int start_i, int end_i)
{
	int		i;
	int		delta;
	int		pivot;
	int		mean;

	mean = ft_get_mean(s->data, start_i, end_i);
	delta = ABS((s->data[start_i] - mean));
	pivot = s->data[start_i];
	i = start_i;
	while (++i <= s->top)
	{
		if (delta > (ABS((s->data[i] - mean))))
		{
			delta = ABS((s->data[i] - mean));
			pivot = s->data[i];
		}
	}
	return (pivot);
}
