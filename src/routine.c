/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:37:46 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/08 22:59:03 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_eat(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (ft_ltake_fork(philo))
			if (ft_get_time() - philo->last_meal > philo->tab->tt_die)
				return (ft_print(philo->tab, philo->id, DEAD), 1);
	}
	else
		if (ft_rtake_fork(philo))
			if (ft_get_time() - philo->last_meal > philo->tab->tt_die)
				return (ft_print(philo->tab, philo->id, DEAD), 1);
	philo->last_meal = ft_get_time();
	ft_print(philo->tab, philo->id, EATING);
	ft_usleep(philo, philo->tab->tt_eat);
	philo->last_meal = ft_get_time();
	philo->eating_count++;
	ft_rrelease_fork(philo);
	ft_lrelease_fork(philo);
	return (0);
}

static int	ft_sleep(t_philo *philo)
{
	ft_print(philo->tab, philo->id, SLEEPING);
	ft_usleep(philo, philo->tab->tt_sleep);
	return (0);
}
void	*ft_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->tab->m_ready);
	pthread_mutex_unlock(&philo->tab->m_ready);
	while ((philo->tab->eating_count == 0 || philo->eating_count < philo->tab->eating_count) 
			&& ft_dead_status(philo->tab) == 0)
	{
		if (ft_eat(philo))
			break ;
		if (ft_dead_status(philo->tab))
			break ;
		if (ft_sleep(philo))
			break ;
		ft_print(philo->tab, philo->id, THINKING);
	}
	return (NULL);
}

