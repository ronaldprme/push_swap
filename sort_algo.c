/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:36:38 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/07 09:57:38 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_mid && cheapest_node->target_node->above_mid)
		rotate_both(a, b, cheapest_node);
	if (!(cheapest_node->above_mid) && !(cheapest_node->target_node->above_mid))
		rev_rotate_both(a, b, cheapest_node);
	before_push(a, cheapest_node, 'a');
	before_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	before_push(a, (*b)->target_node, 'a');
	pa(b, a);
}

void	sort_algo(t_stack_node **a, t_stack_node **b)
{
	int	size_a;

	size_a = stack_size(*a);
	if (size_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	if (size_a-- > 3 && !stack_sorted(*a))
		pb(a, b);
	while (size_a-- > 3 && !stack_sorted(*a))
	{
		prep_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prep_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	last_sort(a);
}
