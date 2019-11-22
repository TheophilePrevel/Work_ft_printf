# DIRECTORIES
DEP_DIR	= dep
OBJ_DIR	= obj
DIR		= $(DEP_DIR) $(OBJ_DIR)

# FILES
NAME	= libftprintf.a
SRC		= ft_printf.c \
			ft_parse_flags.c \
			ft_print_char_str_mem.c \
			ft_print_int.c \
			ft_print_hex.c \
			ft_print_pt.c \
			ft_putchar_fd.c \
			ft_strchr.c 

DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'

$(NAME): $(OBJ)
	@echo 'Creation of $@'
	@ar -rcs $@ $^

all: $(NAME)

clean:
	rm -rf $(DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEP_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: %.c | $(DIR)
	@echo 'Compilation of $<'
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re
