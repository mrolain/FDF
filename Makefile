# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 22:29:59 by mrolain           #+#    #+#              #
#    Updated: 2024/09/09 12:01:55 by mrolain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =  src/fdf.c \
		src/closing.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \
		src/ft_atoi.c \
		src/ft_split.c \
		src/ft_memcpy.c \
		
OBJS = ${SRCS:.c=.o}

CC = cc -Wall -Wextra -Werror -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -I /home/mrolain/42cursus/FDF/minilibx-linux
LDFLAGS = -L /home/mrolain/42cursus/FDF/minilibx-linux -lmlx -lXext -lX11 -lm
RM = rm -f

OTHER_MAKEFILE_DIR = /home/mrolain/42cursus/FDF/minilibx-linux

all:		${NAME} compile_other_makefile

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

compile_other_makefile:
		$(MAKE) -C ${OTHER_MAKEFILE_DIR}

clean:
		@${RM} ${OBJS}

fclean: clean
		@${RM} ${NAME}

re:		fclean all