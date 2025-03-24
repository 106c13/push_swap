CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/ft_commands.c mandatory/ft_push_counter.c mandatory/ft_utils.c mandatory/ft_list_tools.c mandatory/ft_sorter.c mandatory/push_swap.c \
	mandatory/ft_atoi.c mandatory/ft_median_counter.c mandatory/ft_split.c

OBJ = $(SRC:.c=.o)

HEADER = push_swap.h

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all


.PHONY:	all clean fclean re
