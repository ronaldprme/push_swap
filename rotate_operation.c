/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:36:11 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:42:46 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*old_first;

	if (!*stack || !(*stack)->next_node)
		return ;
	old_first = (*stack);
	last_node = find_last(*stack);
	*stack = (*stack)->next_node;
	(*stack)->prev_node = NULL;
	last_node->next_node = old_first;
	old_first->prev_node = last_node;
	old_first->next_node = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
