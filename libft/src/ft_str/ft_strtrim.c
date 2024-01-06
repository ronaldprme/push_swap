/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:02:15 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:02:18 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *to_remove)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;
	char	*s1_copy;

	start = 0;
	while (s1[start] != '\0' && ft_strchr(to_remove, s1[start]) != NULL)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(to_remove, s1[end - 1]) != NULL)
		end--;
	len = end - start;
	s1_copy = (char *)malloc((len + 1) * sizeof(char));
	if (!s1_copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1_copy[i] = s1[start + i];
		i++;
	}
	s1_copy[i] = '\0';
	return (s1_copy);
}
