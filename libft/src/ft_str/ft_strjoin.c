/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:01:23 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:01:24 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size1;
	size_t	size2;
	int		i;
	char	*s3;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	s3 = malloc((size1 + size2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[size1 + i] = s2[i];
		i++;
	}
	s3[size1 + i] = '\0';
	return (s3);
}
