/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:23:34 by adardour          #+#    #+#             */
/*   Updated: 2023/08/17 13:55:44 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
void	v()
{
	system("leaks cub3D");
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
	if (!put_data(data, fd, &reached_map) || reached_map < 6)
		return (printf(DISPLAY_ERROR1),1);
	close(fd);
	parse_map(data, reached_map);
	check_symbols(data->map_represent);
	complete_the_map(get_longest_length(data->map_represent), data);
	if (!check_map(data->map_represent))
		exit(1);
	free_data(data);
	free_things(data->map_represent);
	atexit(v);
}
