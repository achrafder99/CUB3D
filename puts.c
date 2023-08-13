/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:48:05 by adardour          #+#    #+#             */
/*   Updated: 2023/08/13 16:52:03 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_rgb(t_data *data, char *line, char identifier)
{
	char	**spliting;
	char	**spliting_floor;
	char	**spliting_ceiling;

	spliting = ft_split(line, ' ');
	if (identifier == 'F')
	{
		spliting_floor = ft_split(spliting[1], ',');
		data->floor.R = ft_strdup(spliting_floor[0]);
		data->floor.G = ft_strdup(spliting_floor[1]);
		data->floor.B = ft_strdup(spliting_floor[2]);
		free_things(spliting_floor);
	}
	else if (identifier == 'C')
	{
		spliting_ceiling = ft_split(spliting[1], ',');
		data->ceiling.R = ft_strdup(spliting_ceiling[0]);
		data->ceiling.G = ft_strdup(spliting_ceiling[1]);
		data->ceiling.B = ft_strdup(spliting_ceiling[2]);
		free_things(spliting_ceiling);
	}
	free_things(spliting);
}

void	put(char *line, t_data *data, char i)
{
	char	**spliting;

	spliting = ft_split(line, ' ');
	if (i == 'N')
		data->texture.NO = ft_strdup(spliting[1]);
	if (i == 'S')
		data->texture.SO = ft_strdup(spliting[1]);
	if (i == 'W')
		data->texture.WE = ft_strdup(spliting[1]);
	if (i == 'E')
		data->texture.EA = ft_strdup(spliting[1]);
	if (i == 'F')
		put_rgb(data, line, 'F');
	if (i == 'C')
		put_rgb(data, line, 'C');
	free_things(spliting);
}

void	put_data(t_data *data, int fd, int *reached_map)
{
	int		flags;
	char	*line;

	flags = -1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == 'N' || line[0] == 'S' \
		|| line[0] == 'W' || line[0] == 'E' \
		|| line[0] == 'F' || line[0] == 'C')
		{
			put(line, data, line[0]);
			(*reached_map)++;
		}
		else
			flags++;
		if (*reached_map == 6)
			(*reached_map) += flags;
		free(line);
		line = get_next_line(fd);
	}
}
