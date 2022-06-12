# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 01:12:56 by thabeck-          #+#    #+#              #
#    Updated: 2022/06/04 18:46:43 by thabeck-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
RM 			= rm -f
LIBFT		= libft/
HDR			= ft_printf.h
SRCS 		= ft_printf.c ft_printhex.c ft_printptr.c ft_printuint.c
OBJS 		= $(SRCS:.c=.o)

PURPLE		= \033[0;35m
RESET		= \033[0m

all:		$(NAME)

$(NAME): 	$(OBJS) $(HDR)
		@echo "\n$(PURPLE)$(NAME) was created$(RESET)"
		make -C $(LIBFT)
		cp libft/libft.a .
		mv libft.a $(NAME)
		ar rcs $(NAME) $(OBJS)
		@echo "$(PURPLE)libft.a was added to $(NAME)$(RESET)"

.c.o:
		@echo "\n$(PURPLE)object file [$(<:.c=.o)] from $(NAME) was created$(RESET)"
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
		@echo "$(PURPLE) $(NAME) object files were deleted$(RESET)"
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean:		clean
		@echo "\n$(PURPLE)$(NAME) was deleted$(RESET)"
		$(RM) $(NAME)
		$(RM) $(LIBFT)libft.a

re :		fclean all

.PHONY:		all clean fclean re
	