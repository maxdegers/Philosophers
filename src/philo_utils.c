/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:38:56 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/11 14:01:50 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_tab *tab, int id, t_message m)
{
	unsigned long	time;
	static char		*mess[6] = {
		"has died", "has finished eating", "is thinking",
		"is sleeping", "is eating", "has taken a fork"};

	pthread_mutex_lock(&tab->tab_mutex[M_PRINT]);
	if (tab->is_dead == 0)
	{
		time = ft_get_time() - tab->start_tim;
		if (m == DEAD)
		{
			pthread_mutex_lock(&tab->tab_mutex[M_DEAD]);
			tab->is_dead = 1;
			pthread_mutex_unlock(&tab->tab_mutex[M_DEAD]);
			printf("%lu \033[1;36m%d \033[1;31m%s\033[0m\n",
				time, id + 1, mess[m]);
		}
		else if (m == END)
			printf("\033[1;32mAll philosophers have eaten %ld times\033[0m\n",
				tab->eating_count);
		else
			printf("%lu \033[1;36m%d \033[1;33m%s\033[0m\n",
				time, id + 1, mess[m]);
	}
	pthread_mutex_unlock(&tab->tab_mutex[M_PRINT]);
}

int	ft_dead_status(t_tab *tab)
{
	int	i;

	pthread_mutex_lock(&tab->tab_mutex[M_DEAD]);
	i = tab->is_dead;
	pthread_mutex_unlock(&tab->tab_mutex[M_DEAD]);
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(const char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
