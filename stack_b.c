/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:37:06 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 14:23:56 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*iterate_a;
	t_stack_node	*set_target_node;
	int				target_value;

	while (b)
	{
		target_value = INT_MAX;
		iterate_a = a;
		while (iterate_a)
		{
			if (b->nbr < iterate_a->nbr && iterate_a->nbr < target_value)
			{
				target_value = iterate_a->nbr;
				set_target_node = iterate_a;
			}
			iterate_a = iterate_a->next_node;
		}
		if (target_value == INT_MAX)
			set_target_node = find_min(a);
		b->target_node = set_target_node;
		b = b->next_node;
	}
}

void	prep_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
