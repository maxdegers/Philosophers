/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:46:55 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/07 19:36:07 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdint.h>
# include <time.h>
# include <sys/time.h>
# include <limits.h>

typedef enum e_error
{
	MALLOC,
	THREAD_CREATE,
	THREAD_JOIN,
	THREAD_INIT,
	ARGS_U,
	ARGS_D,
	ARGS_N,
	TIME,
}	t_error;

struct	s_tab;

typedef struct	s_philo
{
	int				id;
	struct s_tab	tab;
}				t_philo;

typedef struct	s_tab
{
	unsigned long	start_tim;
	size_t			n_philo;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	long			tt_think;
	size_t			eating_count;
	int				is_dead;
	int				is_done;
	t_philo			*tab_philo;
	t_fork			*tab_fork;
	pthread_mutex_t	m_print;
}		t_tab;

typedef struct	s_fork
{
	int				owner;
	pthread_mutex_t	m_fork;
}		t_fork;

// atoi.c
long int	ft_atol(const char *str);
int			ft_atoi(const char *str);
// checker.c
int			ft_check(int argc, char **argv);
// error.c
void    ft_perror(t_error error);
void    ft_big_free(t_tab   tab);
#endif