CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = push_swap.h
SRC = ft_algo.c \
	ft_algo2.c \
	ft_atoi.c \
	ft_check.c \
	ft_check2.c \
	ft_chunk_size.c \
	ft_isdigit.c \
	ft_less_op.c \
	ft_less_op2.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_operation_manager.c \
	ft_pa.c \
	ft_pb.c \
	ft_print_result.c \
	ft_ra.c \
	ft_rb.c \
	ft_rr.c \
	ft_rra.c \
	ft_rrb.c \
	ft_rrr.c \
	ft_sa.c \
	ft_sb.c \
	ft_solve_case.c \
	ft_solve_case2.c \
	ft_solve_case3.c \
	ft_sort.c \
	ft_ss.c \
	main.c \
	resolve.c \
	resolve2.c \
	utils.c \
	ft_split.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	 $(CC) -o $(NAME) $(OBJ) -I $(INCLUDES)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
