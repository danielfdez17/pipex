# * Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m
OK = $(GREEN)[OK]$(RESET)

# * Program / Library name
NAME = libft.a

# * Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror # -g3 -fsanitize=address

# * Removal
RM = rm -f

# * Archiver
AR = ar -rcs

# * Includes
INCLUDES = -I inc/

# * Objects dir
OBJ_DIR = obj/

# Source files
# SRCS = $(wildcard *.c)
LIBFT_DIR = src/
LIBFT_SRCS =	$(addprefix $(LIBFT_DIR), ft_atoi.c) \
				$(addprefix $(LIBFT_DIR), ft_bzero.c) \
				$(addprefix $(LIBFT_DIR), ft_calloc.c) \
				$(addprefix $(LIBFT_DIR), ft_isalnum.c) \
				$(addprefix $(LIBFT_DIR), ft_isalpha.c) \
				$(addprefix $(LIBFT_DIR), ft_isascii.c) \
				$(addprefix $(LIBFT_DIR), ft_isdigit.c) \
				$(addprefix $(LIBFT_DIR), ft_isprint.c) \
				$(addprefix $(LIBFT_DIR), ft_itoa.c) \
				$(addprefix $(LIBFT_DIR), ft_memchr.c) \
				$(addprefix $(LIBFT_DIR), ft_memcmp.c) \
				$(addprefix $(LIBFT_DIR), ft_memcpy.c) \
				$(addprefix $(LIBFT_DIR), ft_memmove.c) \
				$(addprefix $(LIBFT_DIR), ft_memset.c) \
				$(addprefix $(LIBFT_DIR), ft_putchar_fd.c) \
				$(addprefix $(LIBFT_DIR), ft_putendl_fd.c) \
				$(addprefix $(LIBFT_DIR), ft_putnbr_fd.c) \
				$(addprefix $(LIBFT_DIR), ft_putstr_fd.c) \
				$(addprefix $(LIBFT_DIR), ft_split.c) \
				$(addprefix $(LIBFT_DIR), ft_strchr.c) \
				$(addprefix $(LIBFT_DIR), ft_strdup.c) \
				$(addprefix $(LIBFT_DIR), ft_striteri.c) \
				$(addprefix $(LIBFT_DIR), ft_strjoin.c) \
				$(addprefix $(LIBFT_DIR), ft_strlcat.c) \
				$(addprefix $(LIBFT_DIR), ft_strlcpy.c) \
				$(addprefix $(LIBFT_DIR), ft_strlen.c) \
				$(addprefix $(LIBFT_DIR), ft_strmapi.c) \
				$(addprefix $(LIBFT_DIR), ft_strncmp.c) \
				$(addprefix $(LIBFT_DIR), ft_strnstr.c) \
				$(addprefix $(LIBFT_DIR), ft_strrchr.c) \
				$(addprefix $(LIBFT_DIR), ft_strtrim.c) \
				$(addprefix $(LIBFT_DIR), ft_substr.c) \
				$(addprefix $(LIBFT_DIR), ft_tolower.c) \
				$(addprefix $(LIBFT_DIR), ft_toupper.c) \
				$(addprefix $(LIBFT_DIR), ft_lstadd_back.c) \
				$(addprefix $(LIBFT_DIR), ft_lstadd_front.c) \
				$(addprefix $(LIBFT_DIR), ft_lstclear.c) \
				$(addprefix $(LIBFT_DIR), ft_lstdelone.c) \
				$(addprefix $(LIBFT_DIR), ft_lstiter.c) \
				$(addprefix $(LIBFT_DIR), ft_lstlast.c) \
				$(addprefix $(LIBFT_DIR), ft_lstmap.c) \
				$(addprefix $(LIBFT_DIR), ft_lstnew.c) \
				$(addprefix $(LIBFT_DIR), ft_lstsize.c) \
				$(addprefix $(LIBFT_DIR), ft_printf.c) \
				$(addprefix $(LIBFT_DIR), ft_put_char.c) \
				$(addprefix $(LIBFT_DIR), ft_put_hex.c) \
				$(addprefix $(LIBFT_DIR), ft_put_int.c) \
				$(addprefix $(LIBFT_DIR), ft_put_str.c) \
				$(addprefix $(LIBFT_DIR), ft_put_uint.c) \
				$(addprefix $(LIBFT_DIR), get_next_line.c) \
				$(addprefix $(LIBFT_DIR), get_next_line_utils.c)
SRCS = $(LIBFT_SRCS)


# Bonus source files
# BONUS_SRCS = $(wildcard *_bonus.c)
# BONUS_SRCS =	ft_lstadd_back_bonus.c\
# 				ft_lstadd_front_bonus.c\
# 				ft_lstclear_bonus.c\
# 				ft_lstdelone_bonus.c\
# 				ft_lstiter_bonus.c\
# 				ft_lstlast_bonus.c\
# 				ft_lstmap_bonus.c\
# 				ft_lstnew_bonus.c\
# 				ft_lstsize_bonus.c
# SRCS += $(addprefix src/, $(BONUS_SRCS))
# Include files
# INCS = $(wildcard *.h)
# INCS = libft.h

# Object files
OBJS = $(patsubst $(LIBFT_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
# OBJS = $(SRCS:.c=.o)

# # Bonus object files
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# ? Main program compilation
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(OK) $(GREEN)$(NAME)$(RESET)"

# Links a .c (and .h if needed) to its .o file
# %.o: $(LIBFT_DIR)%.c
$(OBJ_DIR)%.o: $(LIBFT_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ? Compiles the whole program/library
all: obj $(NAME)

# ? Creates the object directorygs
obj:
	@mkdir -p $(OBJ_DIR)

# ? Removes the object files
clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(OK) $(RED)Removed object files$(RESET)"

# ? Removes both object and executable files
fclean: clean
	@$(RM) $(NAME)
	@echo "$(OK) $(RED)Removed $(NAME)$(RESET)"

# ? Rebuilds the program/library
re: fclean all
	@echo "$(OK) $(YELLOW)Rebuilt $(NAME)$(RESET)"

.PHONY: all clean fclean re
