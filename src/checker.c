/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:34:17 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/08 22:34:25 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_num(const char *str)
{
	size_t	i;

	if (!str)
		return (1);
	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (1);
	}
	return (0);
}
int	ft_check(int argc, char **argv)
{
	if (argc > 6)
		return (ft_perror(ARGS_U), 1);
	if (argc < 5)
		return (ft_perror(ARGS_D), 1);
	while (argc > 1)
	{
		if ((ft_is_num(argv[argc-1]) == 1) || ft_atol(argv[argc-1]) < 1)
			return (ft_perror(ARGS_N), 1);
		argc--;
	}
	return (0);
}
