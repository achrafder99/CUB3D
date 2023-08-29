/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:45:07 by adardour          #+#    #+#             */
/*   Updated: 2023/08/29 13:25:38 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	open_file(char *filename)
{
	int		fd;
	char	*substr;

	substr = ft_substr(filename, 0, ft_strlen(filename) - 1);
	fd = open(substr, O_RDONLY);
	free(substr);
	return (fd);
}

void	open_texture(char *n, char *s, char *w, char *e)
{
	int	fd_n;
	int	fd_s;
	int	fd_w;
	int	fd_e;

	fd_n = open_file(n);
	fd_s = open_file(s);
	fd_w = open_file(w);
	fd_e = open_file(e);
	if (fd_n == -1 || fd_s == -1 || fd_w == -1 || fd_e == -1)
		return (perror("Texture Error : "), exit(1));
	else if (((ft_strcmp(ft_strrchr(n, '.') + 1, "xpm")) - '\n') != 0 || \
	((ft_strcmp(ft_strrchr(s, '.') + 1, "xpm")) - '\n') != 0 || \
	((ft_strcmp(ft_strrchr(w, '.') + 1, "xpm")) - '\n') != 0 || \
	((ft_strcmp(ft_strrchr(w, '.') + 1, "xpm")) - '\n') != 0)
	{
		printf("the format path must be (.xpm)\n");
		exit(1);
	}
}
