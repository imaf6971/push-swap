/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:28:25 by erayl             #+#    #+#             */
/*   Updated: 2021/11/28 05:39:13 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *from, t_stack	*to)
{
	t_stackelem	*tmp;
	t_stackelem	*tmp1;

	if (from->head == NULL)
		return ;
	tmp = to->head;
	tmp1 = from->head->next;
	to->head = from->head;
	to->head->next = tmp;
	from->head = tmp1;
	from->size--;
	to->size++;
}

void	pa(t_swap *swap)
{
	write(1, "pa\n", 3);
	push(swap->b, swap->a);
}

void	pb(t_swap *swap)
{
	write(1, "pb\n", 3);
	push(swap->a, swap->b);
}
