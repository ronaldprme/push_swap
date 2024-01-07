/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:37:42 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/07 13:58:20 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	if (!*stack || !((*stack)->next_node))
		return ;
	*stack = (*stack)->next_node;
	(*stack)->prev_node->prev_node = *stack;
	(*stack)->prev_node->next_node = (*stack)->next_node;
	if ((*stack)->next_node)
		(*stack)->next_node->prev_node = (*stack)->prev_node;
	(*stack)->next_node = (*stack)->prev_node;
	(*stack)->prev_node = NULL;
}

void	sa(t_stack_node	**a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
	