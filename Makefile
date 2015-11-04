# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/15 12:52:31 by plisieck          #+#    #+#              #
#    Updated: 2015/01/18 12:12:29 by plisieck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME			=	ft_ls
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror 
AR				=	ar rc
CCLIBFT			=	cd libft/; make; cd ../
FCLIBFT			=	cd libft/; make fclean; cd ../
LIBFT			=	libft/libft.a
RM				=	rm -f
SRCS			=	ft_ls.c ft_ls2.c ft_ls3.c ft_ls4.c ft_ls5.c	ft_ls6.c \
					ft_ls7.c ft_ls8.c ft_ls9.c ft_ls10.c ft_ls11.c ft_ls12.c \
					ft_ls13.c ft_ls14.c ft_ls15.c ft_ls16.c ft_ls17.c ft_ls18.c\
					ft_ls19.c
				
OBJS			=	$(SRCS:.c=.o)


all				:	$(NAME)

$(NAME)			:	$(OBJS)
                                     
	$(CCLIBFT)
	$(CC) -O3 $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(INCS)	                                                               

%.o				:	srcs/%.c
	$(CC) -O3 $(CFLAGS) -c $< $(INCS)

fclean			:	clean
	$(FCLIBFT)
	$(RM) $(NAME)
clean			:
	$(RM) $(OBJS)


re				:	fclean all

.PHONY: all clean fclean re
