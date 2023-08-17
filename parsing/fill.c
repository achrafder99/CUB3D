/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:51:47 by adardour          #+#    #+#             */
/*   Updated: 2023/08/13 22:38:23 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill(int fd, t_data *data, int count, char *start_map)
{
	char	*line;
	int		i;

	data->map_represent[0] = ft_strdup(start_map);
	i = 1;
	while (i < count)
	{
		line = get_next_line(fd);
		data->map_represent[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	data->map_represent[i] = NULL;
}
