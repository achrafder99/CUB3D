/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:48:08 by adardour          #+#    #+#             */
/*   Updated: 2023/08/12 22:36:25 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_last()
{	
	int fd;
	char *last;
	fd = open("cub.cub",O_RDWR);
	char *line;
	line = get_next_line(fd);
	while (line)
	{
		if (strcmp(line, "\n") && !ft_strstr(line," "))
		{
			last = ft_strdup(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (last);
}

char	*get_begin(int reached_map)
{
	int		fd;
	int		i;
	char	*line;
	char 	*first_line;

	i = 0;
	fd = open("cub.cub", O_RDWR, 0777);
	line = get_next_line(fd);
	if (fd == -1)
	{
		perror("");
		exit(1);
	}
	while (i < reached_map && line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	while (!ft_strchr(line, '1') && line)
	{
		line = get_next_line(fd);
	}
	first_line = ft_strdup(line);
	while (line)
		line = get_next_line(fd);
	close(fd);
	return (ft_strdup(first_line));
}

void	parse_map(t_data *data, int reached_map)
{
	char	*start_map;
	char	*last_map;
	int		fd;
	
	int i;
	i = 0;
	start_map = get_begin(reached_map);
	last_map = get_last();

	printf("begin %s\n",start_map);
	printf("last %s\n",last_map);

}

void	init(t_data *data)
{
	data->texture.EA = NULL;
	data->texture.SO = NULL;
	data->texture.NO = NULL;
	data->texture.WE = NULL;
	data->ceiling.B = NULL;
	data->ceiling.R = NULL;
	data->ceiling.G = NULL;
	data->floor.B = NULL;
	data->floor.R = NULL;
	data->floor.G = NULL;
}

int	parse_element(t_data *data)
{
	if (!data->texture.EA \
	|| !data->texture.SO \
	|| !data->texture.WE \
	|| !data->texture.NO \
	|| !data->floor.R \
	|| !data->floor.G \
	|| !data->floor.B \
	|| !data->ceiling.R \
	|| !data->ceiling.G \
	|| !data->ceiling.B)
	{
		printf("error\n");
		return (0);
	}
	return (1);
}

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
	char	*line;
	int 	flags;

	flags = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == 'N')
		{
			put(line, data, 'N');
			(*reached_map)++;
		}
		else if (line[0] == 'S')
		{
			put(line, data, 'S');
			(*reached_map)++;
		}
		else if (line[0] == 'W')
		{
			put(line, data, 'W');
			(*reached_map)++;
		}
		else if (line[0] == 'E')
		{
			put(line, data, 'E');
			(*reached_map)++;
		}
		else if (line[0] == 'F')
		{
			put(line, data, 'F');
			(*reached_map)++;
		}
		else if (line[0] == 'C')
		{
			put(line, data, 'C');
			(*reached_map)++;
		}
		else
			flags++;
		if (*reached_map == 6)
			(*reached_map) += flags;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	main(int c, char**argv)
{
	int		fd; 
	t_data	*data;
	int		reached_map;

	reached_map = 0;
	fd = open("cub.cub", O_RDWR, 0777);
	if (fd == -1)
	{
		perror("");
		return (0);
	}
	data = malloc(sizeof(t_data));
	init(data);
	put_data(data, fd, &reached_map);
	parse_map(data, reached_map);
	// if (!parse_element(data))
	// {
	// 	exit(1);
	// }
	// else
	// 	printf("start\n");
	free_data(data);
}
