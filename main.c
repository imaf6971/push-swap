/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:18:34 by erayl             #+#    #+#             */
/*   Updated: 2021/12/06 13:27:09 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	compare(int a, int b)
{
	return (a - b);
}

int	mid_value(t_stack *s)
{
	int			mid_index;
	int			i;
	t_stackelem	*si;

	mid_index = s->size / 2;
	i = 0;
	si = s->head;
	while (i < mid_index)
	{
		si = si->next;
		i++;
	}
	return (si->value);
}

void	smallsort(t_swap *swap)
{
	int	ttm;
	int	mtb;
	int	btt;

	ttm = compare(
		swap->a->head->value,
		swap->a->head->next->value);
	mtb = compare(
		swap->a->head->next->value,
		swap->a->tail->value;
	btt = compare(
		swap->a->tail->value,
		swap->a->head->value);
	if (ttm > 0 && mtb < 0 && btt > 0)
		sa(swap);
	else if (ttm > 0 && mtb > 0 && btt < 0)
	{
		sa(swap);
		rra(swap);
	}
	else if (ttm > 0 && mtb < 0 && btt < 0)
		ra(swap);
	else if (ttm < 0 && mtb > 0 && btt > 0)
	{
		sa(swap);
		ra(swap);
	}
	else if (ttm < 0 && mtb > 0 && btt < 0)
		rra(swap);
}

void	fivesort(t_swap *swap)
{
	pb(swap);
	pb(swap);
	smallsort(swap);
	if (swap->b->head->value > swap->a->tail->value)
	{
		pa(swap);
		ra(swap);
	}
}

int	main(int argc, char const *argv[])
{
	int		i;
	t_swap	*swap;

	if (argc > 1)
	{
		swap = swap_init();
		i = 1;
		while (i < argc)
		{
			args_to_stack(argv[i], swap->a);
			i++;
		}
		check_stack_unique(swap->a);
		check_stack_is_sorted(swap->a);
		simplify(swap->a);
		if (swap->a->size == 3)
			smallsort(swap);
		else if (swap->a->size == 5)
			fivesort(swap);
		else
			radix_sort(swap);
		swapdel(swap);
	}
	return (0);
}
