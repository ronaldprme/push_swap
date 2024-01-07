/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:36:58 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/07 12:24:22 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_sort(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_mid)
			ra(a);
		else
			rra(a);
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*iterate_b;
	t_stack_node	*set_target_node;
	int				target_value;

	while (a)
	{
		target_value = INT_MIN;
		iterate_b = b;
		while (iterate_b)
		{
			if (a->nbr > iterate_b->nbr && iterate_b->nbr > target_value)
			{
				target_value = iterate_b->nbr;
				set_target_node = iterate_b;
			}
			iterate_b = iterate_b->next_node;
		}
		if (target_value == INT_MIN)
			set_target_node = find_max(b);
		a->target_node = set_target_node;
		a = a->next_node;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	int				cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next_node;
		//printf("mid [%i] index[%i] nbr:[%i]push_cost: %i\n",
		//stack->above_mid, stack->index, stack->nbr, stack->push_cost);
	}
	
	cheapest_node->cheapest = 1;
}

void	calculate_cost(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		if (a->above_mid)
			a->push_cost = a->index;
		else
			a->push_cost = size_a - (a->index);
		if (a->target_node->above_mid)
			a->push_cost = a->push_cost + (a->target_node->index);
		else
			a->push_cost = a->push_cost + (size_b - (a->target_node->index));
		a = a->next_node;
	}
}

void	prep_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	calculate_cost(a, b);
	set_cheapest(a);
}
