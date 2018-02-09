/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:57:45 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/09 20:58:07 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_rotate_stack(t_stack *a, t_stack *b, int index)
{
	int	target;

	target = a->data[index];
	while (a->data[a->top] != target)
		if (index >= a->top / 2)
			ft_exec_cmd(a, b, "ra", 1);
		else
			ft_exec_cmd(a, b, "rra", 1);
}
