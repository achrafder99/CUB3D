/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:48:05 by adardour          #+#    #+#             */
/*   Updated: 2023/09/08 16:08:45 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"
#include "../include/cub.h"

void	proccess_color(t_help help, int *flag, char *identifier, t_data *data)
{
	help.j = 0;
	while (help.spliting[help.i][help.j])
	{
		if (help.spliting[help.i][help.j] == ',' \
		&& help.spliting[help.i][help.j] != '\0')
		{
			help.color = ft_substr(help.spliting[help.i], \
				help.start, help.j - help.start);
			put_color(help.color, *flag, identifier, data);
			free(help.color);
			(*flag)++;
			help.j++;
		}
		help.start = help.j;
		while (help.spliting[help.i][help.j] && \
		help.spliting[help.i][help.j] != ',')
			help.j++;
	}
	if (help.start != help.j)
	{
		help.color = ft_substr(help.spliting[help.i], \
		help.start, help.j - help.start);
		put_color(help.color, *flag, identifier, data);
		free(help.color);
	}
}

void	put_celing_floor(char *line, char *identifier, t_data *data)
{
	t_help		help;
	static int	flag;

	flag = 0;
	help.spliting = ft_split(line, ' ');
	help.i = 1;
	help.start = 0;
	while (help.spliting[help.i])
	{
		proccess_color(help, &flag, identifier, data);
		help.i++;
	}
	free_things(help.spliting);
}

int	just_check(char *color)
{
	int	i;

	i = 0;
	while (color[i] && color[i] != ' ')
		i++;	
	while (color[i])
	{
		if (color[i] != ' ' || color[i] < 48 || color[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	put_rgb(t_data *data, char *line, char *identifier, int *reached_map)
{
	int		i;
	char	**spliting;
	char	*trim;
	char	*str;

	i = -1;
	str = ft_strchr(line, identifier[0]) + 1;
	while (str[i] && str[i] == ' ')
		i++;
	i = -1;
	spliting = ft_split(str, ',');
	while (spliting[++i])
	{
		trim = ft_strtrim(spliting[i], " \n");
		if (!just_check(trim))
			return (free(trim), free_things(spliting), 0);
		free(trim);
	}
	free_things(spliting);
	if (i != 3)
		return (0);
	put_celing_floor(line, identifier, data);
	(*reached_map)++;
	return (1);
}

int	put_data(t_data *data, int fd, int *reached_map)
{
	char		*line;
	char		**spliting;
	static int	flags;

	line = get_next_line(fd);
	while (line != NULL)
	{
		spliting = ft_split(line, ' ');
		if (!ft_strcmp(spliting[0], "SO") || \
		!ft_strcmp(spliting[0], "WE") || \
		!ft_strcmp(spliting[0], "EA") || \
		!ft_strcmp(spliting[0], "NO"))
			put(line, data, reached_map);
		else if (!ft_strcmp(spliting[0], "\n"))
			(*reached_map)++;
		else if (!ft_strcmp(spliting[0], "F") || \
		!ft_strcmp(spliting[0], "C"))
		{
			if (!put_rgb(data, line, spliting[0], reached_map))
				return (0);
		}
		free(line);
		free_things(spliting);
		line = get_next_line(fd);
	}
	if (*reached_map < 6)
		return (0);
	return (1);
}
