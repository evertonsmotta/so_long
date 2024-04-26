# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 12:54:54 by evdos-sa          #+#    #+#              #
#    Updated: 2023/08/30 16:44:58 by evdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                   COLORS                                     #
# ---------------------------------------------------------------------------- #

GREEN_COLOR = \033[38;5;46m
BLUE_COLOR	= \033[38;5;33m
PINK_COLOR	= \033[38;5;200m
YELLOW		= \033[0;33m
RED			= \033[0;31m
RESET		= \033[0m

# ---------------------------------------------------------------------------- #
#                                  VARIABLES                                   #
# ---------------------------------------------------------------------------- #

NAME		=  so_long
CC			=  cc
SRCS		=  \
				./srcs/so_long.c ./srcs/builders.c ./srcs/destroyers.c\
				./srcs/checkers.c ./srcs/put_image.c ./srcs/moves.c\
				./srcs/so_long_utils.c
CFLAGS		=  -Wall -Werror -Wextra -g3
MINILIBX_D	=  minilibx-linux
HEADERS	=  includes
LIBFT		=  ./libft/libft.a
OBJS		=  $(SRCS:.c=.o)
RM			= rm -rf

# ---------------------------------------------------------------------------- #
#                                    TASKS                                     #
# ---------------------------------------------------------------------------- #

all:		$(NAME)

%.o:		%.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	@make -C $(MINILIBX_D)
	@echo "$(YELLOW)Compiling so_long...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MINILIBX_D) -lmlx -lX11 -lXext -o $(NAME)
	@echo "$(GREEN_COLOR)so_long compiled!$(RESET)"


$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@$(MAKE) -C ./libft bonus
	@echo "$(PINK_COLOR)Libft compiled!$(RESET)"

clean:		clean
	@echo "$(YELLOW)Cleaning libft and minilibx-linux objects...$(RESET)"
	@$(RM) $(OBJS)
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C $(MINILIBX_D) clean
	@echo "$(PINK_COLOR)Objects cleaned!$(RESET)"

fclean:	clean
	@echo "$(YELLOW)Cleaning so_long minilibx-linux and libft objects...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "$(GREEN_COLOR)Fclean done.$(EOC)"

re:		fclean all

.PHONY:	all clean fclean re
