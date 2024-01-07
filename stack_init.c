/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:37:19 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/07 10:32:04 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	int		count;
	long	res;

	count = 1;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
	{
		count = count * -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	return (res * count);
}

void	create_node(t_stack_node **a, int n)
{
	t_stack_node	*newnode;
	t_stack_node	*last_node;

	if (!a)
		return ;
	newnode = malloc(sizeof(t_stack_node));
	if (!newnode)
		return ;
	newnode->next_node = NULL;
	newnode->nbr = n;
	//newnode->cheapest = 0;
	if (!(*a))
	{
		*a = newnode;
		newnode->prev_node = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next_node = newnode;
		newnode->prev_node = last_node;
	}
}

void	stack_init(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			exit_errors(a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_errors(a);
		if (error_duplicate(*a, (int)n))
			exit_errors(a);
		create_node(a, (int)n);
		i++;
	}
}
