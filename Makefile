# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 11:34:08 by agerbaud          #+#    #+#              #
#    Updated: 2025/09/12 11:41:02 by agerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS =	srcs/compute_moves.c			\
		srcs/create_chunks.c			\
		srcs/greater_elem.c				\
		srcs/index_stack.c				\
		srcs/push_swap.c				\
		srcs/sort_stack.c				\
		srcs/free_stacks.c				\
		srcs/init_stacks.c				\
		srcs/is_sorted_stack.c			\
		srcs/parse_args.c				\
		srcs/push_stack.c				\
		srcs/reverse_rotate_stacks.c	\
		srcs/rotate_stacks.c			\
		srcs/swap_stacks.c

BONUS_SRCS = srcs/checker/checker.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -Iincludes
BUILD_DIR = .build

OBJECTS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPENDENCIES = $(SRCS:%.c=$(BUILD_DIR)/%.d)

BONUS_OBJECTS = $(BONUS_SRCS:%.c=$(BUILD_DIR)/%.o)
BONUS_DEPENDENCIES = $(BONUS_SRCS:%.c=$(BUILD_DIR)/%.d)

LIBFT_SRC = $(wildcard $(LIBFTDIR)/*.c) $(wildcard $(LIBFTDIR)/**/*.c)
LIBFT_HDR = $(wildcard $(LIBFTDIR)/*.h) $(wildcard $(LIBFTDIR)/**/*.h)
LIBFT_DEPS = $(LIBFT_SRC) $(LIBFT_HDR)


all: $(NAME)

$(LIBFT): $(LIBFT_DEPS)
	$(MAKE) -C $(LIBFTDIR) bonus

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -o $@


-include $(DEPENDENCIES)


clean:
	$(RM) -r $(BUILD_DIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all


.PHONY: all clean fclean re
