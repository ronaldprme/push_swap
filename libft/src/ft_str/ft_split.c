/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:01:00 by rprocopi          #+#    #+#             */
/*   Updated: 2024/01/06 16:01:03 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *s, char c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	if (ft_strlen(s) == 0)
		return (count);
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (count);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count + 1);
}

static char	**ft_array(int size)
{
	char	**res;

	res = (char **)malloc((size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	else
		return (res);
}

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**populate_array(char **res, const char *s, char c, size_t count)
{
	size_t		i;
	size_t		array;
	size_t		len;

	i = 0;
	array = 0;
	while (array < count)
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		len = 0;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		res[array] = ft_substr(s, i, len);
		if (!res[array])
			return (NULL);
		i = i + len;
		array++;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char		**res;
	size_t		count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	res = ft_array(count);
	if (!res)
		return (NULL);
	res = populate_array(res, s, c, count);
	if (!res)
		ft_free(res);
	res[count] = NULL;
	return (res);
}
