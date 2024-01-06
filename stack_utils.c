/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:37:33 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 14:24:04 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next_node;
	}
	return (count);
}

int	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next_node)
	{
		if (stack->nbr > stack->next_node->nbr)
			return (0);
		stack = stack->next_node;
	}
	return (1);
}

t_stack_node	*find_last(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next_node)
		node = node->next_node;
	return (node);
}

t_stack_node	*find_min(t_stack_node *node)
{
	int				min;
	t_stack_node	*min_node;

	if (!node)
		return (NULL);
	min = INT_MAX;
	while (node)
	{
		if (min > node->nbr)
		{
			min = node->nbr;
			min_node = node;
		}
		node = node->next_node;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *node)
{
	int				max;
	t_stack_node	*max_node;

	if (!node)
		return (NULL);
	max = INT_MIN;
	while (node)
	{
		if (node->nbr > max)
		{
			max = node->nbr;
			max_node = node;
		}
		node = node->next_node;
	}
	return (max_node);
}
