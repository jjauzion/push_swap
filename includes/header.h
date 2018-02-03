/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:14:12 by jjauzion          #+#    #+#             */
/*   Updated: 2018/02/03 19:10:37 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "ft_printf.h"

typedef struct	s_stack
{
	int			*data;
	int			top;
}				t_stack;

typedef struct	s_command
{
	char	*cmd;
	void	(*fct)(t_stack *a, t_stack *b);
}				t_cmd;

void			ft_free_stack(t_stack **s);
int				ft_parser(t_stack **a, t_stack **b, char **argv, int size);
int				get_next_line(const int fd, char **line);
int				ft_exec_cmd(t_stack *a, t_stack *b, char *cmd);
void			ft_display(t_stack a, t_stack b);
int				ft_issorted(t_stack a);
void			ft_sort(t_stack *a, t_stack *b, int start, int end);
void			ft_flush_b(t_stack *a, t_stack *b);
int				ft_partition(t_stack *a, t_stack *b, int start, int end);

void			ft_swapa(t_stack *a, t_stack *b);
void			ft_swapb(t_stack *a, t_stack *b);
void			ft_swapab(t_stack *a, t_stack *b);
void			ft_pusha(t_stack *a, t_stack *b);
void			ft_pushb(t_stack *a, t_stack *b);
void			ft_rotatea(t_stack *a, t_stack *b);
void			ft_rotateb(t_stack *a, t_stack *b);
void			ft_rotateab(t_stack *a, t_stack *b);
void			ft_rev_rotatea(t_stack *a, t_stack *b);
void			ft_rev_rotateb(t_stack *a, t_stack *b);
void			ft_rev_rotateab(t_stack *a, t_stack *b);

#endif
