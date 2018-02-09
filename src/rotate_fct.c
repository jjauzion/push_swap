/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:37:36 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/09 20:37:38 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rotatea(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	(void)b;
	if (a->top < 0)
		return ;
	tmp = a->data[a->top];
	i = a->top;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = tmp;
}

void	ft_rotateb(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	(void)a;
	if (b->top < 0)
		return ;
	tmp = b->data[b->top];
	i = b->top;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = tmp;
}

void	ft_rotateab(t_stack *a, t_stack *b)
{
	ft_rotatea(a, b);
	ft_rotateb(a, b);
}
