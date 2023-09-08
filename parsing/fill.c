/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:51:47 by adardour          #+#    #+#             */
/*   Updated: 2023/09/08 15:37:35 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	fill(int fd, t_data *data, int count, char *start_map)
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
	if (ft_strchr(data->map_represent[count - 1], '\n'))
	{
		printf("error encountered : ");
		close(fd);
		return (0);
	}
	close(fd);
	data->map_represent[i] = NULL;
	return (1);
}
