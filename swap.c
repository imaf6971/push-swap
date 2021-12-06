/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:27:36 by erayl             #+#    #+#             */
/*   Updated: 2021/11/28 01:08:38 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap_head(t_stackelem *stack_head)
{
	int	tmp;

	tmp = stack_head->value;
	stack_head->value = stack_head->next->value;
	stack_head->next->value = tmp;
}

void	sa(t_swap *swap)
{
	swap_head(swap->a->head);
	write(1, "sa\n", 3);
}

void	sb(t_swap *swap)
{
	swap_head(swap->b->head);
	write(1, "sb\n", 3);
}

void	ss(t_swap *swap)
{
	write(1, "ss\n", 3);
	swap_head(swap->a->head);
	swap_head(swap->b->head);
}
