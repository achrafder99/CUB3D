/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:23:34 by adardour          #+#    #+#             */
/*   Updated: 2023/08/14 21:32:15 by adardour         ###   ########.fr       */
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
	close(fd);
	parse_map(data, reached_map);
	check_symbols(data->map_represent);
	if (!check_map(data->map_represent) || !parse_element(data))
		exit(1);
	else
		start_drawing(data);
	free_data(data);
	free_things(data->map_represent);
}
