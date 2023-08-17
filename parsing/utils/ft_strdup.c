/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:54:02 by adardour          #+#    #+#             */
/*   Updated: 2023/08/14 11:01:15 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	i;
	
	if (!s1)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}