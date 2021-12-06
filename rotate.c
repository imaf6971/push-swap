/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 01:08:54 by erayl             #+#    #+#             */
/*   Updated: 2021/11/28 07:37:29 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *stack)
{
	t_stackelem	*tmp;

	tmp = stack->head->next;
	stack->tail->next = stack->head;
	stack->tail = stack->head;
	stack->head = tmp;
	stack->tail->next = NULL;
}

void	ra(t_swap *swap)
{
	write(1, "ra\n", 3);
	rotate(swap->a);
}

void	rb(t_swap *swap)
{
	write(1, "rb\n", 3);
	rotate(swap->b);
}

void	rr(t_swap *swap)
{
	write(1, "rr\n", 3);
	rotate(swap->a);
	rotate(swap->b);
}
