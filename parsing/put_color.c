/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:42:33 by adardour          #+#    #+#             */
/*   Updated: 2023/09/07 20:36:16 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/cub.h"

void	put_color(char *color, int flag, char *identifier, t_data *data)
{
	if (ft_strlen(color) == 0)
		return ;
	if (!ft_strcmp(identifier, "F"))
	{
		if (flag == 0 && !data->floor.r)
			data->floor.r = ft_strtrim(color, "\n");
		else if (flag == 1 && !data->floor.g)
			data->floor.g = ft_strtrim(color, "\n");
		else if (flag == 2 && !data->floor.b)
			data->floor.b = ft_strtrim(color, "\n");
	}
	else
	{
		if (flag == 0 && !data->ceiling.r)
			data->ceiling.r = ft_strtrim(color, "\n");
		else if (flag == 1 && !data->ceiling.g)
			data->ceiling.g = ft_strtrim(color, "\n");
		else if (flag == 2 && !data->ceiling.b)
			data->ceiling.b = ft_strtrim(color, "\n");
	}
}
