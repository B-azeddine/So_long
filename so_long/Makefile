
INC = so_long.h
INC_BONUS = so_long_bonus.h
NAME = so_long
NAME_BONUS = so_long_bonus

SRCS = so_long.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
		libft/ft_puts.c libft/ft_itoa.c libft/ft_split.c libft/ft_strdup.c libft/ft_strncmp.c \
		map.c check_uniq_items.c destroys.c destroy2.c send_to_allocation.c \
		ft_print.c check_valid_path.c utlis.c wall_utils.c

SRCS_BONUS = bonus/so_long_bonus.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
			bonus/check_uniq_items_bonus.c bonus/destroy2_bonus.c \
			bonus/ft_print_bonus.c bonus/send_to_allocation_bonus.c bonus/utlis_bonus.c \
			bonus/check_valid_path_bonus.c bonus/destroys_bonus.c bonus/map_bonus.c bonus/wall_utils_bonus.c \
			bonus/ft_puts_bonus.c bonus/ft_itoa_bonus.c bonus/ft_split_bonus.c bonus/ft_strdup_bonus.c bonus/ft_strncmp_bonus.c

OBJECTS = ${SRCS:.c=.o}

OBJECTS_BONUS = ${SRCS_BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror 
CC = cc

all :  ${NAME}

bonus : ${NAME_BONUS}

${NAME} : ${OBJECTS} $(INC) 
	${CC} -lmlx -framework OpenGL -framework AppKit $(CFLAGS) ${OBJECTS} -o ${NAME}

${NAME_BONUS} : ${OBJECTS_BONUS} 
	${CC} -lmlx -framework OpenGL -framework AppKit $(CFLAGS) ${OBJECTS_BONUS} -o ${NAME_BONUS}

clean :
	rm  -rf ${OBJECTS} ${OBJECTS_BONUS}

fclean : clean
	rm -rf ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : all bonus clean fclean re