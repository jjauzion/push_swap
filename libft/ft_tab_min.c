/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:24:27 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/01 19:02:56 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tab_min(int *tab, int nb_elm)
{
	int		i;
	int		min;

	if (!tab || nb_elm <= 0)
		return (0);
	min = tab[0];
	i = 0;
	while (++i < nb_elm)
		min = (min > tab[i]) ? min = tab[i] : min;
	return (min);
}
