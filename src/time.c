/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:38:12 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/09 15:09:59 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(t_philo *philo, long long time)
{
	long long	c_time;

	c_time = ft_get_time();
	while (c_time - philo->last_meal < time)
	{
		if (c_time - philo->last_meal > philo->tab->tt_die)
		{
			ft_print(philo->tab, philo->id, DEAD);
			philo->tab->is_dead = 1;
			return ;
		}
		c_time = ft_get_time();
	}
}
