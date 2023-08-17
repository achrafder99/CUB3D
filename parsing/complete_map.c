/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:43:21 by adardour          #+#    #+#             */
/*   Updated: 2023/08/17 13:32:31 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char *line)
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

void	fill_line(char *line, char *return_line, int *check, int fill_line)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] != '\n')
		{
			if (line[i] != ' ')
			{
				return_line[i] = line[i];
				(*check)++;
			}
			else
			{
				return_line[i] = '.';
				(*check)++;
			}
		}
	}
	while (i++ < fill_line)
	{
		return_line[*check] = '.';
		(*check)++;
	}
}

char	*complete_line(char *line, int longest_length)
{
	int		dd;
	char	*return_line;
	int		flags;
	int		check;

	flags = 0;
	check = 0;
	dd = longest_length - strlen(line);
	if (!check_line(line))
		longest_length -= 1;
	else
		flags = 1;
	return_line = malloc((sizeof(char) * longest_length) + 1);
	if (!return_line)
		exit(1);
	fill_line(line, return_line, &check, longest_length);
	if (flags)
	{
		return_line[check] = '\n';
		check += 1;
	}
	return_line[check] = '\0'; 
	return (return_line);
}

void	complete_the_map(int longest_length, t_data *data)
{
	int	i;

	i = 0;
	while (data->map_represent[i] != NULL)
	{
		free(data->map_represent[i]);
		data->map_represent[i] = complete_line(data->map_represent[i], \
		longest_length);
		i++;
	}
}

int	get_longest_length(char **represent_map)
{
	int	index;
	int	length;

	index = 0;
	length = ft_strlen(represent_map[0]);
	while (represent_map[index])
	{
		if (ft_strlen(represent_map[index]) > length)
			length = ft_strlen(represent_map[index]);
		index++;
	}
	return (length);
}
