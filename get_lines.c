/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:20:19 by adardour          #+#    #+#             */
/*   Updated: 2023/08/13 22:41:18 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

char	*get_begin(int reached_map, int fd)
{
	char	*line;
	char	*first_line;
	char	*old;

	while (reached_map)
	{
		line = get_next_line(fd);
		free(line);
		reached_map--;
	}
	while (!ft_strchr(line, '1') && line)
	{
		line = get_next_line(fd);
		old = first_line;
		first_line = ft_strdup(line);
		free(old);
		free(line);
	}
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (first_line);
}
