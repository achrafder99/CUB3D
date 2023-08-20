/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:35:02 by adardour          #+#    #+#             */
/*   Updated: 2023/08/20 12:36:56 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_data(t_data *data)
{
	free(data->texture.no);
	free(data->texture.so);
	free(data->texture.ea);
	free(data->texture.ea);
	free(data->ceiling.r);
	free(data->ceiling.g);
	free(data->ceiling.b);
	free(data->floor.r);
	free(data->floor.g);
	free(data->floor.b);
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
