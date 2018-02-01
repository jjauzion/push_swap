/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:04:19 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/01 19:05:33 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_median(int *tab, int nb_elm)
{
	int		i;
	int		median;

	if (!tab || nb_elm <= 0)
		return (0);
	median = tab[0];
	i = 0;
	while (++i < nb_elm)
		sum += tab[i];
	return (sum / nb_elm);
}
