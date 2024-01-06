/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:35:12 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:15:30 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *number)
{
	if (!(*number == '-' || *number == '+' || 
			(*number >= '0' && *number <= '9')))
		return (1);
	number++;
	while (*number)
	{
		if (!(*number >= '0' && *number <= '9'))
			return (1);
		number++;
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next_node;
	}
	return (0);
}

void	clean_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!(*stack))
		return ;
	while ((*stack))
	{
		temp = (*stack)->next_node;
		free(*stack);
		*stack = temp;
	}
}

void	exit_errors(t_stack_node **a)
{
	clean_stack(a);
	ft_printf("Error\n");
	exit (1);
}
