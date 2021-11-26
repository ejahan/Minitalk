# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elisa <elisa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 12:52:35 by elisa             #+#    #+#              #
#    Updated: 2021/11/26 10:34:13 by elisa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	=	server

NAME_CLIENT	=	client

INCS	=	minitalk.h

SRCS_SERVER	=	./SRCS/server.c ./SRCS/utils.c

SRCS_CLIENT	=	./SRCS/client.c ./SRCS/utils.c

OBJS_SERVER	=	${SRCS_SERVER:.c=.o}

OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror #-g3 #-fsanitize=address

RM		=	rm -rf

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

all:		${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}:	${OBJS_SERVER}
			$(CC) ${CFLAGS} $(OBJS_SERVER) -I $(INCS) -o $(NAME_SERVER)

${NAME_CLIENT}:	${OBJS_CLIENT}
			$(CC) ${CFLAGS} $(OBJS_CLIENT) -I $(INCS) -o $(NAME_CLIENT)

clean:
			${RM} ${OBJS_SERVER} ${OBJS_CLIENT}

fclean:		clean
			${RM} ${NAME_SERVER} ${NAME_CLIENT}

re:			fclean all

.PHONY:		all clean fclean re
