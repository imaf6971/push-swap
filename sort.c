/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 07:22:32 by erayl             #+#    #+#             */
/*   Updated: 2021/11/28 07:57:00 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (stack);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	simplify(t_stack *st)
{
	t_stack	*copy;
	size_t	i;
	size_t	j;

	copy = stackdup(st);
	sortll(copy);
	i = 0;
	while (i < st->size)
	{
		j = 0;
		while (j < copy->size)
		{
			if (get_by_index(st->head, i) == get_by_index(copy->head, j))
			{
				set_by_index(st->head, i, (int) j);
				break ;
			}
			j++;
		}
		i++;
	}
	delstack(copy);
}

int	getmaxbits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_swap	*swap)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	tmp;

	max_num = swap->a->size;
	max_bits = getmaxbits(max_num);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < max_num)
		{
			tmp = swap->a->head->value;
			if (((tmp >> i) & 1) == 1)
				ra(swap);
			else
				pb(swap);
			j++;
		}
		while (swap->b->size != 0)
			pa(swap);
		i++;
	}	
}

void	swapdel(t_swap	*swap)
{
	delstack(swap->a);
	delstack(swap->b);
	free(swap);
}
