/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:41:01 by adardour          #+#    #+#             */
/*   Updated: 2023/08/20 14:42:35 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strrchr(char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	if (c == 0)
		return ((char *)s + length);
	while (length--)
	{
		if (s[length] == (unsigned char)c)
			return ((char *)s + length);
	}
	return (NULL);
}
