/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:23:05 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:21:41 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next_node;
	if (*src)
		(*src)->prev_node = NULL;
	node_to_push->prev_node = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next_node = NULL;
	}
	else
	{
		node_to_push->next_node = *dest;
		(*dest)->prev_node = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
