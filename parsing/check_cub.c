/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:35:58 by adardour          #+#    #+#             */
/*   Updated: 2023/09/07 20:31:16 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/parsing.h"

int	check_cub(char *path)
{
	char	*extension;

	extension = ft_strrchr(path, '.');
	if (!extension)
		exit (1);
	extension += 1;
	if (ft_strcmp(extension, "cub"))
	{
		printf("the extension must be .cub");
		exit(1);
	}
	return (1);
}
