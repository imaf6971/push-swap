NAME 	=	push_swap

HEADER	=	stack.h

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I $(HEADER)

LIBFT	=	libft.a
LIBFT_DIRECTORY = ./libft/

SRCS	=	main.c push.c swap.c rotate.c reverse_rotate.c stack.c argcheck.c sort.c stack0.c smallsort.c
OBJ		=	$(patsubst %.c, %.o, $(SRCS))

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIRECTORY)$(LIBFT) -o $(NAME)

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ) $(BOBJ)

fclean	:
	@rm -f $(OBJ) $(BOBJ) $(NAME)

re		:	fclean	$(NAME)