AR = ar rcs
RANLIB = ranlib
AS = nasm
ASFLAGS = -f elf64
CC = clang
CFLAGS = -Wall -Wextra -Werror

NAME = libasm.a

# Mandatory source files
SRC =	ft_strlen.s	\
		ft_strcpy.s	\
		ft_strcmp.s	\
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s

# Bonus source files
BONUS_SRC = ft_list_size_bonus.s	\
			ft_list_push_front_bonus.s

# Object files
OBJ = $(SRC:.s=.o)
BONUS_OBJ = $(BONUS_SRC:.s=.o)

MAIN = main.c
MAIN_BONUS = main_bonus.c
EXEC = main
EXEC_BONUS = main_bonus

# Main rules
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

# Bonus rule - only rebuilds if bonus objects are newer than library
bonus: $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)
	$(RANLIB) $(NAME)

# Test and run - without forcing recompilation
run: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(EXEC)

run_bonus: bonus
	$(CC) $(CFLAGS) $(MAIN_BONUS) $(NAME) -o $(EXEC_BONUS)

# Clean rules
clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(RM) $(NAME) $(EXEC) $(EXEC_BONUS)

re: fclean all

re_bonus: fclean bonus

# Assembly compilation
%.o:%.s
	$(AS) $(ASFLAGS) $< -o $@

.PHONY: all clean fclean re re_bonus run run_bonus bonus
