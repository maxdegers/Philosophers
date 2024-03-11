/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:34:15 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/11 14:17:35 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_perror(t_error error)
{
	if (error == MALLOC)
		ft_putstr_fd("\033[1;31mError\033[0m: Malloc failed.\n", 2);
	if (error == THREAD_INIT)
		ft_putstr_fd("\033[1;31mError\033[0m: Thread initialization failed.\n",
			2);
	if (error == MUTEX_INIT)
		ft_putstr_fd("\033[1;31mError\033[0m: Mutex initialization failed.\n",
			2);
	if (error == ARGS_U)
		ft_putstr_fd("\033[1;31mError\033[0m: Too many arguments.\n", 2);
	if (error == ARGS_D)
		ft_putstr_fd("\033[1;31mError\033[0m: Not enough arguments.\n", 2);
	if (error == ARGS_N)
		ft_putstr_fd("\033[1;31mError\033[0m: Invalid argument.\n", 2);
	if (error == THREAD_CREATE)
		ft_putstr_fd("\033[1;31mError\033[0m: Thread creation failed.\n", 2);
	if (error == THREAD_JOIN)
		ft_putstr_fd("\033[1;31mError\033[0m: Thread join failed.\n", 2);
	if (error == TIME)
		ft_putstr_fd("\033[1;31mError\033[0m: Time failed.\n", 2);
}

static void	ft_free_mutex(t_tab *tab)
{
	size_t	i;

	i = 0;
	if (tab->tab_fork != NULL)
	{
		while (i < tab->n_philo)
		{
			pthread_mutex_destroy(&tab->tab_fork[i].m_fork);
			i++;
		}
	}
	if (tab->tab_mutex != NULL)
	{
		i = 0;
		while (i <= M_DEAD)
		{
			pthread_mutex_destroy(&tab->tab_mutex[i]);
			i++;
		}
	}
}

void	ft_big_free(t_tab *tab)
{
	ft_free_mutex(tab);
	if (tab->tab_fork != NULL)
		free(tab->tab_fork);
	if (tab->tab_philo != NULL)
		free(tab->tab_philo);
	if (tab->tab_mutex != NULL)
		free(tab->tab_mutex);
}
