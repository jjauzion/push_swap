/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:35:01 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/02 18:51:50 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_flush(t_stack *a, t_stack *b)
{
	int		pivot;
	int		bottom;

	if (b->top < 0)
		return (1);
	pivot = b->data[0];
	bottom = 0;
	while (bottom <= b->top)
	{
		if (b->data[b->top] >= pivot)
			ft_exec_cmd(a, b, "pa");
		else
		{
			ft_exec_cmd(a, b, "rb");
			bottom++;
		}
	}
	ft_flush(a, b);
	return (1);
}
