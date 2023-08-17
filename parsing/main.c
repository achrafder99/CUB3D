/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:23:34 by adardour          #+#    #+#             */
/*   Updated: 2023/08/17 14:27:58 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check(char *color)
{
	int	i;

	i = 0;
	while (i < ft_strlen(color))
	{
		if (color[i] != '\n')
		{
			if (color[i] >= 'a' && color[i] <= 'z')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_car(char *r, char *g, char *b)
{
	int	i;
	int	check_;

	i = 0;
	check_ = 0;
	while (i < 3)
	{
		if (i == 0)
			check_ += check(r);
		else if (i == 1)
			check_ += check(g);
		else if (i == 2)
			check_ += check(b);
		i++;
	}
	return (check_);
}

int	check_rgbs(t_ceiling ceiling, t_floor floor)
{
	if (check_car(ceiling.R, ceiling.G, ceiling.B) != 3 \
	|| check_car(floor.R, floor.G, floor.B) != 3)
		return (0);
	return (1);
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
	if (!put_data(data, fd, &reached_map)  || reached_map < 6)
		return (printf(DISPLAY_ERROR1), 1);
	if (!check_rgbs(data->ceiling, data->floor))
		return (printf(DISPLAY_ERROR2));
	close(fd);
	parse_map(data, reached_map);
	check_symbols(data->map_represent);
	complete_the_map(get_longest_length(data->map_represent), data);
	if (!check_map(data->map_represent))
		exit(1);
	free_data(data);
	free_things(data->map_represent);
}
