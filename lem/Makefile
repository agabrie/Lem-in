# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zee <zee@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 08:15:41 by agabrie           #+#    #+#              #
#    Updated: 2018/09/08 05:01:06 by zee              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem_in.a

CNAME	=	../lem-in

SRCS	=	init.c ants.c rooms.c links.c manipulist.c

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	../libft/libft.a

GCC		=	gcc -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) :
		@$(GCC) -c $(SRCS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "Library [$(NAME)] updated!"

clean:
		@/bin/rm -rf $(OBJS)

libclean:
		@/bin/rm -rf $(NAME)

lemclean:
		@/bin/rm -rf $(CNAME)

fclean: clean libclean

allclean : clean libclean lemclean
		make allclean -C ../libft

re: allclean all lcompile
		@make fclean

lcompile:
		@make re -C ../libft
		@$(GCC) main.c $(NAME) $(LIBFT) -o $(CNAME)

lemin: all lcompile libclean clean