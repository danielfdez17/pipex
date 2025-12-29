# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 09:34:42 by danfern3          #+#    #+#              #
#    Updated: 2025/11/14 15:18:18 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# * Colors and utils
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m
OK = $(GREEN)[OK]$(RESET)
NO_PRINT = --no-print-directory

# * Program name
NAME = pipex

# * Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror # -g3 -fsanitize=address

# * Removal
RM = rm -f

# * Includes
INCLUDES = -I inc/ -I inc/libft/inc/

# * Objects dir
OBJ_DIR = obj/

# * Sources files
PIPEX_DIR = src/
PIPEX_SRCS =	$(addprefix $(PIPEX_DIR), error_bonus.c) \
				$(addprefix $(PIPEX_DIR), files_bonus.c) \
				$(addprefix $(PIPEX_DIR), free_bonus.c) \
				$(addprefix $(PIPEX_DIR), main_bonus.c) \
				$(addprefix $(PIPEX_DIR), pipes_bonus.c) \
				$(addprefix $(PIPEX_DIR), run_bonus.c)
SRCS = $(PIPEX_SRCS)

# * Creating object files
OBJS = $(patsubst $(PIPEX_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# * LIBFT
LIBFT_DIR = inc/libft/
LIBFT = inc/libft/libft.a

# ! RULES
# ? Links a .c (and .h if needed) to its .o file
$(OBJ_DIR)%.o: $(PIPEX_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ? main program compilation
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(OK) $(GREEN)$(NAME)$(RESET)"

# ? libft compilation
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all $(NO_PRINT)
	@echo "$(OK) $(GREEN)libft.a$(RESET)"

# ? Compiles the whole program/library
bonus: all
all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

# ? Removes the object files
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean $(NO_PRINT)
	@echo "$(OK) $(RED)Removed object files$(RESET)"

# ? Removes both object and executable files
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean $(NO_PRINT)
	@echo "$(OK) $(RED)Removed $(NAME)$(RESET)"

# ? Rebuilds the program/library
rebonus: fclean all
	@$(MAKE) -C $(LIBFT_DIR) re $(NO_PRINT)
	@echo "$(OK) $(YELLOW)Rebuilt $(NAME)$(RESET)"

# ! Automating / Debugging rules
run: all
	clear
	valgrind --track-fds=yes -s ./$(NAME) infile "ls -l" "cat Makefile" "grep a" "wc -l" outfile

run2: all
	clear
	valgrind --track-fds=yes -s ./$(NAME) infile "sleep 2" ls "cat Makefile" "grep src" outfile

valgrind: all
	clear
	valgrind --leak-check=full --track-origins=yes -s ./$(NAME) infile "ls -l" "cat Makefile" "grep a" "wc -l" outfile

debug: all
	clear
	gdb ./$(NAME)

# Protects all rules from files with same name
.PHONY: all obj clean fclean bonus rebonus run run2 valgrind debug

# Indicates the main rule to be executed when only 'make' is called
.GOAL: all