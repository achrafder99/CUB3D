/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:29:39 by adardour          #+#    #+#             */
/*   Updated: 2023/08/14 12:09:43 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
