/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:36:48 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 14:23:42 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*max_node;

	max_node = find_max(*a);
	if (max_node == *a)
		ra(a);
	else if (max_node == (*a)->next_node)
		rra(a);
	if ((*a)->nbr > (*a)->next_node->nbr)
		sa(a);
}
