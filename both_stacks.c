/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:34:45 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:43:22 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	before_push(t_stack_node **stack, t_stack_node *target_node, char s)
{
	while (*stack != target_node)
	{
		if (s == 'a')
		{
			if (target_node->above_mid)
				ra(stack);
			else
				rra(stack);
		}
		else if (s == 'b')
		{
			if (target_node->above_mid)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = (stack_size(stack) / 2);
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_mid = 1;
		else
			stack->above_mid = 0;
		stack = stack->next_node;
		i++;
	}
}

t_stack_node	*find_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next_node;
	}
	return (NULL);
}
