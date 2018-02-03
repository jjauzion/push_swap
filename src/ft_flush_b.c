#include "header.h"

void	ft_flush_b(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
		ft_exec_cmd(a, b, "pa", 1);
}
