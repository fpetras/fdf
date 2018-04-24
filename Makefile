# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpetras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 08:13:19 by fpetras           #+#    #+#              #
#    Updated: 2018/04/24 12:03:03 by fpetras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
	  get_map_data.c \
	  set_constants.c \
	  draw.c

OBJPATH = obj/
OBJ = $(addprefix $(OBJPATH),$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = libmlx.a -framework OpenGL -framework AppKit

# ----- ANSI Escape Sequences ----- #
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
UNDERLINE = \033[0;4m
TEXT_RESET = \033[0;0m
# --------------------------------- #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(TEXT_RESET)"
	@echo "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0"
	@echo "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0"
	@echo "0 $(PURPLE)10 10 10 10 10$(TEXT_RESET)  0 $(PURPLE)10 10 10 10$(TEXT_RESET)  0  0  0 $(PURPLE)10 10 10 10 10$(TEXT_RESET)  0"
	@echo "0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0 $(PURPLE)10$(TEXT_RESET)  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0"
	@echo "0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0 $(PURPLE)10$(TEXT_RESET)  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0"
	@echo "0 $(PURPLE)10 10 10 10$(TEXT_RESET)  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0 $(PURPLE)10$(TEXT_RESET)  0  0 $(PURPLE)10 10 10 10$(TEXT_RESET)  0  0"
	@echo "0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0 $(PURPLE)10$(TEXT_RESET)  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0"
	@echo "0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0 $(PURPLE)10$(TEXT_RESET)  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0"
	@echo "0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0 $(PURPLE)10 10 10 10$(TEXT_RESET)  0  0  0 $(PURPLE)10 10$(TEXT_RESET)  0  0  0  0"
	@echo "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0"
	@echo "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0\n"
	@echo "$(UNDERLINE)libft:$(TEXT_RESET)"
	@echo "$(BLUE)"
	@make -C libft
	@echo "$(TEXT_RESET)"
	@echo "Generating executable file:\n$(WHITE)$@\n$(TEXT_RESET)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) libft/libft.a $(MLXFLAGS)
	@echo "$(GREEN)Success$(TEXT_RESET)"

$(OBJPATH)%.o: %.c
	@test -d $(OBJPATH) || mkdir $(OBJPATH)
	@echo "$(CYAN)Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@rm -rf $(OBJPATH)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
