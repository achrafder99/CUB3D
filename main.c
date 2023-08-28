
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:39:08 by aalami            #+#    #+#             */
/*   Updated: 2023/08/24 15:16:45 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub.h"
#include "./include/parsing.h"

int	open_file(char *filename)
{
	int		fd;
	char	*substr;

	substr = ft_substr(filename, 0, ft_strlen(filename) - 1);
	fd = open(substr, O_RDONLY);
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
	else if (((ft_strcmp(ft_strrchr(n, '.') + 1, "xpm")) - '\n') != 0 || \
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

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img.data + (y * mlx->img.size + x * (mlx->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int	render_map(t_mlx *mlx)
{
	if (check_wall(mlx))
	{
		if (mlx->player.turn_direction != 0)
			rotate_player(mlx);
		if (mlx->player.walk_direction != 0)
				walk_player(mlx);
	}
	cast_rays(mlx);
	render_projection(mlx);
	render_walls(mlx);
	render_ceiling(mlx);
	render_floor(mlx);
	draw_map_img(mlx->map, mlx);
	draw_player(mlx);
	draw_rays(mlx);
	mlx_put_image_to_window(mlx->mlx_init, mlx->mlx_win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int	check_wall(t_mlx *mlx)
{
	int	pos_x;
	int	pos_y;
	if (mlx->player.walk_direction != 0)
	{
		pos_x = (mlx->player.x + ((cos(mlx->player.rotat_angle) * (mlx->player.mov_speed * 5)) * mlx->player.walk_direction)) / TILE_SIZE;
		pos_y = (mlx->player.y+ ((sin(mlx->player.rotat_angle) * (mlx->player.mov_speed * 5)) * mlx->player.walk_direction)) / TILE_SIZE;
		if (mlx->map[pos_y][pos_x] == '1')
			return (0);
	}
	return (1);
}

int	release(int key, t_mlx *mlx)
{
	if (key == 13 || key == 1)	
		mlx->player.walk_direction = 0;
	if (key == 123 || key == 124)
		mlx->player.turn_direction = 0;
	return (0);	
}

void	fill_text_arr(t_mlx *mlx, t_texture *text, int *text_arr)
{
	int color;
	int	i = 0;
	int x;
	int y;
	char *dst;
	x = 0;
	y = 0;
	while (y < text->h * text->img.size)
	{
		x = 0;
		while(x < text->w)
		{
			dst = text->img.data + (y  + x * ( text->img.bpp / 8));
			text_arr[i] = *(unsigned int*)dst;
			i++;
			x ++;
		}
		y += text->img.size;
	}
}

int	check_path(char *path, t_mlx *mlx)
{
	int w;
	int h;
	void *img;
	img  = mlx_xpm_file_to_image(mlx->mlx_init, path, &w, &h);
	if (!img)
		return (0);
	return (1);
}
int is_empty(t_mlx *mlx)
{
	char *path;
    int width;
    int height;

	int i;
	i = 0;
	while (i < 4)
	{
		if (i == 0)
			path = ft_substr(mlx->text_ure.ea, 0, ft_strlen(mlx->text_ure.ea) -1);
		else if (i == 1)
			path = ft_substr(mlx->text_ure.so, 0, ft_strlen(mlx->text_ure.so ) -1);
		else if (i == 2)
			path = ft_substr(mlx->text_ure.no, 0, ft_strlen(mlx->text_ure.no) -1);
		else if (i == 3)
			path = ft_substr(mlx->text_ure.we, 0, ft_strlen(mlx->text_ure.we) -1);
		if (!check_path(path, mlx))
		{
			free(path);
			return (1);
		}
		else
			free(path);
		i++;
	}
    return (0);
}

void	leak()
{
	system("leaks cub3d");
}
void	free_map(t_mlx *mlx)
{
	int i = 0;
	int j = 0;

	while (i < 14)
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
}
int	ft_exit(t_mlx *mlx)
{
	free(mlx->rays);
	free_map(mlx);
	mlx_destroy_window(mlx->mlx_init, mlx->mlx_win);
	free(mlx);
	exit (0);
	return (0);
}

int	parsing(t_data *data, char **argv, int reached_map, int fd, t_mlx *mlx)
{
	init(data); 
	if (!put_data(data, fd, &reached_map) || reached_map < 6)
		return (printf(DISPLAY_ERROR1), 1);
	if (!check_rgbs(data->ceiling, data->floor))
		return (printf(DISPLAY_ERROR2),1);
	close(fd); 
	parse_map(data, reached_map, argv[1]);
	check_symbols(data->map_represent);
	complete_the_map(get_longest_length(data->map_represent), data);
	colors(data);
	open_texture(data->texture.no, data->texture.so, data->texture.we, \
	data->texture.ea);
	mlx->text_ure.ea = data->texture.ea;
	mlx->text_ure.so = data->texture.so;
	mlx->text_ure.no = data->texture.no;
	mlx->text_ure.we = data->texture.we;
	if (!check_map(data->map_represent) || is_empty(mlx))
	{
		printf("some error in map or textures\n");
		free(mlx);
		exit(1);
	}
	return (0);
}

void	drawing(t_mlx *mlx, t_data *data)
{
	mlx->data = data;
	mlx->map = data->map_represent;
	init_player(mlx);
	mlx->win_h = get_rows(data->map_represent) * TILE_SIZE;
	mlx->win_w = get_columns(data->map_represent) * TILE_SIZE;
	mlx->rays = (t_ray *)malloc(sizeof(t_ray) * mlx->win_w);
	mlx->mlx_win = mlx_new_window(mlx->mlx_init, mlx->win_w, mlx->win_h, "cub3d");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_init, mlx->win_w, mlx->win_h);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size, &mlx->img.endian);
	init_rays_dir(mlx);
	mlx->text_n.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_init, "textures/eagle.xpm", &mlx->text_n.w, &mlx->text_n.h);
	mlx->text_n.img.data = mlx_get_data_addr(mlx->text_n.img.img_ptr, &mlx->text_n.img.bpp, &mlx->text_n.img.size, &mlx->text_n.img.endian);
	mlx->text_s.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_init, "./textures/redbrick.xpm", &mlx->text_s.w, &mlx->text_s.h);
	mlx->text_s.img.data = mlx_get_data_addr(mlx->text_s.img.img_ptr, &mlx->text_s.img.bpp, &mlx->text_s.img.size, &mlx->text_s.img.endian);
	mlx->text_e.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_init, "./textures/eagle.xpm", &mlx->text_e.w, &mlx->text_e.h);
	mlx->text_e.img.data = mlx_get_data_addr(mlx->text_e.img.img_ptr, &mlx->text_e.img.bpp, &mlx->text_e.img.size, &mlx->text_e.img.endian);
	mlx->text_w.img.img_ptr = mlx_xpm_file_to_image(mlx->mlx_init, "./textures/eagle.xpm", &mlx->text_w.w, &mlx->text_w.h);
	mlx->text_w.img.data = mlx_get_data_addr(mlx->text_w.img.img_ptr, &mlx->text_w.img.bpp, &mlx->text_w.img.size, &mlx->text_w.img.endian);
	mlx_hook(mlx->mlx_win, 03, 0, release, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, ft_exit, mlx);
	mlx_hook(mlx->mlx_win, 02, 0, move_player, mlx);
	mlx_loop_hook(mlx->mlx_init, render_map, mlx);
	mlx_loop(mlx->mlx_init);
}

int	main(int c,char **argv)
{
    int		fd;
	t_data	*data;
	int		reached_map;
	t_mlx	*mlx;
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx_init = mlx_init();
	reached_map = 0;
	fd = open(argv[1], O_RDWR, 0777);
	if (fd == -1)
		return (perror(""), 0);
	data = malloc(sizeof(t_data));
	if (parsing(data, argv, reached_map, fd, mlx))
		exit(1);
	drawing(mlx, data);
}
