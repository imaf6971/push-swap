/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 07:23:26 by erayl             #+#    #+#             */
/*   Updated: 2021/12/15 15:16:29 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	check_stack_is_sorted(t_stack *stack)
{
	t_stackelem	*this;
	t_stackelem	*next;

	if (stack->size == 0)
		exit(0);
	this = stack->head;
	next = this->next;
	while (next != NULL)
	{
		if (this->value > next->value)
			return ;
		this = next;
		next = next->next;
	}
	exit(0);
}

void	sortll(t_stack *st)
{
	int			tmp;
	t_stackelem	*min;
	t_stackelem	*i;
	t_stackelem	*j;

	i = st->head;
	while (i != NULL)
	{
		j = i;
		min = j;
		while (j != NULL)
		{
			if (min->value > j->value)
				min = j;
			j = j->next;
		}
		tmp = i->value;
		i->value = min->value;
		min->value = tmp;
		i = i->next;
	}
}

int	get_by_index(t_stackelem *s, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		s = s->next;
		i++;
	}
	return (s->value);
}

void	set_by_index(t_stackelem *s, size_t index, int value)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		s = s->next;
		i++;
	}
	s->value = value;
}

void	delstack(t_stack	*stack)
{
	t_stackelem	*i;

	i = stack->head;
	while (i != NULL)
	{
		free(i);
		i = i->next;
	}
	free(stack);
}
