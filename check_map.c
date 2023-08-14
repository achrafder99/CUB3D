/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:09:48 by adardour          #+#    #+#             */
/*   Updated: 2023/08/14 14:32:39 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_characters(char *line, int *w, int *e, int *o)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n')
		{
			if ((line[i] != '0' && line[i] != '1') \
			&& (line[i] != 'N' && line[i] != 'S' \
			&& line[i] != 'E' && line[i] != 'W'))
			{
				printf("symbol not valid\n");
				exit(1);
			}
			else if (line[i] == 'N' || line[i] == 'S' \
			|| line[i] == 'E' || line[i] == 'W')
				(*o)++;
			else if (line[i] == '1')
				(*w)++;
			else if (line[i] == '0')
				(*e)++;
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
		while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
			i++;
	}
	else
	{
		length = ft_strlen(line) - 1;
		if (check_new_line(line))
			length -= 1;
		while (line[length] != '\0' && (line[length] == ' ' \
		|| line[length] == '\t'))
			length--;
		i = length;
	}
	return (i);
}

int	check_map(char **represent_map)
{
	int	i;

	i = 0;
	while (represent_map[i])
	{
		if (represent_map[i][get_index(represent_map[i], 0)] != '1' \
		|| represent_map[i][get_index(represent_map[i], 1)] != '1')
		{
			printf("The map must be closed/surrounded by walls\n");
			exit(1);
		}
		i++;
	}
	return (1);
}
