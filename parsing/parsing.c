/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:45:30 by adardour          #+#    #+#             */
/*   Updated: 2023/09/08 14:17:46 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/parsing.h"

int	check__(char *identifier)
{
	return (ft_strcmp(identifier, "NO") && \
			ft_strcmp(identifier, "SO") && \
			ft_strcmp(identifier, "WE") && \
			ft_strcmp(identifier, "EA") && \
			ft_strcmp(identifier, "C") && \
			ft_strcmp(identifier, "F"));
}

int	check_line_2(char *line, char **spliting, int *flags)
{
	if (ft_strcmp(line, "\n"))
	{
		spliting = ft_split(line, ' ');
		if (check__(spliting[0]))
			return (free(line), free_things(spliting), 0);
		else 
			(*flags)++;
		free_things(spliting);
	}
	return (1);
}

int	validate_element(char **argv, int reached_map, t_data *data)
{
	char		**spliting;
	char		*line;
	int			fd;
	int			i;
	static int	flags;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror(""), 0);
	i = -1;
	line = get_next_line(fd);
	while (line != NULL && ++i < reached_map)
	{
		if (!check_line_2(line, spliting, &flags))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	if (flags > 6)
		return (free(line), 0);
	data->start_map = ft_strdup(line);
	free(line);
	return (1);
}

int	parsing(char **argv, int reached_map, int fd, t_data *data)
{
	if (!put_data(data, fd, &reached_map))
	{
		printf(DISPLAY_ERROR1);
		close(fd);
		exit (1);
	}
	else if (!validate_element(argv, reached_map, data))
		return (1);
	else if (!check_rgbs(data->ceiling, data->floor))
		return (printf(DISPLAY_ERROR2), 1);
	else if (!parse_map(data, reached_map, argv[1]))
		return (1);
	else if (!check_symbols(data->map_represent))
		return (1);
	else if (!colors(data))
		return (printf("error\n"), 1);
	complete_the_map(get_longest_length(data->map_represent), data);
	open_texture(data->texture.no, \
	data->texture.so, data->texture.we, \
	data->texture.ea);
	if (!check_map(data->map_represent) || !check_(data->map_represent))
		return ((void)free_things(data->map_represent), free_data(data), 1);
	return (0);
}
