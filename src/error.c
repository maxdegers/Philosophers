/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:34:15 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/08 15:36:12 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_perror(t_error error)
{
	if (error == MALLOC)
		write(2, "\033[1;31mError\033[0m: MALLOC Fail.\n", 27);
	if (error == THREAD_CREATE)
		write(2, "\033[1;31mError\033[0m: Thread creation fail.\n", 30);
	if (error == THREAD_JOIN)
		write(2, "\033[1;31mError\033[0m: Thread join fail.\n", 26);
	if (error == THREAD_INIT)    
		write(2, "\033[1;31mError\033[0m: Thread init fail.\n", 26);
	if (error == ARGS_U)
		write(2, "\033[1;31mError\033[0m: Too much arguments.\n", 27);
	if (error == ARGS_D)
		write(2, "\033[1;31mError\033[0m: Too few arguments.\n", 26);
	if (error == ARGS_N)
		write(2, "\033[1;31mError\033[0m: invalide arguments.\n", 27);
	if (error == MUTEX_INIT)    
		write(2, "\033[1;31mError\033[0m: Mutex init fail.\n", 24);  
}

void    ft_free_mutex(t_tab *tab)
{
	size_t	i;

	i = 0;
	if (tab->tab_fork)
	{
		while (i < tab->n_philo)
		{
			pthread_mutex_destroy(&tab->tab_fork[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&tab->m_print);
	pthread_mutex_destroy(&tab->m_ready);
	pthread_mutex_destroy(&tab->m_time);
}

void    ft_big_free(t_tab   *tab)
{
	ft_free_mutex(tab);
	if (tab->tab_fork)
		free(tab->tab_fork);
	if (tab->tab_philo)
		free(tab->tab_philo);
}