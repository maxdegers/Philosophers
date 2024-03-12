/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:37:46 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/12 19:03:23 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_eat(t_philo *philo)
{
	if (philo->id % 2)
	{
		while (!ft_ltake_fork(philo))
			if (ft_get_time() - philo->last_meal > philo->tab->tt_die)
				return (ft_print(philo->tab, philo->id, DEAD), 1);
		while (!ft_rtake_fork(philo))
			if (ft_get_time() - philo->last_meal > philo->tab->tt_die)
				return (ft_print(philo->tab, philo->id, DEAD), 1);
	}
	else
	{
		while (!ft_rtake_fork(philo))
			if (ft_get_time() - philo->last_meal > philo->tab->tt_die)
				return (ft_print(philo->tab, philo->id, DEAD), 1);
		while (!ft_ltake_fork(philo))
			if (ft_get_time() - philo->last_meal > philo->tab->tt_die)
				return (ft_print(philo->tab, philo->id, DEAD), 1);
	}
	philo->last_meal = ft_get_time();
	ft_print(philo->tab, philo->id, EATING);
	ft_usleep(philo, philo->tab->tt_eat);
	philo->last_meal = ft_get_time();
	philo->eating_count++;
	return (ft_lrelease_fork(philo), ft_rrelease_fork(philo), 0);
}

static int	ft_sleep(t_philo *philo)
{
	ft_print(philo->tab, philo->id, SLEEPING);
	ft_usleep(philo, philo->tab->tt_sleep);
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->tab->tab_mutex[M_READY]);
	pthread_mutex_unlock(&philo->tab->tab_mutex[M_READY]);
	if (philo->id % 2)
		ft_usleep(philo, philo->tab->tt_think);
	while ((philo->tab->eating_count == 0
			|| philo->eating_count < philo->tab->eating_count)
		&& ft_dead_status(philo->tab) == 0)
	{
		if (ft_eat(philo))
			break ;
		if (ft_dead_status(philo->tab))
			break ;
		if (ft_sleep(philo))
			break ;
		if (ft_dead_status(philo->tab))
			break ;
		ft_print(philo->tab, philo->id, THINKING);
	}
	return (NULL);
}
