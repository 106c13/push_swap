CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/ft_commands.c mandatory/ft_push_counter.c mandatory/ft_utils.c \
	mandatory/ft_list_tools.c mandatory/ft_sorter.c mandatory/push_swap.c \
	mandatory/ft_atoi.c mandatory/ft_median_counter.c mandatory/ft_split.c \
	mandatory/ft_list_utils.c

SRC_BONUS = bonus/checker.c  bonus/ft_atoi.c  bonus/ft_commands.c  bonus/ft_list_tools.ic \
		bonus/ft_split.c  bonus/ft_utils.c  bonus/get_next_line.c  bonus/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = mandatory/push_swap.h
HEADER_BONUS = bonus/checker.h

NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re: fclean all


.PHONY:	all clean fclean re
