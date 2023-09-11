/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:23:19 by adardour          #+#    #+#             */
/*   Updated: 2023/09/10 19:00:53 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/cub.h"

void	west_east(char *flag, t_data *data, char *path, int *reached_map)
{
	if (!ft_strcmp(flag, "WE"))
	{
		if (data->texture.we)
			free(data->texture.we);
		data->texture.we = ft_strdup(path);
		(*reached_map)++;
	}
	else if (!ft_strcmp(flag, "EA"))
	{
		if (data->texture.ea)
			free(data->texture.ea);
		data->texture.ea = ft_strdup(path);
		(*reached_map)++;
	}
}

void	north_south_west_east(t_data *data, char *path, \
char *flag, int *reached_map)
{
	if (!ft_strcmp(flag, "NO"))
	{
		if (data->texture.no)
			free(data->texture.no);
		data->texture.no = ft_strdup(path);
		(*reached_map)++;
	}
	else if (!ft_strcmp(flag, "SO"))
	{
		if (data->texture.so)
			free(data->texture.so);
		data->texture.so = ft_strdup(path);
		(*reached_map)++;
	}
	west_east(flag, data, path, reached_map);
}

int	put(char *line, t_data *data, int *reached_map, char *identifier)
{
	char		*substr;
	int			end;
	char		*start;
	int			i;

	if (!ft_strcmp(identifier, "SO") || \
	!ft_strcmp(identifier, "NO") || \
	!ft_strcmp(identifier, "EA") || \
	!ft_strcmp(identifier, "WE"))
	{
		i = 0;
		start = line + 2;
		while (start[i] && (start[i] == ' ' || start[i] == '\t'))
			i++;
		end = i;
		while (end < ft_strlen(start) - 2)
			end++;
		substr = ft_substr(start, i, end);
		north_south_west_east(data, substr, identifier, reached_map);
		free(substr);
	}
	return (1);
}
