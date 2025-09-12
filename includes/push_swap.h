/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:23:10 by agerbaud          #+#    #+#             */
/*   Updated: 2025/09/12 11:45:22 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

# include "../libft/includes/libft.h"

# define INT_MAX	2147483647

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_instructions
{
	int		ra;
	int		rb;
	bool	rra;
	bool	rrb;
	int		sum;
}	t_instructions;

typedef struct s_value
{
	int	value;
	int	index;
}	t_value;

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}	t_stack;

typedef void	(*t_operation)(t_stack);

void			free_stacks(t_stack stacks);

bool			init_stack(int argc, char **argv, t_stack *stacks);
bool			is_sorted_stack(t_list *stack);
bool			parse_args(int argc, char **argv, t_list **stack);
void			push_a(t_stack stacks);
void			push_b(t_stack stacks);
void			rotate_a(t_stack stacks);
void			rotate_b(t_stack stacks);
void			rotate_stacks(t_stack stacks);
void			reverse_rotate_a(t_stack stacks);
void			reverse_rotate_b(t_stack stacks);
void			reverse_rotate_stacks(t_stack stacks);
void			swap_a(t_stack stacks);
void			swap_b(t_stack stacks);
void			swap_stacks(t_stack stacks);
t_instructions	compute_moves(t_list *stack, t_stack stacks, int position);
void			create_chunks(int size, t_stack stacks);
t_value			*greater_elem(int value, t_list *stack);
void			index_stack(t_list *stack, int size);
void			sort_stack(t_stack stacks, int size);

#endif
