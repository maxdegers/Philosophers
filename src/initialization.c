/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:34:10 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/07 23:11:54 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_set_tab(t_tab tab, int argc, char **argv);

int ft_init(t_tab *tab, int argc, char **argv)
{
	if (ft_set_tab(tab, argc, argv))
		return (1);
	if (ft_set_mutex(tab))
		return (1);
	// if (ft_set_philo(tab))
	// 	return (1);
	// if (ft_set_threads(tab))
	// 	return (1);
	return (0);
}

static int	ft_set_tab(t_tab *tab, int argc, char **argv)
{
	if (ft_check(argc, argv))
		return (1);
	tab->start_tim = ft_get_time();
	tab->n_philo = ft_atol(argv[1]);
	tab->tt_die = ft_atol(argv[2]);
	tab->tt_eat = ft_atol(argv[3]);
	tab->tt_sleep = ft_atol(argv[4]);
	if (argc == 6)
		tab->eating_count = ft_atoi(argv[5]);
	else
		tab->eating_count = -1;
	tab->is_dead = 0;
	tab->is_done = 0;
	return (0);
}

int	ft_set_mutex(t_tab *tab)
{
	size_t	i;

	if (pthread_mutex_init(&tab->m_print, NULL))
		return (ft_perror(THREAD_INIT), 1);
	if (tab->tab_fork = malloc(tab->n_philo * sizeof(t_fork)))
		return (ft_perror(MALLOC), 1);
	while (i <= tab->n_philo)
	{
		if (pthread_mutex_init(&tab->tab_fork[i], NULL))
			return (ft_perror(MUTEX_INIT), 1);
		i++;
	}
	
	return (0);

}