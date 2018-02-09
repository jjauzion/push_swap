/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:35:53 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/09 20:36:29 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_rev_rotateb(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	(void)a;
	if (b->top < 0)
		return ;
	tmp = b->data[0];
	i = 0;
	while (i < b->top)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->top] = tmp;
}

void	ft_rev_rotatea(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	(void)b;
	if (a->top < 0)
		return ;
	tmp = a->data[0];
	i = 0;
	while (i < a->top)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->top] = tmp;
}

void	ft_rev_rotateab(t_stack *a, t_stack *b)
{
	ft_rev_rotatea(a, b);
	ft_rev_rotateb(a, b);
}
