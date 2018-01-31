/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:49:58 by jjauzion          #+#    #+#             */
/*   Updated: 2018/01/31 13:36:38 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_init_cmdlst(t_cmd cmd_lst[12])
{
	cmd_lst[0].cmd = "sa";
	cmd_lst[0].fct = &ft_swapa;
	cmd_lst[1].cmd = "sb";
	cmd_lst[1].fct = &ft_swapb;
	cmd_lst[2].cmd = "ss";
	cmd_lst[2].fct = &ft_swapab;
	cmd_lst[3].cmd = "pa";
	cmd_lst[3].fct = &ft_pusha;
	cmd_lst[4].cmd = "pb";
	cmd_lst[4].fct = &ft_pushb;
	cmd_lst[5].cmd = "ra";
	cmd_lst[5].fct = &ft_rotatea;
	cmd_lst[6].cmd = "rb";
	cmd_lst[6].fct = &ft_rotateb;
	cmd_lst[7].cmd = "rr";
	cmd_lst[7].fct = &ft_rotateab;
	cmd_lst[8].cmd = "rra";
	cmd_lst[8].fct = &ft_rev_rotatea;
	cmd_lst[9].cmd = "rrb";
	cmd_lst[9].fct = &ft_rev_rotateb;
	cmd_lst[10].cmd = "rrr";
	cmd_lst[10].fct = &ft_rev_rotateab;
	cmd_lst[11].cmd = "quit";
}

int			ft_exec_cmd(t_stack *a, t_stack *b, char *cmd)
{
	t_cmd	cmd_list[12];
	int		i;

	ft_init_cmdlst(cmd_list);
	i = 0;
	while (i < 12 && !ft_strequ(cmd, cmd_list[i].cmd))
		i++;
	if (i == 11)
		return (0);
	if (i == 12)
	{
		ft_printf("Unknown command ('quit' to exit)\n");
		return (1);
	}
	cmd_list[i].fct(a, b);
	return (1);
}
