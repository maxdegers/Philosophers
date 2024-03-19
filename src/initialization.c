/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:34:10 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/19 11:35:52 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_set_tab(t_tab *tab, int argc, char **argv)
{
	if (ft_check(argc, argv) == 1)
		exit(1);
	tab->n_philo = ft_atol(argv[1]);
	if (tab->n_philo > MAX_PHILO)
	{
		ft_putstr_fd(MAX_PHILO_STR, 1);
		tab->n_philo = MAX_PHILO;
	}
	tab->tt_die = ft_atol(argv[2]);
	tab->tt_eat = ft_atol(argv[3]);
	tab->tt_sleep = ft_atol(argv[4]);
	tab->tt_think = 0;
	if ((tab->n_philo % 2 == 0) && (tab->tt_eat > tab->tt_sleep))
		tab->tt_think = 4000;
	if (argc == 6)
		tab->eating_count = ft_atoi(argv[5]);
	else
		tab->eating_count = 0;
	tab->is_dead = 0;
	tab->is_done = 0;
	return (0);
}

static int	ft_set_mutex(t_tab *tab)
{
	size_t	i;

	tab->tab_mutex = malloc((M_DEAD + 1) * sizeof(pthread_mutex_t));
	if (!tab->tab_mutex)
		return (ft_perror(MALLOC), 1);
	i = 0;
	while (i <= M_DEAD)
	{
		if (pthread_mutex_init(&tab->tab_mutex[i], NULL))
			return (ft_perror(MUTEX_INIT), 1);
		i++;
	}
	tab->tab_fork = malloc(tab->n_philo * sizeof(t_fork));
	if (!tab->tab_fork)
		return (ft_perror(MALLOC), 1);
	i = 0;
	while (i < tab->n_philo)
	{
		tab->tab_fork[i].owner = -1;
		if (pthread_mutex_init(&tab->tab_fork[i].m_fork, NULL))
			return (ft_perror(MUTEX_INIT), 1);
		i++;
	}
	return (0);
}

static int	ft_set_philo(t_tab *tab)
{
	size_t	i;

	i = 0;
	tab->tab_philo = malloc(tab->n_philo * sizeof(t_philo));
	if (!tab->tab_philo)
		return (ft_perror(MALLOC), 1);
	while (i < tab->n_philo)
	{
		tab->tab_philo[i].id = i;
		tab->tab_philo[i].tab = tab;
		tab->tab_philo[i].eating_count = 0;
		tab->tab_philo[i].left_fork = &tab->tab_fork[i];
		tab->tab_philo[i].last_meal = ft_get_time();
		tab->tab_philo[i].tt_die = tab->tab_philo[i].last_meal
			+ tab->tab_philo[i].tt_die;
		tab->tab_philo[i].right_fork = &tab->tab_fork[(i + 1) % tab->n_philo];
		i++;
	}
	return (0);
}

static int	ft_set_threads(t_tab *tab)
{
	size_t	i;

	pthread_mutex_lock(&tab->tab_mutex[M_READY]);
	i = 0;
	while (i < tab->n_philo)
	{
		if (pthread_create(&tab->tab_philo[i].p_thread,
				NULL, &ft_routine, &tab->tab_philo[i]))
		{
			while (i--)
				if (pthread_join(tab->tab_philo[i].p_thread, NULL))
					ft_perror(THREAD_JOIN);
			return (ft_perror(THREAD_CREATE), 1);
		}
		i++;
	}
	tab->start_tim = ft_get_time();
	pthread_mutex_unlock(&tab->tab_mutex[M_READY]);
	i = -1;
	while (++i < tab->n_philo)
		if (pthread_join(tab->tab_philo[i].p_thread, NULL))
			return (ft_perror(THREAD_JOIN), 1);
	ft_end(tab);
	return (0);
}

int	ft_init(t_tab *tab, int argc, char **argv)
{
	if (ft_set_tab(tab, argc, argv) == 1)
		return (1);
	if (ft_set_mutex(tab))
		return (1);
	if (ft_set_philo(tab))
		return (1);
	if (ft_set_threads(tab))
		return (1);
	return (0);
}
