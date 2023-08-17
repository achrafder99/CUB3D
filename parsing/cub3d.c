/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:48:08 by adardour          #+#    #+#             */
/*   Updated: 2023/08/13 16:58:27 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_spaces(char *line)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	get_length_line(char *line)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (line[i] != '\0' && strcmp(line, "\n"))
	{
		if (line[i] != ' ' && line[i] != '\t')
			length++;
		i++;
	}
	return (length);
}

char	*remove_spaces(char *line)
{
	int		i;
	int		j;
	int		length;
	char	*clear_line;

	length = get_length_line(line);
	clear_line = malloc((sizeof(char) * length) + 1);
	if (!clear_line)
	{
		perror("");
		exit(1);
	}
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != ' ' && line[i] != '\t')
			clear_line[j++] = line[i++];
	}
	clear_line[j] = '\0';
	return (clear_line);
}

void	fill_map(char *first_line, t_data *data, int count)
{
	char	*removes;
	int		fd;
	char	*line;
	int		i;

	fd = open("cub.cub", O_RDWR);
	if (fd == -1)
		return (perror(""), exit(1));
	line = get_next_line(fd);
	while (strcmp(line, first_line))
	{
		line = get_next_line(fd);
		free(line);
	}
	data->map_represent[0] = remove_spaces(line);
	i = 0;
	line = get_next_line(fd);
	while (++i < count && line)
	{
		if (check_spaces(line))
			data->map_represent[i] = remove_spaces(line);
		free(line);
		line = get_next_line(fd);
	}
	data->map_represent[i] = NULL;
}

int	get_lines(int fd)
{
	char	*line;
	int		count;

	line = get_next_line(fd);
	count = 1;
	while (line != NULL)
	{
		if (strcmp(line, "\n") && check_spaces(line))
			count++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}
