/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:09:49 by erayl             #+#    #+#             */
/*   Updated: 2021/12/05 16:06:50 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
#include "libft/libft.h"
typedef struct s_stackelem
{
	int					value;
	struct s_stackelem	*next;
} t_stackelem;
typedef struct s_stack
{
	t_stackelem	*head;
	t_stackelem	*tail;
	size_t		size;
} t_stack;
typedef	struct s_swap
{
	t_stack	*a;
	t_stack	*b;
} t_swap;
void	args_to_stack(const char *arg, t_stack *a);
t_stack	*stack_init(void);
t_swap	*swap_init();
void	sortll(t_stack *st);
int		get_by_index(t_stackelem *s, size_t index);
void	delstack(t_stack	*stack);
void	set_by_index(t_stackelem *s, size_t index, int value);
void	pushtoend(t_stack *stack, int value);
void	check_stack_unique(t_stack *stack);
int		checkarg(const char *str);
void	simplify(t_stack *st);
void	swapdel(t_swap	*swap);
void	radix_sort(t_swap	*swap);
void	check_stack_is_sorted(t_stack *stack);
long	atol_and_check(const char *s);
t_stack	*stackdup(t_stack *stack);
void	sa(t_swap	*swap);
void	sb(t_swap	*swap);
void	ss(t_swap	*swap);
void	pb(t_swap *swap);
void	pa(t_swap *swap);
void	ra(t_swap *swap);
void	rb(t_swap *swap);
void	rr(t_swap *swap);
void	rrr(t_swap *swap);
void	rra(t_swap *swap);
void	rrb(t_swap *swap);
#endif