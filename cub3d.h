/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:47:40 by adardour          #+#    #+#             */
/*   Updated: 2023/08/12 17:51:00 by adardour         ###   ########.fr       */
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
	t_texture texture;
	t_floor  floor;
	t_ceiling ceiling;
	char	**map_represent;
}	t_data;


#include	"./get_next_line/get_next_line.h"
#include	<fcntl.h>
char	*ft_strchr(char *s, int c);
const char	*ft_strstr(const char *haystack, const char *needle);
char	**ft_split(char *str, int del);
char	*ft_strdup(char *s1);
int	ft_atoi(const char *str);
void	free_data(t_data *data);
void	free_things(char **spliting);

#endif
