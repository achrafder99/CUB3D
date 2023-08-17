/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:47:40 by adardour          #+#    #+#             */
/*   Updated: 2023/08/17 14:18:12 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define TAILED 	32

#include	"./get_next_line/get_next_line.h"
#include	<fcntl.h>
#include 	<mlx.h>
#include 	<math.h>

#define DISPLAY_ERROR "The map must be closed/surrounded by walls\n"
#define DISPLAY_ERROR1 "Therese some elements missing\n"
#define DISPLAY_ERROR2 "color not valid expected format (R-G-B)\n"

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



typedef struct t_vars
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		WIDTH;
	int		HEIGHT;
	t_data  *data;
}	t_vars;


char	*ft_strchr(char *s, int c);
const 	char	*ft_strstr(const char *haystack, const char *needle);
char	**ft_split(char *str, int del);
char	*ft_strdup(char *s1);
int		ft_atoi(const char *str);
void	free_data(t_data *data);
void	free_things(char **spliting);
int		 put_data(t_data *data, int fd, int *reached_map);
void	parse_map(t_data *data, int reached_map);
int		parse_element(t_data *data);
char	*get_begin(int reached_map, int fd);
int		parse_element(t_data *data);
void	put(char *line, t_data *data, char i);
void	put_rgb(t_data *data, char *line, char identifier);
void	parse_map(t_data *data, int reached_map);
int		check_spaces(char *line);
void	fill(int fd, t_data *data, int count, char *start_map);
int		check_map(char **represent_map);
void	check_symbols(char	**represent_map);
void    complete_the_map(int longest_length, t_data *data);
int 	get_longest_length(char **represent_map);
void	check_characters(char *line, int *w, int *e, int *o);
int 	get_columns(char **represent);
int    	get_rows(char **represent);
#endif
