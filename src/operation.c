/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:37:22 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/09 20:37:24 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swapa(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)b;
	if (a->top < 1)
		return ;
	tmp = a->data[a->top];
	a->data[a->top] = a->data[a->top - 1];
	a->data[a->top - 1] = tmp;
}

void	ft_swapb(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)a;
	if (b->top < 1)
		return ;
	tmp = b->data[b->top];
	b->data[b->top] = b->data[b->top - 1];
	b->data[b->top - 1] = tmp;
}

void	ft_swapab(t_stack *a, t_stack *b)
{
	ft_swapa(a, b);
	ft_swapb(a, b);
}

void	ft_pusha(t_stack *a, t_stack *b)
{
	if (b->top < 0)
		return ;
	a->top++;
	a->data[a->top] = b->data[b->top];
	b->top--;
}

void	ft_pushb(t_stack *a, t_stack *b)
{
	if (a->top < 0)
		return ;
	b->top++;
	b->data[b->top] = a->data[a->top];
	a->top--;
}
