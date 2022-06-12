# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 19:09:59 by thabeck-          #+#    #+#              #
#    Updated: 2022/06/03 21:53:51 by thabeck-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
GREEN		= \033[0;32m
RESET		= \033[0m
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
RM 			= rm -f
HDR			= libft.h
SRCS 		= ft_isalpha.c 			\
			ft_isdigit.c 			\
			ft_isalnum.c 			\
			ft_isascii.c 			\
			ft_isprint.c 			\
			ft_strlen.c 			\
			ft_memset.c 			\
			ft_bzero.c 				\
			ft_memcpy.c 			\
			ft_memmove.c 			\
			ft_strlcpy.c 			\
			ft_strlcat.c 			\
			ft_toupper.c 			\
			ft_tolower.c 			\
			ft_strchr.c 			\
			ft_strrchr.c 			\
			ft_strncmp.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_strnstr.c			\
			ft_atoi.c 				\
			ft_strdup.c 			\
			ft_calloc.c 			\
			ft_substr.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_split.c				\
			ft_itoa.c				\
			ft_strmapi.c			\
			ft_striteri.c			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\

BONUS_SRCS  = ft_lstnew.c			\
			ft_lstadd_front.c  		\
			ft_lstsize.c 			\
			ft_lstlast.c			\
			ft_lstadd_back.c		\
			ft_lstdelone.c 			\
			ft_lstclear.c			\
			ft_lstiter.c			\
			ft_lstmap.c				\
		
OBJS 		= $(SRCS:.c=.o)
BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)


all:		$(NAME)

$(NAME): 	$(OBJS) $(HDR)
		@echo "\n$(GREEN)$(NAME) was created$(RESET)"
		ar -rcs $(NAME) $(OBJS)
		ranlib $(NAME)

bonus:		$(NAME) $(BONUS_OBJS)
		@echo "\n$(GREEN)$(NAME) was created with Bonus$(RESET)"
		ar -rcs $(NAME) $(BONUS_OBJS)
		ranlib $(NAME)
	
.c.o:
		@echo "\n$(GREEN)object file [$(<:.c=.o)] from $(NAME) was created$(RESET)"
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
		@echo "$(GREEN) $(NAME) object files were deleted$(RESET)"
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
		@echo "\n$(GREEN)$(NAME) was deleted$(RESET)"
		$(RM) $(NAME)

re :		fclean all

.PHONY:		all clean fclean re bonus
