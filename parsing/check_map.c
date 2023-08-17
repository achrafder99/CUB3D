/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:09:48 by adardour          #+#    #+#             */
/*   Updated: 2023/08/17 13:40:58 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_last_line(char **map_represent, int index_last)
{
	int	i;

	if (ft_strchr(map_represent[index_last], '\n'))
	{
		printf("error encountered\n");
		free_things(map_represent);
		exit(1);
	}
	i = 0;
	while (map_represent[index_last][i] != '\0')
	{
		if (map_represent[index_last][i] != '.')
		{
			if (map_represent[index_last][i] != '1')
			{
				printf("The map must be closed/surrounded by walls\n");
				free_things(map_represent);
				exit(1);
			}
		}
		i++;
	}
}

void	check_symbols(char	**represent_map)
{
	int	i;
	int	w;
	int	e;
	int	o;

	w = 0;
	e = 0;
	o = 0;
	i = 0;
	while (represent_map[i])
	{
		check_characters(represent_map[i], &w, &e, &o);
		i++;
	}
	if (o > 1 || o == 0)
	{
		printf("orientation should contain ones\n");
		exit(1);
	}
}

int	check_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_index(char *line, int from)
{
	int	i;
	int	length;

	if (from == 0)
	{
		i = 0;
		while (line[i] != '\0' && (line[i] == '.' || line[i] == '\t'))
			i++;
	}
	else
	{
		length = ft_strlen(line) - 1;
		if (check_new_line(line))
			length -= 1;
		while (line[length] != '\0' && (line[length] == 'S' \
		|| line[length] == '\t'))
			length--;
		i = length;
	}
	return (i);
}

int	check_map(char **represent_map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < ft_strlen(represent_map[0]) - 1)
	{
		if (represent_map[0][j] != '.')
		{
			if (represent_map[0][j] != '1')
				return (printf(DISPLAY_ERROR), 0);
		}
	}
	i = -1;
	while (represent_map[++i])
	{
		if ((represent_map[i][get_index(represent_map[i], 0)] != '.' \
		&& represent_map[i][get_index(represent_map[i], 1)] != '.'))
		{
			if ((represent_map[i][get_index(represent_map[i], 0)] != '1' \
			|| represent_map[i][get_index(represent_map[i], 1)] != '1'))
				return (printf(DISPLAY_ERROR), 0);
		}
	}
	check_last_line(represent_map, i - 1);
	return (1);
}
