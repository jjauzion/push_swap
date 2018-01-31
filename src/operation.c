/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:07:05 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/31 13:34:23 by jjauzion         ###   ########.fr       */
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
	a->data[a->top]	= a->data[a->top - 1];
	a->data[a->top - 1] = tmp;
}

void	ft_swapb(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)a;
	if (b->top < 1)
		return ;
	tmp = b->data[b->top];
	b->data[b->top]	= b->data[b->top - 1];
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
