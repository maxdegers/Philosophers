/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:38:56 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/08 22:39:04 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_print(t_tab *tab, int id, t_message m)
{
	unsigned long	time;
	static char		*message[6] = {"died", "is eating", "is sleeping",
			"is thinking", "has taken a fork",
			"Too many philosophers, set to 200"};

	pthread_mutex_lock(&tab->m_print);
	time = ft_get_time() - tab->start_tim;
	if (m == DEAD)
		printf("%lu \033[1;36m%d \033[1;31m%s\033[0m\n", time, id + 1, message[m]);
	if (m == END)
		printf("\033[1;32mAll philosophers have eaten %ld times\033[0m\n", tab->eating_count);
	if (m == M_PHILO)
		printf("\033[1;34m%s\033[0m\n", message[m]);
	else
		printf("%lu \033[1;36m%d \033[1;33m%s\033[0m\n", time, id + 1, message[m]);
	pthread_mutex_unlock(&tab->m_print);
}
int	ft_dead_status(t_tab *tab)
{
	int i;

	pthread_mutex_lock(&tab->m_print);
	i = tab->is_dead;
	pthread_mutex_unlock(&tab->m_print);
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