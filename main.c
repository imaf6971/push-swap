/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:18:34 by erayl             #+#    #+#             */
/*   Updated: 2021/12/15 15:18:14 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
