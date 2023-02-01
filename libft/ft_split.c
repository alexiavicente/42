/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:37:21 by marvin            #+#    #+#             */
/*   Updated: 2021/11/16 10:37:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#include "libft.h"
#include <stdlib.h>

int		count_seg(char const *s, char c);
void	allocate_rows(char **result, char const *s, char c, int l);
char	*assign_row(char const *s, int start, char c);
void	free_all(char **result, int row);

char	**ft_split(char const *s, char c)
{
	int		rows;
	char	**result;

	if (s == 0)
		return (0);
	rows = count_seg(s, c);
	result = (char **) malloc(sizeof(char *) * rows + 1);
	if (result == 0)
		return (0);
	allocate_rows(result, s, c, rows);
	return (result);
}

int	count_seg(char const *s, char c)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	if ((s[i] != 0) && (((char *)s)[i] != c))
		result ++;
	while (s[i])
	{
		if (((char *)s)[i] == c && ((char *)s)[i + 1] != c)
			result ++;
		i ++;
	}
	    return (result);
}

void	allocate_rows(char **result, char const *s, char c, int l)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (s[i] && row < l)
	{
		if (((char *)s)[i] == c)
			i ++;
		else
		{
			result[row] = assign_row(s, i, c);
			if (result[row] == 0)
			{
				free_all(result, row);
				return ;
			}
			i += ft_strlen(result[row] + 1);
			row ++;
		}
	}
	result[row] = 0;
}

char	*assign_row(char const *s, int start, char c)
{
	char	*result;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[start + size] && s[start + size] != c)
		size ++;
	result = (char *) malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (0);
	while (i < size)
	{
		result[i] = s[start + i];
		i ++;
	}
	result [i] = 0;
	return (result);
}

void	free_all(char **result, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(result[i]);
		result[i] = 0;
		i++;
	}
}