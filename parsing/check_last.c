/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:01:55 by adardour          #+#    #+#             */
/*   Updated: 2023/09/08 17:40:19 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"
#include "../include/parsing.h"

int	check_line_last(char *last)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (last[i])
	{
		if (last[i] == ' ')
			count++;
		i++;
	}
	if (count == ft_strlen(last))
		return (0);
	return (1);
}

int	check_last(char *path)
{
	char	*line;
	char	*last;
	int		fd;

	fd = open(path, O_RDONLY);
	last = NULL;
	if (fd == -1)
		exit(1);
	line = get_next_line(fd);
	while (line)
	{
		if (last != NULL)
		{
			free(last);
			last = NULL;
		}
		last = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	if (!check_line_last(last))
		return (free(last), 0);
	free(last);
	return (1);
}
