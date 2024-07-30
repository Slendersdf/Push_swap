NAME = push_swap

COMP = cc -Wall -Wextra -Werror -I ./

MANDATORY_SRC = main.c ft_split.c \
					push_swap_sort_prototype.c push_swap_one_hundred.c push_swap_five_hundred.c \
						push_swap_instruct_part_one.c push_swap_instruct_part_two.c push_swap_instruct_part_three.c push_swap_instruct_part_four.c \
							push_swap_check_args.c push_swap_utils.c push_swap_utils_two.c push_swap_sort_utils.c push_swap_sort_utils_two.c

OBJ_MANDATORY = ${MANDATORY_SRC:.c=.o}

%.o: %.c
	${COMP} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ_MANDATORY}
	${COMP} ${OBJ_MANDATORY} -o ${NAME}

clean:
	rm -f ${OBJ_MANDATORY}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
