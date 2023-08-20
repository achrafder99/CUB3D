/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:23:34 by adardour          #+#    #+#             */
/*   Updated: 2023/08/20 14:41:49 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(char *filename)
{
	int		fd;
	char	*substr;

	substr = ft_substr(filename, 0, ft_strlen(filename) - 1);
	fd = open(substr, O_RDWR);
	free(substr);
	return (fd);
}

void	open_texture(char *n, char *s, char *w, char *e)
{
	int	fd_n;
	int	fd_s;
	int	fd_w;
	int	fd_e;

	fd_n = open_file(n);
	fd_s = open_file(s);
	fd_w = open_file(w);
	fd_e = open_file(e);
	if (fd_n == -1 || fd_s == -1 || fd_w == -1 || fd_e == -1)
		return (perror(""), exit(1));
	if (((ft_strcmp(ft_strrchr(n, '.') + 1, "xpm")) - '\n') != 0 || \
	((ft_strcmp(ft_strrchr(s, '.') + 1, "xpm")) - '\n') != 0 || \
	((ft_strcmp(ft_strrchr(w, '.') + 1, "xpm")) - '\n') != 0 || \
	((ft_strcmp(ft_strrchr(w, '.') + 1, "xpm")) - '\n') != 0)
	{
		printf("the format path must be (.xpm)\n");
		exit(1);
	}
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
			check_ += check_color(r);
		else if (i == 1)
			check_ += check_color(g);
		else if (i == 2)
			check_ += check_color(b);
		i++;
	}
	return (check_);
}

void	init(t_data *data)
{
	data->texture.ea = NULL;
	data->texture.so = NULL;
	data->texture.no = NULL;
	data->texture.we = NULL;
	data->ceiling.b = NULL;
	data->ceiling.r = NULL;
	data->ceiling.g = NULL;
	data->floor.b = NULL;
	data->floor.r = NULL;
	data->floor.g = NULL;
}

int	main(int c, char**argv)
{
	int		fd;
	t_data	*data;
	int		reached_map;

	reached_map = 0;
	fd = open("cub.cub", O_RDWR, 0777);
	if (fd == -1)
		return (perror(""), 0);
	data = malloc(sizeof(t_data));
	init(data); 
	if (!put_data(data, fd, &reached_map) || reached_map < 6)
		return (printf(DISPLAY_ERROR1), 1);
	if (!check_rgbs(data->ceiling, data->floor))
		return (printf(DISPLAY_ERROR2));
	close(fd); 
	parse_map(data, reached_map);
	check_symbols(data->map_represent);
	complete_the_map(get_longest_length(data->map_represent), data);
	colors(data);
	open_texture(data->texture.no, data->texture.so, data->texture.we, \
	data->texture.ea);
	if (!check_map(data->map_represent))
		exit(1);
	free_data(data);
	free_things(data->map_represent);
}
