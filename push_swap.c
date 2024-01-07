/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:35:43 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/07 13:16:30 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free (av);
	return ;
}

static void	manage_stacks(t_stack_node **a, t_stack_node **b)
{
	if (stack_size(*a) == 2)
		sa(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else
		sort_algo(a, b);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**av_made;

	a = NULL;
	b = NULL;
	av_made = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit (1);
	else if (ac == 2)
	{
		av_made = ft_split(av[1], ' ');
		stack_init(&a, av_made);
	}
	else
		stack_init(&a, (av + 1));
	if (!stack_sorted(a))
		manage_stacks (&a, &b);
	if (av_made)
		clean_av(av_made);
	clean_stack(&a);
	return (0);
}
