/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:03:03 by adardour          #+#    #+#             */
/*   Updated: 2023/08/15 10:04:53 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_length(char *line, int del)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != del)
		i++;
	return (i);
}

int	get_count(char *line, int del)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (line[i] != '\0')
	{
		if (line[i] != del && line[i] != '\0')
		{
			size++;
			while (line[i] != del && line[i] != '\0')
				i++;
		}
		while (line[i] == del && line[i] != '\0')
			i++;
	}
	return (size);
}

char	**ft_split(char *line, int del)
{
	char	**spliting;
	int		i;
	int		j;
	int		count;

	count = get_count(line, del);
	spliting = malloc((sizeof(char *) * count) + 1);
	if (!spliting)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*line != '\0' && *line == del)
			del++;
		if (*line != '\0' && *line != del)
		{
			j = 0;
			spliting[i] = malloc((sizeof(char) * get_length(line, del)) + 1);
			while (*line != '\0' && *line != del)
				spliting[i][j++] = *line++;
			spliting[i][j] = '\0';
			while (*line != '\0' && *line == del)
				line++;
		}
		i++;
	}
	spliting[i] = NULL;
	return (spliting);
}
