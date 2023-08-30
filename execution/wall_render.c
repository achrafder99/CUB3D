/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:10:27 by aalami            #+#    #+#             */
/*   Updated: 2023/08/29 20:07:26 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include <stdio.h>
#include <stdlib.h>

void	draw_west_text(t_mlx *mlx, int wall_top, int wall_bot, int i)
{
	int	y_off;
	int	color;
	int	step;
	int	y;
	int	dis_from_top;
	char *dst;

	y = wall_top;
	step = abs(wall_bot - wall_top);
	while (step)
	{
		dis_from_top = y + (mlx->rays[i].wall_height / 2) - (mlx->win_h / 2);
		y_off = dis_from_top * ((float)mlx->text_w.h
				/ mlx->rays[i].wall_height);
		dst = mlx->text_w.img.data + (y_off * mlx->text_w.img.size + mlx->text_w.text_offset * 4);
		color = *(unsigned int *)dst;
		my_mlx_pixel_put(mlx, i, wall_top, color);
		wall_top += 1;
		y++;
		step--;
	}
}

void	draw_east_text(t_mlx *mlx, int wall_top, int wall_bot, int i)
{
	int	y_off;
	int	color;
	int	step;
	int	y;
	int	dis_from_top;
	char *dst;

	y = wall_top;
	step = abs(wall_bot - wall_top);
	while (step)
	{
		dis_from_top = y + (mlx->rays[i].wall_height / 2) - (mlx->win_h / 2);
		y_off = dis_from_top * ((float)mlx->text_e.h
				/ mlx->rays[i].wall_height);
		dst = mlx->text_e.img.data + (y_off * mlx->text_e.img.size + mlx->text_e.text_offset * 4);
		color = *(unsigned int *)dst;
		my_mlx_pixel_put(mlx, i, wall_top, color);
		wall_top += 1;
		y++;
		step--;
	}
}

void	draw_north_text(t_mlx *mlx, int wall_top, int wall_bot, int i)
{
	int	y_off;
	int	color;
	int	step;
	int	y;
	int	dis_from_top;
	char *dst;

	y = wall_top;
	step = abs(wall_bot - wall_top);
	while (step)
	{
		dis_from_top = y + (mlx->rays[i].wall_height / 2) - (mlx->win_h / 2);
		y_off = dis_from_top * ((float)mlx->text_n.h
				/ mlx->rays[i].wall_height);
		dst = mlx->text_n.img.data + (y_off * mlx->text_n.img.size + mlx->text_n.text_offset * 4);
		color = *(unsigned int *)dst;
		my_mlx_pixel_put(mlx, i, wall_top, color);
		wall_top += 1;
		y++;
		step--;
	}
}

void	draw_south_text(t_mlx *mlx, int wall_top, int wall_bot, int i)
{
	int	y_off;
	int	color;
	int	step;
	int	y;
	int	dis_from_top;
	char	*dst;

	y = wall_top;
	step = abs(wall_bot - wall_top);
	while (step)
	{
		dis_from_top = y + (mlx->rays[i].wall_height / 2) - (mlx->win_h / 2);
		y_off = dis_from_top * ((float)mlx->text_s.h
				/ mlx->rays[i].wall_height);
		dst = mlx->text_s.img.data + (y_off * mlx->text_s.img.size + mlx->text_s.text_offset * 4);
		color = *(unsigned int *)dst;
		my_mlx_pixel_put(mlx, i, wall_top, color);
		wall_top += 1;
		y++;
		step--;
	}
}

void	draw_based_on_direction(t_mlx *mlx, int i, char dir)
{
	if (dir == 'n')
	{
		mlx->text_n.text_offset = (int)fmod(mlx->rays[i].hit_x, TILE_SIZE);
		draw_north_text(mlx, (int)mlx->rays[i].top_wall,
			(int)mlx->rays[i].bot_wall, i);
	}
	else if (dir == 's')
	{
		mlx->text_s.text_offset = (int)fmod(mlx->rays[i].hit_x, TILE_SIZE);
		draw_south_text(mlx, (int)mlx->rays[i].top_wall,
			(int)mlx->rays[i].bot_wall, i);
	}
	else if (dir == 'e')
	{
		mlx->text_e.text_offset = (int)fmod(mlx->rays[i].hit_y, TILE_SIZE);
		draw_east_text(mlx, (int)mlx->rays[i].top_wall,
			(int)mlx->rays[i].bot_wall, i);
	}
	else
	{
		mlx->text_w.text_offset = (int)fmod(mlx->rays[i].hit_y, TILE_SIZE);
		draw_west_text(mlx, (int)mlx->rays[i].top_wall,
			(int)mlx->rays[i].bot_wall, i);
	}
}
