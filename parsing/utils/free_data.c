/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:35:02 by adardour          #+#    #+#             */
/*   Updated: 2023/08/12 17:52:55 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_data(t_data *data)
{
	free(data->texture.NO);
	free(data->texture.SO);
	free(data->texture.EA);
	free(data->texture.WE);
	free(data->ceiling.R);
	free(data->ceiling.G);
	free(data->ceiling.B);
	free(data->floor.R);
	free(data->floor.G);
	free(data->floor.B);
	free(data);
}

void	free_things(char **spliting)
{
	int	i;

	i = 0;
	while (spliting[i])
	{
		free(spliting[i]);
		i++;
	}
	free(spliting);
}