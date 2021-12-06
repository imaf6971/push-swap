/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:10:41 by erayl             #+#    #+#             */
/*   Updated: 2021/12/05 15:49:02 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stackelem	*newstackelem(int num)
{
	t_stackelem	*new;

	new = (t_stackelem *) malloc(sizeof(t_stackelem));
	if (!new)
		return (new);
	new->value = num;
	new->next = NULL;
	return (new);
}

void	pushtoend(t_stack *stack, int value)
{
	t_stackelem	*elem;

	elem = newstackelem(value);
	stack->size++;
	if (stack->head == NULL && stack->tail == NULL)
	{
		stack->head = elem;
		stack->tail = elem;
		return ;
	}
	stack->tail->next = elem;
	stack->tail = elem;
}

void	check_stack_unique(t_stack *stack)
{
	t_stackelem	*current;
	t_stackelem	*tmp;

	current = stack->head;
	while (current != NULL)
	{
		tmp = current->next;
		while (tmp != NULL)
		{
			if (current->value == tmp->value)
			{
				write(STDERR_FILENO, "Error\n", 6);
				exit(1);
			}
			tmp = tmp->next;
		}
		current = current->next;
	}
}

t_swap	*swap_init(void)
{
	t_swap	*swap;

	swap = (t_swap *) malloc(sizeof(t_swap));
	if (!swap)
		return (swap);
	swap->a = stack_init();
	swap->b = stack_init();
	return (swap);
}

t_stack	*stackdup(t_stack *stack)
{
	t_stack		*dup;
	t_stackelem	*tmp;

	dup = stack_init();
	tmp = stack->head;
	while (tmp != NULL)
	{
		pushtoend(dup, tmp->value);
		tmp = tmp->next;
	}
	return (dup);
}
