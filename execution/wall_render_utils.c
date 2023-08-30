/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:43:23 by aalami            #+#    #+#             */
/*   Updated: 2023/08/30 12:49:50 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	render_walls(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->win_w)
	{
		draw_project(mlx, i, 0, mlx->rays[i].top_wall, \
		mlx->data->ceiling.color);
		if (mlx->rays[i].hit_h)
		{
			if (mlx->rays[i].f_u)
				draw_based_on_direction(mlx, i, 'n');
			else
				draw_based_on_direction(mlx, i, 's');
		}
		else
		{
			if (mlx->rays[i].f_r)
				draw_based_on_direction(mlx, i, 'e');
			else
				draw_based_on_direction(mlx, i, 'w');
		}
		draw_project(mlx, i, mlx->rays[i].bot_wall, mlx->win_h, \
		mlx->data->floor.color);
		i++;
	}
}

void	render_projection(t_mlx *mlx)
{
	float	proj_dis;
	float	correct_dis;
	int		i;

	i = 0;
	proj_dis = (mlx->win_w / 2) / (tan(FOV / 2));
	while (i < mlx->win_w)
	{
		correct_dis = cos(mlx->player.rotat_angle - mlx->rays[i].ray_angle)
			* mlx->rays[i].dis;
		mlx->rays[i].wall_height = proj_dis * (TILE_SIZE / (correct_dis));
		mlx->rays[i].top_wall = (mlx->win_h / 2) - (mlx->rays[i].wall_height
				/ 2);
		mlx->rays[i].bot_wall = (mlx->win_h / 2) + (mlx->rays[i].wall_height
				/ 2);
		if (mlx->rays[i].top_wall < 0)
			mlx->rays[i].top_wall = 0;
		if (mlx->rays[i].bot_wall > mlx->win_h)
			mlx->rays[i].bot_wall = mlx->win_h;
		i++;
	}
}
