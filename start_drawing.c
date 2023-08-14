/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:43:21 by adardour          #+#    #+#             */
/*   Updated: 2023/08/14 21:32:42 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_line(char *line)
{
    int i = 0;
    while(line[i] != '\0')
    {
        if (line[i] == '\n')
        {
            return (1);
        }
        i++;
    }
    
    return (0);
}

char    *complete_line(char *line, int longest_length)
{
    char *return_line;
    int flags;
    int check;
    flags = 0;
    check = 0;
    int dd = longest_length - strlen(line);
    if (!check_line(line))
    {
      longest_length -= 1;
    }
    else
      flags = 1;
    return_line = malloc((sizeof(char) * longest_length) + 1);
    if (!return_line)
    {
        perror("");
        exit(1);
    }
    int i;
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != '\n')
        {
          if (line[i] != ' ')
          {
            return_line[i] = line[i];
            check++;
          }
          else
          {
            return_line[i] = 's';
            check++;
          }
        }
        i++;
    }
    while (i < longest_length)
    {
      return_line[check] = 's';
      check++;
      i++;
    }
    if (flags)
    {
        return_line[check] = '\n';
        check += 1;
    }
    return_line[check] = '\0'; 
    return (return_line);
}

void    complete_the_map(int longest_length, t_data *data)
{
    int i;
    i = 0;

    while (data->map_represent[i] != NULL)
    {
        data->map_represent[i] = complete_line(data->map_represent[i], longest_length);
        printf("%s",data->map_represent[i]);
        i++;
    }
    
}

int get_longest_length(char **represent_map)
{
    int index;
    int length;
    index = 0;
    length = ft_strlen(represent_map[0]);
    while (represent_map[index])
    {
        if (ft_strlen(represent_map[index]) > length)
            length = ft_strlen(represent_map[index]);
        index++;
    }
    return (length);      
}

int    get_rows(char **represent)
{
    int rows;
    rows = 0;
    while (represent[rows])
        rows++;
    return (rows);
}

int get_columns(char **represent)
{
    int i;
    int j;
    i = 0;
    while (represent[i])
    {
        j = 0;
        while (represent[i][j] != '\0')
        {
            // printf("%c",represent[i][j]);
            j++;
        }
        i++;
    }
    return (10);
}

void    start_drawing(t_data *data)
{
    t_vars vars;
    int  longes_length;

    longes_length = get_longest_length(data->map_represent);
    complete_the_map(longes_length, data);
    vars.rows = get_rows(data->map_represent);
    vars.column = get_columns(data->map_represent);
}
