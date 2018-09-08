# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zee <zee@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 11:21:00 by agabrie           #+#    #+#              #
#    Updated: 2018/09/08 05:03:53 by zee              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make all -C lem

re:
	@make re -C lem

clean:
	@make clean -C lem

fclean:
	@make fclean -C lem

lcompile:
	@make lcompile -C lem

libclean:
	@make libclean -C lem

lemclean:
	@make lemclean -C lem

allclean:
	@make allclean -C lem

lemin:
	@make lemin -C lem
