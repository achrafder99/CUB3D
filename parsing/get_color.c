/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:28:32 by adardour          #+#    #+#             */
/*   Updated: 2023/09/08 18:12:27 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

unsigned int	get_color(char *r, char *g, char *b)
{
	return (ft_atoi(r) << 16 | ft_atoi(g) << 8 | ft_atoi(b));
}
