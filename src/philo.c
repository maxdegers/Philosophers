/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:16:26 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/11 14:26:39 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_tab	tab;

	if (ft_init(&tab, argc, argv))
		return (ft_big_free(&tab), 1);
	ft_big_free(&tab);
	return (0);
}
