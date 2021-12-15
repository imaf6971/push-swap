/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:17:01 by erayl             #+#    #+#             */
/*   Updated: 2021/12/15 15:28:48 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	smallsort(t_swap *swap)
{
	int	ttm;
	int	mtb;
	int	btt;

	ttm = swap->a->head->value - swap->a->head->next->value;
	mtb = swap->a->head->next->value - swap->a->tail->value;
	btt = swap->a->tail->value - swap->a->head->value;
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

void	mins_to_b(t_swap *swap)
{
	while (swap->a->size != 3)
	{
		if (swap->a->head->value == 0 || swap->a->head->value == 1)
			pb(swap);
		else if (swap->a->head->next->value == 0
			|| swap->a->head->next->value == 1)
			sa(swap);
		else if (swap->a->tail->value == 0 || swap->a->tail->value == 1)
			rra(swap);
		else
			ra(swap);
	}
	if (swap->b->head->value == 0)
		sb(swap);
}

void	fivesort(t_swap *swap)
{
	mins_to_b(swap);
	smallsort(swap);
	pa(swap);
	pa(swap);
}
