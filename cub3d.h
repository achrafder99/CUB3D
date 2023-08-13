/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:47:40 by adardour          #+#    #+#             */
/*   Updated: 2023/08/13 21:56:48 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H


typedef struct t_texture
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
}	t_texture;

typedef struct t_floor
{
	char *R;
	char *G;
	char *B;
}
	t_floor;
typedef struct t_ceiling
{
	char *R;
	char *G;
	char *B;
}	t_ceiling;

typedef struct t_data
{
	t_ceiling	ceiling;
	t_floor		floor;
	t_texture	texture;
	char		**map_represent;
}	t_data;


#include	"./get_next_line/get_next_line.h"
#include	<fcntl.h>

char	*ft_strchr(char *s, int c);
const 	char	*ft_strstr(const char *haystack, const char *needle);
char	**ft_split(char *str, int del);
char	*ft_strdup(char *s1);
int		ft_atoi(const char *str);
void	free_data(t_data *data);
void	free_things(char **spliting);
void	put_data(t_data *data, int fd, int *reached_map);
void	parse_map(t_data *data, int reached_map);
int		parse_element(t_data *data);
char	*get_begin(int reached_map, int fd);
int		parse_element(t_data *data);
void	put_data(t_data *data, int fd, int *reached_map);
void	put(char *line, t_data *data, char i);
void	put_rgb(t_data *data, char *line, char identifier);
void	parse_map(t_data *data, int reached_map);
int		check_spaces(char *line);
void	fill(int fd, t_data *data, int count, char *start_map);
#endif
