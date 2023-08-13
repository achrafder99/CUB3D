# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 11:51:51 by adardour          #+#    #+#              #
#    Updated: 2023/08/13 21:52:28 by adardour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXECUTABLE = cub3D

SRCS = main.c ./get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
./utils/ft_strchr.c ./utils/ft_strstr.c ./utils/ft_split.c ./utils/ft_strdup.c ./utils/ft_atoi.c \
./utils/free_data.c \
./cub3d.c get_lines.c parse_element.c ./puts.c ./parse_map.c ./fill.c

CC = cc 
RM = rm -rf
CFLAGS = 

OBJS = ${SRCS:%.c=%.o}

all: ${EXECUTABLE}

%.o:%.c cub3d.h
	${CC} ${CFLAGS} -c $< -o ${<:%.c=%.o}

$(EXECUTABLE): ${OBJS} cub3d.h
	${CC} ${CFLAGS} ${OBJS} -o ${EXECUTABLE}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${EXECUTABLE}

re: fclean all