# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 11:34:08 by agerbaud          #+#    #+#              #
#    Updated: 2024/04/05 16:28:16 by agerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
SRCS =	srcs/compute_moves.c	\
		srcs/create_chunks.c	\
		srcs/greater_elem.c		\
		srcs/index_stack.c		\
		srcs/push_swap.c		\
		srcs/sort_stack.c

UTILS =	srcs/free_stacks.c				\
		srcs/init_stacks.c				\
		srcs/is_sorted_stack.c			\
		srcs/parse_args.c				\
		srcs/push_stack.c				\
		srcs/reverse_rotate_stacks.c	\
		srcs/rotate_stacks.c			\
		srcs/swap_stacks.c

BONUS_SRCS = srcs/checker/checker.c

CC = cc -Wall -Wextra -Werror -MMD -g3

OBJECTS = $(SRCS:.c=.o)
UTILS_OBJECTS = $(UTILS:.c=.o)
BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)
DEPENDENCIES = $(SRCS:.c=.d) $(UTILS:.c=.d) $(BONUS_SRCS:.c=.d)


all: libft bonus $(NAME)

bonus: libft $(BONUS_NAME)

$(NAME): $(OBJECTS) $(UTILS_OBJECTS) $(LIBFT)
	$(CC) -o $@ $^ $(LFLAGS)

$(BONUS_NAME): $(BONUS_OBJECTS) $(UTILS_OBJECTS) $(LIBFT)
	$(CC) -o $@ $^ $(LFLAGS)

libft:
	$(MAKE) -C $(LIBFTDIR)

-include $(DEPENDENCIES)

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	$(RM) $(OBJECTS) $(UTILS_OBJECTS) $(BONUS_OBJECTS) $(DEPENDENCIES)
	$(MAKE) -C $(LIBFTDIR) $@

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFTDIR) $@

re: fclean all

.PHONY: all clean fclean re bonus libft

