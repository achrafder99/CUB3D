/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:47:40 by adardour          #+#    #+#             */
/*   Updated: 2023/08/20 14:42:43 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TAILED 32

# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define DISPLAY_ERROR "The map must be closed/surrounded by walls\n"
# define DISPLAY_ERROR1 "There are some elements missing\n"
# define DISPLAY_ERROR2 "Color not valid; expected format (R-G-B)\n"

typedef struct s_dd
{
	void		*img_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*img_data;
}				t_dd;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_texture;

typedef struct s_floor
{
	char			*r;
	char			*g;
	char			*b;
	unsigned int	color;
}				t_floor;

typedef struct s_ceiling
{
	char			*r;
	char			*g;
	char			*b;
	unsigned int	color;
}				t_ceiling;

typedef struct s_data
{
	t_ceiling	ceiling;
	t_floor		floor;
	t_texture	texture;
	char		**map_represent;
}				t_data;

typedef struct s_vars
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
	t_data		*data;
	t_player	player;
	t_dd		d;
}				t_vars;

char			*ft_strchr(char *s, int c);
const char		*ft_strstr(const char *haystack, const char *needle);
char			**ft_split(char *str, int del);
char			*ft_strdup(char *s1);
int				ft_atoi(const char *str);
void			free_data(t_data *data);
void			free_things(char **spliting);
int				put_data(t_data *data, int fd, int *reached_map);
void			parse_map(t_data *data, int reached_map);
int				parse_element(t_data *data);
char			*get_begin(int reached_map, int fd);
int				parse_element(t_data *data);
void			put(char *line, t_data *data, char i);
void			put_rgb(t_data *data, char *line, char identifier);
void			parse_map(t_data *data, int reached_map);
int				check_spaces(char *line);
void			fill(int fd, t_data *data, int count, char *start_map);
int				check_map(char **represent_map);
void			check_symbols(char **represent_map);
void			complete_the_map(int longest_length, t_data *data);
int				get_longest_length(char **represent_map);
void			check_characters(char *line, int *w, int *e, int *o);
int				get_columns(char **represent);
int				get_rows(char **represent);
void			start_drawing(t_data *data);
unsigned int	get_color(char *r, char *g, char *b);
void			colors(t_data *data);
int				check_rgbs(t_ceiling ceiling, t_floor floor);
int				check_color(char *color);
int				check_car(char *r, char *g, char *b);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strrchr(char *s, int c);
#endif