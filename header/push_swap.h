/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:43:11 by agerbaud          #+#    #+#             */
/*   Updated: 2024/01/12 10:22:14 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>

typedef struct stack_lst
{
	int		nbr;
	void	*next;
}	t_stack;

/*ALGO*/
t_stack	*put_into_stack(char **list);

/*INSTRUCTIONS*/
void	ft_swap(t_stack *stack_a, t_stack *stack_b, int target);
void	ft_push(t_stack *stack_a, t_stack *stack_b, int target);
void	ft_rotate(t_stack *stack_a, t_stack *stack_b, int target);
void	ft_reverse_rotate(t_stack *stack_a, t_stack *stack_b, int target);

/*LST INSTRUCTIONS*/
t_stack	*ft_lstnew(void *content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstcount(t_stack *lst);

/*UTILS*/
int		ft_atoi(const char *nptr);
int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd, int *nb_char);
void	ft_putstr_fd(char *s, int fd, int *nb_char);
void	ft_putnbr_fd(int n, int fd, int *nb_char);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd, int *nb_char);
void	ft_puthexa(unsigned int nbr, char *base, int *nb_char);
void	ft_putpointer(unsigned long long nbr, int *nb_char, int first);
size_t	ft_strlen(const char *s);

#endif
