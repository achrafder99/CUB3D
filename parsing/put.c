/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:23:19 by adardour          #+#    #+#             */
/*   Updated: 2023/09/07 20:09:51 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/cub.h"

void	north_south_west(t_data *data, char **spliting, char *flag)
{
	if (!ft_strcmp(flag, "NO"))
	{
		if (data->texture.no)
			free(data->texture.no);
		data->texture.no = ft_substr(spliting[1], 0, \
		ft_strlen(spliting[1]) - 1);
	}
	else if (!ft_strcmp(flag, "SO"))
	{
		if (data->texture.so)
			free(data->texture.so);
		data->texture.so = ft_substr(spliting[1], 0, \
		ft_strlen(spliting[1]) - 1);
	}
	else if (!ft_strcmp(flag, "WE"))
	{
		if (data->texture.we)
			free(data->texture.we);
		data->texture.we = ft_substr(spliting[1], 0, \
		ft_strlen(spliting[1]) - 1);
	}
}

int	put(char *line, t_data *data, int *reached_map)
{
	static int	flags;
	char		**spliting;

	spliting = ft_split(line, ' ');
	if (!ft_strcmp(spliting[0], "SO") \
	|| !ft_strcmp(spliting[0], "NO") \
	|| !ft_strcmp(spliting[0], "WE"))
		north_south_west(data, spliting, spliting[0]);
	else if (!ft_strcmp(spliting[0], "EA"))
	{
		if (data->texture.ea)
			free(data->texture.ea);
		data->texture.ea = ft_substr(spliting[1], 0, \
		ft_strlen(spliting[1]) - 1);
	}
	free_things(spliting);
	(*reached_map)++;
	return (1);
}
