# DIRECTORIES
DEP_DIR	= dep
OBJ_DIR	= obj
LIBFT_DIR	= libft/
DIR		= $(DEP_DIR) $(OBJ_DIR)

# FILES
NAME	= printf.a
SRC		= 
BONUS	= 
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_B	:= $(BONUS:%.c=$(OBJ_DIR)/%.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'

$(NAME): $(OBJ)
	@echo 'Creation of $@'
	@ar -rcs $@ $^

all: $(NAME)

bonus: $(NAME) $(OBJ_B) 
	@echo 'Add bonus to $(NAME)'
	@ar -rcs $(NAME) $^

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
