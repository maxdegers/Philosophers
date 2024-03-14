/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:38:12 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/14 19:40:18 by mbrousse         ###   ########.fr       */
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
	long long	end;

	end = ft_get_time() + time;
	c_time = ft_get_time();
	while (c_time < end)
	{
		c_time = ft_get_time();
		if (c_time > philo->tt_die)
		{
			ft_print(philo->tab, philo->id, DEAD);
			return ;
		}
		usleep(10);		
	}
	usleep(philo->tab->n_philo * 10);
}
