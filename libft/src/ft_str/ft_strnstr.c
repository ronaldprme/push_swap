/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:02:01 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:02:02 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *base, const char *find, size_t n)
{
	size_t	i;
	size_t	fi;

	if (*find == '\0')
	{
		return ((char *)base);
	}
	i = 0;
	while (base[i] != '\0' && i < n)
	{
		fi = 0;
		while (base[i + fi] == find[fi] && (i + fi) < n)
		{
			if (find[fi + 1] == '\0')
			{
				return ((char *)(base + i));
			}
			fi++;
		}
		i++;
	}
	return (NULL);
}
