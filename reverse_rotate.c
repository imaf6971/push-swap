/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 01:43:24 by erayl             #+#    #+#             */
/*   Updated: 2021/11/28 07:38:24 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stackelem	*get_lastprev(t_stack *stack)
{
	t_stackelem	*elem;

	elem = stack->head;
	while (elem->next != stack->tail)
		elem = elem->next;
	return (elem);
}

void	reverse_rotate(t_stack *stack)
{
	t_stackelem	*tmp;
	t_stackelem	*tmp0;

	tmp = get_lastprev(stack);
	tmp0 = stack->head;
	stack->head = stack->tail;
	stack->head->next = tmp0;
	stack->tail = tmp;
	tmp->next = NULL;
}

void	rra(t_swap *swap)
{
	write(1, "rra\n", 4);
	reverse_rotate(swap->a);
}

void	rrb(t_swap *swap)
{
	write(1, "rrb\n", 4);
	reverse_rotate(swap->b);
}

void	rrr(t_swap *swap)
{
	write(1, "rrr\n", 4);
	reverse_rotate(swap->a);
	reverse_rotate(swap->b);
}
