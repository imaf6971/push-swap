/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 07:25:56 by erayl             #+#    #+#             */
/*   Updated: 2021/12/05 17:00:52 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	err_and_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

long	atol_and_check(const char *s)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*s && *s == ' ')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	if (!ft_isdigit(*s))
		err_and_exit();
	while (*s && ft_isdigit(*s))
	{
		result *= 10;
		result += *s++ - '0';
	}
	if (*s != '\0' || (result * sign) > INT32_MAX
		|| (result * sign) < INT32_MIN)
		err_and_exit();
	return (result * sign);
}

void	args_to_stack(const char *arg, t_stack *a)
{
	char	**splitnums;
	size_t	i;

	splitnums = ft_split(arg, ' ');
	i = 0;
	while (splitnums[i] != NULL)
	{
		pushtoend(a, atol_and_check(splitnums[i]));
		i++;
	}
	while (i--)
		free(splitnums[i]);
	free(splitnums);
}
