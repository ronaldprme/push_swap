/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:56:26 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 15:56:29 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	else
	{
		temp = lst;
		count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return (count);
	}
}
