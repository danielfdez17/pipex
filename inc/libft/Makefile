# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 07:42:17 by danfern3          #+#    #+#              #
#    Updated: 2025/10/10 08:59:34 by danfern3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = libft.a

# Source files
LIBFT_DIR = ./src/libft/
LIBFT_SRCS = $(shell ls $(LIBFT_DIR) | grep -E ".+\.c")

OBJ_DIR = ./src/obj/

SRCS = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(LIBFT_SRCS:.c=.o))

FT_PRINTF_DIR = ./src/ft_printf/
FT_PRINTF_SRCS = $(shell ls $(FT_PRINTF_DIR) | grep -E ".+\.c")
SRCS += $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_SRCS))
OBJS += $(addprefix $(OBJ_DIR), $(FT_PRINTF_SRCS:.c=.o))

GNL_DIR = ./src/gnl/
GNL_SRCS = $(shell ls $(GNL_DIR) | grep -E ".+\.c")
SRCS += $(addprefix $(GNL_DIR), $(GNL_SRCS))
OBJS += $(addprefix $(OBJ_DIR), $(GNL_SRCS:.c=.o))

# Include files
INCLUDES = -I ./inc/headers/

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
# CFLAGS += -fsanitize=address

# Removal
RM = rm -f

# Archiver
AR = ar -rcs

# Links a .c (and .h if needed) to its .o file
$(OBJ_DIR)%.o: $(LIBFT_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(FT_PRINTF_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compiles the whole program/library
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "Compiling $(NAME)"

# Removes the object files
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "Removing .o files"
# Removes both object and executable files
fclean: clean
	@$(RM) $(NAME)
	@echo "Removing $(NAME)"

# Rebuilds the program/library
re: fclean all

# Executes norminette for every file
# norminette:
# 	echo Executing norminette for every file
# 	$(NORMINETTE) $(NCFLAGS) $(NHFLAGS) $(SRCS) $(HEADERS) $(BONUS_SRCS)

# .PHONY: all clean fclean re rebonus bonus
